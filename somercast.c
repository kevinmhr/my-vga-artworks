/*
 *    Example program for the Allegro library, by Shawn Hargreaves.
 *
 *    This program demonstrates how to load and display a bitmap
 *    file.  You have to use this example from the command line to
 *    specify as first parameter a graphic file in one of Allegro's
 *    supported formats.  If the file is loaded successfully,
 *    it will be displayed until you press a key.
 */


#include <allegro.h>
#include <math.h>
#include <stdio.h>
char *bitmapbuffer;
int vertices[]={50,50,70,100,150,50};

int orient[]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,160,150,140,130,120,110,100,90,80,70,60,50,40,30,20,10};
int z;
int dirx=0;
int roll=0;
int keytrig=0;
int color;
int y;
int framex,framey;
int k;
int x;
double t;
double t2;
int x2;
 double planex;
 double planex2;
 int posx=0;             int planey;
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
 int frame;
 int k;
 float camerax;
 float cameray;
 int disx,disy;
 int tx=1;
 int tx2=0;
int f;
int walltall;
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
int map[]={0,0,1,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,1,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,1,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,1,0,0,1,0,0,
0,0,0,0,0,0,0,0,0,0,
0,1,0,0,1,0,0,0,0,0,
0,1,0,0,1,0,0,0,0,0};
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


              int y;
              int hit=0;
                  if (plus1=200){plus1=0;}



               if (map[planey]>0){
              hit=1;   }


                          posx=cameray;
           for (int k=0;k<320;k=k+1){

              if (hit=1) {posx++; }
                if (posx>planey){posx=0;}


                      planex2 =(posx+100);

                       //    if (posx<0){posx=100;}
            planex =z* (cameray)/planey;

            // int dirx=abs(1/camerax);

          //   planex2 =(camerax)-(cameray);

             z++;



             disx=planex+40+planex2;
             disy=-disx+170;

    // if (map[planey]>0){
     vline(screen,z,disx,disy,3); }
            if (z>320+plus1){z=plus1; }
   //  rectfill(screen,50,50,100,100,8);

                            //  }

                       if (dirx>=100){dirx=0;}
}


int keyboard(){


          tx=1;
            tx2=1;
            t=0.3;
               t2=0.1;



                 colx=getpixel(screen,playerx+10,playery+30);

            // if (colx!=4){t=0;}
                 colx=getpixel(screen,playerx-10,playery+30);

           //  if (colx!=4){t=0;}



                 colx=getpixel(screen,playerx-10,playery-20);

           //  if (colx!=4){t2=0;}
                  colx=getpixel(screen,playerx+10,playery-20);

           //  if (colx!=4){t2=0;}
                   colx=getpixel(screen,playerx,playery-20);

            // if (colx!=4){t2=0;}





             colx=getpixel(screen,playerx+30,playery+10);

          //   if (colx!=4){tx=0;}
               colx=getpixel(screen,playerx+30,playery+20);

           //  if (colx!=4){tx=0;}

              colx=getpixel(screen,playerx-10,playery+20);

            // if (colx!=4){tx2=0;}

              colx=getpixel(screen,playerx-20,playery);

            // if (colx!=4){tx2=0;}

                    colx=getpixel(screen,playerx-20,playery+10);

            // if (colx!=4){tx2=0;}

        if (key[KEY_LEFT]) { camerax-=t; cameray+=t; plus1-=t2;plus2+=t2; framex=framex-25; framey=30; ; frame=frame+400;   if (frame>800){frame=0;} }

                               if (framex>100){framex=0;}     if (framex<0){framex=75;}
    if (key[KEY_RIGHT]) { camerax+=t; cameray-=t;   plus1+=t2;plus2-=t2; framex=framex+25; framey=0;  frame=frame+400;     if (frame>800){frame=0;}   }
         if (key[KEY_UP]) {  dirx+=t;    planey++; cameray+=t;  vertical=vertical-10;}
         //frame=frame+400;  =0;}

   if (key[KEY_DOWN]) {planey--;  cameray-=t;     vertical=vertical+10;}
if  (plus1<0){plus1==9400;}

                    // if (playery>100){playery=0;}

                    //   if (playerx=100){playerx=0;}


                   //    if (camerax<0);{xoffset-=1;camerax=9;}
                     //  if (cameray>10);{playery+=t;cameray=100;}


      //  if (key[KEY_UP]) if (key[KEY_RIGHT]){z++;}
      //  if (key[KEY_UP]) if (key[KEY_LEFT]){z--;}
       //  if (key[KEY_LEFT]) if (key[KEY_RIGHT]){z++;}
       // if (key[KEY_LEFT]) if (key[KEY_LEFT]){z--;}



  //  if (plus>9400){plus==0;}



                         //  plus+=t;


                             mapfunc();

     // spritefunction();

   

}










int main(int argc, char *argv[]) {

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
     while (i!=0){





                  ti3++;            if (ti3>=500){ti3=0;lenght++;   if (lenght >3000){lenght=0;  clear_to_color(screen,0);   ti2+=10;  if (ti2>200){ti2=0;}keyboard();   poll_keyboard();   draw_sprite(surface,walkingspr,0,0); }
                                                                                                                            //  draw_trans_sprite(spr1,walkingspr,0,0);


                                                                                                                          //    blit(surface,screen,framex ,framey,playerx,playery,25, 30);
                                                                                                                                 }

    }


 destroy_bitmap(screen); destroy_bitmap(the_image);

   
   readkey();
//   return 0;
}
END_OF_MAIN()


