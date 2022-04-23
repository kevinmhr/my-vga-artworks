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
int c;
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9

typedef unsigned char byte;

byte far *VGA=(byte far *)0xA0000000L;
int color[10];
#define SETPIX(x,y,c) *(VGA+(x)+(y)*640)=c
#define SETPIC(x,y,c) *(VGA+(x)+(y)*320)=c
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int x, y,i,l,k,t;
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
void selec(){

for( c=0; c<10;c++ ){
c++;
//SETPIC(x*200,y*200,4  );

}

}
void default_scene(){


  for( y = 0; y < height; ++y ) {
    for( x = 0; x < width; ++x ) {


     // SETPIX( x , *VGA^2*i&y&x, i&y );
     //  SETPIX( *VGA^1&i&y, *VGA^6^i*x^y, tan(i&y));
      //  SETPIX(  *VGA&height,*VGA^height*x, tan(height));
    // SETPIX( x, y, y );
    }
  }
}
void default_scene2(){


  for( k = 0; k < 10; ++k ) {
    for( t = 0; t < 10; ++t ) {


     // SETPIX( x , *VGA^2*i&y&x, i&y );
      // SETPIC( k, t,k);
	SETPIC(  x+k,y+t, color[c]);

    // SETPIX( x, y, y );
    }


}

}



void roll(){


  for( k = 0; k < 30; ++k ) {
   // for( t = 0; t < 240; ++t ) {
   SETPIX( x,y ,tan(k));

     // SETPIX( x , *VGA^2*i&y&x, i&y );
      // SETPIC( k, t,k);
	SETPIX(  k*height,k&height, l&k^l);
    // SETPIX( x, y, y );

l=l*k;
k++;
//k=k;
height++;
l++;
  }
}




int main()
{
  char kc = 0;
  char s[255];
  byte *pal;

  set_mode( VGA_256_COLOR_MODE );


 selec();

  /* printf("Hello, world!\n"); */


  /* loop until ESC pressed */
  while( kc != 0x1b )

  {
  roll();
  selec();
  default_scene2();



       l++;

  roll();
    if(kbhit()) {
kc = getch();
      if( kc == (char)0 ) {
	kc = getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */
	      c++;
	    y=y-10;
		 height=height+10;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:

            l=l+20;
	    i=i*3;

	    x=x+10;

	  break;
	case 0x4b:

	x=x-10;
	i=i*3;
	break;


	case 0x50: /* down arrow */
		 height=10;
	  y=y+10;
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
