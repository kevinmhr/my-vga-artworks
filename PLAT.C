

  //raycaster....
//coded by keyvan mehrbakhsh 2025..
//enjoy..


#include <stdio.h>
#include <stdlib.h>

#include <dos.h>
#include <time.h>



#include "kbd.c"
#include "TIMER.c"


#include <math.h>
#define VIDEO_INT           0x10      /* the BIOS video interrupt. */
#define SET_MODE            0x00      /* BIOS func to set the video mode. */
#define VGA_256_COLOR_MODE  0x13      /* use to set 256-color mode. */
#define TEXT_MODE           0x03      /* use to set 80x25 text mode. */

#define SCREEN_WIDTH        320       /* width in pixels of mode 0x13 */
#define SCREEN_HEIGHT       200       /* height in pixels of mode 0x13 */
#define NUM_COLORS          256       /* number of colors in mode 0x13 */
#define PICKUP1       60       /* number of colors in mode 0x13 */
#define LOCKSW       63
#define DOOR         50
#define SPECWALL     3
#define BGTILE     70

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;


  FILE *fp;

byte *VGA=(byte *)0xA0000000L;        /* this points to video memory. */
word *my_clock=(word *)0x0000046C;    /* this points to the 18.2hz system


					 clock. */
   int playerx,playery;
   int playerxtemp,playerytemp;
   double v,u;
   char changed=0;
   char hdir=1;
   char footx;
   char stepstime=0;
   char steps=0;
   char hit=0;
   char hitdur;
  char si,ti;
  int hitth=0;
  int sprcol=0;
  int i,j,x,y,x1,y1;
  double t;
  int k;
  int sounddur;
  char corx,cory;
  char jump=0;
  char lock=0;
  char jumpth1=0;
  char move=0;

char opaquecol=60;
char led;
char pickupcol=0;
int score=0;
char jpfire=0;
int  sintab[640];
int  sintab2[640];
int  sintab3[640];

int costab[1100];
//int  sintab2[1100];
//int costab2[1100];
   char rotatedir;
   char movedir;
char *buffer;
char *buffer2;

 char section=0;
char nextsec=0;
char bt=0;
char color,col1,col2;
int level=0;

 char collockx=1,collockx1=1,collocky=1,collocky1=1;
int mineanim=0;

int plus2=0;
char plusodd=0;
char map[15000];
char mapbuffer[1600];

/*
typedef struct tagENTITY

{
int posxacc[50];
int posyacc[50];
double posx[50];
 double posy[50];
int dirx[50];
int diry[50];

} ENT;
ENT plane;
//ENT cre;

ENT bullet;
*/
typedef struct tagBITMAP              /* the structure for a bitmap. */
{
  word width;
 word height;
  byte *data;
} BITMAP;
  BITMAP bmp;
   BITMAP bmp2;
    BITMAP font1;

void kputpixel(char *buffer,int x,int y,char col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);
int plus=0;
char sclv=0,sclh=0;
    char kt=0;
   unsigned int col[320];

 byte f,o,l;
 byte u1=0,f1=0,o1=0,l1=0;
 int ang=0;

int playerx=3;
int playery=2;

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
if (j>0){
if (j<200){
if (i<320){

 kputpixel(buffer,i,j,col);    }  }   }

}}                       }

void kvline(char *buffer,int i,int y,int h,int col){
int j;

for (j=y;j<y+h;j+=1){
kputpixel(buffer,i,j,col);    }     }



void khline(char *buffer,int x,int y,int w,int col){
int i;

for (i=x;i<x+w;i+=1){
kputpixel(buffer,i-1,y,col);    }     }




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
void kputpixel(char *buffer,int x,int y,char col){
int y1=x+(y*320);
int color=col;

if (y>=0&&y<=200&&x>=0&&x<=320) {
//asm push si
asm push es

asm les di,buffer
asm add di,y1



asm mov ax,[color]

//asm shr al,4

asm stosw
asm pop es
//asm pop si




//buffer[x+(y*320)]=col;
   }

}


void kdrawtransbitmap(BITMAP *b,int desx,int desy,int posx,int posy,int w,int h,int colc){
int x,y;
int col;

for (y=0;y<=h;y++){

for (x=0;x<=w;x++){
if (y+posy>0){ if (posx+x<320){  if (y+posy<200){
col=b->data[(x+desx)+((y+desy)*320)];
if (col)

buffer[((x+posx))+(((y+posy))*320)]=col+colc;  }    }
	      }            }

}





}

void blittext(int textplacex,int textplacey,char* tex,int fontsize,int textlenght,int ink){

int col;
int coly;
int integ=0;
//enemii.y=0;
//enemii.x=0;
//char* tex=" this is a game of ball and other things";
int o=0;
int i,j;
int k=1;

int warpy;



for (i=0;i<textlenght;i++){
//    warpy+=0.001;


//integ=*(fontsize);


/*
if (fontsize>10){
slow2++;
rectfill(surface,(i*(fontsize))+textplacex,textplacey,(i*(fontsize))+textplacex+fontsize,textplacey+fontsize+4,slow2);

masked_blit(font1,surface,1+(double)((integ)*(13.182)),75,(i*(fontsize))+textplacex,textplacey,fontsize,fontsize+4);
    if (inv==1){   masked_blit(font1,surface,(double)((integ)*(13.18)),53,(i*(fontsize))+textplacex,textplacey,fontsize,fontsize+3);

   }
    }

if (fontsize==8){
masked_blit(font1,surface,(integ)*(7),0,(i*(fontsize))+textplacex,textplacey,fontsize,fontsize);
    }

 */
      int integ=(((int)tex[i]))-90;

     int x=0;
     int y=0;
     int y1;
     for (j=0;j<fontsize*(fontsize+fontsize/2);j++){




      x++; if (x>fontsize){x=0;y++;}

    coly=y;

   if (fontsize>=10){

   col=kgetpixelbmp(&font1,1+(double)((integ)*(13.182))+x,y+74);


       if (col==255){


      col=col;

     kputpixel(buffer,(i*fontsize)+x+textplacex,textplacey+(coly),col);     }

		 }


   y1=y;
   if ((integ*7)<x){y1=y+20;}
  if (fontsize<=10){
   col=kgetpixelbmp(&font1,(integ*7)+x-2,y1+5);
   if (col==255){
   kputpixel(buffer,(i*fontsize)+x+textplacex,textplacey+y,ink);

	       }


















	      }  }

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

void clear_buffer(char col,int lenght)
{
	asm {
		push es
		mov al,[col]

		mov ah,[col]
		les di,buffer
		mov cx,[lenght]
		rep stosw
		pop es


 }
}
pickupfill(int u){
 int t=0;int n=0; int i;
 for (i=0;i<10000;i++){

 t++; if (t>319){t=0;n++;}
       if (t>105&&t<115&&n==8){map[i]=u;}

       if (t>100&&t<120&&n==12){map[i]=u;}


		  }

}

void makeblocks(int charwidth,int charheight,int charoffsetx,int charoffsety,int textureposition,int top,int bottom)
{
int i,t,n;
t=0;n=0;
 for (i=0;i<15000;i++){
//  map[i]=0;

 t++; if (t>319){t=0;n++;}
		    if (n>=charoffsety&&n<=charoffsety+charheight&&t>=charoffsetx&&t<=charoffsetx+charwidth){


		       map[i]=textureposition+1;
	          if (top==1){
	       if (n>charoffsety) { map[i]=textureposition+11;       }

	       if (t==charoffsetx){map[i]=textureposition+10;}
	       if (t==charoffsetx+charwidth){map[i]=textureposition+12;}




	       if (n==charoffsety) {

	       if (t==charoffsetx){map[i]=textureposition;}

	       if (t==charoffsetx+charwidth){map[i]=textureposition+2;}
			   }
			   }
	       if (bottom==1){
		  if (n==charoffsety+charheight) {
		       map[i]=textureposition+21;
	       if (t==charoffsetx){map[i]=textureposition+20;}

	       if (t==charoffsetx+charwidth){map[i]=textureposition+22;}
			   }
			   }





		      }




}

}
void mapfill(int u,int t,int k,int o){
int i;  int n;      int l=0;
   u=0;   t=0;   k=0;  o=0; n=0;
 for (i=0;i<15000;i++){
  map[i]=0;

 t++; if (t>319){t=0;n++;}
    //   if (o>20){o=0;}
         if (n>0&&n<39&&t<320){   map[i]=BGTILE; }

      if (n==1){map[i-319]=2;}
       if (t==80&&n<15){map[i]=2;}
	       if (t==80&&n>14&&n<20){map[i]=DOOR;}

	   if (t==160&&n<15){map[i]=2;}
      //	  if (n==20){map[i]=2;}

   //   if (t==319){map[i]=2;}

	   if (t==1){map[i]=2;}
  //     if (n>15+o){n=0;o+=14;}
	 if (t==60&&n==5){map[i]=LOCKSW;}


  if (t>105&&t<115&&n==10){map[i]=1;}



       if (t>100&&t<120&&n==14){map[i]=1;}
       if (t>105&&t<115&&n==8){map[i]=PICKUP1;}

       if (t>100&&t<120&&n==12){map[i]=PICKUP1;}


	       if (t>55&&t<65&&n==10){map[i]=1;}
		       if (t>65&&t<75&&n<5){map[i]=SPECWALL;}

       if (t>50&&t<70&&n==14){map[i]=1;}
   if (n==40){map[i]=3;}

//   if (n==15+o){map[i]=0;}
//      if (n==12+o){map[i-1]=3;map[i+1]=3;}

//   if (t==15){if (n==10){map[i]=0;       }   }
//   if (t==14){if (n==10){map[i]=0;       }    }
//   if (t==14){if (n==11){map[i]=0;       }    }
//      if (t==15){if (n==5){map[i]=0;       }    }

//  if (k>5){map[i]=2;  k=0;   }

//	 map[9]=0;

  //	  map[92]=5;
 }


     }

void initpos(){
  int i;
  for (i=0;i<50;i++){
//bullet.posx[i]=-30;
//  bullet.posy[i]=-50;
//  bullet.diry[i]=2;
 //   plane.posy[i]=1;

//  bullet.dirx[i]=2;
//  cre.dirx[i]=1;
//    cre.diry[i]=1;
//  cre.posxacc[i]=0;
// cre.posx[i]=0;


// cre.posy[i]=0;
	       }







}


tiledrawtrans(){
int i=0;
int j=0;
int k;
int y1,x1;

  //     u=0;f=0;l=0;o=0;
	    for (k=0;k<612;k+=1){

	    i+=10; if(i>330){
	    i=0;j+=10;
	    }





	  if (mapbuffer[k]!=BGTILE){
		       y1=0;
					       if (mapbuffer[k]>=20){
				    y1=10;}
					       if (mapbuffer[k]>=30){
				    y1=20;}
					       if (mapbuffer[k]>=40){
				    y1=30;}
					       if (mapbuffer[k]>=50){
				    y1=40;}
					       if (mapbuffer[k]>=60){
				    y1=50;}
					       if (mapbuffer[k]>=70){
				    y1=60;}



	   x1=(char)(mapbuffer[k]-(int)(mapbuffer[k]/10)*10);



      for (x=0;x<10;x+=1){


       for (y=0;y<10;y+=1){
	opaquecol=26;



	      if (mapbuffer[k]==DOOR&&lock==-1){
	       opaquecol=70;
	       sprcol=buffer2[((x+(x1*10))+((y+y1+1)*320))]+opaquecol;

	      }
	      if (mapbuffer[k]==LOCKSW&&lock==-1){
	       opaquecol=70;
	       sprcol=buffer2[((x+(x1*10))+((y+y1+1)*320))]+opaquecol;

	      }
		   if (mapbuffer[k]==PICKUP1&&lock==-1){
	       opaquecol=70+pickupcol;
	       sprcol=buffer2[((x+(x1*10))+((y+y1+1)*320))]+opaquecol;

	      }
		sprcol=buffer2[((x+(x1*10))+(((y)+y1+1)*320))]+opaquecol;

     if (j<200&&(y+j-10-cory+5)>1&&sprcol!=26&&sprcol!=70&&sprcol!=70+pickupcol){

		  if (x+sintab2[i]<12){sprcol=sprcol+3;}


kputpixel(buffer,x+i-10-corx,y+j-10-cory+5,sprcol);


	       }
		     }

 }
 }
 } }

tiledrawsolid(){
int i=0;
int j=0;
int k;
int y1,x1;

  //     u=0;f=0;l=0;o=0;
	    for (k=0;k<612;k+=1){

	    i+=10; if(i>330){
	    i=0;j+=10;
	    }





	  if (mapbuffer[k]==BGTILE){
		       y1=0;
					       if (mapbuffer[k]>=20){
				    y1=10;}
					       if (mapbuffer[k]>=30){
				    y1=20;}
					       if (mapbuffer[k]>=40){
				    y1=30;}
					       if (mapbuffer[k]>=50){
				    y1=40;}
					       if (mapbuffer[k]>=60){
				    y1=50;}
					       if (mapbuffer[k]>=70){
				    y1=60;}



	   x1=(char)(mapbuffer[k]-(int)(mapbuffer[k]/10)*10);




//      for (x=0;x<10;x+=1){


       for (y=0;y<10;y+=1){
	opaquecol=26;


	    //  sprcol=x+y*320;
//     sprcol=mapbuffer[k];
     if (j<180){
	if( ((i-corx-10)>0)&&(i-corx-10)<330&&(y+j-cory-10)>0){
memcpy(buffer+(i-corx-10)+((y+j-cory-10)*320),buffer2+(x1*10)+(320*(y1+y)),10);
			   }


			   }
		     }


 }


}
}



void main()
{
    char stk=1;
    int ticks=0;
    int delay;
    buffer=(byte*)malloc(64000U);
      buffer2=(byte*)malloc(64000U);

   load_bmp("rocket2.bmp",&bmp);
     load_bmp("font1.bmp",&font1);

   load_bmp("sprites.bmp",&bmp2);

init:

SetTimer();

//initpos();

mapfill(0,0,0,0);
makeblocks(2,4,1,18,23,1,1);
makeblocks(2,3,1,13,20,1,1);
makeblocks(2,3,1,8,20,1,1);
makeblocks(2,3,45,26,23,1,1);
makeblocks(2,3,100,26,23,1,1);


makeblocks(300,0,0,30,12,0,0);
makeblocks(300,0,70,19,12,0,0);

for (x=0;x<5;x++){

makeblocks(4,x,x*4+20,29-x,10,0,0);

makeblocks(4,x,x*3+50,29-x,30,0,0);



}
 /* open the file */

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */

SetKeyboard();




//   memset(buffer2,0,64000);

//
  memset(buffer,0,64000);
t=0;
for (i=0;i<256;i++){
  t+=0.05;
  col[i]=((cos(t)));
}

si=100;

       col2=1;

while (stk==1){
nosound();
ti++; if (si<120){  sound(si*ti*2);  }
if (ti>1){ti=0;si++;if (si>=120){si=120; } }


//plasma(1,0);

//kdrawtransbitmap(&bmp2,0,0,0,0,320,200,0);


kdrawtransbitmap(&bmp,0,9,100,100,50,55,0);
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

  if(KeyTable[K_SPACE]){
  stk++;

  }

/*
   if (kbhit())

{

 getch();

   }

  */



}


   if (stk>2){stk=0;   memset(buffer,0,64000);
 }
v=0;
gh:
//tt=0;


for (i=0;i<320;i+=1){
v+=0.05;
if (sin(v)!=0){
sintab[i]=(int)(sin(v))*200;
//sintab2[i]=(int)(128/sin(v));

	       }
if (cos(v)!=0){

costab[i]=(int)(cos(v)*128);
//costab2[i]=(int)(128/cos(v));
}

}
		   v=0;
for (x=0;x<320;x++){
for (y=0;y<200;y++){

if(kgetpixelbmp(&bmp2,x,y)!=26){;
buffer2[x+(y*320)]=kgetpixelbmp(&bmp2,x,y);


				}

}}
playerxtemp=140;
playerytemp=50;

GlobalCounter=0;
GlobalSec=0;
t=0;
plus=0;
ang=1; corx=0;cory=0;
		  x=plus;
v=0;  u=0;
for (i=0;i<350;i+=1){
v+=0.019;
u+=0.01;
sintab[i]=-sin(v)*10;
sintab2[i]=sin(u)*15;

		    }
u=0;
for (i=0;i<12;i+=1){
u+=0.5;
sintab3[i]=sin(u-1)*5;

}				      y=0;
			  for (i=0;i<630;i++){
			  x++; if (x>33+plus){x=plus;y+=320;}
			  mapbuffer[i]=map[x+y];
			  }

	  hitdur=100;
	  hitth=0;
	  lock=1;
	  jump=1;
	   jumpth1=70;
while (stk==2){
 char sky;
 int texy;
byte dotcol;

int texrow;
int  k;
 int i;
 int changetimer;
 int mappos;
 int j;
 int sc;
 char x1,y1,y2;

  int k2=0;
char side=0;
int z;
move=0;





   //	    ticks=2;



clear_buffer(0,32000);
			     ticks=0;
//timing
		      while (GlobalSec<GlobalCounter){
				  GlobalSec+=7 ;
				  ticks+=1;
				       }
                           //       ticks=2;


tiledrawsolid();

tiledrawtrans();

 playerx=playerxtemp-10;
 playery=playerytemp-20;


for (y=0;y<10;y++){
for (x=-sintab3[y];x<12+sintab3[y];x++){
	sprcol=7;
	if (x+sintab3[y]<3||x-sintab3[y]>8||sintab3[y]<0){sprcol=1;}
	if (y>7){
	sprcol=1;
	}
	if (y<3){
	sprcol=34;
	}

    kputpixel(buffer,x+playerx-1,y+playery-15,sprcol);


	sprcol=0;


	 if (hdir==1){
	      kputpixel(buffer,playerx+7,playery-10,sprcol);
		    }
	 if (hdir==0){
	       kputpixel(buffer,playerx+1,playery-10,sprcol);
}

}
}


for (x=0;x<2;x++){
 footx=x;
for (y=0;y<7;y++){
	sprcol=8;
       footx+=steps*2;
      kputpixel(buffer,playerx+x+footx+5,y+playery,sprcol);

}
}
for (y=0;y<15;y++){
for (x=sintab3[y];x<13-sintab3[y];x++){
//for (x=0;x<13;x++){

	//    y1=(x+playerx-10)+(y+playery-5)*320;
	sprcol=1;
		if (x+sintab[y]<3||x-sintab[y]>8){sprcol=4;}

	       kputpixel(buffer,x+playerx-1,y+playery-5,sprcol);


}
}
       if(KeyTable[K_SPACE]==0){
	      // hit=0;
		hitth=0;

	       }

	     hitdur--;
if (hitdur<0){ hit=0;hitdur=100; }
			nosound();
if(KeyTable[K_SPACE]&&hit==0){

if (hitth<100){hit=1;hitth++; sound(500);}


		   }


if (hit==1){
hitth=100;
for (x=0;x<10;x++){
for (y=0;y<2;y++){
	sprcol=8;

	     if(hdir==1&&changed==0){

			 kputpixel(buffer,x+playerx+15,y+playery,sprcol);
		  if (mapbuffer[(int)(((playerx+25+corx-ticks)/10))+(int)((((y+playery-5)/10)))*34]==LOCKSW){  sound(1000);
 //		  map[plus+(int)(((playerx+x)/10)+2)+(int)((((y+playery)/10)))*320]==5;
	     //	  map[plus+(int)(((playerx-corx-ticks)/10)+3)+(int)(((playery+y-5)/10))*320]=40;
		  pickupfill(PICKUP1);
		  changed=1;
		   lock=-lock;
		   pickupcol++;


		   hit=0;
		  }
	    /*
		  if (mapbuffer[(int)(((playerx+15-corx-ticks)/10))+(int)((((y+playery-5)/10)))*33]==40){  sound(1000);
		  map[plus+(int)(((playerx-corx-ticks)/10)+3)+(int)(((playery+y-5)/10))*320]=LOCKSW;     }
		  changed=1;
		  lock=-lock;
	      */
	 }

		     if(hdir==0){
			 kputpixel(buffer,x+playerx-10,y+playery,sprcol);


	 }


}
}

}
//legs
for (x=0;x<2;x++){
 footx=x;
for (y=0;y<10;y++){
	sprcol=1;
       footx+=steps;
      kputpixel(buffer,playerx+x+footx+5,y+playery+10,sprcol);


      kputpixel(buffer,playerx-x-footx+5,y+playery+10,sprcol);

	sprcol=0;
//	    kputpixel(buffer,playerx+5,y+playery+10,sprcol);


}
}
//hands
for (x=0;x<2;x++){
 footx=x;
for (y=0;y<7;y++){
	sprcol=8;
       footx+=steps*2;
 //     kputpixel(buffer,playerx+x+footx+5,y+playery,sprcol);


      kputpixel(buffer,playerx-x-footx+5,y+playery,sprcol);

	sprcol=0;
//	    kputpixel(buffer,playerx+5,y+playery+10,sprcol);


}
}







		  if (collocky==1){

					    playerytemp+=ticks;

			    if (playerytemp>160){playerytemp=160;
			    cory+=ticks; if (cory>10){cory=1;
			      plus+=320;
			  x=plus-1;	  y=0;
			  for (i=0;i<612;i++){
			  mapbuffer[i]=2;
			  x++; if (x>33+plus){x=plus;y+=320;}
			  mapbuffer[i]=map[x+y];


					       }     }


					  }
					   }





	   collockx=1;
	   collockx1=1;
	   collocky=1;
	   collocky1=1;
	//collision detection
	  //    ticks=(int)ticks;
	  for (y=0;y<10;y++){
	  mappos=(unsigned int)(((playerxtemp+corx)/10)-2)+(unsigned int)(((playerytemp+y+cory-ticks)/10))*34;
//	  kputpixel(buffer,playerx-11,playery+y,4);
	  if (mapbuffer[mappos]!=0&&mapbuffer[mappos]<60){collockx1=0; }

	  if (mapbuffer[mappos]==DOOR&&lock==-1){collockx1=1;}
	  mappos=(unsigned int)(((playerxtemp+corx)/10)-1)+(unsigned int)(((playerytemp+y+cory-ticks)/10))*34;


	  if (mapbuffer[mappos]==PICKUP1&&changed==0){map[plus+(unsigned int)(((playerxtemp)/10)-1)+(unsigned int)(((playerytemp+y+cory-ticks)/10))*320]=BGTILE;
		     sounddur++;
	    if (sounddur<500){

	    sound(sounddur*10);         }



	   changed=1;}

	  mappos=(unsigned int)(((playerxtemp+corx-ticks)/10)+1)+(unsigned int)(((playerytemp+y+cory-ticks)/10))*34;
	  if (mapbuffer[mappos]!=0&&mapbuffer[mappos]<60){collockx=0;}
	  if (mapbuffer[mappos]==DOOR&&lock==-1){collockx=1;}
	  mappos=(unsigned int)(((playerxtemp+corx)/10)+1)+(unsigned int)(((playerytemp+y+cory-ticks)/10))*34;

	  if (mapbuffer[mappos]==PICKUP1&&changed==0){map[plus+(int)(((playerxtemp)/10)+1)+(int)(((playerytemp+y+cory-ticks)/10))*320]=BGTILE;
	     sounddur++;
	    if (sounddur<500){

	    sound(sounddur*10);         }

	    changed=1; }
	    }
		  for (x=0;x<10;x++){
	   mappos=(unsigned int)(((playerxtemp+x+corx)/10)-1)+(unsigned int)((((playerytemp+cory)/10)+1)*34);

	  if (mapbuffer[mappos]!=0&&mapbuffer[mappos]<60){collocky=0;

	  }

		  if (mapbuffer[mappos]==DOOR){collocky=1;}

	   mappos=( unsigned int)(((playerxtemp+x+corx)/10)-1)+(unsigned int)(((playerytemp+cory)/10)-2)*34;
	  if (mapbuffer[mappos]!=0&&mapbuffer[mappos]<60){collocky1=0;
	  jumpth1=100;

	  }


	  }


       //	   mappos=(int)(((playerx-corx+11)/10))+(int)(((playery+y-cory)/10))*33;
      //	  if (mapbuffer[mappos]==10&&lock==-1){collockx=1;}
      //	  mappos=(int)(((playerx-corx-11)/10))+(int)(((playery+y-cory)/10))*33;
     //	  if (mapbuffer[mappos]==10&&lock==-1){collockx1=1;}

       //downpulling

	    if (sounddur>500){sounddur=0;}

if(KeyTable[K_LEFTARROW]){
	       hdir=0;   changed=0;
		 if (collockx1==1){
		 playerxtemp-=ticks;
			       stepstime+=ticks;
		       if (stepstime>5){stepstime=0;

		 steps+=1;    }
		 if (steps>1){steps=0;}


		       }
		       if (playerxtemp<145){playerxtemp=145;
		       corx=corx-ticks;

		      if(corx<1){corx=10;plus-=1;
			  x=plus-1;
				      y=0;
			  for (i=0;i<612;i++){

			  x++; if (x>33+plus){x=plus;y+=320;}
			  mapbuffer[i]=map[x+y];
			  }     }                 }



  }



 if(KeyTable[K_RIGHTARROW]){
		       changed=0;
		       if (ticks>0){
		       stepstime+=ticks;
		       if (stepstime>5){stepstime=0;
		       steps+=1;                     }
		       if (steps>1){steps=0;}
				    }
			   hdir=1;
		       if (collockx==1){
		       playerxtemp+=ticks;

		       if (playerxtemp>180){  playerxtemp=180;
		       corx+=ticks;

			  }
			  if(corx>10){corx=1;


			  plus+=1;

			  x=plus-1;
				      y=0;
			  for (i=0;i<612;i++){

			  x++; if (x>33+plus){x=plus;y+=320;}
			  mapbuffer[i]=map[x+y];
			  }

			   }   }





  }

if(KeyTable[K_LEFTARROW]==0){
if(KeyTable[K_RIGHTARROW]==0){  steps=0;
					}}

/*
    if(KeyTable[K_DOWNARROW]){
				      x=plus;
				      y=0;
			  for (i=0;i<600;i++){
			  mapbuffer[i]=2;
			  x++; if (x>32+plus){x=plus;y+=320;}
			  mapbuffer[i]=map[x+y];
			  }
			  if (collocky==1){
			  playery++;       }
			  if (playery>120){playery=120;
			  cory=(cory+1*ticks);         }
				  if(cory>5){cory=0;plus+=320;}

		  movedir=-1;



  }

  */
       if(KeyTable[K_UPARROW]==0&&collocky==0){jump=0;  }

    if(KeyTable[K_UPARROW]){



		       //	  cory=(cory-1);
		//      if (collocky==0){jump=1;}

		      if (jump==0&&collocky!=1){
		     jump=1;  jumpth1=0;    }


  }
       if (jumpth1<70&&collocky1!=0){

	playerytemp-=collocky1*(int)(ticks*2);
		       if (playerytemp<50){
		       cory-=ticks; if (cory<1){cory=10;
			  plus-=320;
				     x=plus-1;
				      y=0;
			  for (i=0;i<612;i++){

			  x++; if (x>33+plus){x=plus;y+=320;}
			  mapbuffer[i]=map[x+y];
			  }

				   } }







	   jumpth1+=ticks;

		  }

    //	if (jumpth1>30){   jump=0; }











    if(KeyTable[K_ESCAPE]){
   stk=0;
  }






//
   blittext(50,190,"find yourself around",8,20,3);

    //	clear_buffer(7,1600);
	kdrawrectfill(buffer,0,-5,10,200,0);

	kdrawrectfill(buffer,0,170,320,10,0);

 while (!(inportb(0x3DA)&0x08));
// while (inportb(0x3DA)&0x08);

 memcpy(VGA,buffer,64000);

 nosound();

}


while (stk==0){
RestoreKeyboard();

 return;       }


}

