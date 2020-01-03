data segment

ans1 db 'Prime!$'         
ans2 db 'NOT Prime!$'
msg db 'Enter number from 2 to 255. in the end put . : $'

string dw 2 dup(0) ;to save the input string
num_digits dw 0  ;the number of the number digits
number dw 0	;to save the number

data ends

stac segment stack

db 100h dup(0)

stac ends


code segment
assume ds:data,cs:code,ss:stac
start:  	mov ax,data
       	 mov ds,ax
	
	mov bx, offset num_digits
	push bx

     	mov bx, offset string
	push bx

	call input  ;input a number
	
	mov bx,offset string
	mov si,offset number
	
	push bx
	push si
	push num_digits

	call convert   ;convert the string that the user enterd to number

	mov bx,offset number
	push bx

	mov dl,10   ; new line
	mov ah,2
      	 int 21h

	call prime_or_no   ;print if the number is prime or no
	

	mov ah,4ch
     	   int 21h



prime_or_no proc

	mov bp,sp
	mov bx,[bp+2] ;the number
	mov dx,[bx]

	xor cx,cx  ;cx=0
	mov cl,2    

Check_: 
	cmp dx,cx  ;check if the division equal to the number
	je end_Check 
	mov ax,dx
	div cl   ;ax/cl
	cmp ah,0 ; check if they are number that divisible without remainder  
	je not_prime ;print no prime
	inc  cl   ;cl++

jmp Check_

end_Check: ;print prime
 	mov dx,offset ans1       
      	  mov ah,9
       	 int 21h
jmp end_

not_prime:
	 mov dx,offset ans2       
     	   mov ah,9
   	     int 21h
end_:

	ret 2

prime_or_no endp




Convert proc
	
	mov bp,sp

	mov cx,[bp+2] ;num digits
	mov si,[bp+4] ;number
	mov bx,[bp+6] ;string 
	
	mov dl,10 
	mov ax,0
help_: 	
	 mul dl  ; multplay with 10
	mov dh,[bx] ;take a one digit
	sub dh,'0' ;convert the code asqi to her number
	add al,dh ; add the digit to the new number
	inc bx 
	loop help_

	mov [si],ax ;save the number
	
	ret 6

Convert endp
		
	


Input proc
	mov dx,offset msg	; print message to input
        	mov ah,9
       	 int 21h

	mov bp, sp
	mov bx,[bp+2]
	mov dx,0	

scaning:	mov ah,1 ;scaning a char
     	   int 21h

	cmp al,'.' ;check if the char is different than dot
	je end_input

	mov [bx],al ;save the char
	inc dl 

	inc bx  ;count the size of the string

	jmp scaning
end_input:
	;save the size of the string
	mov bx,[bp+4] 
	mov [bx],dx 

	ret 4
Input endp






     	
code ends
end start


