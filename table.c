#include <allegro.h>
#include <math.h>



#define MAX_BALLS 10

BITMAP* surface;
BITMAP* pic;
BITMAP *coliface;
BITMAP *bgspr;

//MIDI *eff;

int k=1,z=1;
int col=11;
char hitball;
int count=1000;
double ballx[10],bally[10];

int g=1;
char collisioncol;
char showline=1;
double playerxmove,playerymove;
double ballxmove[10],ballymove[10];

char playerxdir=1,playerydir=1;
char ballxdir[10],ballydir[10];
double linex,liney,ballxline,ballyline;
double playerx=140,playery=100;
double move=0;
char map[150]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,2,0,0,2,2,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,1,1,0,0,0,0,2,0,0,0,0,1,
    1,0,0,1,1,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
char trig,balltrig[10];

float trans,accy=0,accx=0,ang,acc,acc2,ballacc[MAX_BALLS],ballangx[MAX_BALLS],ballangy[MAX_BALLS];
int sc;
int board(){

int i=-20,j=0;


for (int k=0;k<150;k++){

i+=20;
if (i>280){i=0; j+=20;}

if (map[k]==1){
   blit(bgspr,surface,0,0,i,j,20,20);
      rectfill(coliface,i,j,i+20,j+20,1);




     
            }



}










}

int balls(){


                                                        acc2-=0.00001;

                                  if (acc>0.3){acc=0.3;}


                   if (acc2<0.00){acc2=0.00;}

           //    play_looped_midi(eff,0,12);



            for (int k=0;k<MAX_BALLS;k++){
                    rectfill(coliface,ballx[k]-3,bally[k]-3,ballx[k]+3,bally[k]+3,k+100);






                      //    ballacc[k]-=0.00001;
circlefill(surface,ballx[k],bally[k],3,k);

                for (int y=-8;y<=8;y+=1){
               
                for (int x=-8;x<=8;x+=1){

                    collisioncol=getpixel(coliface,playerx+x,playery+y);

                    
                  if (collisioncol==k+100){
              //     balltrig[k]=1;

                     ballxdir[k]=1;
                     ballydir[k]=1;


                        double tempacc=acc;
                        acc-=0.0001;
                        if (acc<0){acc=0;}

                                  //         if (x==0){  playerydir=-playerydir;}
                                   //        if (y==0){  playerxdir=-playerxdir;}

                           hitball=k;
                                           if (x>1){


                                           playerxdir=-1;
                                            ballangx[k]=x;

                                            }
                                              if (x<-1){
                                           playerxdir=1;
                                              ballangx[k]=x;
                                            }
                                                 if (y>1){
                                          playerydir=1;

                                              ballangy[k]=y;
                                            }
                                              if (y<-1){
                                           playerydir=-1;

                                            ballangy[k]=y;
                                            }


               count=30;

       /*       if (collisioncol==43){
                 if (trig==0){
                      int u=collisioncol-100;
         
               ballangy[u]=1;
               ballydir[u]=1;
                ballacc[u]-=1;
               ballydir[k]=-1;  }
    }    */




        

                                                   
                                        //           if (x==0){ballxdir[k]=-ballxdir[k];}

                                        //           if (y==0){ballydir[k]=-ballydir[k];}

                 if (acc>0.1){
                 ballacc[k]=acc2;

                 trig=0;          }

                 if (trig==0){
                 if (acc<0.1){ ballacc[k]=ballacc[k]-0.01;
                     if (ballacc[k]<0.01){ballacc[k]=0.01;
                     if (playerx<40){playerx+=1; ballx[k]+=1; }
                          if (playerx>260){playerx-=1; ballx[k]-=1; }



                     }  }
      

                 }










      }



              }









                   }


             if (ballacc[k]==0){
             //ballxdir[k]=1;ballydir[k]=1;


             }

             collisioncol=getpixel(coliface,ballx[k]+6,bally[k]);

               if (collisioncol==1){    ballxdir[k]=1;           ballacc[k]-=0.001;
                        if (ballacc[k]<0.01){ballacc[k]=0.01;   }
                                         if(  ballxmove[k]*ballxdir[k]>0){   ballxdir[k]=-1;
                                                                 }
            

                                    }
                 
             collisioncol=getpixel(coliface,ballx[k]-6,bally[k]);
             if (collisioncol==1){    ballxdir[k]=-1;      ballacc[k]-=0.001;
                                                            if (ballacc[k]<0.01){ballacc[k]=0.01;   }

           if(  ballxmove[k]*ballxdir[k]<0){   ballxdir[k]=1;
                                                                 }
            


              }

            collisioncol=getpixel(coliface,ballx[k],bally[k]+6);
           //      putpixel(surface,ballx[k],bally[k]+6,255);

            if (collisioncol==1){    ballydir[k]=1;    ballacc[k]-=0.001;
                                              if (ballacc[k]<0.01){ballacc[k]=0.01;   }

             if(  ballymove[k]*ballydir[k]>0){   ballydir[k]=-1;
                                                                 }
            


                 }


   
                       collisioncol=getpixel(coliface,ballx[k],bally[k]-6);
                 if (collisioncol==1){    ballydir[k]=-1;     ballacc[k]-=0.001;
                                                      if (ballacc[k]<0.01){ballacc[k]=0.01;   }
                        if(  ballymove[k]*ballydir[k]<0){   ballydir[k]=1;
                                                                 }
            


                 }



             ballxmove[k]=(ballangx[k]*(ballacc[k]*0.5));//(sin(ballang)+cos(ballang))*(balltrig[k]*ballacc[k]);
             ballymove[k]=(ballangy[k]*(ballacc[k]*0.5));//(sin(ballang)-cos(ballang))*(balltrig[k]*ballacc[k]);
//ballxline=ballangx;
//ballyline=-ballangy;


//line(surface,ballx[k],bally[k],ballx[k]+ballxline,bally[k]+ballyline,3);

              ballx[k]+=ballxmove[k]*ballxdir[k];
              bally[k]+=ballymove[k]*ballydir[k];








                   ballacc[k]-=0.000005;
                  if (ballacc[k]<0){ballacc[k]=0;
                  ballxdir[k]=0;
                  ballydir[k]=0;

               }



                       }






           acc-=0.0005;
          if (acc<=0){acc=0;trig=0;}



  




}
int balltoballcol(){
            double feedback=1;

      //    if (trig==0)   { rectfill(coliface,playerx-6,playery-6,playerx+6,playery+6,43);}
         for (int k=0;k<MAX_BALLS;k++){

             collisioncol=getpixel(coliface,ballx[k],bally[k]+6);

             if (collisioncol>100){

                      int u=collisioncol-100;
         
               balltrig[u]=1;
            //   ballacc[k]=ballacc[k]/2;
               ballacc[u]=ballacc[k]*feedback;
               ballangy[u]=1;
               if (ballx[k]<ballx[u]){  ballangx[u]=(ballx[u]-ballx[k])/10;    }
               if (ballx[k]>ballx[u]){  ballangx[u]=-(ballx[k]-ballx[u])/10;    }
               ballydir[u]=1;
                ballxdir[u]=1;
               ballangy[k]=-1;
                 hitball=k+u;
              //   count=30;

                 }

             collisioncol=getpixel(coliface,ballx[k],bally[k]-6);

              if (collisioncol>100){

               int u=collisioncol-100;

               balltrig[u]=1;
          //        ballacc[k]=ballacc[k]/2;
               ballacc[u]=ballacc[k]*feedback;

               ballangy[u]=-1;
               if (ballx[k]<ballx[u]){  ballangx[u]=(ballx[u]-ballx[k])/10;    }
               if (ballx[k]>ballx[u]){  ballangx[u]=-(ballx[k]-ballx[u])/10;    }
               ballydir[u]=1;
                ballxdir[u]=1;

                ballangy[k]=1;

                 hitball=k+u;
                  count=0;
                  }
              
                  


                                      collisioncol=getpixel(coliface,ballx[k]+5,bally[k]);

    if (collisioncol>100){

               int u=collisioncol-100;

               balltrig[u]=1;
        //          ballacc[k]=ballacc[k]/2;
               ballacc[u]=ballacc[k]*feedback;
              
               ballangx[u]=1;
               if (bally[k]<bally[u]){  ballangy[u]=(bally[u]-bally[k])/10;    }
               if (bally[k]>bally[u]){  ballangy[u]=-(bally[k]-bally[u])/10;    }
               ballydir[u]=1;
                ballxdir[u]=1;

               ballangx[k]=-1;

                    hitball=k+u;
                 count=30;

               }






                                     collisioncol=getpixel(coliface,ballx[k]-5,bally[k]);


    if (collisioncol>100){

               int u=collisioncol-100;

               balltrig[u]=1;
            //      ballacc[k]=ballacc[k]/2;
               ballacc[u]=ballacc[k]*feedback;

               ballangx[u]=-1;
               if (bally[k]<bally[u]){  ballangy[u]=(bally[u]-bally[k])/10;    }
               if (bally[k]>bally[u]){  ballangy[u]=-(bally[k]-bally[u])/10;    }
               ballydir[u]=1;
                ballxdir[u]=1;


               ballangx[k]=1;
                    hitball=k+u;
                 count=30;
                  }


                 }









                     




                




}
int player(){



           playerxmove=(sin(ang)+cos(ang))*(trig*acc);
         playerymove=(sin(ang)-cos(ang))*(trig*acc);

                   if (acc>0){showline=0;}


circlefill(surface,playerx,playery,3,1);




if (trig==0){
line(surface,playerx,playery,playerx+linex,playery+liney,3);}


                 
             
            if (trig==0){playerxdir=1;playerydir=1;showline=1;}

           collisioncol=getpixel(coliface,playerx+9,playery);
                  putpixel(surface,playerx+6,playery,255);

           if (collisioncol==1){    playerxdir=1;
                 if(  playerxmove*playerxdir>0){   playerxdir=-1;
                                                                 }
                                            }
                  putpixel(surface,playerx-6,playery,255);


                    collisioncol=getpixel(coliface,playerx-9,playery);
           if (collisioncol==1){ playerxdir=-1;

                if(  playerxmove*playerxdir<0){   playerxdir=1;
                                                                 }



          }






           collisioncol=getpixel(coliface,playerx,playery+9);
                  putpixel(surface,playerx,playery+6,255);

                if (collisioncol==1){ playerydir=1;
                   if(  playerymove*playerydir>0){   playerydir=-1;
                                                                 }


                }

             collisioncol=getpixel(coliface,playerx,playery-9);
                  putpixel(surface,playerx,playery-6,255);

               if (collisioncol==1){    playerydir=-1;
                      if(  playerymove*playerydir<0){   playerydir=1;
                                                                 }


              }



playery+=playerymove*playerydir;
playerx+=playerxmove*playerxdir;

linex=(sin(ang)+cos(ang))*10;
liney=(sin(ang)-cos(ang))*10;



//   putpixel(surface,playerx,playery,255);




}

int main(){
  int d=0;

  int i; int x=0,y=0;


 int u=0;


      for (int k=0;k<MAX_BALLS;k++){
      ballx[k]=-10;
      bally[k]=-10;

                                    }
  for (int k=0;k<140;k++){

     x+=20; if (x>300){ x=0;y+=20;}
      if (map[k]==2){ u++;
         ballacc[u]=0;
        ballxmove[u]=0;
        ballymove[u]=0;
        ballxdir[u]=0;
        ballydir[u]=0;
        balltrig[u]=0;


      
      ballx[u]=x;
      bally[u]=y;
       if (u>MAX_BALLS){u=0;}

      }


  }


  

   if (allegro_init() != 0)
      return 1;


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

pic=load_bitmap("map1.bmp",0);
surface=create_bitmap(320,240);
bgspr=create_bitmap(60,60);


coliface=create_bitmap(320,240);
//eff=load_midi("midtst.mid");
clear_to_color(bgspr,25);
char x1=3,y1=3;
for (int i=0;i<400;i++){
x1+=2; if (x1>17){x1=3;y1+=2;}
//y1+=1;
if (y1>17){y1=3;}


putpixel(bgspr,x1,y1,21);






}

	int k=1;
//	char txt_buffer1[64],txt_buffer2[64];
//	time_t before,after;
//	unsigned long frames;
//	float framerate;

//	init_sincos();
//        z=10;
//	init_sphere();

//	before=time(NULL);
//	frames=0;
trig=0;

accx=0.01;
accy=0.02;
   
	while(k==1)
	{


            clear_to_color(coliface,0);
            clear_to_color(surface,0);





         //          rectfill(surface,0,0,320,240,5);
      //                             blit(coliface,screen,0,0,0,0,320,240);
                        count--;
                      if (count<0){nosound();}
                       if (count==29){
                       sound(hitball*100);

                      // play_midi(eff,0);midi_seek(hitball+20);
                       }
                      
      if (trig==0){

     if (key[KEY_LEFT]){ accy+=0.001; g++; ang+=0.01;

     }
     if (key[KEY_RIGHT]){ accy-=0.001; g--; ang-=0.01;


                     }
     }
     if (key[KEY_UP]){  accx+=0.001; if (trig==0){
     trig=1;
     acc=1;  acc2=0.06; }    }
     
     if (key[KEY_DOWN]){  accx-=0.001;   }
                       board();
             balls();
                   player();
	
             balltoballcol();
                             blit(surface,screen,0,0,0,0,320,240);



if (key[KEY_ESC]) {

k=0;  }












}
return 0;}END_OF_MAIN()


