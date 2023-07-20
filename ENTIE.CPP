
#include <alloc.h>
#include <conio.h>
#include <dos.h>
#include <mem.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM_COLORS 256

#define SET_MODE 0x00
#define VIDEO_INT 0x10
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03

int height= 200;
int width= 320;

#define PI 3.14159


unsigned int SINEX[256];
unsigned int SINEY[256];



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
  float movx,movy;
  float x=50;
 float y=50;
 float x2=50;
 float y2=50;
 float x3=50;
 float y3=50;
 int swit[100];
  float r=0;
  int placesy[]={10,40,70,100,130,160,190};
    int placesx[]={10,40,70,100,130,160,190,220,250,280,310};

  float o=0;
   float r2=0;
  float o2=0;
 int lpin;
  int lpin2;
   float r3=0;
  float o3=0;
int rol=1;
int co;
void init_sin()
{
  int i;
  for( i = 0;i < 256; ++i ) {
    SINEX[i] = 320 * (( sin(2.0*M_PI*i/256.0) + 1.0) /2.0);
    SINEY[i] = 200 * (( sin(2.0*M_PI*i/128.0) + 1.0) /2.0);
  }
}

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





  for(i=0;i<320;i++)

  for(j=0;j<200;j++){





   // SETPIX(i,j,0);



    SETPIX(i,j,0);


//    SETPIX(i,j,0);





	      }


 }

void draw_rectangle( int x, int y, int w, int h, byte c )
{
  int i, j;
  for( j = y; j < y + h; ++j ) {
    for( i = x; i < x + w; ++i ) {
      byte far *dst = (byte far *)VGA + i + j * width;
      *dst = c;
    }
  }
}


void circle_slow(int x,int y, int radius, byte color)
{
     float n=0,invradius=1;
  int dx=0,dy=radius-1;
  word dxoffset,dyoffset,offset = (y<<8)+(y<<6)+x;

  while (dx<=dy)
  {
    if (rol>100){ dy=radius + rol; }
    dxoffset = (dx<<6) + (dx<<8);
    dyoffset = (dy<<6) + (dy<<8);
    VGA[offset+dy-dxoffset] = color;  /* octant 0 */
    VGA[offset+dx-dyoffset] = color;  /* octant 1 */
    VGA[offset-dx-dyoffset] = color;  /* octant 2 */
    VGA[offset-dy-dxoffset] = color;  /* octant 3 */
    VGA[offset-dy+dxoffset] = color;  /* octant 4 */
    VGA[offset-dx+dyoffset] = color;  /* octant 5 */
    VGA[offset+dx+dyoffset] = color;  /* octant 6 */
    VGA[offset+dy+dxoffset] = color;  /* octant 7 */

    dx=dx++;
    n+=invradius;

    dy=radius *cos(sin(n*SINEX[rol]/10));

	       // sin(acos(n))+ SINEX[rol]
  }

	     }
void Draw_triangle(float a,int b,int size,int col){
   int k,j;
   int c;



  //  k=a+size;
  //  i=b+size;
   for (i=a;i<a+size;i++){

       SETPIX(i,b,col);}

      for (i=b;i>b-size;i--){

 a=a+(0.5);
 SETPIX(int(a),i,col);


	      }
   for (i=b-size;i<b;i++){

 a=a+(0.50);



       SETPIX(int(a),i,col);}




    }

   //SETPIX(k,a+k,col);












void moving(){






}

int rolling(){


 // if (rol>lpin){rol=0;}
  if (swit[rol]==1){ o=o-0.5;r=r-0.5;}
  if (swit[rol]==2){o=o+0.5;r=r+0.5;}
//if (swit[rol]==3){o=o+0.5;r=r+0.5;}
 //		if (swit[rol]==4){o=o+0.5;r=r+0.5;}
 rol++;

 return 0;
}

void snd()
{
  int snu;

  for (snu=100;snu<1000;snu++){
   sound(snu+x+y+rol);       }

}
void Draw_rowsandcul(){

for (int i=0 ;i<6;i++){



   for (int k=0;k<10;k++){

 Draw_triangle(placesx[k]-5+x/5,placesy[i]+5+y/5,10,7);
			   }





}
	}
//}


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


// if (lpin>lpin2) {lpin=0;}
// if (lpin2>100){lpin2=0; }

// y2=y2+5;
//  x3=x3+5;
//y3=y3+5;

// x=x+5;
// y=y+5;
//rolling();}

  if (rol>lpin){rol=0;rolling();}
    //  movx=movx+1;
    // movy=movy+1;


   lpin++;
  //lpin2++;
  //o=o++;r=r++;o2=o2++;r2=r2++;o3=o3++;r3=r3++;rolling(); }
rolling();
 if (y>=150){r=-(r)/2;co++;snd();}

if (x>=270){o=-(o)/2;co++;snd();}
 if (x>=270){x=270;}
  if (y>=150){y=150;}
 if (k>1){k=1;}

if(y<20){r=-(r);co++;snd(); }
 if (x<=20){o=-(o);co++;snd();}

 if (y2>=150){r2=-(r2)/2;}

if (x2>=270){o2=-(o2)/2;}
 if (x2>=270){x2=270;}
  if (y2>=150){y2=150;}


if(y2<20){r2=-(r2); }
 if (x2<=20){o2=-(o2);}

 if (y3>=150){r3=-(r3)/2;}

if (x3>=270){o3=-(o3)/2;}
 if (x3>=270){x3=270;}
  if (y3>=150){y3=150;}


if(y3<20){r3=-(r3); }
 if (x3<=20){o3=-(o3);}



//if (o>5){o=5;}
//if (o2>5){o2=5;}
//if (o3>5){o3=5;}
 // if (r>=500){r=0;}
//if (r2>=500){r2=0;}
//if (r3>=500){r3=0;}


      //	for (int sync=0;sync<1;sync++){
	//  x=x-10;
init_sin();

  for (int d2=0 ;d2<2;d2++){
		 circle_slow(x,y,SINEY[rol],rol);
	 for (int i=0 ;i<15;i++){



	//  x2=x2-10;


Draw_rowsandcul();

			     circle_slow(x+8+i,y+12+i,30,rol);

		    //  Draw_triangle(x+d,y+d2+30,30,3);
		     //  Draw_triangle(x+d,y+d2+30,60,2);
		     draw_rectangle(x-(i),y-(i),30,30,co );
				     circle_slow(x+i,y+i,i,co);


	      x=x+o;
 y=y+r;

	}  }





       rol++;
	//     o++;
     // o2++;
      //	     o3++;
       //	      r++;
       //	      r2++;
       //	     r3++;
  x2=x2+o2;
  y2=y2+r2;
  x3=x3+o3;
 y3=y3+r3;



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

		 r=r-2;
		  r2=r2-2;
		   r3=r3-2;
		// rolling();
	       //	 movy=movy-1;
	     //	 height=height+10;
	  //strcpy(s, "up arrow");
	break;
	case 0x4d:
		      o=o+2;
		       o2=o2+2;
			o3=o3+2;
		//	rolling();
	      // movx=movx+1;
	   // i=i*3;



	  break;
	case 0x4b:
		  //	 rolling();
		    //	 movx=movx-1;

		      o=o-2;
		       o2=o2-2;
			o3=o3-2;

	break;


	case 0x50: /* down arrow */
	    r=r+2;
	     r2=r2+2;
	      r3=r3+2;
	       //	    movy=movy+1;
     //	rolling();
      //	break;
     //	case 0x52:





	  //strcpy(s, "down arrow");
       //	  break;
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
