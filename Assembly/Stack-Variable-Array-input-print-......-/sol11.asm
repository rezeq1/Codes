data segment

msg1 db 'Enter number from 1 to 255. in the end put . : $'

numstr dw 2 dup(0)

numstrLen dw 0

num dw 0

data ends

stack segment stack

db 100h dup(0)

stack ends


code segment
assume ds:data,cs:code,ss:stack
start:  mov ax,data
        mov ds,ax

	; print mes1
	mov dx,offset msg1	
        mov ah,9
        int 21h

	mov bx, offset numstrLen
	push bx
        mov bx, offset numstr
	push bx
	

	call keletProc

	call newLine
	
	mov bx,offset numstr
	mov si,offset num
	
	push bx
	push si
	push numStrLen

	call strToNum 

	mov bx,offset num
	push bx

	call printSqure
	

	mov ah,4ch
        int 21h

;********************************

printSqure proc

	mov bp,sp
	mov bx,[bp+2]
	mov cx,[bx]

loop_ll:push cx
	mov cx,[bx]

loop_l:	mov dl,'*'
	mov ah,2
	int 21h
	loop loop_l	
	
	mov dl,10 ;new line
	mov ah,2
        int 21h

	pop cx
	loop loop_ll
	
	
	ret 2



printSqure endp



;********************************
strToNum proc
	
	mov bp,sp
	mov cx,[bp+2] ;counter
	mov si,[bp+4] ;return
	mov bx,[bp+6] ;string 
	
	mov dl,10 
	mov ax,0 ;res = 0

loop_c: mul dl ; res = res*10
	mov dh,[bx] ;dh = char digit 123 --> 1
	sub dh,'0' ;from char to digit
	add al,dh ; res = res + digit
	inc bx ; next digit
	loop loop_c

	mov [si],ax ; return real number
	
	ret 6

strToNum endp
		
	
;*******************************
keletProc proc
	mov bp, sp
	mov bx,[bp+2] ; ref to string
	mov dx,0	

loop_in:mov ah,1
        int 21h
	cmp al,'.'
	je end_input
	mov [bx],al
	inc dl ;count how much digits in number
	inc bx
	jmp loop_in
end_input:
	mov bx,[bp+4]; ref to length
	mov [bx],dx ;counter
	ret 4
keletProc endp
;*******************************

newLine proc
	mov dl,10 ;new line
	mov ah,2
        int 21h
	ret
newLine endp  
;*******************************



     	
code ends
end start


