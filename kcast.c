
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
 double anglevalue=0;
 int invx=1;
  double raydiry;
  double raydirx;
  double speed;
int lhight;
        double i=0.1;              int invy=1;
double times=1;
int vlinemin=50;
int vlinemax=100;
                                
int pixstep;
int scanpixx=1;
int scanpixy=1;
int  mapx;
int mapy;
double dirrx;
double dirry;
int  pixstepsxmax;
int pixstepsymax;
  double j=0.1;
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
double rayx[10],rayy[10];
int keytrig=0;
int color;
int y=60;
int framex,framey;
int k;
int x=103;
double pixx[1];
double pixy[1];
double t;
double t2;
int x2;
 double planex=1;
 double planex2;
 int posx=0;             double planey=1;
double angle;
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
 double camerax;

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
int map[10][10]={
{1,1,1,1,1,1,1,1,1,1},
{1,0,1,1,0,0,1,0,0,1},
{1,0,0,0,1,0,0,0,0,1},
{1,0,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1,1,1},
{1,0,0,1,0,1,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,0,0,1,1,0,1,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1},};
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




                     putpixel(screen,mapx*10,mapx*10,5);
                   //    putpixel(screen,pixstepsxmax*10,pixstepsymax*10,5);
                                         int h=200;
     double w=640;

                                 if (ti3>=50){ti3=0;  ; clear_to_color(screen,0);    }
                             for (int k=0;k<w;k=k+1){

                                    double deltadistx;
                                   double deltadisty;

                                             double sidedistx;
                                    double sidedisty;
       
                    //   if (map[pixstepsxmin][pixstepsymin]=0){

                                  double camerax=(k*2)/(double)w-1;
                                      int   mapx= (pixx[r]);
                                    int   mapy=(pixy[r]);
                                  raydirx=dirrx+planex*camerax;
                                  raydiry=dirry+planey*camerax;
                        //         rayy[r]=pixy[r];
                                                         //   (raydirx=0);

                                                        //    (raydiry=0);
                                                        deltadistx=sqrt(1+(raydiry*raydiry)/(raydirx*raydirx))*2;
                                                        deltadisty=sqrt(1+(raydirx*raydirx)/(raydiry*raydiry))*2;
                                            speed=0.001;

                                     int stepx;
                                     int stepy;

                                        int side;
                                 int rayhit=0;
                                    double perpwalldist;
             if (raydirx<0){   stepx=-1;
             sidedistx=(pixx[r]-mapx)*deltadistx;}

              else {   stepx=1;
             sidedistx=(mapx+1.0 -pixx[r])*deltadistx;}

             
                if (raydiry<0){   stepy=-1;
             sidedisty=(pixy[r]-mapy)*deltadisty;}

             
                else{   stepy=1;
             sidedisty=(mapy+1.0 -pixy[r])*deltadisty;}
             





                   while(  rayhit==0){

                   if( sidedistx<sidedisty)
                   {sidedistx+=deltadistx;
                   mapx+= stepx;
                   side=0;
                   }
                   else
                   { sidedisty+= deltadisty;
                   mapy+= stepy;
                   side =1;
                   }

                     if (map[mapx][mapy]>0){ rayhit=1;}

                
                       } 
                      if (side==1){color=5;}
                      if (side==0){color=4;}


                                   if (side==0) {perpwalldist=(sidedistx-deltadistx);}
                          else  {  perpwalldist=(sidedisty-deltadisty);}
                        int lhight=(int)400/perpwalldist;




                  int drawstart= -lhight/2+h/2;
                if (drawstart <0){ drawstart=0; }
                int drawend= lhight/2+h/2;
                if (drawend>=h){ drawend=h; }


                          vline(screen,k,drawstart,drawend,color);

                 }

                            putpixel(screen,(pixx[r]*10)+100,(pixy[r]*10)+50,3);


                               //                rayy[r]-=0.1;
                              // rayx[r]+=i/1000;





                              //   color++;if (color>10){color=1;}






                  //  pixx+=;
                  //  pixy+=;
               //        x=x*invx;
              //  y=y*invy;
                 //  x=stepx;
                 //  y=stepy;


                    //   if (pixx<50){invx=-invx;}


                 //     if (x>1){x=1;}
                  //  if (y>1){y=1;}
                   //  if (x<-1){x=-1;}
                  //  if (y<-1){y=-1;}

               //   else {invx=1;  invy=-1;}


                         



                //   pixx+=((pixdirx*sin(x))/(pixdiry*cos(x)))/2;
                //   pixy+=((pixdirx*sin(y))/(pixdiry*cos(y)))/2;

                    dirx=(blockx)*10;
                    diry=(blocky)*10;
                 hit=0;

                 if (map[blockx][blocky]==1){

              hit=1;
              }

      //     for (int k=0;k<320;k=k+1){
                 //     dirx=7;
                  //    diry=4;
                   //   hit=0;
  //    putpixel(screen,(pixx[r])+100,(pixy[r])+50,3);





                       //    if (posx<0){posx=100;}


            // int dirx=abs(1/camerax);

          //   planex2 =(camerax)-(cameray);


                 //    posx++;

                   //                 z++;


                                      // int w=1;
                              for (int i=0;i<100;i=i+10){
                              for (int j=0;j<100;j=j+10){
                            if (map[i/10][j/10]==1){  rectfill(screen,i+100,j+50,i+110,j+60,3);             }

                             // hline(screen,i,j,j+10,5 )
                              line(screen,i+100,j+50,i+100,j+60,1);    line(screen,i+100,j+50,i+110,j+50,1);  } }

                              rect(screen,dirx+100,diry+50,dirx+110,diry+60,8);
                              
              if (hit==1) {
                //  cameray=dirx;
                      planey++;

                     // if (posx>40){posx=0;}




                           rectfill(screen,dirx+100,diry+50,dirx+110,diry+60,1);

                                              }
                                              //  }


                 planex2 =(posx)+70;


    // if (map[planey]>0){







   //  rectfill(screen,50,50,100,100,8);



                      // if (dirx>=100){dirx=0;}
}


int draw(){








}
int keyboard(){

      if (key[KEY_LEFT]) {   pixx[r]-=0.01;dirx--; }



             if (key[KEY_RIGHT]) {  pixx[r]+=0.01; dirx++;}
             if (key[KEY_UP]) {        pixy[r]+=0.01;   }
             if (key[KEY_DOWN])  { pixy[r]-=0.01;          }
                if (key[KEY_Q]) { anglevalue=1000;   dirrx+=5*sin(anglevalue);
                                                       dirry+=5*cos(anglevalue);
                                                       planex+=5*sin(anglevalue);
                                                       planey+=5*cos(anglevalue);

                                                                                 }
                 if (key[KEY_A]) {    anglevalue=1000;    dirrx-=5*sin(-anglevalue);
                                                            dirry-=5*cos(-anglevalue);
                                                            planex-=5*sin(-anglevalue);
                                                            planey-=5*cos(-anglevalue);
                                                                                   }

              poll_keyboard();










}




int keyboard2(){

            double olddirrx=dirrx;
             double oldplanex=planex;
      if (key[KEY_LEFT]) {

      dirrx= dirrx*cos(-speed)-dirry*sin(-speed);
     dirry= olddirrx*sin(-speed)+dirry*cos(-speed);

     planex= planex*cos(-speed)-planey*sin(-speed);
     planey= oldplanex*sin(-speed)+planey*cos(-speed);







     }

             if (key[KEY_RIGHT]) {


     dirrx= dirrx*cos(-speed)-dirry*sin(-speed);
     dirry= olddirrx*sin(-speed)+dirry*cos(-speed);

     planex= planex*cos(-speed)-planey*sin(-speed);
     planey= oldplanex*sin(-speed)+planey*cos(-speed);

              }

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

   if (set_gfx_mode(GFX_AUTODETECT, 320, 200, 0, 0) != 0) {
      if (set_gfx_mode(GFX_SAFE, 320, 200, 0, 0) != 0) {
       set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
 return 1;
      }   }
   //  drawing_mode(DRAW_MODE_TRANS, NULL,0,0);
//set_multiply_blender(0, 0, 0, 0);
  //     set_color_depth(8);
   //set_write_alpha_blender();
//bitmapbuffer="metal.bmp";
   /* read in the bitmap file */

       //   solid_mode();
  // the_image= load_bitmap(bitmapbuffer, the_palette1);
   sprsheet=load_bitmap("spritesheet.bmp",the_palette2);
   //   set_palette(the_palette);
//    the_block1= load_bitmap("block1.bmp",the_palette2);
     spr1=create_bitmap(320,240);
  surface=create_bitmap(320,240);
 //      spritefunction();
       walkingspr=load_pcx("walking.pcx",the_palette);
   // mapfunc();
//   set_palette(the_palette2);
//    set_alpha_blender();

    t=1;
    int i;
    i=1;
    plus1=0;
     xoffset=0;
     camerax=0;
           rayx[r]=pixx[r];
          rayy[r]=-5;
     while (i!=0){
                             ti2++;  if (ti2>20000){ti2=0;ti3++;    keyboard();       mapfunc();
                          }






                   }





destroy_bitmap(screen); destroy_bitmap(the_image);

   
   readkey();
//   return 0;
}END_OF_MAIN()


