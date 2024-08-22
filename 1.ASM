
.model tiny
.486
.stack 2000h
org 00h




.code


start:
startsort:

getstring:

nextrow: add rownum,1
	mov  cs:wordstartpos,0











nextword:





















 ;     push cs



      inc cs:wordstartpos
      inc cs:wordstartpos





  push si

 mov si,cs:wordstartpos



     push bp



     mov bp,0

printit:

      inc si
      inc bp




 ;     mov bp,offset cs:textmain[si]
      mov al,cs:textmain[si]


	 cmp al,"&"
	  je nextrow


      mov [cs:textstr+bp],al
      cmp al,"*"
      jne printit




	mov lenght,bp


	 mov cs:wordstartpos,si

	 pop bp
	 pop si

;      pop es










printstr:
erasestr:
     mov ah,0
      mov al,1
      mov bx,0

     mov bl,rownum

     mov cx,40
     mov dl,0
     mov dh,rownum
    mov bp,offset blanc
     mov ah,13h
    int 10h









     mov di,0






     mov ah,0
      mov al,1
      mov bx,0

     mov bl,rownum

     mov cx,lenght


     mov dl,horpos
     mov dh,rownum









     push cs
     pop es


    mov bp,offset textstr


     mov ah,13h

    int 10h
      push bp
     mov bp,0






	   push ax


	 mov ah,0


       mov ax,0
       int 16h
       cmp al,13
       je nextword

	 pop ax








     ;  mov ax,12h
    ;  int 10h



	   jmp printit

jump1:
    time dw 0

	    wordstartpos dw 0
 lenght dw 0

      blanc db "                                                 "
      rownum db 0

      horpos db 0
      textmain db "    this*  is*  just*  some*  characters*  but*   is it?*   & "

	 writingspc db ""
     writingend:






	  textstr db "                                                                              "











done:








END start












getstr1:

   cmp rownum,22
   je resetrow

   mov bh,rownum
   add bh,1
   mov rownum,bh



writestring:





     mov al,1
     mov bh,0

    mov bl,12

     mov cx,si
     add cx,1
     mov dl,2
     mov dh,rownum
    push cs
    pop es




    mov bp,offset writingspc
    pop ax
     mov ah,13h

    int 10h








	mov ah,0
	int 16h
	 cmp al,13

	je getstr1
	inc di

	inc si
	mov [offset writingspc+di],al



end
