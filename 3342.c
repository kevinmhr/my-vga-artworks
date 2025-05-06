

#include <allegro.h>
#include <math.h>
//#include "map2.c"
char *bitmapbuffer;
 int z=0;
 int zv=0;
 int spdbulcol;
    int k34=0;
int textlenght=2;
int midis=0;
int fry;
int bullettimer2=0;
int digi=0;
int playerhealth=3;
double bulletx2[100];
double ang=66;
double angcor;
double rotatexcor,rotateycor;
double rotateang2=0;
double bullety2[100];
double accelx=0.1;
double accely=0.1;
double accelx2=0.1;
double accely2=0.1;
typedef struct CUBE{
                           
double l2[400];
double i[400];
double j[400];

double l[400];

double i2[400];
double j2[400];
double rotatex[400];
double rotatey[400];
double projx[400];
double projy[400];
double rotatel[400];
}CUBE;
int tick=0;
int frx=0;
int zvb;
int tuy,tuu,fri;
int add=0;
int num=0;
int num2=0;
int num3=0;
int num4=0;
 int ballcnt=0;
 int explostrig=0;
double rotateang=0;
int bulletcnt=0;
int timer5=0;
int add2=0;
int slowspid=0;
int spidtimer=0;
double bulletwarp=0;
double bulletwapd=1;
double hits=0;
double spd;
double ballx;
double bally;
  int faced;
  int explosy=400;    int explosx=400;

int scroll;
int spidanimx,spidanimy;
double timer1=0;
int level=1;
 int trail;
int lastbullet;
int bullethit=1;
   int midiseek;
       int timer2;
  double bulletx[100];
  double bullety[100];
int d;
    double warpx=0;   double warpy=0;
 double bulletdirx[100];
  double bulletdiry[100];
int bullettimer=20;
    int bullettrig;
         int downtrig;

   double playerxt,playeryt;
int pickupcolor;
double curenemix;
int roll=0;
  int jmpbypass;
int keytrig=0;
int addb=0;
int addb2=0;
double acce;
double i;
int y;
  int slow=0;;
int slow3=0;
int framex=0;

     int timerb;
int framey=133;
int ballframex,ballframey;

int keyboard();
int timer3=0;
int mapfunc();
double acce2;
int dur;
int maplenght;

int k;
int enemicnt;
int x;
int t;
int slow2;
int t2;
int tplayer;
int erasure=0;
int t2player;
int x2;
int bulletspd=0;
int ti;
int ti2;
int ti3=1;
int ti4;
int colx,coly;
double playerx=110;
double playery=80;
  double jmptimer2=0;


int swi=1;
int swi2=0;
int bgscrolx,bgscroly;
 int otherposx=0;
 int otherposy=0;
 int frame;
int numtogo=0;
 double tx=0;
 double tx2=0;
int f;
int shift;
int incdec=1;
  int dur2;
double plus;
int lenght;
int jmptrig=0;
double enemiposx=0;
double enemiposy=0;
double jmptimer;
int enemixt1=2;

double bgaddh=0;
int bgaddv=0;
int enemiyt1=2;
int laddercolor;

typedef struct OBJECT{
int colxw;
int colyw;
int diryw[50000];
int dirxw[50000];
int color[50000];
double rx[50000];
double ry[50000];
double rotate[50000];
double bulletx[50000];
double bullety[50000];
double x[50000];
double y[50000];
int dirx[50000];
int diry[50000];
int dirx2[50000];
int diry2[50000];
int bdirx[50000];
int bdiry[50000];
int timer;
double timer3;
int timer2;
int health[50000];
}OBJECT;
OBJECT spider;
OBJECT sleeps;
OBJECT spr;
OBJECT explos;
CUBE cb;
  //       BITMAP *levelbg;
   //       BITMAP *levelbg1;
                BITMAP *map;
   
//     BITMAP *levelbg2;
   BITMAP *collisionpad;
     BITMAP *collisionpad2;
    BITMAP *sprite;
        BITMAP *cubespr;


   PALETTE the_palette1;
   PALETTE the_palette;
   PALETTE the_palette2;

   BITMAP *walkingspr2;
    BITMAP *font1;
   BITMAP *sprites;
     BITMAP *surface;
    BITMAP *sprsheet;
  //  BITMAP *spr1;
    // OBJECT enemii;
//  MIDI *grand;
//char spritebuf[256];

int spr01[]={
0,0,0,0,0,0,0,230,230,230,230,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,230,249,249,249,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,230,249,249,249,249,249,249,230,0,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,230,0,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,249,230,230,230,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,290,249,249,230,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,249,230,230,230,0,0,0,0,
0,0,0,0,230,230,249,249,249,249,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,249,249,249,249,249,249,249,249,249,249,0,0,0,0,0,
0,0,0,249,249,249,249,249,249,249,249,249,230,249,249,249,0,0,0,0,
0,0,249,249,249,0,230,27,27,27,27,27,249,230,249,249,249,0,0,0,
0,249,249,249,0,0,230,27,27,27,27,27,249,230,0,0,0,0,0,0,
0,0,0,0,0,0,230,27,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,230,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,230,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,230,27,249,0,230,230,240,230,0,0,0,0,0,0,
0,0,0,0,0,230,249,249,0,230,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,230,240,240,0,0,230,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,230,240,240,0,0,230,230,249,240,230,0,0,0,0,0,0,
0,0,0,0,0,230,240,0,0,0,0,230,230,230,230,0,0,0,0,0,


0,0,0,0,0,0,0,230,230,230,230,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,230,249,249,249,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,230,249,249,249,249,249,249,230,0,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,230,0,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,249,230,230,230,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,290,249,249,230,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,249,230,230,230,0,0,0,0,
0,0,0,0,230,230,249,249,249,249,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,249,249,249,249,249,249,249,249,249,0,0,0,0,0,0,
0,0,0,0,249,249,249,249,249,249,249,249,230,249,249,0,0,0,0,0,
0,0,0,249,249,0,230,27,27,27,27,27,249,230,249,249,0,0,0,0,
0,0,249,0,0,0,230,27,27,27,27,27,249,230,0,0,0,0,0,0,
0,0,0,0,0,0,230,27,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,230,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,230,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,230,27,249,0,230,230,240,230,0,0,0,0,0,0,
0,0,0,0,0,0,230,249,249,230,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,230,240,240,0,230,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,230,240,240,0,230,230,249,240,230,0,0,0,0,0,0,
0,0,0,0,0,0,230,240,0,0,230,230,230,230,0,0,0,0,0,0,


0,0,0,0,0,0,0,230,230,230,230,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,230,249,249,249,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,230,249,249,249,249,249,249,230,0,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,230,0,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,249,230,230,230,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,290,249,249,230,0,0,0,0,0,0,
0,0,0,0,230,249,249,249,249,249,249,249,249,230,230,230,0,0,0,0,
0,0,0,0,230,230,249,249,249,249,249,230,0,0,0,0,0,0,0,0,
0,0,0,0,0,249,249,249,249,249,249,249,249,249,0,0,0,0,0,0,
0,0,0,0,249,249,249,249,249,249,249,249,230,249,249,0,0,0,0,0,
0,0,0,249,249,0,230,27,27,27,27,27,249,230,249,249,0,0,0,0,
0,0,249,0,0,0,230,27,27,27,27,27,249,230,0,0,0,0,0,0,
0,0,0,0,0,0,230,27,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,230,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,230,27,27,27,27,230,0,0,0,0,0,0,0,
0,0,0,0,0,0,230,27,249,0,230,230,240,230,0,0,0,0,0,0,
0,0,0,0,0,0,230,249,249,0,230,249,230,0,0,0,0,0,0,0,
0,0,0,0,0,230,240,240,0,0,230,249,230,0,0,0,0,0,0,0,
0,0,0,0,0,230,240,240,0,0,230,230,249,240,230,0,0,0,0,0,
0,0,0,0,0,0,230,240,0,0,0,0,230,230,230,230,0,0,0,0,

};



int shrine[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,2040,2040,2040,2040,2040,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,0,0,0,0,0,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,2040,2040,2040,2040,2040,2040,2040,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
              0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
          
              };

int maptemp[90000];

const int corebreak=2060;

void blitnumtex(int sc,int textplacex,int textplacey,int digit){
      int numdig=4;

    int fontsize=8;
       double  integ[10];
          hits=sc;
      if (hits>=9){hits=0;num2++;};

      if (num2>9){num2=0;num3++;};
      if (num3>9){num3=0;num4++;};
      if (num4>9){num4=1;};

      integ[1]=(hits)*6.9+180;

      integ[2]=((int)(num2))*6.9+180;
      integ[3]=((int)(num3))*6.9+180;
      integ[4]=((int)(num4))*6.9+180;

   //    if (hits<0){hits=9999;}
   //   hits--;



        int x=0;
      int y=0;        
     for (int j=0;j<fontsize*(fontsize+fontsize/2);j++){
      x++; if (x>fontsize){x=0;y++;}
int col;  

    int coly=y;

 //    if (warp=1){      coly=y*sin(warpy/10)*2; }

        for (int d=1;d<digit+1;d++){
   col=getpixel(font1,(integ[d])+x,y);
  // slow++; if (slow>50000){ slow=0;        slow2+=1; }


       if (col==255){


      col=col+slow2;

     putpixel(surface,((i*fontsize)+((x-d*6))+textplacex+40),textplacey+(coly),0);

    }


    }        }

    











}
void blittext(int textplacex,int textplacey,char* tex,int fontsize,int textlenght,int inv){



int integ=0;
//enemii.y=0;
//enemii.x=0;
//char* tex=" this is a game of ball and other things";
int o=0;
int i,j;
int k=1;

int warpy;



for (int i=0;i<textlenght;i++){
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
    int  warp=1;
      int integ=(((int)tex[i]))-97;

     int x=0;
     int y=0;

     for (int j=0;j<fontsize*(fontsize+fontsize/2);j++){




      x++; if (x>fontsize){x=0;y++;}
int col;  

    int coly=y;

     if (warp=1){      coly=y*sin(warpy/10)*2; }
   if (fontsize>=10){

   col=getpixel(font1,1+(double)((integ)*(13.182))+x,y+74);
  slow++; if (slow>50000){ slow=0;        slow2+=1; }


       if (col==255){


      col=col+slow2;

     putpixel(surface,(i*fontsize)+x+textplacex,textplacey+(coly),col);     }

                 }
     


  if (fontsize<=10){
   col=getpixel(font1,(integ*7)+x-1,y-1);
   if (col==255){
   putpixel(surface,(i*fontsize)+x+textplacex,textplacey+y,col);

               }


















              }  }

 }




 }



/*
void spritefunction(){
    int j=0;
    int k=0;
   
   for (int i=frame;i<frame+400;i++){

      putpixel(spr1, k, j ,spr01[i]+4);
   k++;
   if (k>=20){j++;k=0;}

       if (j>=20){j=0;}

                      }







}
*/
int collisionimplant(){

        int i=0;
        int j=0;
         for (int k=0;k<50000;k++){
                     sleeps.dirx[k]=1;
                    sleeps.diry[k]=0;


                    maptemp[k]=0;


         }


         
     for (int k=0;k<320*300;k++){
    i++; if (i>320){j++; i=0;}
      // if (j>240){k=320*240;}
   int walls=getpixel(map,0,1);
   int term=getpixel(map,0,2);
      int blue=getpixel(map,0,4);
   int purple= getpixel(map,0,3);
           int spider=getpixel(map,0,5);
            int mapstart=getpixel(map,0,8);
           int mapend=getpixel(map,0,7);

         int col= getpixel(map,i,j);
 

   if (col==walls){maptemp[k]=2060;}
     if (col==term){maptemp[k]=1043;}
        if (col==blue){maptemp[k]=2080;}
           if (col==purple){maptemp[k]=4060;}
            if (col==spider){maptemp[k]=1077;}
             if (col==mapstart){plus=k;}
                    if (col==mapend){maptemp[k]=2050;}














     }






   clear_to_color(collisionpad2,237);

int mapxoffset=+40;
int mapyoffset=-120;
 i=0;int y=0;

for (int k=0;k<320*300;k++){

i+=1; if (i>320){i=0;y+=1;}
//if (y>320){y=0;}
if (maptemp[k]>2000){if (maptemp[k]!=2050){ rectfill(collisionpad2,(i*5)+mapxoffset,(y*5)+mapyoffset,((i*5)+5)+mapxoffset,((y*5)+5)+mapyoffset,4);}
}                                          }


i=0; y=0;
for (int k=0;k<50000;k++){
i+=1; if (i>320){i=0;y+=1;}

//sleeps.x[k]=0;
if (maptemp[k]==1043){sleeps.x[k]=(i*5)+mapxoffset;
sleeps.y[k]=(y*5)+mapyoffset;   }
if (maptemp[k]==1077){spider.x[k]=(i*5)+mapxoffset;
spider.y[k]=(y*5)+mapyoffset;

}

            }


            








}
int blittingtosprite(){

int i=0;
int j=0;
int col=0;

double i2=0;
double j2=0;
double rotatex=sin(ang)+cos(ang);
double rotatey=-sin(ang)+cos(ang);

int framex=160;
int framey=32;
// clear_to_color(sprites,4);

for (int k=0;k<600;k++){


i++;if (i>15){i=0;j++;}
if (j>30){j=0;}

col=getpixel(sprsheet,i+framex,j+framey);
j2=(((i-10)*(rotatex))+((j-15)*(rotatey)))/2;
i2=(((j-15)*(rotatex))-((i-10)*(rotatey)))/2;
//i2=i/10;
//j2=j/10;

if (col!=getpixel(sprsheet,i,j)){
putpixel(surface,i2+playerx,j2+playery,col);
//putpixel(surface,i+playerx+1,j+playery+3,col+10);


    }
//    rectfill(surface,playerx,playery,playerx+5,playery+5,238);


}

}
int othersblittingtosprite(int otherposx;int otherposy;){



}
int init(){
level=1;
//          play_midi(grand,0);
     //  ballx=320;
     //  bally=100;

      hits=0;
      num2=0;
      num3=0;
      num4=0;
         explos.timer=0;
           maplenght=320;
        d=0;
          ti3=0;
          bgscrolx=0;
          z=0;
    sleeps.timer=0;
       sleeps.timer2=0;
          sleeps.timer3=0;
         explos.timer=2000;
         zv=0;
         add2=0;
         add=0;
         acce=1;
         jmptimer=0;
//    enemii.x=1;
 //     enemii.y=1;
         bullettrig=1;
      enemiposx=1;
       enemiposy=1;
       enemicnt=0;
      i=1;
//    plus=2000;
playerx=100;
 playery=50;

  if (level>3){level=1;}
  if (level==1){


         /*      levelbg=load_bitmap("levbg1.bmp",the_palette); */    }

     collisionimplant();

   if (level==2){
  for (int x=0;x<7144;x++){

// maptemp[x]=map1[x];

               }   /* levelbg=load_bitmap("levbg2.bmp",the_palette);*/       }

   if (level==3){
  for (int x=0;x<7144;x++){

// maptemp[x]=map1[x];

               }   /* levelbg=load_bitmap("spritesh.bmp",the_palette); */      }
 for (int i=0;i<100;i++){
   bulletx[i]=800;
      bullety[i]=800;}
  for (int x=0;x<50000;x++){
    spider.dirx[x]=1;  spider.diry[x]=-1;
    spr.dirx[x]=1;  spr.diry[x]=-1;
    sleeps.dirx[x]=-1; sleeps.diry[x]=1;
    spider.bdirx[x]=1;  spider.bdiry[x]=1;
    spider.bulletx[x]=spider.x[x];
    spider.bullety[x]=spider.y[x];
           sleeps.diryw[x]=-1;
       sleeps.dirxw[x]=-1;

 }
//   play_midi(grand,0);
}






int cube(){

// clear_to_color(sprites,4);



int r;

//double z[100];



   fry=0;


int col=0;
 clear_to_color(cubespr,0);
      // rotateang+=0.005;
//   rotatex=(cos(rotateang)+sin(rotateang));
 //  rotatey=(-sin(rotateang)+cos(rotateang));


   //      if (key[KEY_DOWN]){playery--;  }
   //       if (key[KEY_UP]){playery++; }
/*       if (rotateang<1){rotateang=(sintab2[(plus2-100)]/3)+0.8;  rotatex=(cos(rotateang)+sin(rotateang));
   rotatey=(-sin(rotateang)+cos(rotateang));
   }

       if (rotateang>1){rotateang=(sintab2[(plus2-100)]/3)+0.8;   rotatex=(cos(rotateang)+sin(rotateang));
   rotatey=(-sin(rotateang)+cos(rotateang));
   }
  */



   //       if (key[KEY_LEFT]){playerx-=5;  }
    //      if (key[KEY_RIGHT]){playerx+=5; }









              int it,jt;




for (int k=0;k<200;k++){

       cb.i[0]=-1;
       cb.i[1]=-1;
       cb.i[2]=1;
       cb.i[3]=1;
       cb.i[4]=-1;
       cb.i[5]=-1;
       cb.i[6]=1;
       cb.i[7]=1;


       cb.j[0]=-1;
       cb.j[1]=1;
       cb.j[2]=-1;
       cb.j[3]=1;
       cb.j[4]=-1;
       cb.j[5]=1;
       cb.j[6]=-1;
       cb.j[7]=1;



        cb.l[0]=-1;
        cb.l[1]=-1;
        cb.l[2]=-1;
        cb.l[3]=-1;
        cb.l[4]=1;
        cb.l[5]=1;
        cb.l[6]=1;
        cb.l[7]=1;








      double dis=10;


         //  cb.i[k]=sleeps.x[k];
         //  cb.j[k]=sleeps.y[k];
        //   cb.l[k]=sleeps.x[k];

   cb.rotatex[k]=((cb.i[k]*dis)*(cos(rotateang)))+(((cb.l[k]*dis)*sin(rotateang)));
   cb.rotatey[k]=(cb.j[k]*dis);
   cb.rotatel[k]=((cb.i[k]*dis)*(-sin(rotateang)))+(((cb.l[k]*dis)*cos(rotateang)));
                 cb.j2[k]=(cb.rotatey[k]*cos(rotateang))-(cb.rotatel[k]*sin(rotateang));
                 cb.l2[k]=(cb.rotatey[k]*sin(rotateang))+(cb.rotatel[k]*cos(rotateang));

                 
               

                      cb.rotatey[k]=cb.j2[k];
                       cb.rotatel[k]=cb.l2[k];

         
                     cb.rotatel[k]+=40;

              col=rotateang+z+k*10;
              cb.projx[k]=((cb.rotatex[k]*100)/cb.rotatel[k]/5)+100;
              cb.projy[k]=((cb.rotatey[k]*100)/cb.rotatel[k]/5)+100;

        //        playerx=((cos(rotateang)*(sin(rotateang2)*200)))+((sin(rotateang))*(sin(rotateang2)*200))+180;
         //           playery=((cos(rotateang)*(sin(rotateang2)*200)))-((sin(rotateang))*(sin(rotateang2)*200))+90;
                rotateang+=0.01;
                rotateang2+=sin(rotateang)/10;
//circlefill(surface,((cb.projx[k])),((cb.projy[k])),0,220);

/*
   line(cubespr,cb.projx[0],cb.projy[0],cb.projx[4],cb.projy[4],col);
   line(cubespr,cb.projx[1],cb.projy[1],cb.projx[5],cb.projy[5],col);
   line(cubespr,cb.projx[2],cb.projy[2],cb.projx[6],cb.projy[6],col);
   line(cubespr,cb.projx[3],cb.projy[3],cb.projx[7],cb.projy[7],col);


   line(cubespr,cb.projx[0],cb.projy[0],cb.projx[2],cb.projy[2],col);
   line(cubespr,cb.projx[1],cb.projy[1],cb.projx[0],cb.projy[0],col);
   line(cubespr,cb.projx[1],cb.projy[1],cb.projx[3],cb.projy[3],col);
   line(cubespr,cb.projx[2],cb.projy[2],cb.projx[3],cb.projy[3],col);


   line(cubespr,cb.projx[4],cb.projy[4],cb.projx[6],cb.projy[6],col);
   line(cubespr,cb.projx[5],cb.projy[5],cb.projx[4],cb.projy[4],col);
   line(cubespr,cb.projx[5],cb.projy[5],cb.projx[7],cb.projy[7],col);
   line(cubespr,cb.projx[7],cb.projy[7],cb.projx[6],cb.projy[6],col);

  */


                    }



   

 
 

//
//putpixel(surface,i+playerx,j+playery,col+250);  }

  }







int mapfunc(){


  clear_to_color(collisionpad,1);

//       blit(collisionpad2,surface,((z*5)+add)+100,(((zv*5))+add2)+200,0,0,320,240);
  
   int xoffsetcorrec=100;
   int yoffsetcorrec=200;
      // blit(cubespr,surface,0,0,0,0,320,240);

  //   blit(levelbg2,levelbg3,0,150,0,0,105,65);
    //       draw_sprite(surface,levelbg3,bgscrolx/2,bgscroly);

         //    blit(levelbg,screen,0,0,0,0,320,240);




              //      if (vertical>220){vertical=10;}

               int    i=0;







         int  vertical=0;



                  d=100;
          /*
               int xi=0;
               int yi=0-add2;
               int ui=0;


                for(int k=0;k<640;k++){
                  xi+=10; if (xi>=320){yi+=10;xi=0;}
                  blit(sprsheet,surface,0,50,(xi)-(add)+0,yi,1,1);


             
             
                                    }

            */

           for (int k=0;k<(20000);k++){


                 int mapb=k+plus;
                 int k=mapb;




                 i+=1;

          if (i>maplenght){vertical=vertical+5;i=0;            }












           if (maptemp[k]>=2000){



              int x,y;
              double x1,y1;
              x=maptemp[k];
              x1=(int)(x/100);
              y=x-(x1*100);
   //       if(maptemp[k]==2060)    {y=75;x1=99;}
                      //    rectfill(surface,(i*5)-add,vertical,((i+2)*5)-add,vertical+5,4);
               //  masked_blit( sprsheet,surface,20,107,((i*20))-add,vertical ,20, 20);


       masked_blit( sprsheet,surface,x1-10,y-10,((i*5))-add,vertical-add2,5, 5);



                 rectfill(collisionpad,(i*5)-add,vertical-add2,((i*5)-add)+5,vertical+7-add2,4);
                     colx=getpixel(collisionpad,bulletx[lastbullet],bullety[lastbullet]-zvb);
                     if(colx==4){ bulletx[lastbullet]=8000;   }

       
           //   rectfill(surface,(i*5)-add,vertical,((i+2)*5)-add,vertical+7,4);

                        }


               if (maptemp[k]==2050){

                               rectfill(surface,(i*5)-add,vertical-add2,((i*5)-add)+5,vertical+7-add2,4);
                       rectfill(collisionpad,(i*5)-add,vertical-add2,((i*5)-add)+5,vertical+7-add2,21);
              


                                  }









 }















        spdbulcol++;
          blitnumtex(hits,10,10,4);


         sleeps.timer3+=0.1;

  // crossball();
              spider.timer+=1;

        spider.timer2+=3;
     //   spr.timer++;

     //   spr.timer2++;

      int  bulleti;
int i2=0;
int j2=0;

 int lastspider;
            double spdy=0;            double spdx=0;
       
           double spdy2=0;

                                                          double spdx2=0;
int k35=0;
for (int i=0;i<60000;i++){






            if (maptemp[i]==1077){
                             enemicnt=i;
                   if( spider.dirx[enemicnt]==1 )  {   spider.rotate[i]+=0.005; }
                     if(   spider.dirx[enemicnt]==-1)   {   spider.rotate[i]-=0.005; }


                            if (spider.timer>=800) { spider.timer=0;      }


                         if (spider.timer>=400) {      if (playerx<spider.x[i]-(z*5)){   spider.bdirx[i]=1; }  if (playerx>spider.x[i]-(z*5)){   spider.bdirx[i]=-1; }
                         if (playery<spider.y[i]-(zv*5)){   spider.bdiry[i]=1; }if (playery>spider.y[i]-(zv*5)){   spider.bdiry[i]=-1; }


                                       if (playery>spider.y[i]-(zv*5)){
                                   if (playery-spider.y[i]-(zv*5)<=10){   spider.bdiry[i]=0; } }
                                       if (playery<spider.y[i]-(zv*5)){
                                   if (spider.y[i]-(zv*5)-playery<=10){   spider.bdiry[i]=0; } }

                                                spider.bullety[i]=spider.y[i]+5;
                                                spider.bulletx[i]=spider.x[i]+8;









                                              }









                         // rbx[enemicnt]=-1;
                          //  rby[enemicnt]=1;


                          if (spider.timer2==200){   spider.dirx[enemicnt]=-spider.dirx[enemicnt];







    }

            if (spider.timer2==600){      spider.diry[enemicnt]=-spider.diry[enemicnt];     }

                  if (spider.timer2==550){   spider.dirx[enemicnt]=0;}
                         if (spider.timer2==750){   spider.diry[enemicnt]=0;}



              if (spider.timer2>=2000){ spider.timer2=0; }

                           if (spider.timer2==50){   spider.dirx[enemicnt]=1;}
                         if (spider.timer2==150){   spider.diry[enemicnt]=1;}




                              slowspid++;





                  //    if (slow2>20000){ slow2=0;  }



int ks=0;
int is=5;

int js=0;
int col=0;

// clear_to_color(sprites,4);





 //       rectfill(surface,enix[enemicnt]+(i*10),vertical-20-add2+eniy[enemicnt],enix[enemicnt]+((i+1)*10),vertical+10-add2+eniy[enemicnt],90);








                          for (int x=-3;x<15;x++){

                    colx=getpixel(collisionpad2,spider.x[i]+x+xoffsetcorrec,spider.y[enemicnt]-5+yoffsetcorrec);
                                           if (colx==4){
                                     // spider.color[i]+=1;

          spider.diry[enemicnt]=1;   }

                    colx=getpixel(collisionpad2,spider.x[enemicnt]+x+xoffsetcorrec,spider.y[enemicnt]+15+yoffsetcorrec);
                                           if (colx==4){
                                  //   spider.color[enemicnt]+=1;

         spider.diry[enemicnt]=-1;   }

                 }





                 for (int y=-3;y<15;y++){

                    colx=getpixel(collisionpad2,spider.x[enemicnt]+15+xoffsetcorrec,y+spider.y[enemicnt]+yoffsetcorrec);
                                           if (colx==4){
                                        //    spider.color[enemicnt]+=1;

          spider.dirx[enemicnt]=-1;   }

                    colx=getpixel(collisionpad2,spider.x[enemicnt]-1+xoffsetcorrec,y+spider.y[enemicnt]+yoffsetcorrec);
                                           if (colx==4){
                                     //      spider.color[enemicnt]+=1;

         spider.dirx[enemicnt]=1;   }

                 }

                double x2= (sin(spider.rotate[i])-(cos(spider.rotate[i])))/2;
     
             double y2=   (sin(spider.rotate[i])+(cos(spider.rotate[i])))/2;





                      //    if(enix[enemicnt]<50){  rx[enemicnt]=1;  }
                        //   if(enix[enemicnt]-(z*10)-add>320){  r[enemicnt]=-1; }
                         //  if(enix[enemicnt]-(z*10)-add<0){  r[enemicnt]=1;}
                            if (spidanimx>=13){spidanimx=0;}  if(slowspid>20) { slowspid=0;spidanimx+=13;}
                         if (spider.diry[enemicnt]>0){spider.y[enemicnt]+=1+1*(x2);              }
                         if (spider.diry[enemicnt]<0){spider.y[enemicnt]-=1+1*(x2);              }
                         if (spider.dirx[enemicnt]>0){spider.x[enemicnt]+=1+1*(y2); }
                         if (spider.dirx[enemicnt]<0){spider.x[enemicnt]-=1+1*(y2);             }
                      //     if(  enix[enemicnt]==0){ enix[enemicnt]==1; r[enemicnt]=-r[enemicnt];}






                             if (spider.dirx[enemicnt]>=0){fry=0;}  if (spider.dirx[enemicnt]<=0){fry=30;}



//                     if (colx==4){  bullet2x[i]=400;
  //          bullet2y[i]=300;

//         blit(walkingspr,surface,0,0,bullet2x[i],bullet2y[i],2,2);

                        rectfill(collisionpad,spider.bulletx[i]-add-(z*5)-5,spider.bullety[i]-(zv*5)-add2-5,spider.bulletx[i]-add-(z*5)+10,spider.bullety[i]-(zv*5)-add2+10,134);
                             circlefill(surface,spider.bulletx[i]-add-(z*5)-3,spider.bullety[i]-(zv*5)-add2-3,1,spdbulcol);
                                      circlefill(surface,spider.bulletx[i]-add-(z*5)-3+1,spider.bullety[i]-(zv*5)-add2-3,1,spdbulcol+50);
               
                        //                                   circlefill(surface,spider.bulletx[i]-add-(z*10)-2,spider.bullety[i]-(zv*10)-add2-2,1,253);

                              //  rectfill(surface,playerx,playery,playerx,playery,95);
                               int colx=getpixel(collisionpad,playerx+10,playery+10);
              //         if (colx==98){ midiseek=0;   play_midi(grand,0);midi_seek(40); init(); }




                                        colx=getpixel(collisionpad2,spider.bulletx[i]+xoffsetcorrec,spider.bullety[i]+yoffsetcorrec);
                                      if(colx==4){ spider.bulletx[i]=-100;  spider.bullety[i]=-100;}


                    rectfill(collisionpad,spider.x[enemicnt]-(z*5)-add-5,spider.y[enemicnt]-15-add2-(zv*5),spider.x[enemicnt]-(z*5)-add+15,spider.y[enemicnt]-15-add2-(zv*5)+20,84);

     //     textprintf_ex(surface,font,spider.x[enemicnt]-1-(z*10)-add,spider.y[enemicnt]-(zv*10)-add2-10,250,0,"%i",spider.health[i]);
             double x=0;
             double y=0;


            for (int i=0;i<100;i++){

             x++; if (x>10){x=0;y++;}

                double x3=((((x-5)*(x2))+((y-4)*(y2))));
                double y3=((((y-4)*(x2))-((x-5)*(y2))));
                 int colx=getpixel(sprsheet,160+spidanimx+x,32+y);
                 if (colx!=0){
//              putpixel(surface,(x/2)+spider.x[enemicnt]-1-(z*10)-add,(y/2)+spider.y[enemicnt]-(zv*10)-add2+1,0);
         
             putpixel(surface,x3+spider.x[enemicnt]-1-(z*5)-add,y3+spider.y[enemicnt]-(zv*5)-add2,colx+spider.color[enemicnt]);

             //       masked_blit(walkingspr2,surface,155+spidanimx+x3+3,261+y3,spider.x[enemicnt]-1-(z*10)-add,spider.y[enemicnt]-(zv*10)-add2,10,10);

              //      masked_blit(walkingspr2,surface,155+spidanimx+x3+3,261+y3,spider.x[enemicnt]-1-(z*10)-add,spider.y[enemicnt]-(zv*10)-add2,10,10);
                      }

            }

   //         draw_sprite(surface,sprite,);


                     if (spider.bdirx[i]==1){

                   spider.bulletx[i]-=1;        }
                      if (spider.bdirx[i]==-1){
                   spider.bulletx[i]+=1;            }
                      if (spider.bdiry[i]==1){
                   spider.bullety[i]-=1;}
                         if (spider.bdiry[i]==-1){
                   spider.bullety[i]+=1;}



                                           k34=0;   k35=0;

           colx=getpixel(collisionpad,bulletx[lastbullet],bullety[lastbullet]-zvb);
//           putpixel(collisionpad,bulletx[lastbullet],bullety[lastbullet]-zvb,250);
     

         if (colx==84){
                                      explosx=bulletx[lastbullet]; explosy=bullety[lastbullet]-zvb;

         hits+=1;      k34=1;
            bullettrig=0;
                             }

                          if (k34==1){     addb=0; addb2=0;   k35=1; fri=0;   explos.timer=0;   explos.timer2=0;

           midiseek=0; k34=0;  k35=enemicnt; bulletx[lastbullet]=8000;  maptemp[enemicnt]=0;      mapfunc();
                            }





 


 






                        }
























     if (maptemp[i]==1043){
                    //  textprintf_ex(surface,font,10,10,250,0,"%i",k);

               int ballcnt=i;

       //   if (z>1000){ z=0;ballinix=330; balliniy=100; timer1=0;}
       //     if (z<-500){ z=0;ballinix=-130; balliniy=100; timer1=0;}
      //      tx=-1;
                     /*
                           colx=getpixel(collisionpad,ballx[ballcnt]+15,bally[ballcnt]+10);
                       if (colx==4){ tx=0;  }
                           colx=getpixel(collisionpad,ballx[ballcnt]-1,bally[ballcnt]+10);
                       if (colx==4){ tx=0;   }
                           colx=getpixel(collisionpad,ballx[ballcnt],bally[ballcnt]);
                  //     if (colx==4){ty=0; tx=1;  }
                           colx=getpixel(collisionpad,ballx[ballcnt],bally[ballcnt]);
                  //     if (colx==4){ty=0;tx=-1;   }
                    //    if (bally[k]>170){tx=1;}
                       */

                  //    int colx;


                                      //  btx=1;

                  //          if (sleeps.timer>5000){sleeps.timer=0;}

             //  putpixel(screen,ballx,bally+ly,237);
               //  putpixel(screen,(i*10)+ballx-add-10,vertical+bally+y,237);
        //    if (sleeps.timer>=1000) { sleeps.dirx[ballcnt]=0; sleeps.diry[ballcnt]=1;       }

          //     if (sleeps.timer>=2000) { sleeps.dirx[ballcnt]=1;sleeps.diry[ballcnt]=0;      }


           //   if (z>32){z=0;entities();}
                      //  masked_blit(collisionpad,surface,0,0,0,0,320,240);

                   //    putpixel(screen,ballx+lx,bally+10,237);
      
            //         if (sleeps.timer>=3000) { sleeps.dirx[ballcnt]=0;sleeps.diry[ballcnt]=-1;      }
                   // colx=getpixel(collisionpad,((i*10)+ballx-add)+5,vertical+bally-10);

              //       if (sleeps.timer>=4000) {  sleeps.dirx[ballcnt]=-1;sleeps.diry[ballcnt]=0;      }
                                                         //    sleeps.diry[ballcnt]=1;
                                                         //       sleeps.dirx[ballcnt]=1;

                                             //        sleeps.dirx[ballcnt]=sleeps.dirxw[ballcnt];
                                            //  sleeps.diry[ballcnt]=sleeps.diryw[ballcnt];


                               /*

                                  if (playerx>sleeps.x[ballcnt]-(z*20)){

                            if (playerx-(sleeps.x[ballcnt]-(z*20))<10){   sleeps.dirx[ballcnt]=-sleeps.dirx[ballcnt];   }

                                                                  }


                         if (playerx<sleeps.x[ballcnt]-(z*20)){

                         if ((sleeps.x[ballcnt]-(z*20))-playerx<10){        sleeps.dirx[ballcnt]=sleeps.dirx[ballcnt];         }

                                                                                                           }




                                                 if (playery>sleeps.y[ballcnt]-(zv*20)){

                            if (playery-sleeps.y[ballcnt]-(zv*20)<10){   sleeps.diry[ballcnt]=-sleeps.diry[ballcnt];        }

                                                                  }


                         if (playery<sleeps.y[ballcnt]-(zv*20)){

                         if (sleeps.y[ballcnt]-(zv*20)-playery<10){    sleeps.diry[ballcnt]=sleeps.diry[ballcnt];         }
                                                               }



                                 */



                          //  masked_blit(collisionpad,surface,0,0,0,0,320,240);

               //        circle(surface,(i*10)+ballinix[ballcnt]+20-add,vertical+balliniy[ballcnt],3,3);
                       //  for (int x=0;x<10;x++){
                       //  colx=getpixel(collisionpad,(i*10)+ballinix[ballcnt]+10-add,vertical+balliniy[ballcnt]+x);
                    /*    tempx=(int)ballx*0.11;
                       colx=maptemp[k+tempx+1];
                       if (colx>2000){btx=0;   }
                           tempx=(int)ballx*0.11;
                       colx=maptemp[k+tempx-1];
                       if (colx>2000){btx=0;   }
                         int tempy=(int)bally*0.11;
                       colx=maptemp[k+tempy+maplenght+32+65];
                       if (colx>2000){bty=0;   }
                           tempy=(int)bally*0.11;
                          colx=maptemp[k+tempy-maplenght+32+65];

                       if (colx>2000){bty=0;   }
                        colx=getpixel(collisionpad,(i*10)+ballinix[ballcnt]-1-add,vertical+balliniy[ballcnt]+x);
                      if (colx==4){btx=0;   }

                         //                       }
                              */


              //      if( ballinix[ballcnt]+(i*10)<-50){ballinix[ballcnt]=0;balliniy[ballcnt]=0;}
              //      if( ballinix[ballcnt]+(i*10)>500){ballinix[ballcnt]=0;balliniy[ballcnt]=0;}

                 //          (z*10+add)+60,240
                        //    btx[ballcnt]=0;
                        //       bty[ballcnt]=0;



                                                          sleeps.colxw=0;     sleeps.colyw=0;
                                              sleeps.timer2++;
                                                    sleeps.timer++;

                                            //   if (sleeps.timer==0) {         sleeps.colxw=1;     sleeps.colyw=1;    }
                                        //  sleeps.diry[ballcnt]=0;
                                         //                            sleeps.dirx[ballcnt]=0;

                                                int  ballx;
                                 //     if(sleeps.x[ballcnt]-(z*5)-add<10){ sleeps.dirx[ballcnt]=1;}
                                  //      if(sleeps.y[ballcnt]-(zv*5)-add2<10){ sleeps.diry[ballcnt]=1;}
              int  bally;

                                                        int  rt=10;
                                                    spdx=0.5;   spdy=0.5;
                                                      spdx2=0.5;   spdy2=0.5;


                                                //        sleeps.diry[ballcnt]=1;
                                               //           sleeps.dirx[ballcnt]=1;










                                             if (sleeps.timer2==2000) {


                                                           sleeps.dirx[ballcnt]=-1;
                                                            sleeps.diry[ballcnt]=0;
                                                                   }
                                                  if (sleeps.timer2==4000) {
                                                           sleeps.dirx[ballcnt]=0;
                                                            sleeps.diry[ballcnt]=-1;
                                                                   }
                                                        if (sleeps.timer2==6000) {
                                                           sleeps.dirx[ballcnt]=- sleeps.dirx[ballcnt];
                                                            sleeps.diry[ballcnt]=0;
                                                                   }
                                                               if (sleeps.timer2==8000) {
                                                           sleeps.diry[ballcnt]=-sleeps.diry[ballcnt];
                                                            sleeps.dirx[ballcnt]=-sleeps.dirx[ballcnt];
                                                                   }
                                                                     if (sleeps.timer2==10000) {   sleeps.timer2=0;
                                                           sleeps.diry[ballcnt]=-sleeps.diry[ballcnt];
                                                            sleeps.dirx[ballcnt]=-sleeps.dirx[ballcnt];
                                                                   }



                                                                   
                                               /*


                                        if (playerx>(sleeps.x[ballcnt]-(z*5))){   sleeps.dirx[ballcnt]=1;  spdy=0;           }
                                            if (playery<(sleeps.y[ballcnt]-(zv*5))){   sleeps.diry[ballcnt]=-1; spdx=0;             }

                                        
                                        if (playerx<(sleeps.x[ballcnt]-(z*5))){   sleeps.dirx[ballcnt]=-1; spdy=0;           }

                                        if (playery>(sleeps.y[ballcnt]-(zv*5))){   sleeps.diry[ballcnt]=1; spdx=0;         }

                                                       }

                                                       /* 
                                                      if (sleeps.timer>100) {
                                                                                  sleeps.timer=0;
                                                                        if (sleeps.diry[i]==1){sleeps.dirx[i]=0; }
                              if (sleeps.dirx[i]==1){  sleeps.diry[i]=0;   }

                                 if (sleeps.diry[i]==-1){sleeps.dirx[i]=0;}
                              if (sleeps.dirx[i]==-1){sleeps.diry[i]=0; }
                          
                                     }

                                   /*

                                             if(   sleeps.colyw!=0 ){
                                if (playery>(sleeps.y[ballcnt]-(zv*5))){
                                                                             if (playery-(sleeps.y[ballcnt]-(zv*5))<rt){        sleeps.dirx[ballcnt]=-1;          sleeps.diry[ballcnt]=0;

                                                   rectfill(surface, ballx,bally-(zv*5),ballx,bally-(zv*5),238);
          

                                         }   }

                                                         if (playery<(sleeps.y[ballcnt]-(zv*5))){
                                    
                                         if ((sleeps.y[ballcnt]-(zv*5))-playery<rt){                                        sleeps.dirx[ballcnt]=1;          sleeps.diry[ballcnt]=0;
                                                   rectfill(surface, ballx,bally-(zv*5),ballx,bally-(zv*5),238);
          

                                         }   }
                             
                                                                         }

                                                     if(   sleeps.colxw!=0 ){

                                                  if (playerx>(sleeps.x[ballcnt]-(z*5))){
                                    


                                         if (playerx-(sleeps.x[ballcnt]-(z*5))<rt){           sleeps.dirx2[ballcnt]=-1;           sleeps.diry2[ballcnt]=0;
                                                   rectfill(surface, ballx,bally-(zv*5),ballx,bally-(zv*5),238);
          
                                         } }

                                                         if (playerx<(sleeps.x[ballcnt]-(z*5))){
                                    
                                         if ((sleeps.x[ballcnt]-(z*5))-playerx<rt){      sleeps.dirx2[ballcnt]=1;         sleeps.diry2[ballcnt]=0;
                                                   rectfill(surface, ballx,bally-(zv*5),ballx,bally-(zv*5),238);
          

                                         } }



                                         }

                                               */



                                        /*
                                           if (sleeps.timer2>500){   sleeps.timer2=0;
                                             sleeps.dirx[ballcnt]=1;  if ( sleeps.x[ballcnt]>500){ sleeps.dirx[ballcnt]=-1; }
                                            sleeps.diry[ballcnt]=0; }
                                          */


                                        int coll=0;
                                        int colr=0;
                                        int colu=0;
                                        int cold=0;
                                int wall=4;
                                 int term=getpixel(map,0,2);
                          
                         for (int y=-2;y<2;y++){

                             colx=getpixel(collisionpad2,(sleeps.x[ballcnt])-6+xoffsetcorrec,(sleeps.y[ballcnt])+y+yoffsetcorrec);
                             //    putpixel(collisionpad2,ballinix[ballcnt]+60+2,balliniy[ballcnt]+240+y,0);

                      if (colx==wall){


                                     coll=1;


                      }

                             colx=getpixel(collisionpad2,(sleeps.x[ballcnt])+6+xoffsetcorrec,(sleeps.y[ballcnt])+y+yoffsetcorrec);
                               //         putpixel(collisionpad2,ballinix[ballcnt]+60+25,balliniy[ballcnt]+240+y,0);

                      if (colx==wall){


                                colr=1;
                                  }

                                 for (int x=-2;x<6;x++){

                             colx=getpixel(collisionpad2,(sleeps.x[ballcnt])+x+xoffsetcorrec,(sleeps.y[ballcnt])+6+yoffsetcorrec);
                         //                      putpixel(collisionpad2,ballinix[ballcnt]+60+x,balliniy[ballcnt]+17+240,0);

                      if (colx==wall){        cold=1;
              }
   }

                             colx=getpixel(collisionpad2,(sleeps.x[ballcnt])+x+xoffsetcorrec,(sleeps.y[ballcnt])-6+yoffsetcorrec);
                              //                  putpixel(collisionpad2,ballinix[ballcnt]+60+x,balliniy[ballcnt]-5+240,0);

                      if (colx==wall){   //  if (playery>(sleeps.y[ballcnt]-(zv*5)-add2)){
                                        colu=1;
        }
   }
                                          int ut2=0;
                                          int ut=0;
                                          int ut3=0;


              if (colr==1){  if (cold==0){ sleeps.dirx[ballcnt]=0; sleeps.diry[ballcnt]=-1;            }}
              if (coll==1){if (colu==0){ sleeps.dirx[ballcnt]=0; sleeps.diry[ballcnt]=1;   }}
              if (coll==1){if (cold==0){ sleeps.dirx[ballcnt]=0; sleeps.diry[ballcnt]=1;   }}
              if (cold==1){  if (colr==0){ sleeps.dirx[ballcnt]=1;  sleeps.diry[ballcnt]=0;    }}
              if (cold==1){  if (coll==0){sleeps.dirx[ballcnt]=1;  sleeps.diry[ballcnt]=0;    }}
                 if (colr==1){  if (colu==0){ sleeps.dirx[ballcnt]=0; sleeps.diry[ballcnt]=-1;          }}


                     if (colu==1){  if (colr==0) { sleeps.dirx[ballcnt]=-1;   sleeps.diry[ballcnt]=0;         }}
                       if (colu==1){  if (coll==0) {sleeps.dirx[ballcnt]=-1;   sleeps.diry[ballcnt]=0;         }}
          

                   if (colu==1){if (coll==1){ sleeps.dirx[ballcnt]=0; sleeps.diry[ballcnt]=1;          }}
                 

                   if (coll==1){if (colu==1){     sleeps.diry[ballcnt]=1; sleeps.dirx[ballcnt]=0;           }}
         


       //       if (cold==1){if (coll==1){   sleeps.diry[ballcnt]=0;       sleeps.dirx[ballcnt]=0;         }}
         //
          //    if (colr==1){if (cold==1){ sleeps.diry[ballcnt]=-1; sleeps.dirx[ballcnt]=0;           }}
           //   if (coll==1){if (cold==1){ sleeps.dirx[ballcnt]=1;  sleeps.diry[ballcnt]=0;         }}
             //    if (cold==1){if (colr==1){   sleeps.diry[ballcnt]=-1;     sleeps.dirx[ballcnt]=0;            }}


                      //   if (colu==1){if (colr==1){   sleeps.diry[ballcnt]=0; sleeps.dirx[ballcnt]=-1;        }}
      


     //         if (colr==1){if (colu==1){ sleeps.dirx[ballcnt]=-1; sleeps.diry[ballcnt]=0;          }}
      //        if (coll==1){if (colu==1){ sleeps.dirx[ballcnt]=1; sleeps.diry[ballcnt]=0;          }}







                  double ang;



                   int i1=2;
                   int j1=5;

                 int  sleepssprdir=0;
               if (sleeps.diry[ballcnt]==1){   sleeps.y[ballcnt]+=spdy;  sleepssprdir=27; }
               if (sleeps.diry[ballcnt]==-1){   sleeps.y[ballcnt]-=spdy;  sleepssprdir=42; }
               if (sleeps.dirx[ballcnt]==1){ sleeps.x[ballcnt]+=spdx; sleepssprdir=14;  }
               if (sleeps.dirx[ballcnt]==-1){  sleeps.x[ballcnt]-=spdx;   sleepssprdir=0;  }

               /*
               if (sleeps.diry2[ballcnt]==1){    sleeps.y[ballcnt]+=spdy2; }
               if (sleeps.diry2[ballcnt]==-1){   sleeps.y[ballcnt]-=spdy2;  }
                 if (sleeps.dirx2[ballcnt]==1){ sleeps.x[ballcnt]+=spdx2; }
               if (sleeps.dirx2[ballcnt]==-1){  sleeps.x[ballcnt]-=spdx2;  }
                 */
                 

           //     ballx=sleeps.x[ballcnt]-add-(z*5);

             //   bally=sleeps.y[ballcnt]-add2;


             //    rectfill(surface, (i*10)+ballx-add,vertical+bally,(i*10)+ballx-add+10,vertical+bally+10,5);
               //    circlefill(surface,ballinix[ballcnt]-(z*10)-add,balliniy[ballcnt]-(zv*10),3,0);
                 if (sleeps.dirx[ballcnt]==1){ ballframey=229;  slow3++; if (slow3>500){slow3=0;ballframex+=16;}if (ballframex>=48){ballframex=0;}; }
                        if (sleeps.dirx[ballcnt]==-1){ ballframey=173;  slow3++; if (slow3>500){slow3=0;ballframex+=16;}if (ballframex>=48){ballframex=0;}; }
                        /*  if (playerx==ballinix[ballcnt]-(z*10)){   if (bty[ballcnt]==1){     ballframey=189;   slow3++; if (slow3>50){slow3=0;ballframex+=16;}if (ballframex>=32){ballframex=0;};      }
                                if (bty[ballcnt]==-1){  ballframey=212;  slow3++; if (slow3>50){slow3=0;ballframex+=16;}if (ballframex>=32){ballframex=0;};           }         }
                        */
            //     blitnumtex(hits,ballx,bally-(zv*10),4);
//              masked_blit(walkingspr2,surface,269+ballframex,ballframey,ballx,bally-(zv*20),16,18);
                  blit(sprsheet,surface,sleepssprdir,193,sleeps.x[ballcnt]-add-(z*5),sleeps.y[ballcnt]-add2-(zv*5),14,12);






                  rectfill(collisionpad,sleeps.x[ballcnt]-add-(z*5),sleeps.y[ballcnt]-add2-(zv*5),sleeps.x[ballcnt]-add-(z*5)+15,sleeps.y[ballcnt]-add2-(zv*5)+15,93);

               
               /*              int colx=getpixel(collisionpad,playerx,playery);
                  if (colx==16) {init();}  */
          






                              k34=0;   k35=0;

           colx=getpixel(collisionpad,bulletx[lastbullet],bullety[lastbullet]-zvb);
//           putpixel(collisionpad,bulletx[lastbullet],bullety[lastbullet]-zvb,250);
     

         if (colx==93){
                                      explosx=bulletx[lastbullet]; explosy=bullety[lastbullet]-zvb;

         hits+=1;      k34=1;
            bullettrig=0;
                             }

                          if (k34==1){     addb=0; addb2=0;   k35=1; fri=0;   explos.timer=0;   explos.timer2=0;

           midiseek=0; k34=0;  k35=ballcnt; bulletx[lastbullet]=8000;  maptemp[ballcnt]=0;      mapfunc();
                            }





 

                        }
 






                  }




         //                   if (spider.health[i]<1){   }
            //    spider.y[enemicnt]-(zv*10)-add2; */

      //




                 //   explos.x[0]+=0.02;  explos.y[0]+=0.02;
                  //          if (explos.x[0]>10) { explos.x[0]=2;}
                   //        if (explos.y[0]>10)  { explos.y[0]=2;}
                     




























            //      rbx[i]=0;
              //    rby[i]=0;



                





             //       bullet2x[i]+=1*0.5;

                                 int u=lastbullet;;

                              k34=0;

                        /*      for (x=0;x<3;x++){
           colx=getpixel(collisionpad,bulletx[u],bullety[u]-zvb-12+x);
         if (colx==90){ hits+=1;   play_midi(grand,0); midi_seek(250);      k34=1;

            explosx=bulletx[u];     explosy=bullety[u]-zvb-13;
                     }    } */
           colx=getpixel(collisionpad,bulletx[u],bullety[u]-zvb);
         if (colx==93){



         hits+=1;        k34=1;
            bullettrig=0;    explosx=bulletx[u];     explosy=bullety[u]-zvb-13;





            }





                     /*


      if (maptemp[i]==1078){

                             enemicnt=i;


               //     if (spr.timer2>=4000) { spr.timer2=0;      }
                //    if (spr.timer2>=2000) {      spr.bulletx[i]=spr.x[i]+4;   if (playerx<spr.x[i]-(z*10)){   spr.bdirx[i]=1; }  if (playerx>spr.x[i]-(z*10)){   spr.bdirx[i]=-1; }
                      //   if (playery<spr.y[i]-(zv*10)){   spr.bdiry[i]=1; }if (playery>spr.y[i]-(zv*10)){   spr.bdiry[i]=-1; }

                        //                  spr.bullety[i]=spr.y[i]+4; }

                         // rbx[enemicnt]=-1;
                          //  rby[enemicnt]=1;
            if (spr.timer>=1000){   spr.dirx[enemicnt]=-spr.dirx[enemicnt];      }

            if (spr.timer>=2000){   spr.diry[enemicnt]=-spr.diry[enemicnt];     }
            if (spr.timer>2000){ spr.timer=0; }







//         rectfill(collisionpad,spr.x[enemicnt]-(z*10)-add,spr.y[enemicnt]-15-add2-(zv*10),spr.x[enemicnt]-(z*10)-add+15,spr.y[enemicnt]-15-add2-(zv*10)+20,5);





                 //              slowspid++;






                 //     if (slow2>20000){ slow2=0;  }



int ks=0;
int is=5;

int js=0;
int col=0;

// clear_to_color(sprites,4);





 //       rectfill(surface,enix[enemicnt]+(i*10),vertical-20-add2+eniy[enemicnt],enix[enemicnt]+((i+1)*10),vertical+10-add2+eniy[enemicnt],90);


                   rectfill(collisionpad,spr.x[enemicnt]-1-(z*20)-add,spr.y[enemicnt]-(zv*20)-add2,spr.x[enemicnt]-1-(z*20)-add+30,spr.y[enemicnt]-(zv*20)-add2+30,4);


 //         if (spr.dirx[enemicnt]>0){fry=0;}  if (spr.dirx[enemicnt]<0){fry=30;}



                          for (int x=-3;x<25;x++){

                    colx=getpixel(collisionpad2,spr.x[enemicnt]+120+x,spr.y[enemicnt]+480-5);
                                           if (colx==4){


          spr.diry[enemicnt]=1;   }

                    colx=getpixel(collisionpad2,spr.x[enemicnt]+120+x,spr.y[enemicnt]+480+35);
                                           if (colx==4){


         spr.diry[enemicnt]=-1;   }

                 }





                 for (int y=-3;y<25;y++){

                    colx=getpixel(collisionpad2,spr.x[enemicnt]+35+120,y+spr.y[enemicnt]+480);
                                           if (colx==4){


          spr.dirx[enemicnt]=-1;   }

                    colx=getpixel(collisionpad2,spr.x[enemicnt]-1+120,y+spr.y[enemicnt]+480);
                                           if (colx==4){


         spr.dirx[enemicnt]=1;   }

                 }




                         if (spr.diry[enemicnt]>0){spr.y[enemicnt]+=1*0.3;              }
                         if (spr.diry[enemicnt]<0){spr.y[enemicnt]-=1*0.3;              }
                         if (spr.dirx[enemicnt]>0){spr.x[enemicnt]+=1*0.3;             }
                         if (spr.dirx[enemicnt]<0){spr.x[enemicnt]-=1*0.3;             }









           


                masked_blit(sprsheet,surface,0,110,spr.x[enemicnt]-1-(z*20)-add,spr.y[enemicnt]-(zv*20)-add2,30,30);
     //    rect(surface,spr.x[enemicnt]-1-(z*10)-add,spr.y[enemicnt]-(zv*10)-add2,spr.x[enemicnt]-1-(z*10)-add+30,spr.y[enemicnt]-(zv*10)-add2+30,0);
    //      rect(surface,spr.x[enemicnt]-1-(z*10)-add+10,spr.y[enemicnt]-(zv*10)-add2+10,spr.x[enemicnt]-1-(z*10)-add+20,spr.y[enemicnt]-(zv*10)-add2+20,228);

//         draw_sprite(surface,sprite,);


               /*      if (spr.bdirx[i]==1){

                   spr.bulletx[i]-=1;        }
                      if (spr.bdirx[i]==-1){
                   spr.bulletx[i]+=1;            }
                      if (spr.bdiry[i]==1){
                   spr.bullety[i]-=1;}
                         if (spr.bdiry[i]==-1){
                   spr.bullety[i]+=1;}
                 */



//  }








 //     }



             //     if (explos.timer>50)      { }







        //   if (hits>2){copymapchunk();}

 //       textprintf_ex(surface,font,160,0,250,0,"%i",hits);

// blitnum(10,10,8,0);



  explos.timer++;             explos.timer2++;


           if (explos.timer2>=10){explos.timer2=0;  fri+=13;if (fri>=33){fri=0;}  }


                  if (explos.timer<50) {   sound(explos.timer2*100);

                                     masked_blit( sprsheet,surface,126+fri,115,explosx-(addb*5)-add,explosy-(addb2*5)-add2,10, 10);
 

                    }

         if (playerhealth<1){playerhealth=3; init();}
                colx=getpixel(collisionpad,playerx-add,playery-add2);
          //     
                    if (colx==93){ playerhealth-=1;mapfunc(); }
                
                    if (colx==134){playerhealth-=1;mapfunc(); }
                               if (colx==84){playerhealth-=1;mapfunc(); }






}



int keyboard(){


             tplayer=1;
                 t2player=1;

           tx2=1;
           tx=1;

   //           if (key[KEY_LCONTROL]) {   t2player=0;    tplayer=0;   tx=0; tx2=0; }




         for (int x=0;x<10;x++){




                        colx=getpixel(collisionpad,playerx+x-add,playery+15-add2);
          //            putpixel(surface,playerx+x,playery+10,238);
           

                if (colx==4){ tplayer=0; }
                         if (colx==21){init(); }          



              colx=getpixel(collisionpad,playerx+x-add,playery-15-add2);
        //       putpixel(surface,playerx+x,playery-10,238);
                      
             if (colx==4){ t2player=0; }
                              if (colx==21){init(); }          



                                          }





           for (int y=0;y<15;y++){


       //       colx=getpixel(collisionpad,playerx,playery+y);
         //            if (colx==90){ init(); midiseek=-100;   play_midi(grand,0);  midi_seek(160);     }






               colx=getpixel(collisionpad,playerx+10-add,playery+y-add2);

             if (colx==4){tx=0; }

                   if (colx==21){init(); }          

              colx=getpixel(collisionpad,playerx-add,playery+y-add2);

             if (colx==4){tx2=0;}
                     if (colx==21){init(); }          


                                   }
















                                       if (bullettimer==0){


                                                  //  bullety[erasure]=-100;

                                     bullettimer=10;         bullettrig=1;     }
                 if (key[KEY_LCONTROL]) {
                                                         bullettimer--;

                           sound(bullettimer*20 );




                                           //    play_midi(grand,0); midiseek=0; midi_seek(40);
                                                        if (bullettrig==1){



                                   














                                                              //      play_midi(grand,0); midiseek=0; midi_seek(80);

                                                  }

                                                  }



          //     if (z==32){z=0;add+=32;}


       //       if (z>300){z=0;  level++;      init();}




             
          //     if (plus>4950){plus=4800;playerx=40;playery=170;z=0;}



//          if (key[KEY_DOWN]) {plus+=t; frame=frame+400;   if (frame>800){frame=0; } }

                  //        if (jmptimer<0){jmptrig=2;jmptimer=0;}
















                    //   if (jmptimer>50){  jmptrig=0; jmptimer=50;  }
                     //   if (jmptimer<50){  jmptrig=1;  }
         /*

             if (key[KEY_UP]) { jmptimer=0; dur=0;  jmptimer2+=0.2;   downtrig=1;  acce+=0.01; jmptrig=1;


                      if (jmptimer2>50){downtrig=0;}  }






   if (jmptrig==1){

                   //  if (acce>3){acce=3;}
                                dur++;
                                dur2=0;
                             //    tx=tx*1.1;  tx2=tx2*1.1;
                            acce-=0.180;
                                jmptimer+=0.3;

                             timer2++;
                              if (acce<0){acce=0; jmptrig=0; downtrig=0;     }

                              if (downtrig==1){

                              playery=playery-((t2player)*(acce/21));
                                             }


                                             }
                                      else {
                                             acce2+=1.0;
                                             if (acce2>5){acce2=5;}




                                             }
               if (key[KEY_UP]==0){jmptimer=0;dur2=1;  framey=133;    }

                   if (key[KEY_UP]==0) { }
                */
  //  if (plus>9400){plus==0;}

                     int collided=0;

      if ((sin(angcor)+cos(angcor))/3>0){
       if (tx==1){ collided=0;   playerx+=((sin(angcor)+cos(angcor))/3)*accelx;   }
                      }
                         if ((sin(angcor)+cos(angcor))/3<0){
       if (tx2==1){collided=0;    playerx+=((sin(angcor)+cos(angcor))/3)*accelx;   }
                      }


        if ((-sin(angcor)+cos(angcor))/3>0){

         if (tplayer==1){  collided=0;
                  playery+=rotateycor=((-sin(angcor)+cos(angcor))/3)*accelx;
                                          } }

           if ((-sin(angcor)+cos(angcor))/3<0){

         if (t2player==1){   collided=0;
                  playery+=rotateycor=((-sin(angcor)+cos(angcor))/3)*accelx;
                                          } }
     


                                          
                   //  playerx--;
        //     if (tx==0){ accelx2=0.2;}
         //       if (tplayer==0){accely=0.2;}
          //         if (tx2==0){ accelx=0.2;}
           //     if (t2player==0){accely2=0.2;}


             if (accely>1000){accely=1000;}

             if (accelx>2.5){accelx=2.5;}
              accelx-=0.05;
                   accely-=2;
         
            if (accelx<=0){accelx=0;      }
              if (accely<=0){accely=0;      }

     //     if (tx==0){ accelx=0;       }

     //    if (tx2==0){ accelx2=0;  }
      //    if (t2player==0){accely2=0;    }
       //   if (tplayer==0){ accely=0;   }

                           double oldplayerx=playerx;
         //       if (tx==1){        playerx+=((((((playerx)*rotatexcor))+(((playery)*rotateycor))))/1000)*accelx;   }
          //       if (tx2==1){        playerx+=((((((playerx)*rotatexcor))+(((playery)*rotateycor))))/1000)*accelx2;  }


          //     if (tplayer==1){        playery+=(((((((playery)*rotatexcor))-(((playerx)*rotateycor)))))/1000)*accely2;   }
           //     if (t2player==1){        playery+=(((((((playery)*rotatexcor))-(((playerx)*rotateycor)))))/1000)*accely;  }

          

                      t=320;
               t2=320;













       //         playerx=(playerx)+(((((playerx)*rotatex)+((playery)*rotatey))))/1000;
        //           playery=(playery)+(((((playerx)*rotatex)-((playery)*rotatey))))/1000;



               int releasel=1;
               int releaser=1;


               if (timerb<0){timerb=0;}

           if (playerx>230) {
                                          playerx-=1;    add+=1; if (add>5){add=0;  plus=(int)plus+1;z++; addb++; } }
                                    if (playerx<210) {
                           playerx+=1;   add-=1;bgaddh++;  if (add<0)   {add=5;     plus=(int)plus-1;z--; addb--;  } }
                    if (playery>170){ zvb++; playery-=1;                       add2+=1;  if (add2>5){ add2=0;   plus+=maplenght+1;zv=zv+1;addb2++; }  }
                    if (playery<160){ zvb--;  playery+=1;    add2-=1;  if (add2<0){ add2=5;    plus-=maplenght+1;zv=zv-1;    addb2--;   }  }


                              bulletwarp+=bulletwapd*10;
                                                      if (bulletwarp>180) {bulletwapd=-bulletwapd; }
                                                          if (bulletwarp<0) {bulletwapd=-bulletwapd; }
                                                


                                        int thickx=0;
                                        int thicky=0;

                                   //      set_keyboard_rate(10,2);

            //     double rotatex=(sin(ang)-cos(ang));
            //     double rotatey=(-sin(ang)+cos(ang));





         if (key[KEY_LEFT]) {                  angcor-=0.05;

                               if (collided==0){   ang-=0.05; }


         faced=-1;      framey=172; slow++; if (slow>10){slow=0;        framex+=16;          }

        if (framex>175){  framex=155;}



                                                           }


           //              if (z>8000){z=0;}
    if (key[KEY_RIGHT]) {   releaser=0; faced=1;  if (collided==0){   ang+=0.05; }    angcor+=0.05;
      framey=230;

                 slow++; if (slow>10){slow=0;    framex+=16;



                 }                 if (framex>=201){framex=155;}


                  }


                  if (key[KEY_UP]){            faced=2;        accelx+=0.15;    accely+=3;



         framey=210;   slow++; if (slow>10){slow=0;        framex+=16;          }                       if (framex>175){framex=155;}
      }


         if (key[KEY_DOWN]){       faced=-2;                 accelx-=0.15;     accely-=3;



         framey=191;  slow++; if (slow>10){slow=0;        framex+=16;          }                       if (framex>175){framex=155;}
     }
                                                                     bullethit=1;




                      if (key[43]) {    if (key[42]){     faced=-4;}      }
 


                                     

                                                              if (key[41]) {   if (key[42]){     faced=4;}         }



                                                              if (key[45]){

                                                              if(key[41]) {  faced=3;    } if (key[43]) {  faced=-3;  }            }




                                             //  if(bulletcnt>50){bulletcnt=0;bullettrig=0;}














                               if (faced==1){   bulletx[bulletcnt]=(playerx+15);     bulletdirx[bulletcnt]=0.1; warpy=sin(bulletwarp)/5; warpx=0;  bulletdiry[bulletcnt]=0; thickx=1;thicky=0;         }
                                                 if (faced==-1){   bulletx[bulletcnt]=(playerx-10);     bulletdirx[bulletcnt]=-0.1;  warpy=sin(bulletwarp)/5; warpx=0; bulletdiry[bulletcnt]=0; thickx=1;thicky=0; }
                                                  if (faced==2){     bulletdirx[bulletcnt]=0;   bulletdiry[bulletcnt]=-0.1;warpx=sin(bulletwarp)/5; warpy=0;  thickx=0;thicky=1;}
                                                   if (faced==-2){      bulletdirx[bulletcnt]=0;  bulletdiry[bulletcnt]=0.1;warpx=sin(bulletwarp)/5; warpy=0;  thickx=0;thicky=1;}







                                                                 if (faced==3){      bulletdirx[bulletcnt]=-0.1;  bulletdiry[bulletcnt]=-0.1;warpx=sin(bulletwarp)/5; warpy=0;  thickx=1;thicky=1;}
                                                          if (faced==-3){      bulletdirx[bulletcnt]=0.1;  bulletdiry[bulletcnt]=-0.1;warpx=sin(bulletwarp)/5; warpy=0;  thickx=1;thicky=1;}
                                                         if (faced==4){      bulletdirx[bulletcnt]=-0.1;  bulletdiry[bulletcnt]=0.1;warpx=sin(bulletwarp)/5; warpy=0;  thickx=1;thicky=1;}
                                                          if (faced==-4){      bulletdirx[bulletcnt]=0.1;  bulletdiry[bulletcnt]=0.1;warpx=sin(bulletwarp)/5; warpy=0;  thickx=1;thicky=1;}

                                            

           bullethit=0  ;



                                                double bdirx;
                                                  double bdiry;
                                   if (bullettrig==1){     bullettrig=0;



                                            bullety[bulletcnt]=((int)((playery))+zvb);
                                             bulletx[bulletcnt]=((int)((playerx)));







                                                      }

                                               bdirx=(((sin(angcor)+cos(angcor))/10));
                                               bdiry=(((-sin(angcor)+cos(angcor))/10));

                  for (int ib=0;ib<100;ib+=1){

                                               bulletcnt=bulletcnt+1;

                                               if(bulletcnt>100){bulletcnt=0;}
                                   

                          // if (bulleti>400){bulleti=0;}
                    //   if(timerb>300){timerb=300;}

                                 bulletx[ib]= bulletx[ib]+(bdirx*50)+warpx;



                                 bullety[ib]= bullety[ib]+(bdiry*50)+warpy;

                            //    rect(screen,bulletx[i],bullety[i]-(zvb),bulletx[i]+thickx+1,bullety[i]-(zvb)+thicky+1,2);


                                         rectfill(surface,bulletx[ib],bullety[ib]-zvb,bulletx[ib]+1,bullety[ib]+1-zvb,228);
                                     //    blit(cubespr2,screen,bulletx[ib],bullety[ib]-(zvb),5,5);
                        
                                   int colx;
                                                 //  putpixel(screen,bulletx[ib],bullety[ib],250);
                                              colx=getpixel(collisionpad,bulletx[ib],bullety[ib]-zvb);
                                      if(colx==4){  lastbullet=ib;        }
                                           if(colx==93){  lastbullet=ib;       }
                                             if(colx==84){  lastbullet=ib;       }


                                                           }
                    
                                          if(bulletx[bulletcnt]<=20){bulletx[bulletcnt]=8000;bullety[bulletcnt]=8000;  }

                                        if(bulletx[bulletcnt]>=210){bulletx[bulletcnt]=8000;bullety[bulletcnt]=8000;  }


                                       if(bullety[bulletcnt]>=230){bulletx[bulletcnt]=8000;bullety[bulletcnt]=8000;  }


                                 if(bullety[bulletcnt]<=10){bulletx[bulletcnt]=playerx;bullety[bulletcnt]=8000;  }
                                   if   (bulletcnt>=20){         for (int i=bulletcnt-20;i<bulletcnt;i++){ bulletx[i]=8000; bullety[i]=8000;} }


                   //    bulletx[bulletcnt]=playerx;






               jmpbypass++;
                   //  if (jmpbypass>200){jmptrig=0;jmpbypass=0; }
                    // jmptimer--;


                   //    if (jmptimer<100){jmptrig=0;}
                                 if (bgscroly<0){bgscroly=100;}



               //     midis++;if (midis>30){midis=0;stop_midi();  play_midi(grand,0);midi_seek(34);}


                               //    if (tplayer>0){    playery+=(acce2/3);};
                                     // acce-=0.0001;


                           //   bgscroly=bgscroly-(t/160);

                               
                           if (accelx!=0){   sound(accely/10);  }

      ti3++; if (ti3>20){ti3=0;    sound(0);   }
// stop_midi();                 }


//     spritefunction();

   

}








void timek(void){




tick++;

};
END_OF_FUNCTION(timek)

int main(int argc, char *argv[]) {

   LOCK_FUNCTION(timek);
   LOCK_VARIABLE(t);

     jmptimer=0;
//    enemii.x=1;
 //     enemii.y=1;
  //    enemiposx=1;
   //    enemiposy=1;
       enemicnt=0;

   int *dots;
   if (allegro_init() != 0)
      return 1;

  // if (argc != 2) {
    //  allegro_message("Usage: 'exbitmap filename.[bmp|lbm|pcx|tga]'\n");
    //  return 1;
  // }
//install_timer();
   install_keyboard();

         if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
      allegro_message("Error initialising sound system\n%s\n", allegro_error);
      return 1;
   }
         // drawing_mode(5, NULL,1,0);
   if (set_gfx_mode(GFX_AUTODETECT, 320, 200, 0, 0) != 0) {
      if (set_gfx_mode(GFX_SAFE, 320, 200, 0, 0) != 0) {
       set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
 return 1;
      }   }

     //  set_color_depth(8);
   set_write_alpha_blender();
 collisionpad=create_bitmap(480,600);
  collisionpad2=create_bitmap(4400,1500);



       //   solid_mode();
   sprsheet=load_bitmap("mapbit.bmp",the_palette);
      map=load_bitmap("map.bmp",the_palette2);

 //  grand=load_midi("music.mid");

               font1=load_bitmap("fonts.bmp",the_palette);
//      levelbg=load_bitmap("levbg1.bmp",the_palette);
     surface=create_bitmap(480,600);
    cubespr=create_bitmap(20,20);

//           levelbg2=create_bitmap(320,240);
//       levelbg1=load_bitmap("bgsprts.bmp",the_palette2);
      walkingspr2=load_bitmap("walking.bmp",the_palette2);

  int x,y,col,col2;
//    for (int i=0;i<2400000;i++){
//    x++; if(x>4000){x=0;y++;}
 //   if (y>240){y=0;}
//     col2=getpixel(levelbg1,0,0);

  //  col=getpixel(levelbg1,x,y);

 //   if (col!=col2){
 //  putpixel(levelbg2,x,y,col);

   //            }





  //    if (col==col2){
//   putpixel(levelbg2,x,y,256);

    //           }

  //     }

//     x=0;y=0;





  /*



  for (int i=0;i<840000;i++){
   x++;if(x>1024){y++;x=0;}
   if (y>768){y=0;}
   col2=getpixel(walkingspr2,0,0);

   col=getpixel(walkingspr2,x,y);
    if (col!=col2){
   putpixel(walkingspr,x,y,col);

               }





      if (col==col2){
   putpixel(walkingspr,x,y,256);

               }







  }


    */




//    mapfunc();
 set_palette(the_palette2);
//    set_alpha_blender();
  //  sprites=create_bitmap(320,240);



int i;
i=1;
    z=0;
    plus=4800;
bgscroly=100;
         framex=155;
           framey=210;
       init();
        install_int( timek,3);

     while (i!=0){





              
            if (tick>1){     clear_to_color(surface,0);                    blit(sprsheet,surface,53+(playerhealth*9),36,150,60,10,10);


 tick=0; // cube();
          keyboard();          mapfunc();    blittingtosprite();

                          }    poll_keyboard();
                   /*
                   float x1=0;
                     int x2=0;
                     int y=1;
                     int x=1;

                       double j2=1;;

                //   clear_to_color(surface,110);

                      //    i=0;
                          for (int j=0;j<240;j+=1){
                        for (int i=0;i<240;i+=1){
                                             x2=i;

                       x1=((x2)*(j));

                        x=x1+1;

                          int col=getpixel(surface,(i+80),(j));
                              putpixel(screen,(x1)+160,j/2,col);


                          }
                          }



                     */
//      blit(collisionpad,surface,0,0,0,0,320,240);

   blit(surface,screen,60,60,0,0,320,240);

     if (key[KEY_ESC]){ sound(0); return 0;}

    }


 destroy_bitmap(screen);

   
   readkey();
   return 0;


END_OF_MAIN()
}
