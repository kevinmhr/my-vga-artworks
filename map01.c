
//keyvan mehrbakhsh 2024
// note : it's a progressive attempt so it's not to be the same as time passes
// till it getting to some reasonable point maybe or maybe not :D .

#include <allegro.h>
#include <math.h>
#include <stdio.h>
char *bitmapbuffer;
int vertices[]={50,50,70,100,150,50};
int pixdrivex;
int pixdrivey;
 int invx=1;
               int invy=1;
double times=1;
int pixstep;
int  pixstepsxmin;
int pixstepsymin;
int  pixstepsxmax;
int pixstepsymax;
  double j=12.0;
  double i=13.0;
int orient[]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,160,150,140,130,120,110,100,90,80,70,60,50,40,30,20,10};
int z;
int dirx=0;
double pixdirx=10;
double pixdiry=33;
double stepx=0.01;
double stepy=0.01;
int diry=0;
int roll=0;
int hit=0;
int keytrig=0;
int color;
int y=60;
int framex,framey;
int k;
int x=103;
double pixx[10];
double pixy[10];
double t;
double t2;
int x2;
 double planex;
 double planex2;
 int posx=0;             int planey;
int r=0;;
int k;
int ti;
int ti2;
int ti3=1;
int ti4;
int colx,coly;
int xoffset=0;
int playerx=0;
int playery=0;
int swi=1;
int swi2=0;
int blockx;
int blocky;
 int pixhitx=1;
 int pixhity=1;
 int frame;
 int k;
 float camerax;
 float cameray;
 int disx,disy;
 int tx=1;
 int tx2=0;
int f;
int walltall;
int colmap2[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
               4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
               7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
               10,10,10,10,10,10,10,10,10,10.10,10,10,10,10,10,10,10,10,10};
int colmap[]={1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,
              4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,
              7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,
               10,10,10,10,10,10,10,10,10,10};

               
int incdec=1;


  int vertical=0;
   int plus1=0;
     int plus2=0;
int lenght;
 BITMAP *the_image;
   BITMAP *the_block1;
   PALETTE the_palette1;
   PALETTE the_palette;
   PALETTE the_palette2;
   BITMAP *walkingspr;
   BITMAP *sprites;
     BITMAP *surface;
    BITMAP *sprsheet;
    BITMAP *spr1;
char spritebuf[256];
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
int map[20][20]={
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1},
{1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,1,0,0,1},
{1,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},};
int timer(){




     if(ti>1000){z=z+1;}
          if(ti<1000){z=z-1;}
 if (ti>=2000){incdec=-1;}
   if (ti<=0){incdec=1;}
//  if (shift>=32){shift=1;}


             ti=ti+(incdec);

          //x+=y/10;




         x+=ti/500+(z)/20;
         x2+=ti/500+(z)/20;
         x2=x2-1;
















}


int drawroad (){


                          ti2++;
    if (ti2>100){timer();ti2=0;}


              k=k+1;
             // drawroad();

          if (k>=400){k=0;  x=0;x2=0;}




      //   for (int k=100;k<200;k=k+2)  {
          hline(screen,((x)+68)*2,((-k+800)/4),(x2+122)*2,3);
          hline(screen,((x)+60)*2,((-k+800)/4),(x2+120)*2,1);







}




int bg(){



              f=f+1;

              y=y+2;

             // drawroad();
           if (y>=200){y=0;}
          if (f>=100){f=0;}

             hline(screen,0,f+100,320,9);

        hline(screen,0,y-100,320,7);











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

int mapfunc(){
                        if (key[KEY_LEFT]) {  blockx--;   times=times+1;i=i+0.01; }


             if (key[KEY_RIGHT]) {  blockx++;  times=times-1;  i=i-0.01;  }
             if (key[KEY_UP]) {  blocky--;   j=j+0.01;   }
             if (key[KEY_DOWN]) { blocky++;   j=j-0.01;     }



                           //   if (pixx[r]>=12){pixx[r]=4.0;pixy[r]=4.0;     }
                            //     if (pixx[r]<=-2){pixx[r]=4.0;pixy[r]=4.0;  }
                             //    if (pixy[r]>=12){pixy[r]=4.0;pixx[r]=4.0;    }
                              //    if (pixy[r]<=-2){pixy[r]=4.0;pixx[r]=4.0;       }


                //        if (pixx>20 | pixx<30){pixstep=3;}





                      // invx=1;




                 //    pixstepsxmax=((int)(pixx));
               //    pixstepsymax=((int)(pixy));



                     putpixel(surface,pixstepsxmin*10,pixstepsymin*10,7);
                       putpixel(surface,pixstepsxmax*10,pixstepsymax*10,7);
                    putpixel(surface,(pixx[r]*10)+50,(pixy[r]*10),55);
                  //   if (pixx<10){  invx=1;}
                   //     if (pixx>80){  invx=-1;}
                    //       if (pixy<10){  invy=1;}
                     //   if (pixy>80){  invy=-1;}



                    pixstepsxmin=((int)(pixx[0]+0.1));
                     pixstepsymin=((int)(pixy[0]+0.1));



                         if (color>250){map[pixstepsxmin+1][pixstepsymin]=color; }

                  if (map[pixstepsxmin][pixstepsymin]>0){

                       //i=-i;
                                 //   if (pixstepsxmin<1){     pixy[0]=pixy[0]+0.01;  pixx[0]=pixx[0]+0.01 ; }
                             //  if (pixstepsymin<1){     pixx[0]=pixx[0]+0.01;   pixy[0]=pixy[0]+0.01;      }

                             //  if (pixstepsxmin>9){    pixx[0]=pixx[0]+0.01;    pixy[0]=pixy[0]+0.01;}
                               
                             //  if (pixstepsymin>9){ pixx[0]=pixx[0]+0.01  ;     pixy[0]=pixy[0]+0.01;   }



                                   if ((pixx[r])-pixstepsxmin>0.5){ if ((pixy[r])-pixstepsymin>0.5){
                                                           stepx=-stepx;    stepy=-stepy;
                                          if (pixstepsxmin>0){if (pixstepsymin>0){ if (pixstepsxmin<19){if (pixstepsymin<19){
                                          map[pixstepsxmin+1][pixstepsymin]=map[pixstepsxmin][pixstepsymin];
                                          map[pixstepsxmin][pixstepsymin]=0;            if (pixstepsxmin>10){map[pixstepsxmin-10][pixstepsymin]=color;}    if (pixstepsxmin<10){map[pixstepsxmin+10][pixstepsymin]=color;}
                                             if (pixstepsymin>10){map[pixstepsxmin][pixstepsymin-10]=color;}    if (pixstepsymin<10){map[pixstepsxmin][pixstepsymin+10]=color;}
                              }                                 }}                       }}
                                                           }


                                     if ((pixx[r])-pixstepsxmin>0.5){ if ((pixy[r])-pixstepsymin<0.5) {
                                      stepx=-stepx;    stepy=stepy;


                                                         if (pixstepsxmin>0){if (pixstepsymin>0){ if (pixstepsxmin<19){if (pixstepsymin<19){
                                          map[pixstepsxmin-1][pixstepsymin]=map[pixstepsxmin][pixstepsymin];
                                          map[pixstepsxmin][pixstepsymin]=0;        if (pixstepsxmin>10){map[pixstepsxmin-10][pixstepsymin]=color;}    if (pixstepsxmin<10){map[pixstepsxmin+10][pixstepsymin]=color;}
                                             if (pixstepsymin>10){map[pixstepsxmin][pixstepsymin-10]=color;}    if (pixstepsymin<10){map[pixstepsxmin][pixstepsymin+10]=color;}
                              }                                 }}                       }}









                                                             }

                          if ((pixx[r])-pixstepsxmin<0.5){ if ((pixy[r])-pixstepsymin<0.5)  {
                                               stepx=-stepx;    stepy=stepy;

                                       if (pixstepsxmin>0){if (pixstepsymin>0){ if (pixstepsxmin<19){if (pixstepsymin<19){
                                          map[pixstepsxmin][pixstepsymin+1]=map[pixstepsxmin][pixstepsymin];
                                          map[pixstepsxmin][pixstepsymin]=0;          if (pixstepsxmin>10){map[pixstepsxmin-10][pixstepsymin]=color;}    if (pixstepsxmin<10){map[pixstepsxmin+10][pixstepsymin]=color;}
                                              if (pixstepsymin>10){map[pixstepsxmin][pixstepsymin-10]=color;}    if (pixstepsymin<10){map[pixstepsxmin][pixstepsymin+10]=color;}
                              }                                 }}                       }





                                    


                        }    }

                             if ((pixx[r])-pixstepsxmin<0.5){ if ((pixy[r])-pixstepsymin>0.5) {

                                      stepx=stepx;    stepy=-stepy;

                                             if (pixstepsxmin>0){if (pixstepsymin>0){ if (pixstepsxmin<19){if (pixstepsymin<19){
                                          map[pixstepsxmin][pixstepsymin-1]=map[pixstepsxmin][pixstepsymin];
                                          map[pixstepsxmin][pixstepsymin]=0;         if (pixstepsxmin>10){map[pixstepsxmin-10][pixstepsymin]=color;}    if (pixstepsxmin<10){map[pixstepsxmin+10][pixstepsymin]=color;}
                                           if (pixstepsymin>10){map[pixstepsxmin][pixstepsymin-10]=color;}    if (pixstepsymin<10){map[pixstepsxmin][pixstepsymin+10]=color;}
                              }                                 }}                       }







                        }      }







                         }

                             pixx[r]=pixx[r]+i*(stepx);
                            pixy[r]=pixy[r]+j*(stepy);




                  if (map[pixstepsxmin][pixstepsymin]>=1){
          


                                                                          color++;if (color>256){color=1;}
                                 map[pixstepsxmin][pixstepsymin]=color;


                   }

                    dirx=(blockx)*10;
                    diry=(blocky)*10;
                 hit=0;

                 if (map[blockx][blocky]==1){

              hit=1;
              }



                                       int w=1;
                              for (int i=0;i<200;i=i+10){
                              for (int j=0;j<200;j=j+10){

                             //   rectfill(screen,i*10,j*10,(i*10)+10,(j*10)+10,1);
                            if (map[i/10][j/10]>0){



                            rectfill(surface,(i)+50,(j),(i)+60,(j)+10,map[i/10][j/10]);
                                                      blit(sprsheet,surface,map[i/10][j/10]+(i)/4,map[i/10][j/10]+(j)/4,(i)+50,(j),10,10);            }


                             // hline(screen,i,j,j+10,5 )
                              line(surface,(i)+50,(j),(i)+50,(j)+10,1);    line(surface,(i)+50,(j),(i)+60,(j),1);

                             // rect(screen,dirx+10,diry+10,dirx+10,diry+20,8);
                    }        }
           //   if (hit==1) {



               //

             //                                 }
                                              //  }






}








int main(int argc, char *argv[]) {
              pixx[r]=6.5;
              pixy[r]=5.0;
                disy=140;
              disx=40;

   int x=1;
   int *dots;
   if (allegro_init() != 0)
      return 1;

  // if (argc != 2) {
    //  allegro_message("Usage: 'exbitmap filename.[bmp|lbm|pcx|tga]'\n");
    //  return 1;
  // }

   install_keyboard();

   if (set_gfx_mode(GFX_AUTODETECT, 320, 240, 0, 0) != 0) {
      if (set_gfx_mode(GFX_SAFE, 320, 200, 0, 0) != 0) {
       set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
 return 1;
      }   }
   //  drawing_mode(DRAW_MODE_TRANS, NULL,0,0);
//set_multiply_blender(0, 0, 0, 0);
       set_color_depth(8);
   //set_write_alpha_blender();
//bitmapbuffer="metal.bmp";
   /* read in the bitmap file */

       //   solid_mode();
  // the_image= load_bitmap(bitmapbuffer, the_palette1);
   sprsheet=load_bitmap("spritesheet.bmp",the_palette2);
     set_palette(the_palette2);
//    the_block1= load_bitmap("block1.bmp",the_palette2);
     spr1=create_bitmap(20,20);
  surface=create_bitmap(320,240);

       walkingspr=load_pcx("walking.pcx",the_palette);
   // mapfunc();
//   set_palette(the_palette2);
//    set_alpha_blender();

    t=1;

    plus1=0;
     xoffset=0;
     camerax=0;
   //   frame=0;
  //      spritefunction();
     while (i!=0){






                                         ti2++;  if (ti2>100){

         //     poll_keyboard();
                                                      ti2=0;ti++;if (ti>100){ ti=0; rectfill(surface,0,0,320,240,0); mapfunc();               ti3++; blit(surface,screen,0,0,0,0,320,240);
                                                                           ti3++;   if (ti3>=50){ti3=0;}  //   clear_to_color(screen,0);}
                                                    }                          }







                                                                                                                           //  draw_trans_sprite(spr1,walkingspr,0,0);


                                                                                                                          //    blit(surface,screen,framex ,framey,playerx,playery,25, 30);
                                                                                                                                 }




destroy_bitmap(screen); destroy_bitmap(surface);

   
   readkey();
   return 0;}END_OF_MAIN()


