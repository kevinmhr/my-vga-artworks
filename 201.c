#include <allegro.h>
#include <math.h>
int k=1;
int scy=0;
int addy=0;
       double obsticlex[100000];
       double axismove[100000];
       double somenum=1;
       int split=1;
       int x=-1;
       int y=0;
       int addx=0;
       int num2;
       int num3;
       int num4;
       int hits;
       int copanimx=0;
       double planex=160;
       double planey=180;
       double throtl=0;
       double throtr=0;
       double throtu=0;
       double throtd=0;


       
       double curvature=0;
       double scrol=0;
       double sizex=0;
       double sizey=0;
       double offy=0;
       double offx=0;
       int map[100000];
       int rows=0;

      int mapfil=0;
      int ys=0;
      int xs=0;
void blitnumtex(int sc,int textplacex,int textplacey,int digit);




BITMAP* font1;
BITMAP* sprites;

BITMAP* collisionbmp;
BITMAP* surface;
PALETTE PAL;

int mapshape(){

                      mapfil=0;
                      somenum=1;
                        int mapfil=0;
                        double ui=-160;
                        for (int i=99980;i>0;i--){
                      ui+=4;
                      ui=ui;
                      if (ui>160){ui=-160;}

                      somenum+=((cos(ui)*40)*sin(i)*50);
       mapfil+=somenum/70;map[i]=0;
        if (mapfil>1300){map[i]=1;}
         if (mapfil>1850){map[i]=2;}
              if (mapfil>1995){map[i]=5;}
      
           if (mapfil>1999){map[i]=3;}
     
        if (mapfil>2000){map[i+10]=4;}
          if (mapfil>2001) {mapfil=0;}
     //    if (mapfil>5009){mapfil=0;}
                        }

                 for (int i=0;i<1000;i++){

                            map[i]=0;
                              map[i+99000]=0;
                        }



               }


void mapfn(){
                            clear_to_color(surface,0);
             clear_to_color(collisionbmp,0);


               x=0; y=addy-4;
               
             for (int i=0;i<800;i++){


             x+=1;
       if (x>32){y+=10;x=0; }


                                                 if (map[i+rows]==1){
       masked_blit(sprites,surface,54,21,(x*10)+offx,(y)-10,10,10);
//       rect(surface,(x*10)+offx,(y)-10,(x*10)+(10)+offx,(y)+(10)-10,4);
                                    }


                  if (map[i+rows]==2){


       rect(surface,(x*10)+offx,(y)-10,(x*10)+(10)+offx,(y)+(10)-10,3);
       //   rectfill(surface,(x*10)+offx,(y)-10,(x*10)+(10)+offx,(y)+(10)-10,9);

                                  }













            }




                        x=0; y=addy-14;
               
             for (int i=0;i<800;i++){


             x+=1;
       if (x>32){y+=10;x=0; }



                          if (map[i+rows]==3){
         circlefill(surface,(x*10)+offx,(y)-10,3,237);

   circle(surface,(x*10)+offx,(y)-10,3,247);

      rectfill(collisionbmp,(x*10)+offx-5,(y)-10,(x*10)+offx+10,(y)-10+10,34);

             int colx=getpixel(collisionbmp,planex,planey);
       if (colx==34){ map[i+rows]=0;mapfn();      hits+=1; sound(300);}
     






                                    }







                                    
                  if (map[i+rows]==4){
         masked_blit(sprites,surface,6,0,(x*10)+offx,(y)-10,15,32);

         rectfill(collisionbmp,(x*10)+offx,(y)-10,(x*10)+offx+10,(y)-10+32,35);

              int colx=getpixel(collisionbmp,planex,planey);
      if (colx==35){rows=99999;num2=0;num3=0;num4=0;planex=150;planey=180;hits=0;mapshape();mapfn();};

                                    }



                  if (map[i+rows]==5){

                if (axismove[i+rows]<0){copanimx=0;}
                   if (axismove[i+rows]>0){copanimx=15;}

               masked_blit(sprites,surface,70,copanimx+1,obsticlex[i+rows],(y)-10,14,14);
               int colx=getpixel(collisionbmp,obsticlex[i+rows],y-10);
                if (colx==35){axismove[i+rows]=-axismove[i+rows];}
          
         rectfill(collisionbmp,obsticlex[i+rows],(y)-10,obsticlex[i+rows]+14,(y)-10+14,47);
              colx=getpixel(collisionbmp,planex,planey);
      if (colx==47){rows=99999;num2=0;num3=0;num4=0;planex=150;planey=180;hits=0;mapshape();mapfn();};

             obsticlex[i+rows]+=axismove[i+rows];


       
                        }




         }



                  }











int main(){

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



font1=load_bitmap("fonts.bmp",PAL);
sprites=load_bitmap("201.bmp",PAL);
set_palette(PAL);
surface=create_bitmap(320,240);
collisionbmp=create_bitmap(320,240);

    split=1;
   somenum=5;
mapshape();
rows=100000;
int r=0;
for (x=0;x<100000;x++){
r++;
obsticlex[x]=0;axismove[x]=0.05;
 if (r==1){obsticlex[x]=320;axismove[x]=-0.05; }
if (r==2){r=0;}

//axismove[x]=0.05;

}

  while (k==1){


 
           if (rows<1) {  if (split>10){split=1;}  split++;

                 mapfil=0;

                        }






       if (rows<0) {      if (somenum>100){somenum=2;}   somenum++;  mapshape();       rows=99000; }


              y=-4;
              x=-1;
           addx=sin(scrol)*10;
         //   sizey=sin(curvature)*10;
         //   sizex=cos(curvature)*10;


            offx=addx-10;
           
             //   curvature=(cos(scrol))*10;
            scy++; if (scy>planey/30){scy=0;

               addy++;     if (addy>10){addy=0;      rows-=33; sound (0);  }
               scrol+=0.01;


                           }



              mapfn();





      //   line(surface,planex,planey,planex+10,planey,15);
       //    line(surface,planex,planey,planex-10,planey,15);
        //     line(surface,planex,planey,planex,planey-15,15);
         //        line(surface,planex-10,planey,planex,planey-15,15);
          //           line(surface,planex+10,planey,planex,planey-15,15);
        masked_blit(sprites,surface,24,10,planex-14,planey,22,22);


             blitnumtex(hits,10,10,4);
            blit(surface,screen,0,0,0,0,320,240);

                   planex-=throtl;
                   planex+=throtr;
                   planey-=throtu;
                   planey+=throtd;
                   if (planex<10){planex=10;}
                   if (planex>300){planex=300;}
                   if (planey<10){planey=10;}
                   if (planey>160){planey=160;}
               

                     if (throtl<0){throtl=0;}
                     if (throtr<0){throtr=0;}
                     if (throtl>1){throtl=1;}
                     if (throtr>1){throtr=1;}
                     if (throtu<0){throtu=0;}
                     if (throtd<0){throtd=0;}
                     if (throtu>1){throtu=1;}
                     if (throtd>1){throtd=1;}
                

                    throtl-=0.0009;
                    throtr-=0.0009;
                    throtu-=0.0009;
                    throtd-=0.0009;
                  if (key[KEY_RIGHT]) {  throtr+=0.0015;     }
                    if (key[KEY_LEFT]) {  throtl+=0.0015;      }
                     if (key[KEY_UP]) {  throtu+=0.0015;     }
                    if (key[KEY_DOWN]) {  throtd+=0.0015;      }

    if (key[KEY_ESC]) {

        k=0;  }

}
return 0;


}







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
     int i=1;
    int coly=y;

 //    if (warp=1){      coly=y*sin(warpy/10)*2; }

        for (int d=1;d<digit+1;d++){
   col=getpixel(font1,(integ[d])+x,y);
  // slow++; if (slow>50000){ slow=0;        slow2+=1; }


       if (col==255){


      col=col;

     putpixel(surface,((i*fontsize)+((x-d*6))+textplacex+40),textplacey+(coly),255);

    }


    }        }

    











}




