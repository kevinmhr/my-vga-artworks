
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





     push cs

      inc cs:wordstartpos
	inc cs:wordstartpos

	push si
	push di
     mov si,cs:wordstartpos
     mov di,1

printit:

      inc si
      inc di

     push bp


      mov bp,offset cs:textmain[si]
      mov al,cs:textmain[si]


	 cmp al,"&"
	  je nextrow


      mov [cs:textstr+di],al
      cmp al,"*"
      jne printit




	mov lenght,si


	 mov cs:wordstartpos,si

	 pop bp


      pop es

      pop si
      pop di






printstr:



     mov di,0

     push ax
     push bx



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

	  push si
	  mov si,0
erasure:
	  inc si
	  mov al," "
	  mov [cs:textstr+si],al
	  cmp si,lenght
	  jne erasure
	  pop si









    push ax


	     mov ah,0
	mov dx,0
	mov bx,0
       mov dx,0
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

      rownum db 2

      horpos db 0
      textmain db "    this*  is*  just*  some*  characters*  but*   is it?*   & "

	 writingspc db ""
     writingend:
	     textstr db "                                               "

















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
