
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <mem.h>
#include <math.h>
#include <time.h>
#include <string.h>
#define set_vga() { asm { mov ax,13h; int 10h } }
#define set_text() { asm { mov ax,03h; int 10h } }
#define MAX_POINTS 8
     //int x,x2,y,col;
int k=1,i;
	int x,y,col;
   int x2,tme;
unsigned char *frame_buffer,palette[768],*background;
int object_translated[320];
void clear_buffer(void)
{
	asm {
		push es
		les di,frame_buffer
		db 66h
		xor ax,ax
		mov cx,16000
		cld
		db 66h
		rep stosw
		pop es }
}

void copy_buffer(void)
{
	asm {
		push ds
	       push es
		lds si,frame_buffer
		mov ax,0a000h

		mov es,ax

		xor di,di
		mov cx,16000
		cld
		db 66h
		rep movsw
		pop es
		pop ds }
}
void retrace(void)
{
	while(!(inp(0x03da)&8));
	while((inp(0x03da)&8));
}

void set_palette(void)
{
	int i;

	outp(0x03c8,0);
	for(i=0;i<768;i++) outp(0x03c9,palette[i]);
}

void get_palette(void)
{
	int i;

	outp(0x03c7,0);
	for(i=0;i<768;i++) palette[i]=inp(0x03c9);



}

void line(int x1,int x2,int y,
					unsigned char color1,unsigned char color2)
{
	asm {
		mov ax,x1
		cmp ax,x2
		je quit
		jb ok

		xchg ax,x2
		mov x1,ax

		mov al,color1
		xchg al,color2
		mov color1,al }
ok:
	asm {
		push es
		les di,frame_buffer
		mov ax,y
		mov bx,ax
		shl ax,6
		shl bx,8
		add ax,bx
		add ax,x1
		add di,ax

		xor ah,ah
		mov al,color2
		xor bh,bh
		mov bl,color1
		sub ax,bx
		shl ax,7
		cwd
		mov cx,x2
		sub cx,x1
		idiv cx
		mov dx,ax

		xor bh,bh
		mov bl,color1
		shl bx,7
		inc cx
		cld }
draw:
	asm {
		mov ax,bx
		shr ax,7
		stosb
		add bx,dx
		dec cx
		jnz draw
		pop es }
quit:
}
void draw_object_points(int tim,int sz,int sk)
{


	    int x,y;
			    //  sk++;
			  // tim=tim+1;

		       y+=((tan(sk)*cos(x+tim))*sz+100);

			 x=((tan(sk))+sin(x+tim)*sz+170);

			frame_buffer[(y<<6)+(y<<8)+x]=sz;


}


void init_background()
{
	asm {

		les di,background
		mov dx,200 }
ver:
	asm {
		mov cx,320 }
hor:
	asm {
		mov ax,cx
		or ax,dx


		and ax,61
		add al,128+64
		stosb
		dec cx
		jnz hor
		inc dx
		jnz ver
		 }
}
void recover_background(void)
{
	asm {
		push ds
		push es
		les di,frame_buffer
		lds si,background
		mov cx,16000
		cld
		db 66h
		rep movsw
		pop es
		pop ds }
}

void set_palette2(void)
{
	int i;

	outp(0x03c8,128);
	for(i=0;i<128;i++)
	{
		outp(0x03c9,i>>1);
		outp(0x03c9,i>>1);
		outp(0x03c9,i>>1);
	}
  }
int main(void){

 int color,color2;



	clrscr();



	if((frame_buffer=(unsigned char *)malloc(64000))==NULL ||
	(background=(unsigned char *)malloc(64000))==NULL)
	{
		free(frame_buffer);
		printf(
		"%s","Not enough memory!\n\n");
		return 1;
	}

	int x,y,rot,dev;

set_vga();
set_palette2();
init_background();
      while (k==1){

      // line(1,319,y,color,color2);

	   //    tme++;
	     // tme++;
	     x=x+1;
	   // if (x>1000){x=0;}
		x2=x2+1;
	       //	 if (x2>2000){x2=0;}
		 y++;

	   for (i=0;i<x2;i++){
	// if (y>199){color++;color2=color+50;y=0;}
		  //  x++;



	  draw_object_points(y,(rot)/20,x/rot);

	  //  rot++;


	     if (rot==x){rot=0;}
		    rot=rot+1;

	 }

	copy_buffer();
      retrace();
      copy_buffer();
    //  recover_background();

      clear_buffer();



      if (kbhit()){

      return 0;

      }


      }


return 0;

}


