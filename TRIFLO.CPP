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

int height= 20;
int width= 32;

#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9
typedef unsigned short word;
typedef unsigned char byte;
typedef long           fixed16_16;
fixed16_16 SIN_ACOS[1024];

byte far *VGA=(byte far *)0xA0000000L;

#define SETPIX(x,y,c) *(VGA+(x)+(y)*320)=c
//#define CLS(x,c) *(VGA+(x))=c
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
  int i,l,k,z,j;

  int x=20;
 int y=20;
 int x2=50;
 int y2=50;
 int x3=90;
 int y3=90;

  int r=2;
  int o=2;
   int r2=2;
  int o2=2;

   int r3=2;
  int o3=2;

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
void clsc(){

      int c;





  for(i=0;i<340;i++)

  for(j=0;j<200;j++){





   // SETPIX(i,j,0);



    SETPIX(i,j,0);


//    SETPIX(i,j,0);




      }



 }


void circle_fast(int x,int y, int radius, byte color)
{
  fixed16_16 n=0,invradius=(1/(float)radius)*0x10000L;
  int dx=0,dy=radius-1;
  word dxoffset,dyoffset,offset = (y<<8)+(y<<6)+x;

  while (dx<=dy)
  {
    dxoffset = (dx<<8) + (dx<<6);
    dyoffset = (dy<<8) + (dy<<6);
    VGA[offset+dy-dxoffset] = color;  /* octant 0 */
    VGA[offset+dx-dyoffset] = color;  /* octant 1 */
    VGA[offset-dx-dyoffset] = color;  /* octant 2 */
    VGA[offset-dy-dxoffset] = color;  /* octant 3 */
    VGA[offset-dy+dxoffset] = color;  /* octant 4 */
    VGA[offset-dx+dyoffset] = color;  /* octant 5 */
    VGA[offset+dx+dyoffset] = color;  /* octant 6 */
    VGA[offset+dy+dxoffset] = color;  /* octant 7 */
    //dx++;
    n+=invradius;
    dy = (int)((radius * SIN_ACOS[(int)(n>>6)]) >> 16);
  }
}


void circle_slow(int x,int y, int radius, byte color)
{
  float n=0,invradius=1/(float)radius;
  int dx=0,dy=radius-1;
  word dxoffset,dyoffset,offset=(y<<8)+(y<<6)+x;

  while (dx<=dy)
  {
    dxoffset = (dx<<8) + (dx<<6);
    dyoffset = (dy<<8) + (dy<<6);
    VGA[offset+dy-dxoffset] = color;  /* octant 0 */
    VGA[offset+dx-dyoffset] = color;  /* octant 1 */
    VGA[offset-dx-dyoffset] = color;  /* octant 2 */
    VGA[offset-dy-dxoffset] = color;  /* octant 3 */
    VGA[offset-dy+dxoffset] = color;  /* octant 4 */
    VGA[offset-dx+dyoffset] = color;  /* octant 5 */
    VGA[offset+dx+dyoffset] = color;  /* octant 6 */
    VGA[offset+dy+dxoffset] = color;  /* octant 7 */
    dx++;
    n+=invradius;
    dy=radius * sin(acos(n));
  }
}






void moving(){






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

 if (y>=176){r=-(r);} if (y>=190){y=175;}
//if (k>1){k=1;}
if (x>=311){o=-(o);} if (x>=320){x=310;}

 if (k>1){k=1;}

if(y<=10){r=-(r); }  if(y<=0){y=0; }
 if (x<=10){o=-(o);}  if (x<=0){x=0;}
  if (y2>=176){r2=-(r2);} if (y2>=190){y2=175;}
//if (k>1){k=1;}
if (x2>=311){o2=-(o2);} if (x2>=320){x2=310;}



if(y2<=10){r2=-(r2); }  if(y2<=0){y2=0; }
 if (x2<=10){o2=-(o2);}  if (x2<=0){x2=0;}

 if (y3>=176){r3=-(r3);} if (y3>=190){y3=175;}
//if (k>1){k=1;}
if (x3>=311){o3=-(o3);} if (x3>=320){x3=310;}



if(y3<=10){r3=-(r3); }  if(y3<=0){y3=0; }
 if (x3<=10){o3=-(o3);}  if (x3<=0){x3=0;}

		       circle_slow(x3,y3,10+y3/20,3 );

		      circle_slow(x2,y2,10+y2/20,4 );


			 circle_slow(x,y,10+y/20,1 );
  x2=x2+o2;
 y2=y2+r2;
  x3=x3+o3;
 y3=y3+r3;


 x=x+o;
 y=y+r;
	// clsc();
		 clsc();
//	 y=y+k;
//k=k*z;

	 //Clear();

    if(kbhit()) {


      kc = getch();
      if( kc == (char)0 ) {

	kc = getch();
	/* special key handling */
	switch( kc )
	{
	case 0x48: /* up arrow */
		 y2=y2+1;
		 x2=x2+1;

	     //	 height=height+10;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:

	       y3=y3+1;
	       x3=x3+1;
	   // i=i*3;



	  break;
	case 0x4b:
			 x=x+1;
       y=y+1;


	break;


	case 0x50: /* down arrow */



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
