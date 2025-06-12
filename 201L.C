
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


byte *VGA=(byte *)0xA0000000L;        /* this points to video memory. */
word *my_clock=(word *)0x0000046C;    /* this points to the 18.2hz system
  int stk=1;
					 clock. */
char *buffer;
char *buffer2;

char map[20000];

typedef struct tagBITMAP              /* the structure for a bitmap. */
{
  word width;
  word height;
  byte *data;
} BITMAP;

void kputpixel(char *buffer,int x,int y,int col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);
int plus=20000;
int sclv=0,sclh=0;
    double d2=0.04;
   double col[256];
  double col2=0;

 byte u,f,o,l;
 byte u1=0,f1=0,o1=0,l1=0;

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
  FILE *fp;
  long index;
  word num_colors;
  int x,y;

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
  if ((b->data = (byte *) malloc((word)(b->width*b->height))) == NULL)

  {
    fclose(fp);
    printf("Error allocating memory for file %s.\n",file);
    exit(1);
  }

  /* Ignore the palette information for now.
     See palette.c for code to read the palette info. */

  fskip(fp,num_colors*4);

  /* read the bitmap */

  for(index=(b->height-1)*b->width;index>=0;index-=b->width)
    for(x=0;x<b->width;x++)
      b->data[(word)index+x]=(byte)fgetc(fp);

  fclose(fp);
}

void copy_bitmap(BITMAP *bmp)
{
  int j;
  int xoffset=0;
  word bitmap_offset = 0;
  word screen_offset=0;
  for(j=0;j<bmp->height;j++,screen_offset+=SCREEN_WIDTH)
  {
    memcpy(&buffer2[screen_offset],&bmp->data[bitmap_offset],bmp->width);

    bitmap_offset+=bmp->width;

  }
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


void kdrawtransbitmap(char* buffer,int desx,int desy,int posx,int posy,int w,int h,int colc){
int x,y;
int col;
for (y=0;y<=h;y++){

for (x=0;x<=w;x++){

col=buffer2[(x+desx)+((y+desy)*320)];
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
void plasma(int intr,int colc){

int x,y;
u=u1;
f=f1;

for (x=1;x<320;x+=intr){
o=o1;
l=l1;


       for (y=1;y<200;y+=intr){

kputpixel(buffer,x,y,(col[f]+col[u]+col[o]+col[l])+colc);



o+=5;
l+=3;

 }
u+=1;
f+=1;

 }
 l1+=5;
 o1+=3;
 u1+=2;
 f1+=1;
   }

int stk=1;
void main()
{

  double t;
  int i,x,y,x1,y1;
  double k;
  int ti=0;
 // BITMAP bmp;

  BITMAP bmp;
   BITMAP bmp2;
    BITMAP plane;
    buffer=(char*)malloc(64000U);
  buffer2=(char*)malloc(64000U);

   load_bmp("plane.bmp",&plane);

   load_bmp("rocket.bmp",&bmp);

   load_bmp("map.bmp",&bmp2);
  u=0;      k=0;  o=0;
 for (i=0;i<20000;i++){
 o+=10;
 u+=abs(sin(k)*3)+abs(sin(i)*2);; k+=abs(sin(i+k)*3)-abs(sin(i+o)*2);
 if (u>1){map[i]=1; u=0;    }
  if (k>5){map[i]=2;  k=0;   }




 }
 u=0;k=0;
 /* open the file */

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */





//   memset(buffer2,0,64000);

  memset(buffer,0,64000);
t=0;
for (i=0;i<256;i++){
  t+=0.05;
  col[i]=((cos(t)));
}


       col2=1;
while (stk==1){

ti++;

plasma(1,0);

copy_bitmap(&bmp2);
kdrawrectfill(buffer2,50,50,40,40,0);

kdrawtransbitmap(buffer,0,0,0,0,320,200,0);


copy_bitmap(&bmp);


kdrawtransbitmap(buffer,0,0,100,100,50,59,0);
kputpixel(buffer,150,10,f1+o+l);



for (x=0;x<=320;x+=60){

//kdrawrectfill(buffer,x,0,20,200,0);

   }

for (y=0;y<200;y+=60){

//kdrawrectfill(buffer,0,y,320,20,0);

   }

//kdrawtransbitmap(buffer2,buffer,100,100,60,60,0);
   memcpy(VGA,buffer,64000);


  /* draw the background */


   if (kbhit())

{stk++;copy_bitmap(&plane);
 getch();  }





}


   if (stk>2){stk=0;   memset(buffer,0,64000);
 }
d2=0.05;

while (stk==2){
 int k;
 int i=-10;

 int v=-1;
 int sc;
 sclv-=1;
  if(sclv<=0){sclv=10;plus-=32;   }
 kdrawrectfill(buffer,0,0,320,240,0);


 plasma(2,0);
 for (k=0;k<=649;k++){
 i++; if (i>31){i=0;v+=10;}
// if (v>200){v=0;}

if (map[k+plus]==0){
kdrawrectfill(buffer,i*10,v-sclv,5,5,200);  }

if (map[k+plus]==2){
kdrawrectfill(buffer,i*10,v-sclv,8,8,4);  }


     }

kdrawrectfill(buffer,0,190,320,20,0);
//kdrawrectfill(buffer,playerx,playery,20,20,5);
//copy_bitmap(&bmp);

kdrawtransbitmap(buffer,0,0,playerx,playery,35,30,200);
	     if (plus<0){plus=20000;}
	  if (playerx>280){playerx=280;}
	  if (playerx<10){playerx=10;}
	  if (playery>170){playery=170;}
	  if (playery<10){playery=10;}
	 if(accx>0){   accx-=0.005;  }
	 if(accx<0){   accx+=0.005;  }
	 if(accy>0){   accy-=0.005;  }
	 if(accy<0){   accy+=0.005;  }

	  playerx+=accx;
	  playery+=accy;

	  if (accx>1){accx=1;}
	  if (accy>1){accy=1;}
	  if (accx<-1){accx=-1;}
	  if (accy<-1){accy=-1;}
       ti++;  if (ti>4){sound(-1);ti=0;}
    if (bullettrig==1){ti++;     sound(5000); if (ti>4){sound(-1);ti=0;}

      kdrawrectfill(buffer,bulletx,bullety,3,3,62);
    bullety-=(playery)/30;



    }
    if (bullety<10){
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
		case 0x48 :   accy-=0.2;
		break;
		case 0x4b:    accx-=0.2;
		break;
		case 0x50:    accy+=0.2;
		break;
		case 0x4d:    accx+=0.2;
		break;
	       case 32:    bullettrig=1;
		break;

		  }   }
	memcpy(VGA,buffer,64000);




}


while (stk==0){

 return;       }


}

