
  //raycaster....
//coded by keyvan mehrbakhsh 2025..
//enjoy..


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


					 clock. */
  int stk=1;
int num2=0,num3=0,num4=0,num1=0;
int score=0;
char jpfire=0;
  double sidedistx,sidedisty,deltadistx,deltadisty;
   double raydirx,raydiry;
   double rayx,rayy;
 double rayx=30,rayy=30;
int checkx,checky;
char stepx,stepy;
 double v;
 double hl[320];
 int viewang=0;
 double playerdirx,playerdiry;
int hl2[320];
char duckanim=0;
char *buffer;


double z=0;
 char section=0;
char nextsec=0;
char bt=0;
char goolanim=50;
int plusent=0;
char color,col1,col2;
int level=0;
char collock=1;
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

void kputpixel(char *buffer,int x,int y,int col);
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
double ang=0;
double sintab[2040];
double costab[2040];
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
void kputpixel(char *buffer,int x,int y,int col){

if (y>0&y<200&x>0&x<320) {
buffer[x+(y*320)]=col;       }

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
   if (t==15){if (n==10){map[i]=0;}}

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

   double tt=0;
  int sprcol=0;
  double t=0;
  int i,x,y,x1,y1;
  double k;
  int ti=0;
  int si=0;
 // BITMAP bmp;

    buffer=(char*)malloc(64000U);


   load_bmp("rocket2.bmp",&bmp);
     load_bmp("font1.bmp",&font1);

   load_bmp("spr.bmp",&bmp2);
	t=0;

init:



//initpos();

mapfill(0,0,0,0);
 /* open the file */

  set_mode(VGA_256_COLOR_MODE);       /* set the video mode. */





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

plasma(1,0);

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


   if (kbhit())

{stk++;
 getch();  }





}


   if (stk>2){stk=0;   memset(buffer,0,64000);
 }
d2=0.05;
v=0;
gh:
tt=0;

v=0;
for (i=0;i<1940;i+=1){
v+=0.01;
sintab[i]=sin(v);
costab[i]=cos(v);



}
		   v=16;
		  for (k=0;k<320;k+=1){
		     v++;if (v>30){v=16;}
		     col[k]=v;           }
	  for (k=0;k<320;k+=1){

		hl[k]=(((k)/(double)(320)));
		hl2[k]=hl[k]*100;

      }

ang=1;
while (stk==2){
  double walllenght=0;
 double wallheight1;
 double wallheight2;
double walllenght2;
int  k;
 double texdist;
 int i=-10;
 int j;
 double wallx=0;
 int sc;
 char hit=0;
 double tet2=0;
 double xoffset;
  double texstepy;

 double fov;
double raydirx,raydiry;
char side=0;


//  memset(buffer,0,40000);
//  kdrawrectfill(buffer,0,100,320,100,8);
  for (i=0;i<100;i++){
  khline(buffer,0,i,320,(16+(i/6)));

  khline(buffer,0,i+100,320,(197));

  }

tt=0;



	 accy=0; accx=0;


     k=0;

 fov=0.0035;
      z=0;    v=0;

       col1=16;
if (ang>12.5){ang=0.01;}
if (ang<0.01){ang=12.5;}
viewang=(int)(ang*100);
deltadistx=0;
deltadisty=0;
for (k=0;k<320;k+=2




      ){
	hit=0;


  z=0;
 checkx=(int)playerx;
 checky=(int)playery;
	   rayx=sintab[viewang+hl2[k]];
	   rayy=costab[viewang+hl2[k]];

//		     rayx=sin((ang)+vs[k]);
 //		     rayy=cos((ang)+vs[k]);


		       raydirx=rayx;
		       raydiry=rayy;






	     if (raydirx<0){   stepx=-1;
		      deltadistx=-(1/raydirx);

	     sidedistx=(playerx-checkx)*deltadistx;}

	      else {   stepx=1;    deltadistx=(1/raydirx);

	     sidedistx=(checkx+1-playerx)*deltadistx;}


		if (raydiry<0){   stepy=-1;
				  deltadisty=-(1/raydiry);
	     sidedisty=(playery-checky)*deltadisty;}


		else{   stepy=1;          deltadisty=(1/raydiry);


	     sidedisty=(checky+1-playery)*deltadisty;}









z=0;

while (hit==0){
//

	 if (checky>0&checky<200){
	 kdrawrectfill(buffer,(checkx*3)+5,(checky*3),1,1,4);
		       }

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






 if (map[abs(checkx)+(abs(checky)*21)]==0){hit=1;
     }  }

	  if (side==0){

		  walllenght=((double)(sidedistx-deltadistx)*cos(-0.5+hl[k]));
		 wallx=playery+(raydiry*walllenght);
	   }


		  if (side==1){


			  walllenght=((double)(sidedisty-deltadisty)*cos(-0.5+hl[k]));
			 wallx=playerx+(raydirx*walllenght);

       }

			    col2=(int)((wallx*80));










	wallheight1=(100-((120/(walllenght))));

       wallheight2=(100+((120/(walllenght))));


if (side==0){color=16;

 }

if (side==1){color=0;
}

						  col1=4;
				      //	  if (walllenght>20){col1=4+50;}

		texdist=0;

	      texstepy=(1/(1/(walllenght)))*0.5;

	      //	texdist=80+(int)(wallheight1+walllenght2*2)*((i-90)/walllenght2)/2;








	    for (i=wallheight1;i<wallheight2;i++){

    if (i<200){        if (i>0){

	    texdist+=texstepy;



		     if (side==1){

	  kputpixel(buffer,k,i,checkx);






			  if (checkx!=4
			  ){
		  kputpixel(buffer,k+1,i,checkx);

		  }

	   }

	if (side==0){

     col1=kgetpixelbmp(&bmp,col2+40,texdist+10);

     kputpixel(buffer,k,i,col1);

      kputpixel(buffer,k+1,i,col1);


   //

					      }



























}
}


}


}


for (k=0;k<320;k+=2



      ){
	hit=0;


  z=0;
 checkx=(int)playerx;
 checky=(int)playery;
	rayx=sintab[viewang+hl2[k]];
	   rayy=costab[viewang+hl2[k]];

	       //	  playerdirx=sintab[(int)(ang+25)];

	      //	  playerdiry=costab[(int)(ang+25)];


		       raydirx=rayx;
		       raydiry=rayy;



		       deltadistx=sqrt(1+(raydiry*raydiry)/(raydirx*raydirx));

		       deltadisty=sqrt(1+(raydirx*raydirx)/(raydiry*raydiry));


	     if (raydirx<0){   stepx=-1;


	     sidedistx=(playerx-checkx)*deltadistx;}

	      else {   stepx=1;
	     sidedistx=(checkx+1 -playerx)*deltadistx;}


		if (raydiry<0){   stepy=-1;

	     sidedisty=(playery-checky)*deltadisty;}


		else{   stepy=1;

	     sidedisty=(checky+1 -playery)*deltadisty;}



z=0;

while (hit==0){

		  if( sidedistx<sidedisty)
		   {sidedistx+=deltadistx;

		   checkx+= stepx;
			  side=0;

		   }
		   else
		   { sidedisty+= deltadisty;
		   checky+= stepy;
		   side =1;


		   }



 if (map[(int)(checkx)+((int)(checky)*21)]!=2){hit=1;
   }}

	  if (side==0){

		  walllenght=((sidedistx-deltadistx)*(cos(-0.5+hl[k])));
		 wallx=playery+(raydiry*walllenght);
	   }


		  if (side==1){


			  walllenght=((sidedisty-deltadisty)*(cos(-0.5+hl[k])));
			 wallx=playerx+(raydirx*walllenght);

       }

			    col2=(int)((wallx*100));

	wallheight1=(100-(70/(walllenght)));

       wallheight2=(100+(70/(walllenght)));









		texdist=0;

	      texstepy=((1/(1/walllenght)))*0.7;

 if (map[(int)(checkx)+((int)(checky)*21)]==5){
  for (i=wallheight1;i<wallheight2;i++){

    if (i<200){        if (i>0){

	    texdist+=texstepy;

     col1=kgetpixelbmp(&bmp2,col2+100,40+(int)texdist);

      if (col1!=0){
     kputpixel(buffer,k,i,col1+1);

      kputpixel(buffer,k+1,i,col1+1);
		   }



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
	     kdrawrectfill(buffer,(i*3)+3,v+section,3,3,4);


  }







}






//  kdrawrectfill(buffer,(playerx*3)-57,(playery*3),2,2,1);


   if (kbhit()) {
       sc=getch();
      if (sc==27){ stk=0; }
      switch(sc) {
		case 0x48 :     accy=1;

		break;
		case 0x4b:             ang-=0.05;

		break;
		case 0x50:       accy=-1;

		break;
		case 0x4d:              ang+=0.05;

		break;
	       case 32:
		break;

	}	  }
		  collock=1;
		    playerdirx=sin((ang)+0.5);

		    playerdiry=cos((ang)+0.5);

		   playerx+=playerdirx*(accy)*collock*0.5;
		   playery+=playerdiry*(accy)*collock*0.5;

			 if (map[(abs(playerx)+1)+abs(playery)*21]==0){ collock=0;  playerx-=1;     }
			 if (map[(abs(playerx)-1)+abs(playery)*21]==0){ collock=0;  playerx+=1;     }
			 if (map[abs(playerx)+(abs(playery)+1)*21]==0){ collock=0;  playery-=1;     }
			 if (map[abs(playerx)+(abs(playery)-1)*21]==0){ collock=0;  playery+=1
			 ;     }


	   //		  if (playerx>280){playerx=280;}
	//  if (playerx<10){playerx=10;}
	//  if (playery>165){playery=165;}
	//  if (playery<10){playery=10;}

   blittext(50,170,"find yourself around 0222",8,40,1);


//kdrawrectfill(buffer,0,190,320,20,0);

//kdrawtransbitmap(&bmp,63,16,playerx,playery,35,30,0);

	memcpy(VGA,buffer,64000);

 nosound();

}


while (stk==0){

 return;       }


}

