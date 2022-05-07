#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03

int height= 320;
int width= 200;
int ff();
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define GETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int i,k,l,c,o,z;
  int r;

int x=100;
int  y=150;
int key;
void set_mode(byte mode)
{
   union REGS regs;
  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86( VIDEO_INT, &regs, &regs );
}
int chara[]={2,2,3,4,6,3,7,6,8,9,3,5,7,7,3,4,5,7,3,4};
void put_pixels(){

 union REGS regs;
  regs.h.ah = 0x0c;
  regs.h.al = 4;
  regs.x.cx = x;
  regs.x.dx = y;
  int86( VIDEO_INT, &regs, &regs );



}

void default_scene()
		       {
	   for (l=0;l<20;l++){
	      GETPIX( chara[l+2], chara[l]-k*2, l );
	      GETPIX( chara[l+3], chara[l]-k*4, 4 );
	      GETPIX( chara[l+4], chara[l]-k*6, 3 );
			      }





}
void clsc(){


       for(l=0;l<200;l++){

				 SETPIX( x+1, y+1, 3 );
  for(c=0;c<320;c++){

	//	 SETPIX( x+3, y+1, 3 );
    SETPIX (c+1,l+1,0);
	 SETPIX( x+2, y+2, 2 );
	    SETPIX( x+4, y+4, x+y );
		   SETPIX( x+4, y+1, x+y );
	     //	 SETPIX( x+1, y+5, 3 );
			 SETPIX( x+5, y+5, x+y );

				 SETPIX( x+4, y+1, 3 );


     //	 SETPIX( x+2, y+5, 3 );
      }}


						  //    GETPIX( chara[k], chara[k], k );
 }



int main(){






  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );



  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc!=0X1b )


  {
if (y>190){y=190;}
if (x>310){x=310;}
if(y<10){y=10;}
 if (x<10){x=10;}
if (z>0){z=0;}



if (l=x-3&l>150-k){ printf("kcycle");};




k=k+z;

x=x+o;
y=y+r;
clsc();
//key++;
put_pixels();       //	i=i+1;

 default_scene();
    if(kbhit()) {

	       //	printf(s, "r",s);

       kc=getch();
      if( kc == (char)0 ) {
	kc=getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */

	 //  y=y-5;
	 // k=k+2;
	   z=z-1;
	  // o=0;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:

	       //left

      //	x=x+5;
	      r=0;
	      o=1;



	 break;
	case 0x4b:

		 r=0;
       //	x=x-5;
		o=-1;
	  break;

	case 0x50: /* down arrow */
		   o=0;
		k=k-2;
		z=z++;
		//  r=1;
       //	  y=y+5;
	  //strcpy(s, "down arrow");
	   break;
	default: /* other special keys */
	//    r=0;
	  //  o=0;
	 //
	  sprintf(s, "00 %02x", kc);

	}
      }


      else {
       //	sprintf(s, "%02x", kc);
       r=0;o=0;
      }
     // printf("Key pressed: %s\n", s);



  }


}
default_scene();
 set_mode( TEXT_MODE );

  return 0;
}

