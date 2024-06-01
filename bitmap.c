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
char *bitmapbuffer;
int vertices[]={50,50,70,100,150,50};

int orient[]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,160,150,140,130,120,110,100,90,80,70,60,50,40,30,20,10};
int y;
int k;
int x;
int k=100;
int ti;
int ti2;
int ti3;
int ti4;
int swi=1;
int swi2=0;
int f;
int shift;
int incdec=1;
int bg(){



             for (int k=100;k<200;k=k+2)  {

    hline(screen,0,k,320,9);

        hline(screen,0,(k)-100,320,7);
                  }//}













}




int timer(){

 if (ti<=0){incdec=1;}
 if (ti>=2000){incdec=-1;}
 
  ti=ti+(incdec);

         x+=(ti/200)+k/100;


ti3++;

if (y>=200){y=0;  }
if (ti3>200){y++;shift++; ti3=0;bg();}
  if (shift>=32){shift=1;}




          //x+=y/10;















}

int drawroad (){




              k=k+1;
             // drawroad();

          if (k>=400){k=0;x=0;}



            ti2++;
     if (ti2>=5){ti2=0;timer();  }

      //   for (int k=100;k<200;k=k+2)  {

          hline(screen,-(x)+140,(k/4)+100,x+160,1);



}


int main(int argc, char *argv[])
{
   BITMAP *the_image;
   PALETTE the_palette;
   BITMAP *surface;
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
      }
   }
  bitmapbuffer="planet.pcx";
   /* read in the bitmap file */
   the_image = load_pcx(bitmapbuffer, the_palette);
   if (!the_image) {
      set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
      allegro_message("Error reading bitmap file '%s'\n", bitmapbuffer);
      return 1;
   }

   /* select the bitmap palette */
  // set_palette(the_palette);
     int i;
     i=1;
            blit(the_image, screen, 0, 0, 150,
50, the_image->w, the_image->h);
         //   int x;

             for (int k=100;k<200;k=k+2)  {

    hline(screen,0,k,320,9);

        hline(screen,0,k-100,320,7);
                  }//}



     while (i!=0){
   /* blit the image onto the screen */

     //timer();


      
      drawroad();

        //          }//}
        //     for (int i=0;i<5;i++){





      polygon(screen,3,vertices,3);//}


    }
   destroy_bitmap(the_image);
                             destroy_bitmap(screen);



   
   readkey();
//   return 0;
}

END_OF_MAIN()
