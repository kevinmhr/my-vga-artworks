

#include <allegro.h>
#include <math.h>
char *bitmapbuffer;
 int z;
int fry,frx,tuy,tuu,fri;
    int slow3;
    int verti=300;
    int it=400;
double xt=2;
double yt=2;
 double xu,yu;
int add=0;
int add2=0;
unsigned int hits;
double spd;
double sprx1[500];
double spry1[500];
double sprayx[500];
double sprayy[500];
double spraym;
int sprcnt;
int cnt;
int rollbitmap();
  int faced;
int resetgame=0;
double scroll;
int level=1;
 int trail;
int bullethit=1;
int leveltotal=0;
 void stars();
   int cnt;
   int midiseek;
       int timer2;
  int bulletx;
    int bullety;
double vervar,horvar;
int d;

 int bulletdir;
int ballsize;
    int bullettrig;
         int downtrig;

double linerol;
int pickupcolor;
double curenemix;
int roll=0;
  int jmpbypass;
int keytrig=0;
double acce;
double i;
  double rollbit;
int y;
  int slow=0;;
int framex=0;
     int timerb;
int framey=133;
  int r[20000];
int keyboard();

int mapfunc();
double acce2;
int dur;
int maplenght;
double enix[20000];
double eniy[20000];
int k;
int enemicnt;
int x;
int t;
int t2;
 double tplayer;
     double t2player;
int x2;
int slow2;
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

 double tx=0;
 double tx2=0;
int f;
int shift;
int incdec=1;
  int dur2;
int plus;
int lenght;
int jmptrig=0;
double enemiposx=0;
double enemiposy=0;
double jmptimer;
int enemixt1=2;
int enemiyt1=2;
int laddercolor;
double spx,spy;
typedef struct OBJECT{
double x;
double y;



}OBJECT;



                 BITMAP *levelbg;
          BITMAP *levelbg4;
     BITMAP *levelbg3;
   BITMAP *levelbg2;
     BITMAP *levelbg1;
   BITMAP *collisionpad;
    BITMAP *sprite;
   PALETTE the_palette1;
   PALETTE the_palette;
   PALETTE the_palette2;
   BITMAP *walkingspr;
   BITMAP *walkingspr2;
   BITMAP *sprites;
     BITMAP *surface;
    BITMAP *sprsheet;
    BITMAP *spr1;
     OBJECT enemii;

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








int map1[]={


0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,0,0,0,
0,0,0,0,0,0,0,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,8147,0,0,0,


0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,7347,7347,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,0,0,0,
0,0,0,0,0,0,0,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,9147,8147,0,0,0,
0,0,0,0,0,0,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,2047,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,

80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,80,

0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,













};






int maptemp[20000];


int timer(){




     if(ti>1000){z=z+1;}
          if(ti<1000){z=z-1;}
 if (ti>=2000){incdec=-1;}
   if (ti<=0){incdec=1;}
  if (shift>=32){shift=1;}


             ti=ti+(incdec);

          //x+=y/10;




         x+=ti/500+(z)/20;
         x2+=ti/500+(z)/20;
         x2=x2-1;
















}
int ball_func(){
  //  if (bgscrolx>700){bgscrolx=0;}


   //  blit(enemiesbuf,screen,0,0,0,0,320,240);









}



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
int blittingtosprite(){
int i=0;
int j=0;
int col=0;
// clear_to_color(sprites,4);




col=getpixel(walkingspr,i,j+100);
//if (col!=getpixel(walkingspr,1,1)){

masked_blit(sprsheet,surface,102,10,playerx,playery,28,10);

//masked_blit(sprsheet,surface,1,1,playerx,150,28,10);

rectfill(collisionpad,playerx-5,playery,playerx+29,playery+5,7);
//rectfill(surface,playerx,150,playerx+24,155,7);

//putpixel(surface,playerx,150,col-1);
  //  }




}
int othersblittingtosprite(int otherposx;int otherposy;){



}
int init(){
//          play_midi(grand,0);
        leveltotal=0;
       enemiyt1=-1;
        maplenght=32;
        d=0;
          ti3=0;
          bgscrolx=0;
          z=0;
         acce=1;
         jmptimer=0;
    playerx=110;
 playery=170;
    enemii.x=playerx+10;
      enemii.y=playery;
     vervar=0;
     horvar=0;

       enemicnt=0;
      i=1;
    plus=100;

  if (level>3){level=1;}
  if (level==1){
  for (int x=0;x<1000;x++){

 maptemp[x]=map1[x];
 if ( maptemp[x]!=80){ if ( map1[x]>0){ leveltotal+=1; }  }
               }


               levelbg=load_bitmap("bg1.bmp",the_palette);
             //  levelbg=create_bitmap(320,240);
              // clear_to_color(levelbg,0);

               }
   if (level==2){
  for (int x=0;x<20000;x++){

 maptemp[x]=map1[x];

               }    levelbg=load_bitmap("levbg2.bmp",the_palette);       }

   if (level==3){
  for (int x=0;x<20000;x++){

 maptemp[x]=map1[x];

               }    levelbg=load_bitmap("spritesh.bmp",the_palette);       }
               

  for (int x=0;x<20000;x++){
enix[x]=0;     r[x]=1;
eniy[x]=0;


 }

     mapfunc();   

}
int mapfunc(){


                if (resetgame==1){resetgame=0;init();}


                  int enitx=0.1;
                  int enitx2=0.1;




//     clear_to_color(levelbg,0);
    clear_to_color(surface,0);
        stars();
     masked_blit(levelbg,surface,0,0,0,0,320,240);
  clear_to_color(collisionpad,1);


  //   blit(levelbg2,levelbg3,0,150,0,0,105,65);
    //       draw_sprite(surface,levelbg3,bgscrolx/2,bgscroly);

         //    blit(levelbg,screen,0,0,0,0,320,240);




              //      if (vertical>220){vertical=10;}

                  i=1;























              int vertical=10-add2;

             d=0;

             i=1;




                    rollbit++;
              if (rollbit>100){it=330;verti=300;rollbit=0;}
 

               rect(screen,(((it)*10)+7)-(rollbit/15),(verti+7)-(rollbit/15),((it)*10)+(rollbit/10),verti+(rollbit/10),rollbit/2 );
           //      vline(screen,((it+1)*10)-rollbit/10,verti,verti+10,rollbit/2 );


           for (k=plus;k<(640)+plus;k++){








      //      if (key[KEY_LEFT]){ add-=1;   }
      //     if (key[KEY_LEFT]){ add+=1;   }
      //     if (add>10){add=0;}
      //     if (add<0){add=10;}

                        d++;

                      if (z<0){z=0;}
                          enemicnt=(d+z+10);
                      // if (z>320){z=0;}
              //    vertical=vertical+10;
                  i++;
               //   if (vertical>24){i=i+1;}
            if (i>maplenght-1){vertical=vertical+10;i=0;            }


 tuy++;

 if (tuy>20000){    if (frx>=100){frx=0;}
 frx=frx+25;tuy=0; }














        if (maptemp[k]==33) {

       rectfill(collisionpad,(i*10)-add,vertical,((i+1)*10)-add,vertical+10,5);
        //  rectfill(surface,(i*10)-add,vertical,((i+1)*10)-add,vertical+10,5);




int ks=0;
int is=0;
int col=0;
int js=0;



      blit(walkingspr,surface,135,28,(i*10)-add,vertical-add2,12,9);





}













        if (maptemp[k]==803) {
        //    levelbg3=create_bitmap(30,60);
      masked_blit(levelbg2,surface,49,89,(i*10)-add,vertical-add2-35,30,60);
     rectfill(collisionpad,(i*10)-add,vertical-add2-35,(i*10)-add+10,vertical-add2-35+20,98);
      //  rectfill(surface,(i*10)-add,vertical-add2-35,(i*10)-add+10,vertical-add2-35+20,98);






                            }


        if (maptemp[k]==800) {
          //  levelbg3=create_bitmap(60,30);
          masked_blit(levelbg2,surface,17,36,(i*10)-add,vertical-add2-20,60,30);






                            }


               if (maptemp[k]==801) {  

          masked_blit(levelbg2,surface,2,80,((i*10)-add)*2,vertical-add2-20,40,25);








                            }


/*
                                        if (maptemp[k]==77) {


                      enix[enemicnt]+=(double)r[enemicnt]/5;


int ks=0;
int is=5;

int js=0;
int col=0;

// clear_to_color(sprites,4);




    rectfill(collisionpad,enix[enemicnt]+(i*10),vertical-20-add2+eniy[enemicnt],enix[enemicnt]+((i+1)*10),vertical+10-add2+eniy[enemicnt],90);
 //       rectfill(surface,enix[enemicnt]+(i*10),vertical-20-add2+eniy[enemicnt],enix[enemicnt]+((i+1)*10),vertical+10-add2+eniy[enemicnt],90);




col=getpixel(walkingspr,is+frx,js+fry);
//if (col!=getpixel(walkingspr,1,1)){
//putpixel(surface,is+enix[enemicnt]+(i*10)-add,js+vertical-20-add2+eniy[enemicnt],col+1);  }
          if (r[enemicnt]>0){fry=0;}  if (r[enemicnt]<0){fry=30;}

             int colx;
                    enitx=0.5;

                 colx=getpixel(collisionpad,enix[enemicnt]+(i*10)-add,vertical+add2+eniy[enemicnt]+20);
                                           if (colx==4){    if (eniy[enemicnt]<0 ){

                                         eniy[enemicnt]-=0.1; }
                                                      }




//  }





                    colx=getpixel(collisionpad,enix[enemicnt]+(i*10)-add+50,vertical-add2+eniy[enemicnt]);
                                           if (colx==4){


       if (r[enemicnt]>0){    eniy[enemicnt]-=0.2; }       }

                    colx=getpixel(collisionpad,enix[enemicnt]+(i*10)-add-50,vertical-add2+eniy[enemicnt]);
                                           if (colx==4){


       if (r[enemicnt]<0){    eniy[enemicnt]-=0.2;  }               }











                                      eniy[enemicnt]+=0.1;
                      if (eniy[enemicnt]>0){eniy[enemicnt]=0;}







                    if(enix[enemicnt]+(i*10)-add>500){  r[enemicnt]=-1; }
                  if(enix[enemicnt]+(i*10)-add<-50){  r[enemicnt]=1; }
                    colx=getpixel(collisionpad,enix[enemicnt]+(i*10)-add+30,vertical-add2+eniy[enemicnt]+10);
                                           if (colx==4){


          r[enemicnt]=-1;   }

                    colx=getpixel(collisionpad,enix[enemicnt]+(i*10)-add-1,vertical-add2+eniy[enemicnt]+10);
                                           if (colx==4){


         r[enemicnt]=1;   }


          blit(walkingspr,sprite,frx,fry,0,0,20,30);
         draw_sprite(surface,sprite,enix[enemicnt]+(i*10)-add,vertical-20-add2+eniy[enemicnt]);



}


*/

   if (fri>=317){fri=287;}
 if (tuu>10){  fri=fri+10;
 tuu=0; }
tuu++;

     


/*


        if (maptemp[k]==35) {



       rectfill(collisionpad,(i*10),vertical,((i+1)*10),vertical+10,5);




int ks=0;
int is=0;
int col=0;
int js=0;


// clear_to_color(sprites,4);



   fry=4;


for (int ks=0;ks<100;ks++){

is++;if (is>10){is=0;js++;   pickupcolor++;}
if (js>10){js=0;pickupcolor++;}
col=getpixel(walkingspr,is+fri,js+fry);
if (col!=getpixel(walkingspr,100,0)){
putpixel(surface,(is)+(i*10)+2-add,(js)+2+vertical-9-add2,0);
putpixel(surface,(is)+(i*10)+1-add,(js)+vertical-9-add2,1);
putpixel(surface,(is)+(i*10)-add-1,(js)+vertical-10-add2,col);  }




}



}

*/




















/*















                     if (maptemp[k]==80){         blit( sprsheet,surface,0,38,(i*10),vertical-add2 ,10, 10);       }

                     if (maptemp[k]==90){         blit( sprsheet,surface,0,48,(i*10),vertical-add2 ,10, 10);       }

                                          if (maptemp[k]==100){         blit( sprsheet,surface,0,58,(i*10)+scroll,vertical-add2 ,10, 10);       }

        if (maptemp[k]==100) {
          rectfill(collisionpad,(i*10),vertical+1-add2,((i+2)*10),vertical+11-add2,254); }
  //    if (enemicnt>9000){enemicnt=0;}

           //   if (enemicnt>20){enemicnt=0;}


       if (maptemp[k]==8) {
        blit( sprsheet,surface, ti2,40,i*10,vertical-add2 ,10, 10);

                      }
    if (key[KEY_UP]) {


       colx=getpixel(collisionpad,playerx+10,playery);
       if (colx==98){  levelbg=create_bitmap(1000,320); clear_to_color(levelbg,0);   plus=9000;     maplenght=32;              }

                                       }
           colx=getpixel(collisionpad,playerx+10,playery+20);
       if (colx==5){
        midiseek=0;  maptemp[k]=0; play_midi(grand,0);  midi_seek(19);   mapfunc();       }

         if (bulletx>10){     colx=getpixel(collisionpad,bulletx+2,bullety+20);
     if (bullettrig==1){  if (colx==90){     maptemp[k]=0; midiseek=0; for (int x=0;x<20000;x++){ circlefill(screen,bulletx+10,bullety,10,colx++);}    play_midi(grand,0); midi_seek(95);     mapfunc();  bullettrig=0;         }
             colx=getpixel(collisionpad,bulletx,bullety);
               if (colx!=1){ maptemp[k]=0; bullettrig=0; midiseek=0;   play_midi(grand,0);midi_seek(40); mapfunc();  }

                        }        }






  */

     xu=(sin(enemiposy/tuu)+cos(enemiposy/tuu));
  yu=(cos(enemiposy/tuu)-sin(enemiposy/tuu));


   xu=xu*1.8;
   yu=yu*1.8;
   
    circlefill(surface,enemiposx,enemiposy,3.5,237);

   //   rect(surface,enemiposx,enemiposy,enemiposx+xu,enemiposy+yu,8);
//     putpixel(surface,enemiposx+xu,enemiposy+yu,7);
     line(surface,enemiposx,enemiposy,enemiposx+xu,enemiposy+yu,0);
     //   circle(surface,enemiposx,enemiposy,3,3);
  


          if (maptemp[k]==80) {


                 rectfill(collisionpad,(i*10)-add,vertical-add2,((i+1)*10)-add,vertical+10,2);

                  rectfill(surface,(i*10)-add,vertical-add2,((i+1)*10)-add,vertical+10,105);

                  hline( surface,((i)*10)-add+linerol,vertical-add2+2 ,((i)*10)-add+10-linerol, 2);
                     hline( surface,((i)*10)-add,vertical-add2 ,((i)*10)-add+10, 228);




                  }




             if (maptemp[k]>=1000){



             
              int x,y;
              double x1,y1;
              x=maptemp[k];
              x1=(int)(x/100);
              y=x-(x1*100);
       masked_blit( sprsheet,surface,x1-10,y-10,((i)*10)-add,vertical-add2 ,10, 10);
            rectfill(collisionpad,(i*10)-add,vertical-add2,((i+1)*10)-add,vertical+10,4);





// clear_to_color(sprites,4);






//for (int ks=0;ks<100;ks++){



//}



     ballsize=3;


     for (int y=0;y<ballsize;y++){
                   //       putpixel(surface,enemiposx-(ballsize/1.8),enemiposy+y-(ballsize/2.2),7);
               //  putpixel(surface,enemiposx+(ballsize/1.8),enemiposy+y-(ballsize/2.2),7);
          

                        colx=getpixel(collisionpad,enemiposx-(ballsize/1.8),enemiposy+y-(ballsize/2.2));


             if (colx==4){for (int i=0;i<10;i++){  sound(((k)));}enemixt1=1;  hits+=10;   cnt++;  it=i; verti=vertical;
          midiseek=0; play_midi(grand,0);  midi_seek(328); maptemp[k]=0;   mapfunc();    }

              colx=getpixel(collisionpad,enemiposx+(ballsize/1.8),enemiposy+y-(ballsize/2.2));
                        

             if (colx==4){for (int i=0;i<10;i++){  sound(((k)));}enemixt1=0;   hits+=10; cnt++;  it=i; verti=vertical;
                        midiseek=0; play_midi(grand,0);  midi_seek(328); maptemp[k]=0;  mapfunc();  }



                                          }
               for (int x=0;x<ballsize;x++){
            //     putpixel(surface,enemiposx+x-(ballsize/2.2),enemiposy-(ballsize/1.8),7);
            //     putpixel(surface,enemiposx+x-(ballsize/2.2),enemiposy+(ballsize/1.8),7);
           


                        colx=getpixel(collisionpad,enemiposx+x-(ballsize/2.2),enemiposy+(ballsize/1.8));



             if (colx==4){for (int i=0;i<10;i++){ sound((k));} enemiyt1=0;  hits+=10; cnt++;   it=i; verti=vertical;

             midiseek=0; play_midi(grand,0);  midi_seek(328); maptemp[k]=0;   mapfunc();  }
              colx=getpixel(collisionpad,enemiposx+x-(ballsize/2.2),enemiposy-(ballsize/1.7));


             if (colx==4){for (int i=0;i<10;i++){ sound((k));} enemiyt1=1; cnt++;   hits+=10;   it=i; verti=vertical;
                      midiseek=0; play_midi(grand,0);  midi_seek(328); maptemp[k]=0;
                                                  mapfunc(); }





                             }
                                  }











   if (enemii.y<0){enemiyt1=2;  }
if (enemii.y>=200){enemiyt1=-1;    }


if (enemiyt1>=1){enemii.y+=0.0008;}
if (enemiyt1<=0){enemii.y-=0.0008;}


if (enemii.x<=5){enemixt1=2; }
if (enemii.x>=315){enemixt1=-1;}

if (enemixt1>=1){enemii.x+=(horvar-0.0001);}
if (enemixt1<=0){enemii.x-=(horvar-0.0001);}
















 }


midiseek++; if(midiseek>20){midiseek=0;
stop_midi();  
sound(0);






              }












               textprintf_ex(surface,font,10,10,250,0,"%i",hits);
                  textprintf_ex(surface,font,280,10,250,0,"%i",leveltotal);




}








int keyboard(){

             tplayer=1;
            t=160;
               t2=160;
     

           tx2=1;
           tx=1;
                                colx=getpixel(collisionpad,enemiposx,enemiposy);
      if (colx==2){ hits=0;cnt=0;init(); }


                  if (cnt>leveltotal-1){cnt=0;init();}


                  int colx;
           enemiposx=enemii.x;
           enemiposy=enemii.y;
               rectfill(collisionpad,enemiposx-3,enemiposy-3,enemiposx+3,enemiposy+3,10);


               int rocketsize=28;

            for (int x=-3;x<rocketsize;x+=1){

                         colx=getpixel(collisionpad,playerx+x,playery);
 
               //        rectfill(screen,playerx+rocketsize-3,playery,(playerx+rocketsize-rocketsize/3)-1,playery+10,228);
                 //              rectfill(screen,playerx,playery,(playerx+rocketsize/3)-2,playery+10,228);
           
             if (colx==10){enemiyt1=-1;for (int i=0;i<10;i++){ sound(200);}  sound(0); midiseek=0; play_midi(grand,0);  midi_seek(240); if (x>(rocketsize-(rocketsize/3))-1){ horvar=horvar+0.00005; }  if (x<(rocketsize/3)-1){ horvar=horvar+0.00005; } horvar=horvar-0.000025;   }





                                          }

                           if (horvar<0.00055){horvar=0.00055;}
      if (horvar>0.0015){horvar=0.0015;}








/*     for (double y=0;y<ballsize;y+=1){



       colx=getpixel(collisionpad,enemiposx-(ballsize/1.8),enemiposy+y-(ballsize/2.2));
           
                             if (vervar>5){vervar=5;}
             if (colx==7){enemixt1=0;if (y>=1){ vervar-=1; }  if (y<1){ vervar+=1; }   }

     colx=getpixel(collisionpad,enemiposx+(ballsize/1.8),enemiposy+y-(ballsize/2.2));
                           

             if (colx==7){enemixt1=1;if (y>=1){ vervar-=1; }  if (y<1){ vervar+=1; }  }



                                          }



   */


         for (int x=12;x<18;x++){




                        colx=getpixel(collisionpad,playerx+x,playery+31);
                if (colx==4){t=0;tplayer=0;
          t2player=2;       if (dur2==1){jmptimer2=0;}
          tx=1;
            tx2=1;    dur++; if (dur>50){   acce=32; jmptrig=0; } }

              colx=getpixel(collisionpad,playerx+x,playery);
                        

             if (colx==4){t2=0;t2player=0; downtrig=0; acce=0; }
                                          }





           for (int y=0;y<29;y++){


              colx=getpixel(collisionpad,playerx,playery+y);
                     if (colx==90){ init(); midiseek=-100;   play_midi(grand,0);  midi_seek(160);     }






                        colx=getpixel(collisionpad,playerx+21,playery+y);
                        

             if (colx==4){tx=0; }
              colx=getpixel(collisionpad,playerx+10,playery+y);
                        

             if (colx==4){tx2=0;}

               colx=getpixel(collisionpad,playerx+10,playery+y);
                        

             if (colx>230){       tplayer=-1;  tx=1;tx2=1;}
                 colx=getpixel(collisionpad,playerx+20,playery+y);
                        

             if (colx>230){          tplayer=-1;  tx=1;tx2=1;}
             
                                          }




          //     if (z==32){z=0;add+=32;}


              if (z>140){z=0;  level++;      init();}




             
          //     if (plus>4950){plus=4800;playerx=40;playery=170;z=0;}



//          if (key[KEY_DOWN]) {plus+=t; frame=frame+400;   if (frame>800){frame=0; } }

                  //        if (jmptimer<0){jmptrig=2;jmptimer=0;}














                    //   if (jmptimer>50){  jmptrig=0; jmptimer=50;  }
                     //   if (jmptimer<50){  jmptrig=1;  }


           //  if (key[KEY_UP]) { jmptimer=0; dur=0;  jmptimer2+=0.2;   downtrig=1;  acce+=0.01; jmptrig=1;


            //          if (jmptimer2>50){downtrig=0;}  }






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

  //  if (plus>9400){plus==0;}

                   //  playerx--;






      if (key[KEY_LEFT]) {  faced=-1;  if (spd<-5){spd=-5;} spd-=1;     playerx=playerx+((tx2)*((spd))/4);     framey=133;   if (framex<120){framex=120;}   slow++; if (slow>10){slow=0;        framex=framex+30;              }  if (framex>=240){framex=120;}




                                                           }
           //              if (z>8000){z=0;}
    if (key[KEY_RIGHT]) {  faced=1;  if (spd>5){spd=5;} spd+=1;     playerx=playerx+((tx)*((spd))/4);     framey=133;

                 slow++; if (slow>10){slow=0;   framex=framex+30;        }                 if (framex>=120){framex=0;}
                                                    }



        if (playerx>290) { playerx=290;}//  playerx-=1;      if (bgscrolx>400){bgscrolx=400;}  bgscrolx=bgscrolx+(double)tx;  add++; if (add>7){add=0;  plus+=1;  z++;   }  }
        if (playerx<10) {   playerx=10;} //         playerx+=1; if (bgscrolx<0){bgscrolx=0;} bgscrolx=bgscrolx-(double)tx2;     add--;  if (add<0)   {add=7;  plus-=1;  z--; } }


                    
                                                bullethit=1;

          /*
           if (key[KEY_SPACE]){  timerb=0;
                if (faced<0){        bulletdir=-1;}
                if (faced>0){          bulletdir=1;}






           play_midi(grand,0); midiseek=0; midi_seek(100); bullethit=0;  bullettrig=1;bulletx=playerx+10;      bulletx+=10;       ;bullety=playery+10;      }
                            */
                            if (timerb>2000){bullettrig=0;timerb=0; }


                                if (bullettrig>=1) {    bulletx=bulletx+(sin(timerb));    timerb+=1;
                            int i=timerb/100;      if (bulletdir==1){  bullethit=0;      bulletx+=bulletdir;


                                      bulletx+=1+i;

                                rectfill(surface,bulletx,bullety,(bulletx)+2,bullety+2,238); blit(surface,screen,0,0,0,0,320,240);
                                                               }




                                    if (bulletdir==-1){     bullethit=0;       bulletx+=bulletdir;

                                    bulletx-=1+i;

                               rectfill(surface,bulletx,bullety,bulletx+2,bullety+2,238);     blit(surface,screen,0,0,0,0,320,240);


                                                               }


                                                                        }

                                 slow++; if (slow>100){  slow=0;  linerol+=1;}
                   if (linerol>5){linerol=0;}



               jmpbypass++;
                   //  if (jmpbypass>200){jmptrig=0;jmpbypass=0; }
                    // jmptimer--;


                   //    if (jmptimer<100){jmptrig=0;}
                                 if (bgscroly<0){bgscroly=100;}
                                //    if (playery>162){ playery-=4;    add2++;  if (add2>5){ add2=0;   plus+=t;} }
                                //       if (playery<50){ playery+=2;  add2--;  if (add2<0){ add2=5;    plus-=t;} }




                                 //  if (tplayer>0){    playery+=(acce2/3);};
                                     // acce-=0.0001;


                           //   bgscroly=bgscroly-(t/160);



     spritefunction();

   

}


void stars(){



//     blit(levelbg,surface,bgscrolx,bgscroly,0,0,320,240);




            //  slow2++;if (slow2>100){slow2=0;}

                //  spry1[sprcnt]+=sprcnt/10;
            //  sprx1[sprcnt]+=sprcnt/10;






                      //  if(spraym>100){spraym=100;}

                                 slow3++; if (slow3>200){  slow3=0;
                                                         sprx1[sprcnt]=0;spry1[sprcnt]=0;
                                                                                        }

                         //        if (slow2>10){          slow2=0;clear_to_color(surface,0);}
                          //       slow2++;




                    sprx1[sprcnt]+=1;
                        spry1[sprcnt]+=1;

                           //  if (spraym>1000){spraym=0; }



                                sprcnt+=10;


                     if (sprcnt>100){sprcnt=0;    }





                   //  eniy[enemicnt]=100+(sin((enemicnt/10)-(plus/20)))*40;



                     for (int cnt=0;cnt<500;cnt++){


                      spraym=cnt+sprcnt;

                             spx=(cos(spraym)-sin(spraym));
                  spy=(sin(spraym)+cos(spraym));



          sprayx[sprcnt]=(((spry1[sprcnt]*spy))-((sprx1[sprcnt]*spx)));
          sprayy[sprcnt]=(((sprx1[sprcnt]*spy))+((spry1[sprcnt]*spx)));






        //    rectfill(collisionpad,160,100,170,100,4);


          putpixel(surface,sprayx[cnt]+160,sprayy[cnt]+100,3);
             rectfill(surface,160,100,160+2,100+2,0);     }





}







int main(int argc, char *argv[]) {



     jmptimer=0;
    enemii.x=1;
      enemii.y=1;
      enemiposx=1;
       enemiposy=1;
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



       //   solid_mode();
//   the_image= load_bitmap("spritesheet.bmp", the_palette);
   sprsheet=load_bitmap("mapbit.bmp",the_palette2);
   grand=load_midi("canyon.mid");


      
//    the_block1= load_bitmap("block1.bmp",the_palette2);

      levelbg=load_bitmap("bg1.bmp",the_palette2);
     spr1=create_bitmap(320,240);
  surface=create_bitmap(320,240);
   sprite=create_bitmap(10,10);
// themap=create_bitmap (320,240);


              levelbg2=create_bitmap(320,240);
       levelbg1=load_bitmap("bgsprts.bmp",the_palette2);
  walkingspr=create_bitmap(640,480);
      walkingspr2=load_bitmap("walking.bmp",the_palette2);
 //      spritefunction();
      set_palette(the_palette2);
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









  for (int i=0;i<240000;i++){
   x++;if(x>640){y++;x=0;}
   if (y>480){y=0;}
   col2=getpixel(walkingspr2,0,0);

   col=getpixel(walkingspr2,x,y);
    if (col!=col2){
   putpixel(walkingspr,x,y,col);

               }





      if (col==col2){
   putpixel(walkingspr,x,y,256);

               }







  }







//    mapfunc();
 set_palette(the_palette2);
//    set_alpha_blender();
    sprites=create_bitmap(320,240);



int i;
i=1;
    z=0;
    plus=4800;
bgscroly=100;

       init();

     while (i!=0){
      




                  ti3++;             if (ti3>=5000){ti3=0;lenght++;   keyboard();   mapfunc();  ball_func();
                                                                                                                            //  draw_trans_sprite(spr1,walkingspr,0,0);

                                                                                                                              blittingtosprite();
                                                                                                                              //  enemies_func();

                                                                                                                                 blit(surface,screen,0,0,0,0,320,240);
                                                                                               //   blit(sprites,screen,framex,framey,playerx,playery,30, 30);
                                                                                                                                  }

    }


 destroy_bitmap(screen);

   
   readkey();
   return 0;


END_OF_MAIN()
}
