

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <mem.h>
#include <conio.h>

#include <math.h>
#include "kbd.c"

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
int playerx,playery;
int playerh=0;
int raydir;
char *buffer;

char stk=1;
int sintab[2501];
int costab[2501];

int deltasintab[2501];
int deltacostab[2501];

int costab2[1025];
int wave=0;
char map[400];
//char maph[400];
int playermovx,playermovy;
char colidx0,colidx1,colidy0,colidy1;
char sc;
typedef struct tagBITMAP              /* the structure for a bitmap. */
{
  word width;
 word height;
  byte *data;
} BITMAP;
  BITMAP bmp;

void kputpixel(char *buffer,int x,int y,int col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);


void fskip(FILE *fp, int num_bytes)
{
   int i;
   for (i=0; i<num_bytes; i++)
      fgetc(fp);
}


void set_mode(byte mode)
{
  union REGS regs;

  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86(VIDEO_INT, &regs, &regs);
}

void bg_half(char col,char col2)
{
	asm {
		push di
		push es
		mov al,col2
		mov ah,col2
		les di,buffer
		add di,32000
	   //	db 66h
		mov cx,16250
		cld
	 //	db 66h
		rep stosw
		pop es
		pop di
		push es
		mov al,col
		mov ah,col
		les di,buffer

		mov cx,16250

		cld
		rep stosw
		pop es


 }
}


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
if (j>0){
kputpixel(buffer,i,j,col);    }

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

if (y<200){ if (x<=320){if (x>=0){if (y>0){
buffer[x+(y*320)]=col; }     }           }
	   }
}


void kdrawtransbitmap(BITMAP *b,int desx,int desy,int posx,int posy,int w,int h,int colc){
int x,y;
int col;

for (y=0;y<=h;y++){

for (x=0;x<=w;x++){

col=b->data[(x+desx)+((y+desy)*320)];
if (col)
if (y+posy>0){
buffer[x+posx+(((y+posy))*320)]=col+colc;  }
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



void makemap(){
double ang,ang2;
int x,y,i;
x=0;y=0;
for (i=0;i<400;i++){
map[i]=0;
}
for (i=0;i<400;i++){
x++; if(x>20){x=0;y++;}
if (x==0){map[i]=1;}
if (x==20){map[i]=1;}
if (y==1){map[i]=1;}
if (y==18 ){map[i]=1;}
if (x==5&&y==8){map[i]=1;}
if (x==6&&y==9){map[i]=1;}
if (x==5&&y==9){map[i]=1;}
if (x==5&&y==10){map[i]=1;}
//maph[i]=rand();

}
ang=0;

for (x=0;x<1024;x+=1){
ang+=0.003;
if(cos(ang-0.5)!=0){
costab2[x]=(64/(cos(ang-0.5)));
}

}

ang=0;
for (x=0;x<2500;x+=1){
ang+=0.003;

sintab[x]=(sin(ang))*256;


costab[x]=(cos(ang))*256;


}


ang=0;
for (x=0;x<2500;x+=1){
ang+=0.003;
if(sin(ang)!=0){
deltasintab[x]=64/sin(ang);

 }

if(cos(ang)!=0){
deltacostab[x]=64/cos(ang);

}

}


}

void ddaline(char * buffer,int x1,int y1,int x2,int y2,int col){
double x,y;
int n;
int deltax;
int deltay;
int step;

double instepx;
double instepy;

deltax=(x2-x1);
deltay=(y2-y1);

if (abs(deltax)>abs(deltay)){
step=abs(deltax);
}
if (abs(deltax)<abs(deltay)){
step=abs(deltay);
}

instepx=(deltax/(double)step);
instepy=(deltay/(double)step);
x=x1;
y=y1;
for (n=0;n<step;n++){
x+=instepx;
y+=instepy;
kputpixel(buffer,x,y,col);
}

}


void drawvlines(int x,int lenght1,int lenght2,int col,int playerh,char side){
int y;
int y1=lenght2<<6;
int colory=0;
int y2=0;
int y3=0;
int y4=1;


//for (y=sec*lenght1/10;y<lenght2;y++){
 for (y=lenght1;y<lenght2;y++){

//y3+=2;
y3+=1030;
if (y3>lenght2){y4+=32 ; y1+=1; y3=y3+((y-y1>>6)-lenght2<<6);col+=12;}

colory=col^y4+100;
if (side==1){colory=col&y4+1;   }
if (x>0&&x<320&&y>-100&&y<100){
kputpixel(buffer,x,y+playerh+100,240+(colory&0x003a));}

}


}
void floorcast(){
char colx,coly;
int x,y;
int i;
double flrstpx;
double flrstpy;


double flrx;
double flry;
double raydirf;

int planex=-sintab[raydir+160]*0.66;
int planey=costab[raydir+160]*0.66;
int fraydirx0=costab[raydir+160]-planex;
int fraydiry0=sintab[raydir+160]-planey;
int fraydirx1=costab[raydir+160]+planex;
int fraydiry1=sintab[raydir+160]+planey;
double flrdist;

for (y=100;y<200;y+=1){


if (y!=100){
flrdist=((160*0.5/0.66))/(y-100);
	    }

flrstpx=(flrdist*((fraydirx1)-(fraydirx0))/320);
flrstpy=(flrdist*((fraydiry1)-(fraydiry0))/320);


flrx=(playerx*5)+(flrdist)*(fraydirx0);
flry=(playery*5)+(flrdist)*(fraydiry0);


for (i=0;i<320;i+=1){

flrx+=flrstpx;

flry+=flrstpy;
colx=(char)(flrx)>>7&0x0016;
coly=(char)(flry)>>7&0x0020;

kputpixel(buffer,i,y,colx+coly);



}

}



}

void cast(){
int col;
int y,x,texx,texy,texycor;
int x2,y2;
int i,j;
int raydirx,raydiry;

int deltarayx,deltarayy;
int vertlenght2;
char seq=0;
int vertlenght;
int vertlenghtx=0;
int vertlenghty=0;
int side;
  //floor to be concluded <=====


for (i=1;i<320;i+=1) {
char hit=0;
int deltax;
int deltay;
int xstep;
int ystep;
int change;
int mapfrac=8;
int vertline1,vertline2;


int y1=playery;
int x1=playerx;


raydirx=sintab[raydir+i];
raydiry=costab[raydir+i];


if (raydirx>0){
deltarayx=deltasintab[raydir+i];
xstep=1;


}
if (raydirx<0){
xstep=-1;

deltarayx=-deltasintab[raydir+i];

}
if (raydiry>0){
ystep=1;

deltarayy=deltacostab[raydir+i];

}
if (raydiry<0){
ystep=-1;

deltarayy=-deltacostab[raydir+i];

}

vertlenghtx=deltarayx;
vertlenghty=deltarayy;
hit=0;
side=0;

while (hit!=1){
kputpixel(buffer,(x1>>3)+10,(y1>>3)+10,1);

if (vertlenghtx>vertlenghty){

vertlenght=vertlenghty;

vertlenghty+=deltarayy;
y1+=ystep;
side=1;


}
else {
side=0;
vertlenght=vertlenghtx;

vertlenghtx+=deltarayx;
x1+=xstep;


}


if (map[((x1)/mapfrac)+(((y1)/mapfrac)*21)]==1){
hit=1;

if (vertlenght<20){vertlenght=20;}
vertlenght2=((320*costab2[i])/(vertlenght>>2));

col=(x1+y1);

//vertlenght2=vertlenght2+(corraydirx-corraydiry)/64;
vertline1=-(vertlenght2);
vertline2=(vertlenght2);

if (vertline1<-400){ vertline1=-400;}
if (vertline2>400){ vertline2=400;}

//col=(((y1*4)*21)&0x000f)+((x1*4)&0x0007);

//drawvlines(i-1,vertline1,vertline2,col,maph[((x1)+(((y1)/mapfrac)*21)]/8,playerh,side);
drawvlines(i-1,vertline1,vertline2,col,playerh,side);


}



}

}

}


void main()
{
  int ang;
  int r=0;
  int x1,y1,x2,y2;
  double mapskew=0;
  char color;
  int tw=0;
  int tc=0;
  int vscrl;
  int pw,pc;

  int i,x,y;

    buffer=(char*)malloc(64000U);

r=0;
ang=0;



  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */




  memset(buffer,0,64000);


while (stk==1){


   if (kbhit())

{stk++;
 getch();  }





}


   if (stk>2){stk=0;   memset(buffer,0,64000);
 }

  SetKeyboard();


gh:

//initmap();


r=100;

color=0;
playerx=110;
playery=110;
makemap();


while (stk==2){

//  memset(buffer,0,32000);
bg_half(0,20);

x1=0;y1=0;
cast();
colidx0=1;
colidx1=1;
colidy0=1;
colidy1=1;
//    raydir+=0.01;
	 if (raydir>2120){raydir=30;}
	 if (raydir<30){raydir=2120;}

			 if (map[((playerx+10)/8)+(playery/8)*21]==1){ colidx0=0;
			   }

			 if (map[((playerx+15)/8)+(playery/8)*21]==1){ colidx1=0;
			      }


			 if (map[(playerx/8)+((playery+12)/8)*21]==1){ colidy0=0;
			     }
			 if (map[(playerx/8)+((playery+15)/8)*21]==1){ colidy1=0;

			 ;     }


colidx0=1;
colidx1=1;
colidy0=1;
colidy1=1;

     playermovx=sintab[raydir+160]/100;
     playermovy=costab[raydir+160]/100;
     if(KeyTable[K_LEFTARROW]){  raydir-=5;

    }
	if(KeyTable[K_RIGHTARROW]){ raydir+=5;

    }
	if(KeyTable[K_UPARROW]){
	playerx+=playermovx*colidx0; playery+=playermovy*colidy0;

    }
	if(KeyTable[K_DOWNARROW]){
		playerx-=playermovx*colidx1; playery-=playermovy*colidy1;


    }

	playerh-=1;
	if (playerh<0){playerh=0;}
	if(KeyTable[K_SPACE]){
				playerh+=10;
					  }
	if(KeyTable[K_ESCAPE]){

     stk=0;
    }




	     if (stk==0){return;}
 while (!(inportb(0x3DA)&0x08)){}
 while (inportb(0x3DA)&0x08){}

	memcpy(VGA,buffer,64000);




}




}

