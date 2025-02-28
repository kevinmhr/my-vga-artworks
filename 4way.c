

#include <allegro.h>
#include <math.h>
#include "map.c"
char *bitmapbuffer;
 int z,zv;
    int k34=0;
int textlenght=2;
int midis=0;
int fry;
int frx=328;
int zvb;
int tuy,tuu,fri;
int add=0;
 int ballcnt=0;
 int explostrig=0;
int erasure;
int bulletcnt=0;
int timer5=0;
int add2=0;
int slowspid=0;
int spidtimer=0;
int hits=0;
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
int bullethit=1;
   int midiseek;
       int timer2;
  double bulletx[500];
  double bullety[500];
int d;

 double bulletdirx[500];
  double bulletdiry[500];
int bullettimer=20;
    int bullettrig;
         int downtrig;


int pickupcolor;
double curenemix;
int roll=0;
  int jmpbypass;
int keytrig=0;
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
int t2player;
int x2;
int bulletspd=0;
int ti;
int ti2;
int ti3=1;
int ti4;
int colx,coly;
double playerx=110;
double playery=150;
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
double bulletx[20000];
double bullety[20000];
double x[20000];
double y[20000];
int dirx[20000];
int diry[20000];
int bdirx[20000];
int bdiry[20000];
int timer;
int timer2;

}OBJECT;
OBJECT spider;
OBJECT sleeps;
OBJECT spr;
OBJECT explos;
         BITMAP *levelbg;
          BITMAP *levelbg1;
     BITMAP *levelbg2;
   BITMAP *collisionpad;
      BITMAP *collisionpad2;
    BITMAP *sprite;
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
  MIDI *grand;
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

int maptemp[20000];

const int corebreak=2060;

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

integ=((int)tex[i])-97;

//integ=*(fontsize);

if (integ>-1){   if (integ<127){

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
   col=getpixel(font1,(integ)*(7)+x-1,y-1);
   if (col==255){
   putpixel(surface,(i*fontsize)+x+textplacex,textplacey+y,col);

               }

                 }








     }







              }  }

                               }




 }


int copymapchunk(){
int x=0;
int y=0;

for (int i=0;i<200000;i++){
x++; if (x>32){y++;}
if (y>24){return 0;}
if (shrine[i]>0){
maptemp[i+50000]=shrine[x*y];
                 }

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

int i=-65;int y=10;
for (int k=0;k<20000;k++){

i+=1; if (i>(351-65)){i=-65;y+=10;}
//if (y>320){y=0;}
if (maptemp[k]>2000){ rectfill(collisionpad2,(i*10),y,(i*10)+10,y+10,4);}
}
 i=0;
 y=0;
for (int k=0;k<20000;k++){
i+=1; if (i>256+32+65){i=0;y+=10;}
spider.x[k]=0;

if (maptemp[k]==1077){ numtogo++; spider.x[k]=(i*10);   spider.bdiry[k]=0;  spider.bdirx[k]=0;
spider.y[k]=y-245;
            }

spr.x[k]=0;
if (maptemp[k]==1078){spr.x[k]=(i*10);   spr.bdiry[k]=0;  spr.bdirx[k]=0;
spr.y[k]=y-245;
            }


            }
i=0; y=0;
for (int k=0;k<20000;k++){
i+=1; if (i>256+97){i=0;y+=10;}
sleeps.dirx[k]=-1;  sleeps.diry[k]=1;

sleeps.x[k]=0;
if (maptemp[k]==1043){sleeps.x[k]=(i*10);
sleeps.y[k]=y-240;
            }


}





}
int blittingtosprite(){
int i=0;
int j=0;
int col=0;
// clear_to_color(sprites,4);
for (int k=0;k<400;k++){


i++;if (i>16){i=0;j++;}
if (j>16){j=0;}
col=getpixel(walkingspr2,i+framex,j+framey);
if (col!=getpixel(walkingspr2,1,1)){
putpixel(surface,i+playerx,j+playery+3,col);
 //   rectfill(collisionpad,2+playerx,playery+2,i+playerx,j+playery,13);

    }


}
}
int othersblittingtosprite(int otherposx;int otherposy;){



}
int init(){
//          play_midi(grand,0);
     //  ballx=320;
     //  bally=100;
         explos.timer=0;
           maplenght=351-65;
        d=0;
          ti3=0;
          bgscrolx=0;
          z=0;
         explos.timer=2000;
         zv=0;
         add2=0;
         add=0;
         acce=1;
         jmptimer=0;
//    enemii.x=1;
 //     enemii.y=1;

      enemiposx=1;
       enemiposy=1;
       enemicnt=0;
      i=1;
    plus=8454;
playerx=10;
 playery=150;

  if (level>3){level=1;}
  if (level==1){

  for (int x=1;x<20000;x++){

 maptemp[x]=map1[x];


               }


               levelbg=load_bitmap("levbg1.bmp",the_palette);     }
        clear_to_color(collisionpad2,237);

     collisionimplant();

   if (level==2){
  for (int x=0;x<7144;x++){

 maptemp[x]=map1[x];

               }    levelbg=load_bitmap("levbg2.bmp",the_palette);       }

   if (level==3){
  for (int x=0;x<7144;x++){

 maptemp[x]=map1[x];

               }    levelbg=load_bitmap("spritesh.bmp",the_palette);       }
               

  for (int x=0;x<20000;x++){
    spider.dirx[x]=1;  spider.diry[x]=-1;
    spr.dirx[x]=1;  spr.diry[x]=-1;
    sleeps.dirx[x]=1; sleeps.diry[x]=0;
    spider.bdirx[x]=1;  spider.bdiry[x]=1;
    spider.bulletx[x]=spider.x[x];
    spider.bullety[x]=spider.y[x];


 }
//   play_midi(grand,0);
}


int mapfunc(){










        bulletspd=0;









                   int  enemif;
                   

                  int enitx=1;
                  int enitx2=1;




//     clear_to_color(levelbg,0);


  clear_to_color(collisionpad,1);

  
  clear_to_color(surface,110);


    //   blit(collisionpad2,surface,(z*10+add)+60,230+((zv))*10+add2,0,0,320,240);


  //   blit(levelbg2,levelbg3,0,150,0,0,105,65);
    //       draw_sprite(surface,levelbg3,bgscrolx/2,bgscroly);

         //    blit(levelbg,screen,0,0,0,0,320,240);




              //      if (vertical>220){vertical=10;}

               int    i=-65;







         int  vertical=10-add2;




                  d=100;



           for (int k=0;k<(6500);k++){


                 int mapb=k+plus;
                 int k=mapb;

            maplenght=351-65;
                 i+=1;
          if (i>maplenght){vertical=vertical+10;i=-65;            }


            slow2++;
      //      if (key[KEY_LEFT]){ add-=1;   }
      //     if (key[KEY_LEFT]){ add+=1;   }
      //     if (add>10){add=0;}
      //     if (add<0){add=10;}

  //                d++;
//                     if (z<0){z=0;}


                      // if (z>320){z=0;}
              //    vertical=vertical+10;






/*
 tuy++;

 if (tuy>200000){    if (frx>=100){frx=0;}
 frx=frx+25;tuy=0; }
*/
int tx,ty;







        if (maptemp[k]==1900) {
         rectfill(collisionpad,(i*10),vertical+1-add2,((i+2)*10),vertical+11-add2,254); }
  //    if (enemicnt>9000){enemicnt=0;}

           //   if (enemicnt>20){enemicnt=0;}


/*    if (key[KEY_UP]) {


       colx=getpixel(collisionpad,playerx+10,playery);
       if (colx==98){  levelbg=create_bitmap(1000,320); clear_to_color(levelbg,0);   plus=9000;     maplenght=32;              }

                                       }  */









 if (frx>=317){frx=287;}
 if (tuu>50000){  frx=frx+10;
 tuu=0; }
tuu++;



                   if (maptemp[k]==1055) {
                     masked_blit(levelbg1,surface,0,150,(i*10)-add,vertical-20,100,80);
                    }


     if (maptemp[k]==1054) {
                     masked_blit(levelbg1,surface,80,100,(i*10)-add,vertical-20,60,40);
                    }







        if (maptemp[k]==1033) {

       rectfill(collisionpad,(i*10)-add,vertical,((i+1)*10)-add,vertical+10,5);
        //  rectfill(surface,(i*10)-add,vertical,((i+1)*10)-add,vertical+10,5);




int ks=0;
int is=0;
int col=0;
int js=0;



      masked_blit(walkingspr2,surface,frx,14,(i*10)-add,vertical,12,9);





}


























           if (maptemp[k]>=2000){
              int x,y;
              double x1,y1;
              x=maptemp[k];
              x1=(int)(x/100);
              y=x-(x1*100);
       //   if(maptemp[k]==2060)    {y=66;x1=19;}
       masked_blit( sprsheet,surface,x1-10,y-10,((i*10))-add,vertical ,10, 10);

            rectfill(collisionpad,(i*10)-add,vertical,((i+1)*10)-add,vertical+11,4);
                    //    rectfill(collisionpad2,(i*10)-add+320,vertical-add2,((i+1)*10)-add+320,vertical+10,4);

              //           rectfill(surface,(i*10)-add,vertical-add2,((i+1)*10)-add,vertical+10,4);




                        }





              if (maptemp[k]==1807) {
          //  levelbg3=create_bitmap(60,30);
          masked_blit(levelbg1,surface,220,145,(i*10)-add,vertical-20,20,20);
           rectfill(collisionpad,(i*10)-add+10,vertical-20,(i*10)-add+25,vertical,4);
         
          }



                   if (maptemp[k]==1800) {
          //  levelbg3=create_bitmap(60,30);
          masked_blit(levelbg1,surface,180,150,(i*10)-add,vertical-20,20,20);
                 rectfill(collisionpad,(i*10)-add,vertical-20,(i*10)-add+25,vertical,4);
         
               rectfill(collisionpad,(i*10)-add,vertical-20,(i*10)-add+40,vertical-20+30,45);
               int colx=getpixel(collisionpad,playerx,playery);
               if (colx==45){
                         blittext((i*10)-add,vertical-40,"enter the journal ",8,20,0);

                             }

                             rectfill(collisionpad,(i*10)-add,vertical-20,(i*10)-add+25,vertical,4);
         

                            }



        if (maptemp[k]==1803) {
        //    levelbg3=create_bitmap(30,60);
      masked_blit(levelbg1,surface,49,89,(i*10)-add,vertical-35,30,60);
     rectfill(collisionpad,(i*10)-add,vertical-35,(i*10)-add+10,vertical-35+20,98);
      //  rectfill(surface,(i*10)-add,vertical-add2-35,(i*10)-add+10,vertical-add2-35+20,98);






                            }








    if (maptemp[k]==1801) {

          masked_blit(levelbg1,surface,2,80,((((i-1)*10))-add)*2,vertical-20,40,25);








                            }













                       colx=getpixel(collisionpad,playerx+2,playery+20);
                       if (colx==5){maptemp[k]=0; midiseek=0;   play_midi(grand,0);midi_seek(5); mapfunc(); }
              /*      if (bulletx>10){
               colx=getpixel(collisionpad,bulletx,bullety);
               if (colx!=1){ maptemp[k]=0; bullettrig=0; midiseek=0;  play_midi(grand,0);midi_seek(40); mapfunc();  }

        }

          */





























 }






midiseek++; if(midiseek>17){midiseek=0;
stop_midi();
              }






  // crossball();

        spr.timer++;

        spr.timer2++;
        spider.timer++;

        spider.timer2++;
      int  bulleti;
int i2=0;
int j2=0;
for (int i=0;i<20000;i++){


               int ballcnt=i;

                    sleeps.timer++;


      if (maptemp[i]==1043) {
                    //  textprintf_ex(surface,font,10,10,250,0,"%i",k);

            
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

                           if (sleeps.timer>=100) {   sleeps.timer=0;
                         if (playerx<sleeps.x[ballcnt]-(z*10)){     sleeps.dirx[ballcnt]=-1;     }
                             if (playerx>sleeps.x[ballcnt]-(z*10)){     sleeps.dirx[ballcnt]=1;     }
                                   if (playery<sleeps.y[ballcnt]-(zv*10)){     sleeps.diry[ballcnt]=-1;     }
                             if (playery>sleeps.y[ballcnt]-(zv*10)){     sleeps.diry[ballcnt]=1;     }


                                                               }








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

                         for (int y=-5;y<15;y++){

                             colx=getpixel(collisionpad2,sleeps.x[ballcnt]+60+2,sleeps.y[ballcnt]+240+y);
                             //    putpixel(collisionpad2,ballinix[ballcnt]+60+2,balliniy[ballcnt]+240+y,0);

                      if (colx==4){sleeps.dirx[ballcnt]=1;   }

                             colx=getpixel(collisionpad2,sleeps.x[ballcnt]+60+25,sleeps.y[ballcnt]+240+y);
                               //         putpixel(collisionpad2,ballinix[ballcnt]+60+25,balliniy[ballcnt]+240+y,0);

                      if (colx==4){sleeps.dirx[ballcnt]=-1;   }

                                        }
                                 for (int x=5;x<25;x++){

                             colx=getpixel(collisionpad2,sleeps.x[ballcnt]+60+x,sleeps.y[ballcnt]+240+10);
                         //                      putpixel(collisionpad2,ballinix[ballcnt]+60+x,balliniy[ballcnt]+17+240,0);

                      if (colx==4){sleeps.diry[ballcnt]=-1;   }

                             colx=getpixel(collisionpad2,sleeps.x[ballcnt]+60+x,sleeps.y[ballcnt]+240-5);
                              //                  putpixel(collisionpad2,ballinix[ballcnt]+60+x,balliniy[ballcnt]-5+240,0);

                      if (colx==4){sleeps.diry[ballcnt]=1;   }
             
                                                  }

               if (sleeps.dirx[ballcnt]==1){    sleeps.x[ballcnt]+=0.2;  }
               if (sleeps.dirx[ballcnt]==-1){   sleeps.x[ballcnt]-=0.2;  }
               if (sleeps.diry[ballcnt]==1){    sleeps.y[ballcnt]+=0.2;  }
               if (sleeps.diry[ballcnt]==-1){   sleeps.y[ballcnt]-=0.2;  }


              int  ballx=sleeps.x[ballcnt]-add-(z*10);

              int  bally=sleeps.y[ballcnt]-add2;


             //    rectfill(surface, (i*10)+ballx-add,vertical+bally,(i*10)+ballx-add+10,vertical+bally+10,5);
               //    circlefill(surface,ballinix[ballcnt]-(z*10)-add,balliniy[ballcnt]-(zv*10),3,0);
                 if (sleeps.dirx[ballcnt]==1){ ballframey=229;  slow3++; if (slow3>500){slow3=0;ballframex+=16;}if (ballframex>=48){ballframex=0;}; }
                        if (sleeps.dirx[ballcnt]==-1){ ballframey=173;  slow3++; if (slow3>500){slow3=0;ballframex+=16;}if (ballframex>=48){ballframex=0;}; }
                        /*  if (playerx==ballinix[ballcnt]-(z*10)){   if (bty[ballcnt]==1){     ballframey=189;   slow3++; if (slow3>50){slow3=0;ballframex+=16;}if (ballframex>=32){ballframex=0;};      }
                                if (bty[ballcnt]==-1){  ballframey=212;  slow3++; if (slow3>50){slow3=0;ballframex+=16;}if (ballframex>=32){ballframex=0;};           }         }
                        */
                  int colx=getpixel(collisionpad,playerx,playery);
                  if (colx==16) {init();}
               masked_blit(walkingspr2,surface,269+ballframex,ballframey,ballx,bally-(zv*10),16,18);
                  rectfill(collisionpad,ballx-5,bally-(zv*10)-5,ballx+15,bally-(zv*10)+15,16);
                   
               

 }

















            //      rbx[i]=0;
              //    rby[i]=0;



           enemicnt=i;
                






             //       bullet2x[i]+=1*0.5;


           if (maptemp[i]==1077){



                    if (spider.timer>=400) { spider.timer=0;      }

                         if (spider.timer>=200) {      spider.bulletx[i]=spider.x[i]+8;   if (playerx<spider.x[i]-(z*10)){   spider.bdirx[i]=1; }  if (playerx>spider.x[i]-(z*10)){   spider.bdirx[i]=-1; }
                         if (playery<spider.y[i]-(zv*10)){   spider.bdiry[i]=1; }if (playery>spider.y[i]-(zv*10)){   spider.bdiry[i]=-1; }

                                          spider.bullety[i]=spider.y[i]+5; }

                         // rbx[enemicnt]=-1;
                          //  rby[enemicnt]=1;
                          if (spider.timer2>100){   spider.dirx[enemicnt]=-spider.dirx[enemicnt];      }

            if (spider.timer2>200){   spider.diry[enemicnt]=-spider.diry[enemicnt];     }
              if (spider.timer2>300){ spider.timer2=0; }







         rectfill(collisionpad,spider.x[enemicnt]-(z*10)-add,spider.y[enemicnt]-15-add2-(zv*10),spider.x[enemicnt]-(z*10)-add+15,spider.y[enemicnt]-15-add2-(zv*10)+20,90);





                               slowspid++;






                      if (slow2>20000){ slow2=0;  }



int ks=0;
int is=5;

int js=0;
int col=0;

// clear_to_color(sprites,4);





 //       rectfill(surface,enix[enemicnt]+(i*10),vertical-20-add2+eniy[enemicnt],enix[enemicnt]+((i+1)*10),vertical+10-add2+eniy[enemicnt],90);





          if (spider.dirx[enemicnt]>0){fry=0;}  if (spider.dirx[enemicnt]<0){fry=30;}



                          for (int x=-3;x<15;x++){

                    colx=getpixel(collisionpad2,spider.x[enemicnt]+60+x,spider.y[enemicnt]+240-5);
                                           if (colx==4){


          spider.diry[enemicnt]=1;   }

                    colx=getpixel(collisionpad2,spider.x[enemicnt]+60+x,spider.y[enemicnt]+240+15);
                                           if (colx==4){


         spider.diry[enemicnt]=-1;   }

                 }





                 for (int y=-3;y<15;y++){

                    colx=getpixel(collisionpad2,spider.x[enemicnt]+15+60,y+spider.y[enemicnt]+240);
                                           if (colx==4){


          spider.dirx[enemicnt]=-1;   }

                    colx=getpixel(collisionpad2,spider.x[enemicnt]-1+60,y+spider.y[enemicnt]+240);
                                           if (colx==4){


         spider.dirx[enemicnt]=1;   }

                 }




                      //    if(enix[enemicnt]<50){  rx[enemicnt]=1;  }
                        //   if(enix[enemicnt]-(z*10)-add>320){  r[enemicnt]=-1; }
                         //  if(enix[enemicnt]-(z*10)-add<0){  r[enemicnt]=1;}

                         if (spider.diry[enemicnt]>0){spider.y[enemicnt]+=1*0.5;              }
                         if (spider.diry[enemicnt]<0){spider.y[enemicnt]-=1*0.5;              }
                         if (spider.dirx[enemicnt]>0){spider.x[enemicnt]+=1*0.5; if (spidanimx>=13){spidanimx=0;}  if(slowspid>20) { slowspid=0;spidanimx+=13;} }
                         if (spider.dirx[enemicnt]<0){spider.x[enemicnt]-=1*0.5;             }
                      //     if(  enix[enemicnt]==0){ enix[enemicnt]==1; r[enemicnt]=-r[enemicnt];}









                 /*    if (colx==4){  bullet2x[i]=400;
            bullet2y[i]=300;
                 } */
       //  blit(walkingspr,surface,0,0,bullet2x[i],bullet2y[i],2,2);

                        rectfill(collisionpad,spider.bulletx[i]-add-(z*10)-5,spider.bullety[i]-(zv*10)-add2-5,spider.bulletx[i]-add-(z*10)+10,spider.bullety[i]-(zv*10)-add2+10,98);
                             circle(surface,spider.bulletx[i]-add-(z*10)-3,spider.bullety[i]-(zv*10)-add2-3,1,254);
                        //                                   circlefill(surface,spider.bulletx[i]-add-(z*10)-2,spider.bullety[i]-(zv*10)-add2-2,1,253);

                              //  rectfill(surface,playerx,playery,playerx,playery,95);
                               int colx=getpixel(collisionpad,playerx+10,playery+10);
                       if (colx==98){ midiseek=0;   play_midi(grand,0);midi_seek(40); init(); }




                                        colx=getpixel(collisionpad2,spider.bulletx[i]+60,spider.bullety[i]+250);
                                      if(colx==4){ spider.bulletx[i]=spider.x[i];  spider.bullety[i]=spider.y[i];}



         masked_blit(walkingspr2,surface,155+spidanimx,261,spider.x[enemicnt]-1-(z*10)-add,spider.y[enemicnt]-(zv*10)-add2,10,10);
//         draw_sprite(surface,sprite,);


                     if (spider.bdirx[i]==1){

                   spider.bulletx[i]-=1;        }
                      if (spider.bdirx[i]==-1){
                   spider.bulletx[i]+=1;            }
                      if (spider.bdiry[i]==1){
                   spider.bullety[i]-=1;}
                         if (spider.bdiry[i]==-1){
                   spider.bullety[i]+=1;}






            for (int u=0;u<50;u+=1){


                              k34=0;
                        for (int x=-2;x<2;x++){          colx=getpixel(collisionpad,bulletx[u]+x,bullety[u]-zvb-13);   }
         if (colx==90){ hits++;     k34=1;     /*spider.x[enemicnt]-1-(z*10)-add; */
                        explos.timer=0;
             if (explostrig==0){
           explostrig=1;}  maptemp[i]=0; bulletspd=1; midiseek=0;     play_midi(grand,0); midi_seek(250);     bullettrig=0;   mapfunc();
                                      explosx=bulletx[u];     explosy=bullety[u]-zvb-13;
             


                                 }


                                 }


            /*    spider.y[enemicnt]-(zv*10)-add2; */







  }

                              explos.x[0]+=0.02;  explos.y[0]+=0.02;
                            if (explos.x[0]>10) { explos.x[0]=2;}
                           if (explos.y[0]>10)  { explos.y[0]=2;}
                     



      if (maptemp[i]==1078){



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


                   rectfill(collisionpad,spr.x[enemicnt]-1-(z*10)-add,spr.y[enemicnt]-(zv*10)-add2,spr.x[enemicnt]-1-(z*10)-add+30,spr.y[enemicnt]-(zv*10)-add2+30,4);


 //         if (spr.dirx[enemicnt]>0){fry=0;}  if (spr.dirx[enemicnt]<0){fry=30;}



                          for (int x=-3;x<25;x++){

                    colx=getpixel(collisionpad2,spr.x[enemicnt]+60+x,spr.y[enemicnt]+240-5);
                                           if (colx==4){


          spr.diry[enemicnt]=1;   }

                    colx=getpixel(collisionpad2,spr.x[enemicnt]+60+x,spr.y[enemicnt]+240+35);
                                           if (colx==4){


         spr.diry[enemicnt]=-1;   }

                 }





                 for (int y=-3;y<25;y++){

                    colx=getpixel(collisionpad2,spr.x[enemicnt]+35+60,y+spr.y[enemicnt]+240);
                                           if (colx==4){


          spr.dirx[enemicnt]=-1;   }

                    colx=getpixel(collisionpad2,spr.x[enemicnt]-1+60,y+spr.y[enemicnt]+240);
                                           if (colx==4){


         spr.dirx[enemicnt]=1;   }

                 }




                         if (spr.diry[enemicnt]>0){spr.y[enemicnt]+=1*0.3;              }
                         if (spr.diry[enemicnt]<0){spr.y[enemicnt]-=1*0.3;              }
                         if (spr.dirx[enemicnt]>0){spr.x[enemicnt]+=1*0.3;             }
                         if (spr.dirx[enemicnt]<0){spr.x[enemicnt]-=1*0.3;             }









           


                blit(sprsheet,surface,0,110,spr.x[enemicnt]-1-(z*10)-add,spr.y[enemicnt]-(zv*10)-add2,30,30);
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



  }








      }

                          if (explos.timer<=50) { circle(surface,explosx,explosy,explos.timer/10,2);
                               circle(surface,explosx,explosy,10-explos.timer/10,228);
                                                 }

                 explos.timer++;
                    if (explos.timer>=100){explos.timer=100;   }


           if (hits>2){copymapchunk();}

        textprintf_ex(surface,font,160,0,250,0,"%i",hits);

// blitnum(10,10,8,0);


}



int keyboard(){
             tplayer=1;
                 t2player=-1;
            t=255+97;
               t2=255+97;


           tx2=1;
           tx=1;

         for (int x=9;x<15;x++){




                        colx=getpixel(collisionpad,playerx+x,playery+20);
                if (colx==4){t=0;tplayer=0;
                if (dur2==1){jmptimer2=0;}
          tx=1;
            tx2=1;    dur++; if (dur>50){   acce=32; jmptrig=0; } }

              colx=getpixel(collisionpad,playerx+x,playery-4);
                        

             if (colx==4){t2=0;t2player=0; downtrig=0; acce=0; }
                                          }





           for (int y=2;y<16;y++){


              colx=getpixel(collisionpad,playerx,playery+y);
                     if (colx==90){ init(); midiseek=-100;   play_midi(grand,0);  midi_seek(160);     }






                        colx=getpixel(collisionpad,playerx+16,playery+y);
                        

             if (colx==4){tx=0; }
              colx=getpixel(collisionpad,playerx+5,playery+y);
                        

             if (colx==4){tx2=0;}

               colx=getpixel(collisionpad,playerx+5,playery+y);
                        

             if (colx>230){       tplayer=-1;  tx=1;tx2=1;}
                 colx=getpixel(collisionpad,playerx+15,playery+y);
                        

             if (colx>230){          tplayer=-1;  tx=1;tx2=1;}
             

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

                   //  playerx--;


               int releasel=1;
               int releaser=1;

      if (key[KEY_LEFT]) { releasel=0; faced=-1;  if (spd<-5){spd=-5;} spd-=1;     playerx=playerx-tx2;     framey=172; slow++; if (slow>10){slow=0;        framex+=16;          }

        if (framex>=201){  framex=155;}



                                                           }
           //              if (z>8000){z=0;}
    if (key[KEY_RIGHT]) {   releaser=0; faced=1;  if (spd>5){spd=5;} spd+=1;     playerx=playerx+tx;     framey=230;

                 slow++; if (slow>10){slow=0;    framex+=16;



                 }                 if (framex>=201){framex=155;}




                                                }



         if (key[KEY_UP]){



         framey=210;   framex+=16;    if (framex>175){framex=155;}  playery=playery+t2player;      }
         if (key[KEY_DOWN]){



         framey=191;  framex+=16;    if (framex>175){framex=155;}   playery=playery+tplayer;    }

                                                                     bullethit=1;

                                           bullettrig=0;

                //    bulletcnt-=0.1;

           //  if (bulletcnt<0){bulletcnt=0;}
           if (timerb<0){timerb=0;}

            // timerb=0;

                   //   if(bulletx[bulletcnt]>320){bulletx[bulletcnt]=playerx+10;
                    //                                   bullety[bulletcnt]=playery+10;    }



               //     bulletcnt++;




                                                      bullettimer--;

                                             if(bullettimer<=0){bullettimer=0;}


                     if (key[KEY_SPACE]){  if (bullettimer==0){bullettrig=1;bullettimer=20; }
                                         if (key[KEY_UP]){     faced=2;}
                                          if (key[KEY_DOWN]){     faced=-2;   }
                              //    play_midi(grand,0); midiseek=0; midi_seek(40);

                                                  if (bullettrig==1){   bullettrig=0;


                                                                    play_midi(grand,0); midiseek=0; midi_seek(80);

                                                  bullety[bulletcnt]=playery+zvb+10;
                                              bulletx[bulletcnt]=(playerx+10);

                                                  }
                                                  if (faced==1){   bulletx[bulletcnt]=(playerx+15);     bulletdirx[bulletcnt]=0.1;   bulletdiry[bulletcnt]=0;          }
                                                 if (faced==-1){   bulletx[bulletcnt]=(playerx-10);     bulletdirx[bulletcnt]=-0.1;   bulletdiry[bulletcnt]=0;}
                                                  if (faced==2){     bulletdirx[bulletcnt]=0;   bulletdiry[bulletcnt]=-0.1;}
                                                   if (faced==-2){      bulletdirx[bulletcnt]=0;  bulletdiry[bulletcnt]=0.1;}

                                             //  if(bulletcnt>50){bulletcnt=0;bullettrig=0;}
                  






                                              }

                                         for (int i=0;i<100;i+=1){
                                     bulletcnt=bulletcnt+1;

                                 if(bulletcnt>100){bulletcnt=0;bullettrig=0;}


                          // if (bulleti>400){bulleti=0;}
                    //   if(timerb>300){timerb=300;}

                                bulletx[i]=bulletx[i]+(20*bulletdirx[i]);
                                 bullety[i]=bullety[i]+(20*bulletdiry[i]);

                                rect(screen,bulletx[i],bullety[i]-(zvb),bulletx[i]+1,bullety[i]-(zvb)+1,95);
                                   int colx;
                                  colx=getpixel(collisionpad,bulletx[i],bullety[i]-zvb);
                                      if(colx==4){ bulletx[i]=400;  bullety[i]=400;}

                                                              }


           bullethit=0  ;
                                  bullety[erasure]=400;
                        bulletx[erasure]=400;

                             if (erasure>500){erasure=0;}


                   //    bulletx[bulletcnt]=playerx;
                                if(bulletx[bulletcnt]>320){bulletx[bulletcnt]=400;bullety[bulletcnt]=400; }
                                 if(bulletx[bulletcnt]<0){bulletx[bulletcnt]=-100;bullety[bulletcnt]=400; }
                                   if(bullety[bulletcnt]>=220){bulletx[bulletcnt]=400;bullety[bulletcnt]=400; }
                                 if(bullety[bulletcnt]<=0){bulletx[bulletcnt]=400;bullety[bulletcnt]=400; }
                                    erasure++;





               jmpbypass++;
                   //  if (jmpbypass>200){jmptrig=0;jmpbypass=0; }
                    // jmptimer--;


                   //    if (jmptimer<100){jmptrig=0;}
                                 if (bgscroly<0){bgscroly=100;}
                                    if (playerx>=181) {   playerx-=1;      if (bgscrolx>400){bgscrolx=400;}  bgscrolx=bgscrolx+(double)tx; add++;bgaddh--; if (bgaddh<0){bgaddh=30;}if (add>10){add=1;  plus=(int)plus+1;z++;  } }
                                    if (playerx<=100) {   playerx+=1; if (bgscrolx<0){bgscrolx=0;} bgscrolx=bgscrolx-(double)tx2;  add--;bgaddh++; if (bgaddh>30){bgaddh=0;} if (add<1)   {add=10;     plus=(int)plus-1;z--;   } }
                    if (playery>=90){ zvb++; playery-=1;  if (bgaddv<0){bgaddv=30;} bgaddv--;                     add2++;  if (add2>10){ add2=0;   plus+=255+97;zv=zv+1; }  }
                    if (playery<=80){ zvb--; playery+=1;    if (bgaddv>30){bgaddv=0;} bgaddv++; add2--;  if (add2<0){ add2=10;    plus-=255+97;zv=zv-1;}  }



               //     midis++;if (midis>30){midis=0;stop_midi();  play_midi(grand,0);midi_seek(34);}


                               //    if (tplayer>0){    playery+=(acce2/3);};
                                     // acce-=0.0001;


                           //   bgscroly=bgscroly-(t/160);



//     spritefunction();

   

}









int main(int argc, char *argv[]) {



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

//set_multiply_blender(0, 0, 0, 9);
   //    set_color_depth(8);
  //  gfx_driver->set_blender_mode(0,0,0,0,9);
   set_write_alpha_blender();
//bitmapbuffer="metal.bmp";
   /* read in the bitmap file */
 collisionpad=create_bitmap(320,240);
  collisionpad2=create_bitmap(3200,1000);



       //   solid_mode();
//   the_image= load_bitmap("spritesheet.bmp", the_palette);
   sprsheet=load_bitmap("mapbit.bmp",the_palette2);
   grand=load_midi("music.mid");

   //   set_palette(the_palette);
//    the_block1= load_bitmap("block1.bmp",the_palette2);
               font1=load_bitmap("fonts.bmp",the_palette);

      levelbg=load_bitmap("levbg1.bmp",the_palette);
//     spr1=create_bitmap(320,240);
  surface=create_bitmap(320,240);
//   sprite=create_bitmap(20,30);
// themap=create_bitmap (320,240);


           levelbg2=create_bitmap(320,240);
       levelbg1=load_bitmap("bgsprts.bmp",the_palette2);
// walkingspr=create_bitmap(640,480);
      walkingspr2=load_bitmap("walking.bmp",the_palette2);
 //      spritefunction();

  int x,y,col,col2;
    for (int i=0;i<2400000;i++){
    x++; if(x>4000){x=0;y++;}
    if (y>240){y=0;}
     col2=getpixel(levelbg1,0,0);

    col=getpixel(levelbg1,x,y);

    if (col!=col2){
   putpixel(levelbg2,x,y,col);

               }





      if (col==col2){
   putpixel(levelbg2,x,y,256);

               }

       }

     x=0;y=0;





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

     while (i!=0){
      




                  ti3++;            if (ti3>=5000){ti3=0;lenght++;    keyboard();        mapfunc();
                                                                                                                            //  draw_trans_sprite(spr1,walkingspr,0,0);

                                                                                                                              blittingtosprite();
                                                                                                                              //  enemies_func();
             if (key[KEY_ESC]){ return 0;}
                                                                                                                                 blit(surface,screen,0,0,0,0,320,240);
                                                                                               //   blit(sprites,screen,framex,framey,playerx,playery,30, 30);
                                                                                                                                  }

    }


 destroy_bitmap(screen);

   
   readkey();
   return 0;


END_OF_MAIN()
}
