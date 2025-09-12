//so far a jetpack shooter game yet to be ....
//coded by keyvan mehrbakhsh 2025..
//enjoy..


#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <mem.h>
#include <conio.h>
#include <time.h>

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
int num2=0,num3=0,num4=0,num1=0;
int score=0;
char jpfire=0;
char duckanim=0;
char *buffer;
char *buffer2;
char bt=0;
char goolanim=50;
int plusent=0;
int level=0;

int mineanim=0;
int plus2=0;
char plusodd=0;
char map[20000];

typedef struct tagENTITY              /* the structure for a bitmap. */

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
typedef struct tagBITMAP              /* the structure for a bitmap. */
{
  word width;
 word height;
  byte *data;
} BITMAP;
  BITMAP bmp;
   BITMAP bmp2;

void kputpixel(char *buffer,int x,int y,int col);
int kgetpixelpage(char *buffer,int x,int y);
int kgetpixelbmp(BITMAP *bmp,int x,int y);
int plus=0;
char sclv=0,sclh=0;
    char kt=0;
    double d2=0.04;
   double col[256];
  double col2=0;
 double tet=0;
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
if (y+posy>0){ if (posx+x<320){  if (y+posy<200){
col=b->data[(x+desx)+((y+desy)*320)];
if (col)

buffer[((x+posx))+(((y+posy))*320)]=col+colc;  }    }
	      }            }

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
mapfill(int u,int t,int k,int o){
int i;  int n;      int l=0;
   u=0;   t=0;   k=0;  o=0; n=0;
 for (i=0;i<20000;i++){
 o+=abs(sin(k+o)*4);;        if (o>1000){o=0;}
 t+=abs(sin(k+t+o)*4);       if (k>60){k=0;}
 ;

n++;
l++;
 u+=abs(sin(k)*3)+abs(sin(i)*2); k+=(abs(sin(k)))+abs((cos(o)*20));
   if (i>1000&&i<18000){

 if (u>1){map[i]=1;   }


  if (u>40){map[i]=4;  u=0;    }

  if (t>800){map[i]=3;  t=0;    }
    if (n>78){map[i]=32;  n=0;  }
  if (k>74){map[i]=2;     }
	    if (k>77){map[i]=31; }

		 if (k>200){k=0;}
      if (t>790){map[i]=50;  }
	 if (l>2000){map[i]=34;l=0; }

  };

     if (i<1006||i>18000){
	  map[i]=59;
		   }


 }


     }

void initpos(){
  int i;
  for (i=0;i<50;i++){
bullet.posx[i]=-30;
  bullet.posy[i]=-50;
  bullet.diry[i]=2;
    plane.posy[i]=1;

  bullet.dirx[i]=2;
//  cre.dirx[i]=1;
//    cre.diry[i]=1;
//  cre.posxacc[i]=0;
// cre.posx[i]=0;


// cre.posy[i]=0;
	       }







}
void main()
{
  time_t timer;
   double tt=0;

  int sprcol=0;
  double t=0;
  long timer1;
  long timer2;
  int i,x,y,x1,y1;
  double k;
  int ti=0;
  int si=0;
 // BITMAP bmp;

    buffer=(char*)malloc(64000U);
  buffer2=(char*)malloc(64000U);


   load_bmp("rocket2.bmp",&bmp);

   load_bmp("map.bmp",&bmp2);
	t=0;

init:



initpos();

mapfill(0,0,0,0);
 /* open the file */

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */





//   memset(buffer2,0,64000);

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

plasma(1,0);

kdrawtransbitmap(&bmp2,0,0,0,0,320,200,0);


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


   if (kbhit())

{stk++;
 getch();  }





}


   if (stk>2){stk=0;   memset(buffer,0,64000);
 }
d2=0.05;

gh:
tt=0;
timer1=0;
while (stk==2){

 int k;
 int i=-10;
 double collisionx,collisiony;
  int colx,colx2;
 int v;

 int sc;
 double tet2=0;



timer2=350000;

//tt+=0.01;
timer1+=1;
if (timer1>=timer2){
timer1=0;
  memset(buffer,0,64000);
    memset(buffer2,0,64000);

tt=0;


//kputpixel(buffer,(int)timer1,0,4);




		 // cre.posxacc[plusent]=sin(tet);


 si++; if (si>3

 ){si=0;  nosound();    }


  //		  }


 i=-1;

//if (plus<9000&&plus>8000){ plasma(5,0); }
v=0;







  sclv-=0.1 ;
  if(sclv<1


 ){sclv=10
 ;
    duckanim+=20; if (duckanim>20){duckanim=0;}
     jpfire+=10; if (jpfire>10){jpfire=0;}

 ;   if (mineanim>=36){mineanim=0;} mineanim+=9;
  plus+=21 ;
  plus2++; if (plus2>1000){plus2=0; sprcol+=50;}
   }

 for (k=0;k<670;k++){

i++;   if (i>20){i=0;v+=10; }
if (v>350){v=0;}

// i++; if (i>20){i=0;v+=10;}

if ((v+sclv)<350){

	if (map[k+plus]==32){

	   if ((v+sclv)>0){
	       kdrawtransbitmap(&bmp,160,60,(v+sclv),145,20,40,0);

		 }
			  }

	       if (map[k+plus]==50){

	   if ((v+sclv)>0){
	       kdrawtransbitmap(&bmp,200,50,(v+sclv),100,30,120,i*10);
		 }
			  }


if (map[k+plus]==4){
kdrawrectfill(buffer,((v+(sclv))*2),i*10,2,2,1);  }





// if (v>200){v=0;}
if (map[k+plus]==59
){
kdrawrectfill(buffer,v+(sclv),i*10,3,3,9);
}




if (map[k+plus]==0
){
kdrawrectfill(buffer,v+(sclv),i*10,1,1,20);  }

}

}


i=0;
v=0;
for (k=0;k<400;k++){
i++;   if (i>20){i=0;v+=10;}

      if (map[k+plus]==2){

kdrawtransbitmap(&bmp,55+mineanim,49,(((v)+sclv)*3),(i)*10,10,10,sprcol+10);

kdrawrectfill(buffer2,((v+sclv)*3)-2,(i*10)-2,14,14,77);


//kputpixel(buffer,playerx+19,playery,45);
colx=kgetpixelpage(buffer2,bulletx,bullety);

if (colx==77&&bullettrig==1){map[k+plus]=0;bullettrig=0; score+=1; colx=0;colx2=2; sound(1000); goto gh;}

colx=kgetpixelpage(buffer2,playerx+19,playery+5);
if (colx==77){plus=0;sprcol=0;  sound(100);mapfill(0,0,0,0); stk=1;goto init;}

  }
}
i=0;
v=-10;


for (k=0;k<650;k++){
i++;   if (i>20){i=0;v+=10;}
	   if ((v+sclv)*3>0){


		if (map[k+plus]==34){
	       kdrawtransbitmap(&bmp,192+duckanim,13,(v+sclv)*3,(i*10),20,15,0);
	       kdrawrectfill(buffer2,(v+sclv)*3,(i*10),30,10,111);


	       }  }

}
i=0;
v=-10;


for (k=0;k<650;k++){
i++;   if (i>20){i=0;v+=10;}


		   if ((v)>330){v=-10;  }

	       if ((v+sclv)<320){

		if (map[k+plus]==31){  tet-=0.24;
			 if (tet<0){tet=0;}
		       if (((v)*2)<0){plane.posy[i]=0;   }

		   if (((v+sclv)*3)<250){
		     if (((v+sclv)*3)>50){     tet+=0.3;  	 if (tet>1.5){tet=1.5;}

		   if (i*10<100){
		   plane.posy[i]+=tet;   }

			   if (i*10>100){


		   plane.posy[i]-=tet;   }



		    }    }

	   if ((v+sclv)*3>0){


	       kdrawtransbitmap(&bmp,170,35,(v+sclv)*3,plane.posy[i]+(i*10),30,15,0);
	       kdrawrectfill(buffer2,((v+sclv)*3)-2,plane.posy[i]+(i*10)-2,32,18,84);

	  colx=kgetpixelpage(buffer2,bulletx,bullety);

       if (colx==84&&bullettrig==1){map[k+plus]=0;bullettrig=0; score+=1; colx=0;colx2=2; sound(500); colx=0;}
	  colx=kgetpixelpage(buffer2,playerx+19,playery+5);
	  if (colx==84){plus=0;sprcol=0;  sound(100);mapfill(0,0,0,0); stk=1;goto init;}

		 }}}












}



kdrawrectfill(buffer,0,190,320,20,0);

kdrawtransbitmap(&bmp,63,16,playerx,playery,35,30,0);

//kdrawrectfill(buffer2,playerx,playery,35,30,0);

	     if (plus>19000){plus=0; level+=1; if (level>1){level=0;} mapfill(0,0,0,0);initpos();}
	  if (playerx>280){playerx=280;}
	  if (playerx<10){playerx=10;}
	  if (playery>165){playery=165;}
	  if (playery<10){playery=10;}
	 if(accx>0){   accx-=0.004;  }
	 if(accx<0){   accx+=0.004;  }
	 if(accy>0){   accy-=0.004;  }
	 if(accy<0){   accy+=0.004;  }

	  playerx+=accx;
	  playery+=accy;

	  if (accx>1){accx=1;}
	  if (accy>1){accy=1;}
	  if (accx<-1){accx=-1;}
	  if (accy<-1){accy=-1;}

    if (bullettrig==1){ti++;   sound(800);

      kdrawrectfill(buffer,bulletx,bullety,3,3,70);
    bulletx+=10;



    }
      bt++;if (bt>1){bt=0;
     nosound();             }
    // if (ti>5){sound(-1);ti=0;}

    if (bulletx>320){
    bullettrig=0;

    }
    if (bullettrig==0){
    bulletx=playerx+30;
    bullety=playery+7;
    }
    if (kbhit()) {
       sc=getch();
      if (sc==27){ stk=0; }
      switch(sc) {
		case 0x48 :   accy-=0.5; kdrawtransbitmap(&bmp,32+jpfire,165,playerx+10,playery+15,10,14,1);
				sound(100); nosound();
		break;
		case 0x4b:    accx-=0.5;  kdrawtransbitmap(&bmp,32+jpfire,165,playerx+10,playery+15,10,14,1);
				sound(100); nosound();
		break;
		case 0x50:    accy+=0.5;  
		break;
		case 0x4d:    accx+=0.5;  kdrawtransbitmap(&bmp,32+jpfire,165,playerx+10,playery+15,10,14,1);
				sound(100); nosound();
		break;
	       case 32:    bullettrig=1;
		break;

	}	  }
	memcpy(VGA,buffer,64000);


}

}


while (stk==0){
 nosound();
 return;       }


}

