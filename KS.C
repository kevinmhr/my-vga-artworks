

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
char *buffer2;
int plusent=0;
int score=0;;
char shapetype=1;
int plus2=0;
 double ki=0;
int horbloc=0;
int num1,num2,num3,num4;
int hits;
char spd=0;
char sum=0;
char kbr=1;
char kbl=1;
char plusodd=0;
unsigned char map[200];
unsigned char map3[200];
char map2[200];
char bgmap[222];
char shpt=1;
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
  BITMAP font;
//   BITMAP bmp2;
char shape11[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape21[]={0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape22[]={0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,1,1,1,1,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};

char shape31[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,1,0,0,0,0,0,0,0,0,
	       0,1,1,0,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape32[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,1,1,0,0,0,0,0,0,0,0,
	       0,0,1,1,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape41[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,1,1,1,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape42[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,1,0,0,0,0,0,0,0,0,
	       0,0,1,0,0,0,0,0,0,0,0,
	       0,1,1,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape43[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,1,1,1,0,0,0,0,0,0,0,
	       0,0,0,1,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape44[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,1,1,0,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape45[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,1,1,1,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape46[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,1,0,0,0,0,0,0,0,0,0,
	       0,1,1,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape47[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0,
	       0,0,0,1,0,0,0,0,0,0,0,
	       0,1,1,1,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};
char shape48[]={  0,0,0,0,0,0,0,0,0,0,0,
	       0,1,1,0,0,0,0,0,0,0,0,
	       0,0,1,0,0,0,0,0,0,0,0,
	       0,0,1,0,0,0,0,0,0,0,0,
	       0,0,0,0,0,0,0,0,0,0,0};


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
int su=0,so=0;
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
void blitnumtex(int hits,int textplacex,int textplacey,int digit){
      int coly;
      int d;
      int col;
      int numdig=4;
	int x=0;
      int y=0;
     int i=0;
      int j=0;
    int fontsize=8;
       double  integ[10];

      if (score>=9){score=0;num2++;};

      if (num2>9){num2=0;num3++;};
      if (num3>9){num3=0;num4++;};
      if (num4>9){num4=1;};

      integ[1]=(hits)*6.9+180;

      integ[2]=((num2))*6.9+180;
      integ[3]=((num3))*6.9+180;
      integ[4]=((num4))*6.9+180;

     for (j=0;j<fontsize*(fontsize+fontsize/2);j++){
      x++; if (x>fontsize){x=0;y++;}
      coly=y;

	for (d=1;d<digit+1;d++){
   col=kgetpixelbmp(&font,(integ[d])+x,y+2);

       if (col==255){
      col=col;
     kputpixel(buffer,((i*fontsize)+((x-d*6))+textplacex+40),textplacey+coly,9);
    }
    }        }
}



void singlenum(int hits,int textplacex,int textplacey,int color){
      int coly;
      int d;
      int col;
      int numdig=4;
	int x=0;
      int y=0;
     int i=0;
      int j=0;
    int fontsize=8;
       double  integ;

      if (score>=9){score=0;num2++;};

      if (num2>9){num2=0;num3++;};
      if (num3>9){num3=0;num4++;};
      if (num4>9){num4=1;};

      integ=(hits)*6.9+180;


     for (j=0;j<fontsize*(fontsize+fontsize/2);j++){
      x++; if (x>fontsize){x=0;y++;}
      coly=y;


   col=kgetpixelbmp(&font,integ+x,y+2);

       if (col==255){
      col=col;
     kputpixel(buffer,((i*fontsize)+((x-d*6))+textplacex+40),textplacey+coly,color);
    }
    }
}


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


void kblittranspage(char *b,int desx,int desy,int posx,int posy,int w,int h,int colc){
int x,y;
int col;
for (y=0;y<=h;y++){

for (x=0;x<=w;x++){

col=b[(x+desx)+((y+desy)*320)];
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
int k;
int ti;
int x,y;
u=u1;
f=f1;

for (x=1;x<320;x+=intr){
o=o1;
l=l1;


       for (y=1;y<200;y+=intr){
k=(int)(col[f]+col[u]+col[o]+col[l])&(int)colc;
kputpixel(buffer,x,y,k);


o+=3;
l+=2;

 }
u+=3;
f+=2;

 }
 l1+=20;
 o1+=20;
 u1+=5;
 f1+=5;
   }

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

void dragshapes(){
int k;
int x,y,i,j;

 for (k=0;k<20;k++){
 x++; if (x>20){y++;x=0;}

 map[x]=0;
//  shapetype=1;


 for (i=0;i<50;i+=11){
  for (j=0;j<3;j++){

 map[(i+j)-9]=shape11[((i)+j)];

 map3[(i+j)-9]=shape21[((i)+j)];
 if (shapetype==3){
 map[(i+j)-9]=shape22[((i)+j)]; }

 if (shapetype==4){
 map[(i+j)-9]=shape31[((i)+j)]; }
 if (shapetype==5){
 map[(i+j)-9]=shape32[((i)+j)]; }
 if (shapetype==6){
 map[(i+j)-9]=shape41[((i)+j)]; }
 if (shapetype==7){
 map[(i+j)-9]=shape42[((i)+j)]; }
  if (shapetype==8){
 map[(i+j)-9]=shape43[((i)+j)]; }
  if (shapetype==9){
 map[(i+j)-9]=shape44[((i)+j)]; }
    if (shapetype==10){
 map[(i+j)-9]=shape45[((i)+j)]; }
      if (shapetype==11){
 map[(i+j)-9]=shape46[((i)+j)]; }
      if (shapetype==12){
 map[(i+j)-9]=shape47[((i)+j)]; }
      if (shapetype==13){
 map[(i+j)-9]=shape48[((i)+j)]; }

   }}
 }                }
void reshape(){
int i,j;
if (shapetype==1){
     for (j=0;j<5;j++){
     yf: ki+=0.1;      shape11[j+33]=1; 	   shape21[j+33]=abs(sin(ki)*1000);  if (shape21[j+33]>9||shape21[j+33]<1){shape21[j+33]=0; goto yf;}

    }             }
if (shapetype==1){
     for (j=11;j<44;j+=11){
     yf2: ki+=0.1;      shape11[j+1+11]=1; 	   shape21[j+1+11]=abs(sin(ki)*1000);  if (shape21[j+1+11]>9||shape21[j+1+11]<1){shape21[j+1+11]=0; goto yf2;}
    }             }
		 }

void main()
{


  int sprcol=0;
  double t;
  int i,x,y,x1,y1;
  int j;
  double k;
  int vertical;
  int ti=0;
  int si=0;
  int yi=0;
 // BITMAP bmp;
  int xpos;int ypos;
    buffer=(char*)malloc(64000U);
 buffer2=(char*)malloc(64000U);


   load_bmp("fonts.bmp",&font);

 //  load_bmp("map.bmp",&bmp2);
t=0;


//sound(-1);
  for (i=0;i<1000;i++){

  cre.dirx[plusent]=1;
    cre.diry[plusent]=1;
  cre.posxacc[i]=0;
 cre.posx[i]=-320;

 cre.posy[i]=-200;
	       }

//mapfill(0,0,0,0);

 /* open the file */

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */





//   memset(buffer2,0,64000);
for (k=0;k<222;k+=1){
bgmap[k]=0;

}
for (k=0;k<222;k+=11){
bgmap[k+1]=5;

bgmap[k-1]=4;

}

t=0;
for (i=0;i<256;i++){
  t+=0.05;
  col[i]=((cos(t))+10);
}

init:

stk=1;
while (stk==1){



 memset(buffer,0,64000);

blitnumtex(score,120,120,4);
   memcpy(VGA,buffer,64000);

 if (kbhit()){
 for (k=0;k<185;k++){
 map2[k]=0;map[k]=0;score=0;
so=0; shapetype=1; num1=0;num2=0;num3=0;num4=0; plus+=11;

}
stk++; getch();


}



	     }

       col2=1;
 memset(buffer2,0,64000);

dragshapes();
//plus=33;
while (stk==2){
 memset(buffer,0,64000);
     yi+=1;   if (yi>100){yi=0;}
si+=1;
sound(-1);



f+=1;

u2=(sin(f2)*0.03);
l2=(cos(o2)*0.03);
f2+=sin(1)*0.003;
o2+=sin(1)*0.003;

xpos=1;
ypos=1;

//xpos=(sin(l2)*2)+(cos(l2)*2);
//ypos=-(sin(l2)*2)+(cos(l2)*2);

for (y=10;y<180;y+=2){


//kdrawrectfill(buffer,x,0,20,200,0);


//o+=1;
//l+=1;

//o=((int)((sin(y))*l1)|(int)((cos(y))*l1));;
l3=y+((sin(y*((l2)))*10*(num3+1)))+((cos(y*((u2)))*10*(num3+1)));

for (x=30;x<290;x+=2){
o3=x+((cos(x*((u2)))*10*(num3+1)))+((sin(x*((l2)))*10*(num3+1)));

ti=(x|o3);



//if (o>6){o=4;}
//if (l>6){l=4;}
kputpixel(buffer2,x,y,((l3|o3)&(int)20)+10);
k=(o3+l3|ti)&(100+num3*100);

kputpixel(buffer,x,y,k);

//kdrawrectfill(buffer,0,y,320,20,0);

   }

//u++;
//o1+=1;
     }


kdrawrectfill(buffer,100,20,110,150,0);
// if (si<120){  sound(si*ti*2);  }
//if (ti>1){ti=0;si++;if (si>=120){si=120; } }
//if (ti>100){ti=0; }
    i=-1;
    vertical=0;
kbr=1;kbl=1;
shpt=1;
for (k=0;k<165;k++){
i++; if (i>10){vertical+=10;i=0;}

if (map2[k]==0){
kdrawrectfill(buffer,(i*10)+100,vertical+20,8,8,200);

		    }
if (map2[k]>0){
//kblittranspage(buffer2,30,35,(i*10)+100,vertical+20,8,8,1);
singlenum(map2[k],(i*10)+60,vertical+20,map2[k]);
//kdrawrectfill(buffer,(i*10)+100,vertical+20,9,9,2);
		    }
if (plus>-40){
if (map[k-plus]>0){
//kdrawrectfill(buffer,(i*10)+100,vertical+20,9,9,1);
//kblittranspage(buffer2,45,25,(i*10)+100,vertical+20,8,8,14);
singlenum(map3[k-plus],(i*10)+60,vertical+20,map[k-plus]+10);

		    }
}

if (map[k-plus]>0) {

if (map2[k+11]>0) {      if (plus<-30){goto init;  }
reshape();

 for (k=0;k<175;k++){

if (map[k-plus]==1) {map2[k]=map3[k-plus];  }


}



 score+=3;





 spd=0;

 plus=-43;
    //srand(100);
dragshapes();

}             }


if (map[k-plus]==1) {







if (map2[k+1]>0){kbr=0; shpt=0; }
if (map2[k-1]>0){kbl=0; shpt=0; }
if (bgmap[k+11]==4){kbr=0; shpt=0; }
if (bgmap[k+11-11]==4){kbr=0; shpt=0; }

if (bgmap[k-10]==5){kbl=0;  }

if (plus<=-33){if (bgmap[k-11+11]==5){kbl=0;  }
	      }
if (plus<=-24){if (bgmap[k+12]==4){kbr=0; shpt=0;  }
	      }

if (shapetype==2){if (bgmap[k+12]==4|bgmap[k+13]==4){  shpt=0; }

  }

}
}


 su++; if (su>1000){so--;su=0;}

 if (si>60+so-spd){si=0;plus+=11;    horbloc+=11;} if (plus>128){ spd=0;    score+=3;  horbloc=0;
     for (j=0;j<5;j++){
yf1: ki+=0.1;	   shape11[j+33]=1; 	   shape21[j+33]=abs(sin(ki)*100);  if (shape21[j+33]>9||shape21[j+33]<1){shape21[j+33]=0; goto yf1;}
    }
reshape();
for (k=0;k<185;k++){


 if (map[k-plus]==1){map2[k-11]=map3[k-plus];;}



}

plus=-43;
 dragshapes();

}


for (y=0;y<165;y+=11){
int cn[11];
sum=0;
for (x=0;x<11;x++){

  sum+=map2[y+x];
if (sum>22){sum=0;x=11; for(i=0;i<11;i++){  map2[y+i]=0;  }
 //for (k=y-11;k>0;k-=11){  for (x=0;x<11;x++){map2[k+x+11]=map2[k+x];y=y+11;
 // }  }








}
		   }


}

//kdrawtransbitmap(&bmp2,0,0,0,0,320,200,0);


//kdrawtransbitmap(&bmp,0,9,100,100,50,59,0);
//if (f>200){f=0;}
//if (u>320){u=0;}
//u=0;
//f=0;
blitnumtex(score,120,180,4);



//kdrawtransbitmap(buffer2,buffer,100,100,60,60,0);
   memcpy(VGA,buffer,64000);


  /* draw the background */


   if (kbhit())

{
sc=getch();
     if (sc==27){stk++;}
	 switch(sc) {
		case 0x48 :   accy-=0.9;
		shapetype++; if (shapetype>2){shapetype=1;}
		// if (shapetype>0&&shapetype<2){  shapetype+=shpt; if (shapetype>2){shapetype=1;}  dragshapes(); }
	    //	   if (shapetype>3&&shapetype<6){  shapetype+=shpt; if (shapetype>5){shapetype=4;}  dragshapes(); }
	     //	   if (shapetype>5&&shapetype<14){  shapetype+=shpt; if (shapetype>13){shapetype=6;}  dragshapes(); }
		break;
		case 0x4b:    accx-=0.9; if (plus>-35){  plus-=kbl; horbloc-=11;}
		break;
		case 0x50:    accy+=0.9;   spd=67;
		break;
		case 0x4d:    accx+=0.9; if (plus>-35){ plus+=kbr; horbloc+=11;}
		break;
	       case 32:    bullettrig=1;
		break;

		  }   }







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
	 if(accx>0){   accx-=0.0006;  }
	 if(accx<0){   accx+=0.0006;  }
	 if(accy>0){   accy-=0.0006;  }
	 if(accy<0){   accy+=0.0006;  }

	  playerx+=accx;
	  playery+=accy;

	  if (accx>10){accx=10;}
	  if (accy>10){accy=10;}
	  if (accx<-10){accx=-10;}
	  if (accy<-10){accy=-10;}
       ti++;  if (ti>2){sound(-1);ti=0;}
    if (bullettrig==1){ti++;     sound(400); if (ti>2){sound(-1);ti=0;}

 //     kdrawrectfill(buffer,bulletx,bullety,3,3,62);
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
      if (sc==27){stk=0;} }
//	memcpy(VGA,buffer,64000);







while (stk==0){

 return;       }


}

