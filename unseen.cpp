#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
//include "c:\adlib.cpp"
#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03

int height= 200;
int width= 320;
int radius;
int dx,dy;
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9
typedef unsigned short word;
typedef unsigned char byte;
typedef long           fixed16_16;

fixed16_16 SIN_ACOS[2048];
byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)*(y)*200)=c
#define GETPIX(x,y) *(VGA+(x)*(y)*SCREEN_WIDTH)
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int x, y,i,l;
word dxoffset,dyoffset;
  word offset;
void set_mode(byte mode)
{
   union REGS regs;
  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86( VIDEO_INT, &regs, &regs );
}
void put_pixels(){

 union REGS regs;
  regs.h.ah = 0x0c;
  regs.h.al = 4;
  regs.x.cx = x;
  regs.x.dx = y;
  int86( VIDEO_INT, &regs, &regs );



}
void circle_slow(int x,int y, int radius, byte color)
{
  radius=radius;
  float n=0,invradius=1/(float)radius;
  int dx=0,dy=radius-1;
   word dxoffset,dyoffset;
   //offset=(y<<8)+(y<<6)+x;

  while (dx<=dy)
  {
 //   dxoffset = (dx<<8) + (dx<<6);
 //   dxoffset = (sin(dx)) - (cos(dx));
    VGA[offset-tan(dy)*radius-(dx)] = tan(dy);  /* octant 0 */
   // VGA[offset+dx+dyoffset] = color;
   dx++;

    n+=invradius;
    dy=radius * sin(acos(n));
  }
}

void circle_2(int x,int y, int radius, byte color)
{
  radius=radius+1;
  float 	n=0,invradius=1/(float)radius;
  int dx=0,dy=radius-1;

  radius=(y)+(y)*(x);

  while (dx<=dy)
  {
    dxoffset = (dx<<8) + (dx<<6);
    dyoffset = (dy<<8) + (dy<<6);
    VGA[offset+dxoffset+dyoffset] = color;  /* octant 0 */
    dx=dx+100;
    n+=invradius;
    dy=radius * sin(acos(n));
  }
}



void default_scene(){


  for( y = 0; y < 1000; ++y ) {



//      SETPIX( x , *VGA^2*i&y&x, i&y );
    //	    SETPIX( i&y&x, 10^i*x^y, tan(i));
  //	    SETPIX( *VGA^i&y&x, *VGA^i&x^y, tan(i&height));
      //  SETPIX(  *VGA&height,*VGA^height*x, tan(height));
     SETPIX( x, y, y );

  }
}
void scene2(){


  for( y = 0; y < height; ++y ) {
    for( x = 0; x < width; ++x ) {
      x=sin(y);
      SETPIX( x,*VGA^2*i&y&x , i*cos(y) );
   //    SETPIX( x, *VGA^2*i, i *(sin(y) );
     // SETPIX( x, y, y );
    }
  }
}







int main()
{
















  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );




  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc != 0x1b )

  {

      circle_slow(x,y,offset,radius );
	offset=offset+1;
	     // dx=dx+1;
	    i=i+1;
    if(kbhit()) {
      kc = getch();
      if( kc == (char)0 ) {

	kc = getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */

                dx=dx+1;

	 //strcpy(s, "up arrow");
	break;
	case 0x4d:


		    offset=offset>>16;



	  break;
	case 0x4b:

		offset=offset<<16;

	break;


	case 0x50: /* down arrow */
		 offset=offset-1;
	  //strcpy(s, "down arrow");
	  break;
	default: /* other special keys */
	 // sprintf(s, "00 %02x", kc);
	  break;
	}
      } else {
       //	sprintf(s, "%02x", kc);

      }
     // printf("Key pressed: %s\n", s);
    }

  }

  set_mode( TEXT_MODE );

  return 0;
}

