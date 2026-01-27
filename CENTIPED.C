

  //centipede....
//coded by keyvan mehrbakhsh 2026..
//enjoy..


#include <stdio.h>
#include <stdlib.h>

#include <dos.h>
#include <time.h>



#include "kbd.c"
//#include "TIMER.c"
#include "imfplay.c"


#include <math.h>
#define VIDEO_INT           0x10      /* the BIOS video interrupt. */
#define SET_MODE            0x00      /* BIOS func to set the video mode. */
#define VGA_256_COLOR_MODE  0x13      /* use to set 256-color mode. */
#define TEXT_MODE           0x03      /* use to set 80x25 text mode. */

#define SCREEN_WIDTH        320       /* width in pixels of mode 0x13 */
#define SCREEN_HEIGHT       200       /* height in pixels of mode 0x13 */
#define NUM_COLORS          256       /* number of colors in mode 0x13 */
#define PICKUP1       60       /* number of colors in mode 0x13 */
#define LOCKSW       250
#define DOOR         200
#define SPECWALL     3
#define BGTILE     70
#define BGTILE2     10
#define MAXLENGHT   700
#define MAXOBSTICLES 50
typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;


  FILE *fp;

byte *VGA=(byte *)0xA0000000L;        /* this points to video memory. */
word *my_clock=(word *)0x0000046C;    /* this points to the 18.2hz system


					 clock. */
       char stk=1;
   char scr[10];
   int playerx,playery;
   int playerxtemp,playerytemp;
   double v,u;
   char changed=0;
   char hdir=1;
   int advalue,advalue2;

   char stepstime=0;
   int stepstime2=0;
   int bullettimer=0;
   int bullettrig;
   int score;
   int vertical=0;
   char steps=0;
   char hit=0;
  int ticks;
  int si,ti;
  int sprcol=0;
  int i,j,x,y,x1,y1;
  int t;
  int k;
  int bulletx,bullety;
  int lenght=MAXOBSTICLES;
  int sounddur=0;
  char jump=0;
//  int lock[155];

char opaquecol=60;
char pickupcol=0;
int respawn=1;
//har jpfire=0;
int  sintab[640];
int  sintab2[640];
int  sintab3[640];
int  sintab4[640];
   char rotatedir;
   char movedir;
char *buffer;
char color,col1,col2;
int level=0;
int sqrx,sqry;
int sqrdirx=1,sqrdiry=1;

int anim;
int snakemapbuffer[3000];
unsigned char * snakemap;

 int snakeblkpos[MAXLENGHT];
int snkbs=0;
int snklnght=0;
int snkdirx[MAXLENGHT],snkdiry[MAXLENGHT];
int snkby[MAXLENGHT];
char initbtrig=0;
int eattimer=0;
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
if (j>=0){
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
char color=col;

if (y>=0&&y<=200&&x>=0&&x<=320) {
//asm push si
asm push es

asm les di,buffer
asm add di,y1



asm mov al,[color]

//asm shr al,4

asm stosb
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

void blittext(int textplacex,int textplacey,char* tex,int ink){
int textlenght;
int col;
int x2=0,y2=0;
int coly;
int integ=0;
int o=0;
int i,j;
int k=1;
int size=1;
int warpy;
i=0;
while (i<255){i++;

if ((int)(tex[i])==59){
textlenght=i; i=255;

}
}
   size=5;
for (i=0;i<textlenght;i++){
int integ=(((int)tex[i]))-90;

     int x=0;
     int y=0;
     int y1;
	size=2;
     for (k=0;k<50;k++){

	   x++ ;if (x>8){x=0;y++;
	   }





    coly=y;
   y1=y;

   if ((integ*7)<40){y1=y+20;}

   col=kgetpixelbmp(&font1,(integ*7)+x-2,y1+5);
   if (col==255){
   for (x1=0;x1<size;x1++){
      for (y1=0;y1<size;y1++){

   kputpixel(buffer,(i*(8+size))+(x*size)+textplacex+(x1),textplacey+(y*size)+(y1),ink);
			   }  }

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


void keyboard(){

if(KeyTable[K_LEFTARROW]){
     playerx--;	       hdir=0;   changed=0;       // snkdirx=2;    snkdiry=0;

  }



 if(KeyTable[K_RIGHTARROW]){
		       playerx++;
		       changed=0;   //   snkdirx=1;      snkdiry=0;

  }
if (playerx<0){playerx=320;}
if (playerx>320){playerx=0;}

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
     if(KeyTable[K_DOWNARROW]){
		 //     snkdiry=1;

		  //     snkdirx=0;
		     }

	    if(KeyTable[K_SPACE]==0&&bullety==1000){
		  bullettrig=0; nosound();
     }

  if(KeyTable[K_SPACE]&&bullettrig==0){ bullettrig=1;
   bullettimer=100;bulletx=playerx;    bullety=180;
	 sound(bullety*10);

	}

//  bullety--;
 // if (bullety<0){bullety=150;}
  for (x=0;x<2;x++){
    for (y=0;y<2;y++){

  kputpixel(buffer,bulletx+x,bullety+y,59);
		  }  }
  if (bullettimer>0){
  bullettimer--;
  bullety-=10;



  }

       if (bullety<0){bullety=-1;bullettrig=0;}

    if(KeyTable[K_ESCAPE]){
   stk=0;
  }


 }



void centipede2(){


//ADLIB_SendOutput(advalue , advalue2);

//ADLIB_Reset();
  //	sprintf(scr,"%d;", playerx);

    //	blittext(20,20,scr,1);

for (y=0;y<2800;y+=65){


snakemap[-1+y]=8;

//snakemap[64+y]=8;



}


		    stepstime++; if (stepstime>2){stepstime=0;


	      for (snklnght=MAXOBSTICLES;snklnght>0;snklnght--){


if (snkdirx[snklnght]==1){


       if(snakeblkpos[snklnght]!=-1){

snakeblkpos[snklnght]+=1;  


	   }


snakemap[snakeblkpos[snklnght]-1]=0;

if(snakemap[snakeblkpos[snklnght]-1]==8){snakemap[snakeblkpos[snklnght]-1]=8;}



if (snakemap[snakeblkpos[snklnght]+1]==8||snakemap[snakeblkpos[snklnght]+1]==9){
      if(snakeblkpos[snklnght]<2400){

   snakeblkpos[snklnght]+=65;
			       }
   if(snakeblkpos[snklnght]>2400){
   snakeblkpos[snklnght]-=65;}

  // snakemap[snakeblkpos[snklnght]-32]=0;

snkdirx[snklnght]=-1;
vertical+=1;

}






}

if (snkdirx[snklnght]==-1){





       if(snakeblkpos[snklnght]!=-1){


snakeblkpos[snklnght]-=1;
}
if(snakemap[snakeblkpos[snklnght]+1]!=8){
snakemap[snakeblkpos[snklnght]+1]=0;     }

if (snakemap[snakeblkpos[snklnght]-1]==8||snakemap[snakeblkpos[snklnght]-1]==9){
snkdirx[snklnght]=1;
      if(snakeblkpos[snklnght]<2400){
   if (initbtrig==0){initbtrig=1;}
   snakeblkpos[snklnght]+=66;
			       }
   if(snakeblkpos[snklnght]>2400){
   snakeblkpos[snklnght]-=66;}

//snakeblkpos[snklnght]+=66;

//snakemap[snakeblkpos[snklnght]-34]=0;


vertical+=28;


}




}








     if( snakeblkpos[snklnght]>2800){ snakeblkpos[snklnght]=1;snkdirx[snklnght]=1;}

if (snakeblkpos[snklnght]!=0){

if(snkdirx[snklnght]==1){
snakemap[snakeblkpos[snklnght]]=1;}
if(snkdirx[snklnght]==-1){
snakemap[snakeblkpos[snklnght]]=2;}


}




if (initbtrig==1){

snkbs=snklnght;
if(snakemap[snkby[snkbs]]!=8){

snakemap[snkby[snkbs]]=0;
		    }
if(snkby[snkbs]>1&&snkby[snkbs]<2800){
snkby[snkbs]+=65;   }


    for (y=0;y<3;y++){
    for (x=0;x<3;x++){



    if ((x+bulletx/5)+(int)(y+bullety/5)*65==snkby[snkbs]){
		       snakemap[snkby[snkbs]-65]=52;

		       snkby[snkbs]=snakeblkpos[snkbs]+65;;


		      }   }}

if(snakemap[snkby[snkbs]]==9){

snakemap[snkby[snkbs]-65]=51;

snkby[snkbs]=snakeblkpos[snkbs]+65;

			      }

if(snakemap[snkby[snkbs]]!=8){

snakemap[snkby[snkbs]]=50;
}

if(snkby[snkbs]>2800){snkby[snkbs]=snakeblkpos[snkbs]+65;
}

for (x=0;x<15;x++){
if (snakemap[((playerx+x)/5)+(int)(65)*37]==50){

stk=1;   }

}
}



}





}


			      for (snklnght=MAXOBSTICLES;snklnght>0;snklnght--){


		     for (y=0;y<3;y++){




if (snakemap[(bulletx/5)+(int)((y+bullety/5))*65]==50){
	      snakemap[(bulletx/5)+(int)((y+bullety/5))*65]=0;


}

if (snakemap[(bulletx/5)+(int)((y+bullety/5))*65]==9&&bullety!=-1){snakemap[(bulletx/5)+(int)(y+bullety/5)*65]=0;
				 bullety=-1; bulletx=playerx;


	    }

      if (((bulletx/5)+(int)((y+bullety/5))*65)==snakeblkpos[snklnght]&&bullety!=-1){
		  score++;
	      //	 snakein[snklnght]=0;
		  snakeblkpos[snklnght]=-1;
	      snakemap[(bulletx/5)+(int)((y+bullety/5))*65]=0;
	      //	 snkdirx[snklnght]=0;
			 bullety=-1;
			 bulletx=playerx;
				     y=3;
			     lenght-=1;
					 if (lenght<2){initlevel();     }

			    sound(500);


		  }

}





}






}
void drawsnake(){
int i=0,j=0;
		    if (sqrdirx==1){
sqrx+=1;

if (sqrx>=5){ sqrdirx=2; }

  }
if (sqrdirx==2){
sqry+=1;
if (sqry>=5){ sqrdirx=3; }


 }
 if (sqrdirx==3){
sqrx-=1;
if (sqrx<0){ sqrdirx=4; }


 }
 if (sqrdirx==4){
sqry-=1;
if (sqry<0){ sqrdirx=1; }


 }







for (k=1;k<3000;k++){


i+=5; if(i>320){i=0;j+=5;}
if (snakemap[k]==50){
for (x=0;x<2;x++){
kputpixel(buffer,i+2+x,j+2,11);  }

}
if (snakemap[k]==51){
for (x=0;x<2;x++){
kputpixel(buffer,i+2+x,j+2,20);
}
}

if (snakemap[k]==52){
for (x=0;x<2;x++){
kputpixel(buffer,i+2+x,j+2,1);}

}

if (snakemap[k]==1||snakemap[k]==2){


for (y=0;y<5;y++){

for (x=0;x<5;x++){

kputpixel(buffer,x+i,y+j,4);


if (x==0&&y==0||x==0&&y==4||x==4&&y==4||x==4&&y==0){


kputpixel(buffer,x+i,y+j,0);
}


if (y==2&&x==2){
kputpixel(buffer,x+i,y+j,14);


}


//kputpixel(buffer,x+i,y+j,snakemap[k]+3);

if (snakemap[k]==1){

kputpixel(buffer,i+sqrx,j+sqry,9);
kputpixel(buffer,i+sqrx+1,j+sqry,9);
kputpixel(buffer,i+sqrx,j+sqry+1,9);
kputpixel(buffer,i+sqrx+1,j+sqry+1,9);

}
if (snakemap[k]==2){

kputpixel(buffer,i+sqrx,j-sqry+4,9);
kputpixel(buffer,i+sqrx+1,j-sqry+4,9);
kputpixel(buffer,i+sqrx,j-sqry+1+4,9);
kputpixel(buffer,i+sqrx+1,j-sqry+1+4,9);

}





	  }



}
}

if (snakemap[k]==9){


for (y=0;y<5;y++){

for (x=0;x<5;x++){

//for (y=-5;y<5;y++){
//for (x=-5;x<5;x++){

kputpixel(buffer,x+i,y+j,snakemap[k]);


if (x==1||x==3||y==1||y==3){

kputpixel(buffer,x+i,y+j,1);



}
if (x==0&&y==0||x==0&&y==4||x==4&&y==4||x==4&&y==0){

//kputpixel(buffer,x+i,y+j,0);



}





}



}


}





}




}









/*

void snakeblocksarg(){


stepstime++; if (stepstime>5-(lenght/20)){stepstime=0;


if (snkdirx==1){


if (snakemap[snkposx+1+(snkposy*33)]==7){  sound(500); lenght++;respawn=1;pickupcol++;
 score++;
 }
//if (snakemap[snkposx+1+(snkposy*33)]==1){  sound(1000); stk=1; }

     snkposx+=1;



 }

if (snkdirx==2){


if (snakemap[snkposx-1+(snkposy*33)]==7){  sound(500); lenght++; respawn=1;pickupcol++;
 score++;
}

//if (snakemap[snkposx-1+(snkposy*33)]==1){  sound(1000); stk=1; }
if (snakemap[snkposx-1+(snkposy*33)]==3){  sound(1000); stk=1; }

     snkposx-=1;




     }

if (snkdiry==1){



if (snakemap[snkposx+(snkposy*33)+33]==7){  sound(500); lenght++;respawn=1;pickupcol++;
 score++; }
//if (snakemap[snkposx+(snkposy*33)+33]==1){  sound(1000); stk=1; }
if (snakemap[snkposx+(snkposy*33)+33]==3){  sound(1000); stk=1; }

     snkposy+=1;





     }

if (snkdiry==2){


if (snakemap[snkposx+(snkposy*33)-33]==7){  sound(500);lenght++; respawn=1;pickupcol++;
 score++;}
//if (snakemap[snkposx+(snkposy*33)-33]==1){  sound(1000); stk=1; }
if (snakemap[snkposx+(snkposy*33)-33]==3){  sound(1000); stk=1; }
     snkposy-=1;



 }


   if (snkposy>15){snkposy=1;}
   if (snkposy<1){snkposy=15;}
   if (snkposx>30){snkposx=0;}
   if (snkposx<0){snkposx=30;}

   snklnght+=1;


      if (snklnght>=maxlenghtv){


      snklnght=0;

     }


snakeblkpos[snklnght]=snkposx+(snkposy*33);


if ((snklnght+maxlenghtv-lenght)>=0&&(snklnght+maxlenghtv-lenght)<=maxlenghtv){

snakemap[snakeblkpos[snklnght+maxlenghtv-lenght]]=0;                  }



			      for (y=0;y<3;y++){
 if (snakemap[(int)(bulletx/10)+((y+bullety/10)*33)]==1){

snakemap[(int)(bulletx/10)+((y+bullety/10)*33)]=0;

snklnght--;
					  y=3;
	      score++;          lenght-=1;
sound(2000);



		   }                               }

    if ((snklnght-lenght)>=0&&(snklnght-lenght)<maxlenghtv){
snakemap[snakeblkpos[snklnght-lenght]]=0;


	       }



snakemap[snakeblkpos[snklnght]]=1;




}









eattimer+=20;
if (eattimer>=500){




 if (eatsx<50){

   snkdirx=2;}    if (eatsx>50){   snkdirx=1;}   snkdiry=0;}

if (eattimer>=1000){
		eatsx=rand()%100;


 eattimer=0;	  snkdirx=0; if (eatsx<50){   snkdiry=1;}  if (eatsx>50){   snkdiry=2;}  }

//if (eattimer>1500){ 	  snkdirx=2;snkdiry=0;}

//if (eattimer>2000){  	  snkdirx=0;snkdiry=2; eattimer=0;



	 //    if (snkdirx==1&&snkdiry==0){snkdiry=1;snkdirx=0;eattimer=0;}
	 //    if (snkdirx==0&&snkdiry==1){snkdirx=0;snkdiry=0;eattimer=0;}

















}
*/

int initlevel(){
double shape;
int random;
srand(100);
shape=(rand()%100);
initbtrig=0;
obsticleshapes(shape);

lenght=MAXOBSTICLES;
i=1;

for (snklnght=0;snklnght<MAXLENGHT;snklnght++){
 snakeblkpos[snklnght]=0;

      }
for (snklnght=0;snklnght<MAXOBSTICLES;snklnght++){

		  i++;
snakeblkpos[snklnght]=i;
snkdirx[snklnght]=1;
//snakeerspos[snklnght]=1;

//snkposy[snklnght]=0;
snkby[snklnght]=2801;
//snkdiry[snklnght]=0;

 }
i=-1; j=-1;
srand(100);
for (k=0;k<3000;k++){
i++; if (i>64){i=0; j++;}
snakemap[k]=0;

random=rand()%50;
if (random<3&&j<35&&j>1){
snakemap[k]=9;  }





}


  }



drawplayer(){
 int x1=0;
 int x2,y2;
   x=0;   y=0;

for (y=0;y<15;y++){
for (x=-y;x<=y;x++){

		    col1=1;


x1=x/1.5;

			if (x==-y||x==y||y==14){col1=8;}
kputpixel(buffer,playerx+x1,playery+y+180,col1);



}}





}
int obsticleshapes(double shape){
for (i=0;i<10;i+=1){
u+=shape;
if ((sin(u-1)*10)!=0){;
sintab3[i]=(sin(u-1)*5)+(cos(u-1)*5); }

}
}

void main()
{
    int delay;
    buffer=(byte*)malloc(64000U);

   load_bmp("rocket2.bmp",&bmp);
     load_bmp("font1.bmp",&font1);

   load_bmp("sprites.bmp",&bmp2);
     snakemap=(unsigned char*)malloc(3000U);

//SetTimer();
//initpos();

 /* open the file */
//ADLIB_Detect();
//IMF_LoadSong("shooter.imf");
//ISR_Start(100);
//IMF_PlaySong((char*)*snakemap,3000);

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */

SetKeyboard();
bullettrig=0;

init:

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




kdrawtransbitmap(&bmp,0,9,100,100,50,55,0);
kputpixel(buffer,150,10,f1+o+l);


   memcpy(VGA,buffer,64000);


  if(KeyTable[K_SPACE]){
  stk++;

  }



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

	       }
}

t=0;
plus=0;
ang=1; 
		  x=plus;
v=0;  u=0;
for (i=0;i<350;i+=1){
v+=0.019;
u+=0.01;
sintab[i]=-sin(v)*10;
sintab2[i]=sin(u)*15;

		    }
u=0;
for (i=0;i<10;i+=1){
u+=0.5;
if ((sin(u-1)*10)!=0){;
sintab3[i]=(sin(u-1)*5)+(cos(u-1)*10); }

}
for (i=0;i<640;i+=1){
u+=0.2;
if (sin(u)!=0){
sintab4[i]=(sin(u)*7);

 }

}

initlevel();


pickupcol=1;
bullettrig=0;
vertical=0;
playerx=160;
lenght=MAXOBSTICLES;
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


clear_buffer(0,32000);




   if (pickupcol>10){pickupcol=1;}

  keyboard();
// snakeblocksarg();
	  //  blittext(10,170,"abcdefghijklmnopqrstuvwxyz1234567890;",3);
	centipede2();
	    drawsnake();
	drawplayer();

	kdrawrectfill(buffer,0,0,320,1,7);
	kdrawrectfill(buffer,0,199,320,1,7);
	kdrawrectfill(buffer,0,0,1,200,7);
	kdrawrectfill(buffer,319,0,11,200,7);

	sprintf(scr,"%d;", score);

	blittext(20,5,"score:;",1);

	blittext(100,5,scr,3);




//

    //	clear_buffer(7,1600);
//	kdrawrectfill(buffer,0,-5,10,200,0);

		    //  verticaltime=0;
			ticks=2;

 nosound();
   while (!(inportb(0x3DA)&0x08)){}

// while (inportb(0x3DA)&0x08){ }
 
 memcpy(VGA,buffer,64000);


}


while (stk==0){
RestoreKeyboard();
//ADLIB_Reset();
 return;       }

score=0;
initlevel();
respawn=1;
goto init;
}

