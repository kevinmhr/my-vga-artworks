

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

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;


  FILE *fp;

byte *VGA=(byte *)0xA0000000L;        /* this points to video memory. */
word *my_clock=(word *)0x0000046C;    /* this points to the 18.2hz system


					 clock. */
char led;
int stk=1;
int num2=0,num3=0,num4=0,num1=0;
int score=0;
char jpfire=0;
int  sintab[1100];
int costab[1100];
int  sintab2[1100];
int costab2[1100];
int wallheight[2000];
int x1,y1;
   char rotatedir;
   char movedir;
   double accel;
   double rotateforce;
 int playermovx,playermovy;

 double v;

 int viewang=0;
 int playerdirx,playerdiry;
int hl2[320];


char *buffer;
//double textw;
double z=0;
 char section=0;
char nextsec=0;
char bt=0;
char color,col1,col2;
int level=0;

 char collockx=1,collockx1=1,collocky=1,collocky1=1;
int mineanim=0;

int plus2=0;
char plusodd=0;
char map[1200];
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

void kputpixel(char *buffer,int x,int y,unsigned char col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);
int plus=0;
char sclv=0,sclh=0;
    char kt=0;
    double d2=0.04;
   char col[320];

 int tet=0;
 byte u,f,o,l;
 byte u1=0,f1=0,o1=0,l1=0;
 int ang=0;

double playerx=3;
double playery=2;

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
void kputpixel(char *buffer,int x,int y,unsigned char col){

if (y>=0&&y<=200&&x>=0&&x<=320) {
buffer[x+(y*320)]=col;
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

void clear_buffer(void)
{
	asm {
		push es
		mov al,20
		mov ah,20
		les di,buffer
		add di,32000
		db 66h
		mov cx,16250
		cld
		db 66h
		rep stosw
		pop es
		push es
		mov al,1
		mov ah,0
		les di,buffer
		
		mov cx,16250


		rep stosw
		pop es


 }
}


mapfill(int u,int t,int k,int o){
int i;  int n;      int l=0;
   u=0;   t=0;   k=0;  o=0; n=0;
 for (i=0;i<1200;i++){
  map[i]=2;
 t++; if (t>20){t=0;n++;}
 //      if (o>20){o=0;}

 u+=abs(sin(k)*3)+abs(sin(i)*2); k+=abs((cos(o*10)*50))+abs(sin(o*10))*50;

      if (t==20){map[i]=0;map[i-10]=2; }


	   if (t==1){map[i]=0;}
       if (n>15+o){n=0;o+=14;}


   if (n==o){map[i]=0;}

   if (n==15+o){map[i]=0;}
      if (n==12+o){map[i-1]=3;map[i+1]=3;}

   if (t==15){if (n==10){map[i]=0;       }   }
   if (t==14){if (n==10){map[i]=0;       }    }
   if (t==14){if (n==11){map[i]=0;       }    }
      if (t==15){if (n==5){map[i]=0;       }    }

//  if (k>5){map[i]=2;  k=0;   }

	 map[9]=0;

	  map[92]=5;
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
void main()
{

   int timing=0;
   double tt=0;
  int sprcol=0;
  double t=0;
  int i,j,x,y,x1,y1;
  double k;
  int ti=0;
  int si=0;

SetTimer();


    buffer=(byte*)malloc(64000U);


   load_bmp("rocket2.bmp",&bmp);
     load_bmp("font1.bmp",&font1);

   load_bmp("spr.bmp",&bmp2);
	t=0;

init:



//initpos();

mapfill(0,0,0,0);
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
d2=0.05;
v=0;
gh:
tt=0;

v=0;
k=0;
for (i=0;i<2000;i++){
k++;
wallheight[i]=2000/k;

}
for (i=0;i<1000;i+=1){
v+=0.01;
if (sin(v)!=0){
sintab[i]=(int)(sin(v)*128);
sintab2[i]=(int)(128/sin(v));

	       }
if (cos(v)!=0){

costab[i]=(int)(cos(v)*128);
costab2[i]=(int)(128/cos(v));
}

}
		   v=16;
		  for (k=0;k<320;k+=1){
		     v++;if (v>30){v=16;}
		     col[k]=v;           }

	  for (k=0;k<320;k+=2){

		hl2[k]=(((k)/(160)))*70;
	       //	hl[k]=(hl2[k])


      }

GlobalCounter=0;
timing=0;

ang=1;
while (stk==2){
  double walllenght=0;
 char sky;
 int wallhead,wallbuttom;
 int texy;
 int wallheight1;
 int wallheight2;
byte dotcol;
double walllenght2;
int  k;
 double texdist;
 int i=-10;
 int j;
 double wallx=0;
 int sc;
 char hit=0;
 int ticks=0;
 char checkx=0,checky=0;
 double tet2=0;
 double xoffset;
  double texstepy;
  int k2=0;
 double fov;
double sidedistx,sidedisty;
int deltadistx,deltadisty,rayx,rayy;
char side=0;
int z;
int stepx,stepy;

led++;
	 accy=0; accx=0;
      dotcol=0;
    x1=(word)k;






     k=0;

 fov=0.0035;
	v=0;

       col1=16;
if (ang>625){ang=0;}
if (ang<0){ang=625;}
clear_buffer();

	      collockx=1;
			collocky=1;
			collocky1=1;
			collockx1=1;


for (k=0;k<320;k+=2




      ){
	hit=0;



 checkx=(int)playerx;
 checky=(int)playery;

	   rayx=sintab[(int)(ang+hl2[k])];
	   rayy=costab[(int)(ang+hl2[k])];





		  //     deltadistx=sqrt(1+(raydiry*raydiry)/(raydirx*raydirx));

		  //     deltadisty=sqrt(1+(raydirx*raydirx)/(raydiry*raydiry));





	     if (rayx<0){   stepx=-1;
	     //	      deltadistx=-(1/raydirx);
				      deltadistx=-sintab2[(int)(ang+hl2[k])];

	     sidedistx=((playerx-checkx)*deltadistx);

	     }
		if (rayx>0){
		stepx=1;
	 //	 deltadistx=(1/raydirx);
					      deltadistx=sintab2[(int)(ang+hl2[k])];

	     sidedistx=((checkx+1-playerx)*deltadistx);
	     }


		if (rayy<0){   stepy=-1;
		//	      deltadisty=-(1/raydiry);
			deltadisty=-costab2[(int)(ang+hl2[k])];

	     sidedisty=((playery-checky)*deltadisty);

	     }

		if (rayy>0){
		  stepy=1;
	       //	  deltadisty=(1/raydiry);
		   deltadisty=costab2[(int)(ang+hl2[k])];


	     sidedisty=((checky+1-playery)*deltadisty);
	     }










//

while (hit==0){
   //
		    kdrawrectfill(buffer,(checkx*3)+5,(checky*3),1,1,4);

		  if( sidedistx<sidedisty)

		   {sidedistx+=deltadistx;
		   checkx+= stepx;

			  side=0;

		   }
		   else
		   { sidedisty+=deltadisty;
		   checky+= stepy;

		   side =1;


		   }




 if (map[((int)(checkx))+(((int)(checky*21)))]==0){hit=1;


	  if (side==0){
		  walllenght=(((sidedistx-deltadistx))*(sintab[hl2[k]+90]))*0.00008;//*cos(-0.5+hl[k]));

		 wallx=(playery+(rayy*(sidedistx-deltadistx)/16400));

	   }


		  if (side==1){


			  walllenght=(((sidedisty-(deltadisty)))*(sintab[hl2[k]+90])*0.00008);//*cos(-0.5+hl[k]));

			 wallx=(playerx+(rayx*(sidedisty-deltadisty)/16400));

       }


				if (walllenght<0.6){


				 //playerx-=playermovx*0.02; playery-=playermovy*0.02;
				if (playerdirx>0){collockx=0;}
				if (playerdirx<0){collockx1=0;}
				if (playerdiry>0){collocky=0;}
				if (playerdiry<0){collocky1=0;}
				}

			    col2=wallx*100;

		wallheight1=(int)(100-(((int)(150/walllenght))));
			   if (wallheight1<0){wallheight1=0;}
			   wallhead=(int)wallheight1;




       wallheight2=(int)(100+(((int)(150/walllenght))));
		    if (wallheight2>200){wallheight2=200;}
		    wallbuttom=(int)wallheight2;





				    texstepy=walllenght;


			       texdist=(wallheight1-100)*walllenght;










	    for (i=wallheight1;i<wallheight2;i+=1){
				    texdist+=texstepy;

				   texy=(int)(texdist);






		 if (checkx==4){
				     y1=k+(i*320);


		col1=(int)col2|(texy*5);
		 dotcol=(byte)col1;


 asm push es

asm les di,buffer
asm add di,y1

asm mov al,[dotcol]
//asm shr al,4
asm shr ah,3
asm stosw
asm pop es


    }


		 if (checkx!=4){
				     y1=k+(i*320);

     col1=(int)col2&(texy)&(checkx+checky)*20;


    dotcol=(byte)col1;


asm push es
asm les di,buffer
asm add di,y1

asm mov al,[dotcol]
asm stosw


asm les di,buffer
asm add di,y1
asm mov al,[dotcol]

asm add di,1


asm stosw







asm pop es


if (dotcol==140){
  asm push es
asm les di,buffer
asm add di,y1

asm mov al,[led]



asm stosw
asm pop es
		}


//     kputpixel(buffer,k,wallhead,col1);



  //	kputpixel(buffer,k+1,wallhead,col1);






}

	 }

	  }

}

}
















if (playery>16){section=45;plus=315;}
else{plus=0;section=0;}

 i=0;
 v=0;





 for (k=0;k<335;k++){

i++;   if (i>20){i=0;v+=3; }


	 //    kdrawrectfill(buffer,0,0,3,3,4);














  if (map[k+plus]==0){
//
	     kdrawrectfill(buffer,(i*3)+3,v+section,3,3,4);


  }







}






//  kdrawrectfill(buffer,(playerx*3)-57,(playery*3),2,2,1);


	accel-=0.005;
		if (accel<0){accel=0;}

		      //	GlobalSec=0;
			     ticks=0;
			     while (timing<GlobalCounter&&ticks<5){
				  timing+=5;
				  ticks++;

				   }

  if(KeyTable[K_LEFTARROW]){

			ang-=1*ticks;


  }
  if(KeyTable[K_RIGHTARROW]){

	       ang+=1*ticks;

  }

    if(KeyTable[K_DOWNARROW]){


		 accy+=0.01*ticks;
		  movedir=-1;



  }

    if(KeyTable[K_UPARROW]){


		 accy+=0.01*ticks;
		  movedir=1;


  }

    if(KeyTable[K_ESCAPE]){
   stk=0;
  }

				if (accel>0.015){accel=0.015;}

		     accel+=accy;
		    playerdirx=(int)(sintab[(ang)+73]);

		    playerdiry=(int)(costab[(ang)+73]);

			   playermovy=((int)playerdiry*(int)movedir*accel);
			   playermovx=((int)playerdirx*(int)movedir*accel);


			i=1;



			 if (map[((int)(playerx)+i)+(int)(playery)*21]==0){ collockx=0;
			   }

			 if (map[((int)(playerx)-i)+(int)(playery)*21]==0){ collockx1=0;
			      }


			 if (map[(int)(playerx)+(int)((playery)+i)*21]==0){ collocky=0;
			     }
			 if (map[(int)(playerx)+(int)((playery)-i)*21]==0){ collocky1=0;

			 ;     }

			   if (playermovx>0){
			   playerx+=playermovx*collockx*0.03;
					     }
			      if (playermovx<0){
			   playerx+=playermovx*collockx1*0.03;
			     }

			       if (playermovy>0){
			   playery+=playermovy*collocky*0.03;
					     }
			      if (playermovy<0){
			   playery+=playermovy*collocky1*0.03;
			     }


//
   blittext(50,150,"find yourself around   ",8,41,3);




	memcpy(VGA,buffer,64000);

 nosound();

}


while (stk==0){
RestoreKeyboard();

 return;       }


}

