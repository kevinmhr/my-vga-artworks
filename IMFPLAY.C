/*
K1n9_Duk3's IMF Player - A simple IMF player for DOS
Copyright (C) 2013-2016 K1n9_Duk3

Based on the Apogee Sound System (ASS) and Wolfenstein 3-D (W3D)

ASS is Copyright (C) 1994-1995 Apogee Software, Ltd.
W3D is Copyright (C) 1992 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

//#define PRETTY          //use colors & draw status bar
#define OLDSKOOL        //limit IMF files to 64KB max.

#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef PRETTY
    #include <graph.h>
    #include <string.h>
#endif

#ifndef OLDSKOOL
    #include <malloc.h>
    #define ALLOC(x) halloc(x/2, 2)
    #define FREE(x) hfree(x)
    #define IMFDATA unsigned short __huge
    #define IMFSIZE unsigned long
#else
    #define ALLOC(x) malloc(x)
    #define FREE(x) free(x)
    #define IMFDATA unsigned short
    #define IMFSIZE unsigned short
#endif

#define ADLIB_PORT 0x388
#define TIMER_BASE 1192030

//for IMF loading:
static IMFDATA *imfdata;
static IMFSIZE imfsize;

//for IMF playback:
static IMFDATA *_imfptr;
static IMFSIZE _imfwait, _imfsize;
static int _isChunk, loop=0;
static unsigned long _totalticks, _imfticks=0;
static int _isKMF=0;

#ifdef PRETTY
    #include "rawscreen.h"
    //for progress bar:
    #define PROGBAR_LENGTH 76
    #define PROGBAR_COLUMN (1+(80-PROGBAR_LENGTH)/2)
    #define PROGBAR_ROW 22
    #define STATUS_ROW 1
    static char pb_empty[PROGBAR_LENGTH], pb_full[PROGBAR_LENGTH];
    static char regs[256];
#endif

//for interrupt handling:
static void ( __interrupt __far *OldInt8 )( void );
static unsigned long speed, counter=0;

/*===============================
 Code derived from ASS and W3D:
================================*/

static void ADLIB_SendOutput    //from ASS
(
   int reg,
   int data
)

{
   int i;
#ifdef PRETTY
   regs[reg] = data;
#endif
    _disable(); //disable interrupts
    
   outp( ADLIB_PORT, reg );

   for( i = 6; i ; i-- )
   {
      inp( ADLIB_PORT );
   }
   outp( ADLIB_PORT + 1, data );

   for( i = 35; i ; i-- )
   {
      inp( ADLIB_PORT );
   }
   
   _enable(); //enable interrupts
}

void ADLIB_Reset()    //from ASS
{
    unsigned char i, slot1, slot2;
    static unsigned char slotVoice[9][2] = {{0,3},{1,4},{2,5},{6,9},{7,10},{8,11},{12,15},{13,16},{14,17}};
    static unsigned char offsetSlot[18] = {0,1,2,3,4,5,8,9,10,11,12,13,16,17,18,19,20,21};
    
    ADLIB_SendOutput(   1, 0x20);   // Set WSE=1
    ADLIB_SendOutput(   8,    0);   // Set CSM=0 & SEL=0
    ADLIB_SendOutput(0xBD,    0);   // Set AM Depth, VIB depth & Rhythm = 0
    
    for(i=0; i<9; i++)
    {
        slot1 = offsetSlot[slotVoice[i][0]];
	slot2 = offsetSlot[slotVoice[i][1]];
        
        ADLIB_SendOutput(0xB0+i, 0);    //turn note off
	ADLIB_SendOutput(0xA0+i, 0);    //clear frequency

        ADLIB_SendOutput(0xE0+slot1, 0);
        ADLIB_SendOutput(0xE0+slot2, 0);

        ADLIB_SendOutput(0x60+slot1, 0xff);
        ADLIB_SendOutput(0x60+slot2, 0xff);
        ADLIB_SendOutput(0x80+slot1, 0xff);
	ADLIB_SendOutput(0x80+slot2, 0xff);

	ADLIB_SendOutput(0x40+slot1, 0xff);
        ADLIB_SendOutput(0x40+slot2, 0xff);
    }
}

void ADLIB_ResetQnD()   //quick & dirty reset from W3D (for DRO2IMF compatibility)
{
    /*
        The DOSBox raw OPL capture format (.DRO) assumes that all registers are
        initially set to 0 and therefore does not store any commands that set a
        register to 0 at the beginning of the file.

        Due to the rather simple nature of the DRO2IMF converter by Malvineous
	and NY00123, the resulting IMF files do not set any registers to 0
        either, which makes it virtually impossible to play IMF files created
        by DRO2IMF correctly in any of the original DOS games that use the IMF
	format.

        To provide at least basic support for those files, though, this function
        sets all registers to 0, which is exactly what the original IMF playback
        code in W3D does. Setting WSE=1 is also part of the original code and is
        required for many IMF files (e.g. FANFAREA.IMF from DUKE NUKEM II) to
        be played correctly.

	Unfortunately, looped playback of DRO2IMF files will not work correctly
        because the registers are not set to 0 when the song is restarted.
	It would be possible to have IMF_Service() call this function when the
        song is restarted, but that would cause an undesired delay. Plus, you
        do not have that option if you want to play the IMF file in one of the
	DOS games anyway. Just use external tools like "K1n9_Duk3's IMF crusher
        v1.2" to fix the IMF file instead.
    */
    unsigned char i;
    for (i=1; i<=0xF5; ADLIB_SendOutput(i++, 0));    //clear all registers
    ADLIB_SendOutput(1, 0x20);  // Set WSE=1
}

int ADLIB_Detect()   //from ASS
{
    int status1, status2, i;

    ADLIB_SendOutput(4, 0x60);
    ADLIB_SendOutput(4, 0x80);

    status1 = inp(ADLIB_PORT);
    
    ADLIB_SendOutput(2, 0xFF);
    ADLIB_SendOutput(4, 0x21);

    for (i=100; i>0; i--) inp(ADLIB_PORT);

    status2 = inp(ADLIB_PORT);

    ADLIB_SendOutput(4, 0x60);
    ADLIB_SendOutput(4, 0x80);

    if ( ( ( status1 & 0xe0 ) == 0x00 ) && ( ( status2 & 0xe0 ) == 0xc0 ) )
    {
        ADLIB_ResetQnD();
        return 1;
    } else {
        return 0;
    }
}

static void IMF_Service() //based on W3D playback routines
{

    unsigned short value;

    if (!_imfptr)
	return;

    if (_isKMF)
    {
	while ((_imfsize) && (!_imfwait))
	{
	    unsigned short count;

	    value = *_imfptr++;
	    count = value & 0xFF;
	    _imfwait = (value >> 8);
	    _imfsize -= 2;
	    while ((count--) && (_imfsize))
	    {
		value = *_imfptr++;
		_imfsize -= 2;
                ADLIB_SendOutput(value & 0xFF, (value >> 8) & 0xFF);
            }
        }
    }
    else
    {
        while ((_imfsize) && (!_imfwait))
        {
            value = *_imfptr++;

	    _imfwait = *_imfptr++;
	    _imfsize -= 4;
            ADLIB_SendOutput(value & 0xFF, (value >> 8) & 0xFF);
	}
    }
    _imfwait--;
    _imfticks++;
    if (!_imfsize)
    {
	//end of song
        if (loop)
        {
            _imfptr = imfdata;
            _imfsize = imfsize;
            if (_isKMF)
            {
		_imfsize = imfdata[3];
                _imfptr += 4;
	    }
	    else if(_isChunk)
	    {
                _imfsize = (*_imfptr++) & 0xFFFC;
	    }
            _imfticks = 0;
            //for full DRO2IMF compatibility, you would need to call ADLIB_ResetQnD() here
        } else {
            _imfptr = NULL;
        }
        //reset wait value:
	_imfwait = 0;
        //Note that this basically ignores the pause after the last IMF command.
        //(That is exactly how Wolf3D handles it.)
    }
}

static void __interrupt __far ISR_Service()
{
    //our custom interrupt stuff:
    IMF_Service();

    //act as if we didn't modify the timer:
    counter += speed;
    if (counter > 0xFFFFL)
    {
       counter &= 0xFFFFL;
       _chain_intr(OldInt8);    //call old interrupt handler and let it Ack
    } else {
       outp( 0x20,0x20 );       //Ack the interrupt
    }
}

void ISR_ResetRate(unsigned int rate)
{
    _disable(); //disable interrupts
    
    //set new timer:
    speed = TIMER_BASE/rate;
    outp(0x43, 0x36);
    outp(0x40, speed);
    outp(0x40, (speed >> 8));
    
    _enable();  //enable interrupts
}

void ISR_Start(unsigned int rate)
{
    //NEVER lose the original interrupt handler!
    if(OldInt8)
	return;
    
    _disable(); //disable interrupts

    //save old interrupt handler:
    OldInt8 = _dos_getvect(8);

    //set new interrupt hander:
    _dos_setvect(8, ISR_Service);

        //set new timer:
    ISR_ResetRate(rate);

    _enable();  //enable interrupts
}

void ISR_Stop()
{
    _disable(); //disable interrupts

    //restore old timer:
    /*
    outp(0x43, 0x36);
    outp(0x40, 0);
    outp(0x40, 0);
    */
    _asm {
        mov al, 36h;
        out 43h, al;
        mov al, 0;
	out 40h, al;
        out 40h, al;
    }

    //restore old interrupt:
    _dos_setvect(8, OldInt8);

    _enable();  //enable interrupts
}


/*===============================
 New code for the IMF player:
================================*/

int IMF_IsChunk(IMFDATA *data, IMFSIZE size)
{
    /*
        The idea is that the first few IMF commands set up the AdLib registers
        and therefore should have no delay. Even if there is a delay, it would
        normally be relatively low compared to the combined 16-bit value of the 
        (register, value) pair.

        This function checks the first 42 IMF commands, taking the first 16-bit
        value as the assumed chunk size, and adds all the (reg, val) and delay
        values to sum1 and sum2. Assuming the IMF data is a chunk, sum1 should
	contain the sum of all (reg, val) pairs while sum2 contains the sum of
        all delays. If the data really is a chunk, sum1 should be greater than
	sum2 and the chunk size should at least be 2 bytes (size of the chunk
        size value) less than the total size of the data read from a file.

        The only case in which this detection would fail is IMF data that writes
        a bunch of zeroes to register zero (which would be pointless since that
        register is undefined) and/or has very large delays (which would be 
        pointless because it would lead to delays of up to a minute before the
	next IMF command would be processed, resulting in multiple minutes of
        silence before the song actually starts playing notes).
    */
    unsigned long sum1=0, sum2=0, i=2;
    unsigned int chunksize;

    if (data[0] == 0x4D4B && data[1] == 0x1A46)
    {
        _isKMF = 1;
        return 0;
    }

    chunksize = *data++;
    if (chunksize == 0) return 0;

    while (i<size && i-2<chunksize)
    {
	sum1 += *data++;  //if it's a chunk, this is the (register, value) pair
        sum2 += *data++;  //if it's a chunk, this is the delay
	i += 4;
	if (i > 168) break;
    }
    return ((sum1 > sum2) && (chunksize < size));
}


void IMF_PlaySong(IMFDATA *data, IMFSIZE size)
{
    _imfptr = data;
    _imfsize = size;
    _imfwait = 0;
}

void IMF_StopSong()
{
    _imfptr = NULL;
    ADLIB_Reset();
}

char IMF_SongPlaying()
{
    return (_imfptr != NULL);
}

#define MIN(a,b) (((a)<(b)) ? (a) : (b))

int IMF_LoadSong(char *filename)
{
    FILE *in;
    IMFSIZE size;
    int error=0;

    in = fopen(filename, "rb");
    if (!in)
    {
	//try to open filename.imf instead:
	char *buffer = malloc(strlen(filename)+5);
	if (buffer)
	{
	    strcpy(buffer, filename);
	    strcat(buffer, ".IMF");
	    in = fopen(buffer, "rb");
	    free(buffer);
	}
    }
    if (in)
    {
	//get file size:
	fseek( in, 0, SEEK_END );
	size = 65000;//tell(in);
	fseek( in, 0, SEEK_SET );

	//free old song data (if any)
	if(imfdata)
	{
	    IMF_StopSong();
	    FREE(imfdata);
	}

	imfdata = ALLOC(size);
	if (imfdata)
	{
	    IMFDATA *data = imfdata;
	    IMFSIZE size_2 = size/2;

	    while (size_2)
	    {
		size_t step_size = fread(data, 2, MIN(0x4000, size_2), in);
		if (!step_size)
		    break;
		size_2 -= step_size;
		data += step_size;
		printf(". ");
		fflush(stdout);
	    }
	    if(!size_2)
	    {
		imfsize = size;
		imfsize -= imfsize & 3L; //each IMF command is 4 bytes
		_imfptr = imfdata;
		_imfsize = imfsize;
		_imfwait = 0;
		_isChunk = IMF_IsChunk(imfdata, size);
		if (_isKMF)
		{
		    _imfsize = imfdata[3];
		    _imfptr += 4;       // the first 4 words (8 bytes) are header data
		}
		else if (_isChunk)
		{
		    _imfsize = (*_imfptr++) & 0xFFFC;
		}
	    } else {
		printf("Unexpected end of file while reading '%s'.\n", filename);
		error = 1;
	    }
	} else {
	    printf("Out of memory while reading '%s'.\n", filename);
	    error = 1;
	}
	fclose(in);
	return error;
    } else {
	return 1;
    }
}

