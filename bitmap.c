
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
					 clock. */
char *buffer;
char *buffer2;

typedef struct tagBITMAP              /* the structure for a bitmap. */
{
  word width;
  word height;
  byte *data;
} BITMAP;

void kputpixel(char *buffer,int x,int y,int col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);


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
  int x;

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

/**************************************************************************
 *  draw_bitmap                                                           *
 *    Draws a bitmap.                                                     *
 **************************************************************************/

void copy_bitmap(BITMAP *bmp)
{   int x=0;int y=0;
  int j;
  word screen_offset = (y<<8)+(y<<6)+x;
  word bitmap_offset = 0;

  for(j=0;j<bmp->height;j++)
  {
    memcpy(&buffer2[screen_offset],&bmp->data[bitmap_offset],bmp->width);

    bitmap_offset+=bmp->width;
    screen_offset+=SCREEN_WIDTH;
  }
}


void draw_bitmap(BITMAP *bmp,int x,int y)
{
  int j;
  word screen_offset = (y<<8)+(y<<6)+x;
  word bitmap_offset = 0;

  for(j=0;j<bmp->height;j++)
  {
    memcpy(&buffer[screen_offset],&bmp->data[bitmap_offset],bmp->width);

    bitmap_offset+=bmp->width;
    screen_offset+=SCREEN_WIDTH;
  }
}


void kdrawrectfill(char *buffer,int x,int y,int w,int h,int col){
int i,j;
for (i=x;i<x+w;i++){
for (j=y;j<y+h;j++){
kputpixel(buffer,i,j,col);
}}                       }




/**************************************************************************
 *  draw_transparent_bitmap                                               *
 *    Draws a transparent bitmap.                                         *
 **************************************************************************/
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


void kdrawtransbitmap(char* buffer,int posx,int posy,int w,int h,int colc){
int x,y;
int col;
for (y=0;y<=h;y++){

for (x=0;x<=w;x++){

col=buffer2[x+y*(320)];
if (col)
buffer[x+posx+((y+posy)*320)]=col+colc;
}

}





}
void draw_transparent_bitmap(BITMAP *bmp,int x,int y)
{
  int i,j;
  word screen_offset = (y<<6)+(y<<8);
  word bitmap_offset = 0;
  word bitmap_temp_offset = 0;
  byte data;

  for(j=0;j<bmp->height;j++)
  {

    for(i=0;i<bmp->width;i++,bitmap_offset++)
    {

      data = bmp->data[bitmap_offset];
      if (data) buffer[screen_offset+x+i] = data;

    }

    screen_offset+=SCREEN_WIDTH;
  }
}

/**************************************************************************
 *  wait                                                                  *
 *    Wait for a specified number of clock ticks (18hz).                  *
 **************************************************************************/

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

void main()
{
  int k=1;
  double t;
  int i,x,y,x1,y1;
 byte u,f,o,l;
 byte u1=0,f1=0,o1=0,l1=0;
  double col[256];
  double col2=0;
  int ti=0;
 // BITMAP bmp;
  BITMAP bmp;
   BITMAP bmp2;

  buffer=(char*)malloc(64000U);
  buffer2=(char*)malloc(64000U);

   load_bmp("rocket.bmp",&bmp);

   load_bmp("map.bmp",&bmp2);

 /* open the file */

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */





//   memset(buffer2,0,64000);

  memset(buffer,0,64000);


       col2=1;
while (k==1){

ti++;

t=0;
for (i=0;i<256;i++){
  t+=0.05;
  col[i]=((cos(t)));
}

u=u1;
f=f1;

for (x=1;x<320;x++){
o=o1;
l=l1;


       for (y=1;y<200;y++){

kputpixel(buffer,x,y,(col[f]+col[u]+col[o]+col[l])+col2);



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

copy_bitmap(&bmp2);
kdrawrectfill(buffer2,50,50,40,40,0);

kdrawtransbitmap(buffer,0,0,320,200,0);


copy_bitmap(&bmp);



kdrawtransbitmap(buffer,100,100,50,59,0);
kputpixel(buffer,150,10,f1+o+l);



for (x=0;x<=320;x+=60){

//kdrawrectfill(buffer,x,0,20,200,0);

   }

for (y=0;y<200;y+=60){

//kdrawrectfill(buffer,0,y,320,20,0);

   }

//kdrawtransbitmap(buffer2,buffer,100,100,60,60,0);


  /* draw the background */
   memcpy(VGA,buffer,64000);

if (kbhit())

{k=0;  }


}

//  free(bmp.data);                     /* free up memory used */

  set_mode(TEXT_MODE);                /* set the video mode back to
					 text mode. */

  return;


}

