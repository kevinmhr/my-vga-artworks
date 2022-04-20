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

#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)+(y)*height)=c
#define GETPIX(x,y) *(VGA+(x)+(y)*SCREEN_WIDTH)
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int x, y,i,j,l;
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

void default_scene1(){





     // SETPIX( x , *VGA^2*i&y&x, i&y );

       //	SETPIX( *VGA^1&x, *VGA^2^i*x^y, tan(i*x));
       SETPIX(  x+i,y+i, 4);
    // SETPIX( x, y, y );


}
void default_scene(){


  for( i =0; i < 200; ++i ) {


      SETPIX( x^i,y^i , i );
   x++;
  // y++;
   //
//    SETPIX( x, *VGA^2*i, i *(sin(y) );
     // SETPIX( x, y, y );
    }

}







int main()
{
  int c,l;
  x=100;
  y=100;
  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );




  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc != 0x1b )

  {
  for(l=10;l<190;l++){
  for(c=10;c<310;c++){

    SETPIX (c,y,0);
  }
  }

       //	i=i+1;

    default_scene();
    if(kbhit()) {

      kc = getch();
      if( kc == (char)0 ) {
	kc = getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */

		 y=y-1;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:



	x=x+1;





	  break;
	case 0x4b:


	x=x-1;
	break;


	case 0x50: /* down arrow */


	  y=y+1;
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
