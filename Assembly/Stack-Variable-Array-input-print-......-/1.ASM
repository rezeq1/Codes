
stack segment stack

db 100h dup(0)

stack ends


code segment
assume ds:code,cs:code,ss:stack
start:  mov ax,code
        mov ds,ax

	mov ax,10h
	mov bx,8

	push ax
	push bx
	call show_square
	

	mov ah,4ch
        int 21h

;********************************

show_square proc

	mov bp,sp
	mov cx,[bp+4]
	inc cx

loop_ll:push cx
	mov cx,[bp+2]

loop_l:	mov dl,'*'
	mov ah,2
	int 21h
	loop loop_l	
	
	mov dl,10 ;new line
	mov ah,2
        int 21h

	pop cx
	loop loop_ll	
	
	ret 4


show_square endp


     	
code ends
end start


