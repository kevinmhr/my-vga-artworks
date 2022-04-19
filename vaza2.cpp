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

int height= 20;
int width= 32;

#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)*(y))=c
#define GETPIX(x,y) *(VGA+(x)+(y)*SCREEN_WIDTH)
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int x, y,i,l;
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

void default_scene(){


  for( y = 0; y < height; ++y ) {
    for( x = 0; x < width; ++x ) {
  

     // SETPIX( x , *VGA^2*i&y&x, i&y );
       SETPIX( *VGA^1&i&y, *VGA^6^i*x^y, tan(i&y));
      //  SETPIX(  *VGA&height,*VGA^height*x, tan(height));
    // SETPIX( x, y, y );
    }
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
  default_scene();
	i=i+1;
	height=i;


    if(kbhit()) {
      kc = getch();
      if( kc == (char)0 ) {
	kc = getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */

		 height=height+10;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:


	    i=i*3;



	  break;
	case 0x4b:


	i=i*3;
	break;


	case 0x50: /* down arrow */
		 height=10;

	  i=i*2;
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
