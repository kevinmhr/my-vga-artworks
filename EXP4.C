

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <mem.h>
#include <conio.h>
#include <math.h>
#define VIDEO_INT           0x10      /* the BIOS video interrupt. */
#define SET_MODE            0x00      /* BIOS func to set the video mode. */
#define VGA_256_COLOR_MODE  0x13      /* use to set 256-color mode. */
#define TEXT_MODE           0x03      /* use to set 80x25 text mode. */

#define SCREEN_WIDTH        320       /* width in pixels of mode 0x13 */
#define SCREEN_HEIGHT       200       /* height in pixels of mode 0x13 */
#define NUM_COLORS          256       /* number of colors in mode 0x13 */

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;
  FILE *fp;

byte *VGA=(byte *)0xA0000000L;        /* this points to video memory. */
word *my_clock=(word *)0x0000046C;    /* this points to the 18.2hz system
  int stk=1;
					 clock. */

char *buffer;
//char *buffer2;
int plusent=0;
int plus2=0;
double sint[320];
char plusodd=0;
char map[20000];
typedef struct tagENTITY              /* the structure for a bitmap. */
{
double posxacc[1000];
double posyacc[1000];

double posx[1000];
double posy[1000];
int dirx[1000];
int diry[1000];

} ENT;
ENT cre;
typedef struct tagBITMAP              /* the structure for a bitmap. */
{
  word width;
 word height;
  byte *data;
} BITMAP;
//  BITMAP bmp;
//   BITMAP bmp2;


void kputpixel(char *buffer,int x,int y,int col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);
int plus=19000;
int sclv=0,sclh=0;
    double d2=0.04;
   double col[256];
  double col2=0;
 double tet=0;
  byte u,f,o,l;
   byte u3,f3,o3,l3;
   int sc;
 byte u1=0,f1=0,o1=0,l1=0;

 double u2=0,f2=0,o2=0,l2=0;
double playerx=100;
double playery=170;
double accx=0,accy=0;
int bulletx,bullety;
int bullettrig=0;
/**************************************************************************
 *  fskip                                                                 *
 *     Skips bytes in a file.                                             *
 **************************************************************************/

void fskip(FILE *fp, int num_bytes)
{
   int i;
   for (i=0; i<num_bytes; i++)
      fgetc(fp);
}

/**************************************************************************
 *  set_mode                                                              *
 *     Sets the video mode.                                               *
 **************************************************************************/

void set_mode(byte mode)
{
  union REGS regs;

  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86(VIDEO_INT, &regs, &regs);
}

/**************************************************************************
 *  load_bmp                                                              *
 *    Loads a bitmap file into memory.                                    *
 **************************************************************************/

void load_bmp(char *file,BITMAP *b)
{

  long index;
  word num_colors;
  int x,y;
   int j;
  int xoffset=0;
  word bitmap_offset = 0;
  word screen_offset=0;
  /* open the file */
  if ((fp = fopen(file,"rb")) == NULL)
  {
    printf("Error opening file %s.\n",file);
    exit(1);
  }

  /* check to see if it is a valid bitmap file */
  if (fgetc(fp)!='B' || fgetc(fp)!='M')
  {
    fclose(fp);
    printf("%s is not a bitmap file.\n",file);
    exit(1);
  }
  /* read in the width and height of the image, and the
     number of colors used; ignore the rest */
  fskip(fp,16);
  fread(&b->width, sizeof(word), 1, fp);
  fskip(fp,2);
  fread(&b->height,sizeof(word), 1, fp);
  fskip(fp,22);
  fread(&num_colors,sizeof(word), 1, fp);
  fskip(fp,6);

  /* assume we are working with an 8-bit file */
  if (num_colors==0) num_colors=256;


  /* try to allocate memory */
  if ((b->data =(byte*)malloc((word)(64000U))) == NULL)

  {
    fclose(fp);
    printf("Error allocating memory for file %s.\n",file);
    exit(1);
  }

  /* Ignore the palette information for now.
     See palette.c for code to read the palette info. */

  fskip(fp,num_colors*4);

  /* read the bitmap */

  for(index=320*b->height;index>=0;index-=320)
    for(x=0;x<b->width;x++)
   b->data[index+x]=(byte)fgetc(fp);



  fclose(fp);
}





void kdrawrectfill(char *buffer,int x,int y,int w,int h,int col){
int i,j;
for (i=x;i<x+w;i++){
for (j=y;j<y+h;j++){
kputpixel(buffer,i,j,col);
}}                       }


int kgetpixelpage(char *buffer,int x,int y){
int col;

col=buffer[x+(y*320)];

return col;

}



int kgetpixelbmp(BITMAP *bp,int x,int y){
int col;

col=bp->data[x+(y*320)];

return col;

}
void kputpixel(char *buffer,int x,int y,int col){


buffer[x+(y*320)]=col;

}


void kdrawtransbitmap(BITMAP *b,int desx,int desy,int posx,int posy,int w,int h,int colc){
int x,y;
int col;
for (y=0;y<=h;y++){

for (x=0;x<=w;x++){

col=b->data[(x+desx)+((y+desy)*320)];
if (col)
buffer[x+posx+((y+posy)*320)]=col+colc;
}

}





}


void wait(int ticks)
{
  word start;

  start=*my_clock;

  while (*my_clock-start<ticks)
  {
    *my_clock=*my_clock;              /* this line is for some compilers
					 that would otherwise ignore this
					 loop */
  }
}

/**************************************************************************
 *  Main                                                                  *
 *    Draws opaque and transparent bitmaps                                *
 **************************************************************************/

int stk=1;
mapfill(int u,int t,int k,int o){
int i;
  u=0;   t=0;   k=0;  o=0;

 for (i=0;i<19000;i++){
 o+=10;
 t+=abs(sin(k)*3)+(cos(i)*2);
 if (t>50){map[i]=3; t=0;     }

 u+=abs(sin(k)*3)+abs(sin(i)*2);; k+=abs(sin(i+k)*3)-abs(sin(i+o)*2);
 if (u>1){map[i]=1; u=0;    }
  if (k>5){map[i]=2;  k=0;   }




 }        }


void main()
{
  int sprcol=0;
  double t;
  int i,x,y,x1,y1;
  double k;
  int ti=0;
  int si=0;
 int o4,l4;
 // BITMAP bmp;
  int xpos;int ypos;
    buffer=(char*)malloc(64000U);
//  buffer2=(char*)malloc(64000U);
tet=1;

  // load_bmp("rocket.bmp",&bmp);
	t=0;

init:
//sound(-1);
  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */
tet=0;
for (i=0;i<320;i++){
sint[i]=(sin(tet)*10);
tet+=0.05;
		    }



si=100;

       col2=1;
 memset(buffer,0,64000);
   tet=0;
while (stk==1){
//sound(-1);
u2=(sin(f2)*0.1);
l2=(cos(o2)*0.1);
f2+=sin(1)*0.003;
o2+=sin(1)*0.003;

xpos=1;
ypos=1;

//xpos=(sin(l2)*2)+(cos(l2)*2);
//ypos=-(sin(l2)*2)+(cos(l2)*2);
tet+=1;
if (tet>200){tet=0;}

for (y=10;y<190;y+=1){


//kdrawrectfill(buffer,x,0,20,200,0);


//o+=1;
//l+=1;

//o=((int)((sin(y))*l1)|(int)((cos(y))*l1));;
l3=((sin(y*((l2)))*10*sint[y]))+((cos(y*((u2)))*10*sint[y]));


for (x=10;x<310;x+=1){

o3=((cos(x*((u2)))*10*sint[x]))+((sin(x*((l2)))*10*sint[x]));
ti=0;



k=(l3+o3)|110+10;

//if (o>6){o=4;}
//if (l>6){l=4;}
kputpixel(buffer,x,y,k);

//kdrawrectfill(buffer,0,y,320,20,0);

   }

//u++;
//o1+=1;
     }




//kdrawtransbitmap(buffer2,buffer,100,100,60,60,0);
   memcpy(VGA,buffer,64000);


  /* draw the background */


   if (kbhit())

{stk++;
 getch();  }





}


   if (stk>2){stk=1;   memset(buffer,0,64000);
 }
d2=0.05;

gh:

//kdrawrectfill(buffer,0,190,320,20,0);

//kdrawtransbitmap(&bmp,63,18,playerx,playery,35,35,10);
//kdrawrectfill(buffer2,playerx,playery,35,35,0);

	     if (plus<0){plus=20000;}
	  if (playerx>280){playerx=280;}
	  if (playerx<10){playerx=10;}
	  if (playery>170){playery=170;}
	  if (playery<10){playery=10;}
	 if(accx>0){   accx-=0.006;  }
	 if(accx<0){   accx+=0.006;  }
	 if(accy>0){   accy-=0.006;  }
	 if(accy<0){   accy+=0.006;  }

	  playerx+=accx;
	  playery+=accy;

	  if (accx>1){accx=1;}
	  if (accy>1){accy=1;}
	  if (accx<-1){accx=-1;}
	  if (accy<-1){accy=-1;}
       ti++;  if (ti>2){sound(-1);ti=0;}
    if (bullettrig==1){ti++;     sound(400); if (ti>2){sound(-1);ti=0;}

      kdrawrectfill(buffer,bulletx,bullety,3,3,62);
    bullety-=(playery)/20;



    }
    if (bullety<0){
    bullettrig=0;

    }
    if (bullettrig==0){
    bulletx=playerx+18;
    bullety=playery;
    }


    if (kbhit()) {
   sc=getch();
      if (sc==27){stk=0;}
      switch(sc) {
		case 0x48 :   accy-=0.4;
		break;
		case 0x4b:    accx-=0.4;
		break;
		case 0x50:    accy+=0.4;
		break;
		case 0x4d:    accx+=0.4;
		break;
	       case 32:    bullettrig=1;
		break;

		  }   }
	memcpy(VGA,buffer,64000);







while (stk==0){

 return;       }


}

