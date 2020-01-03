data segment
a dw 0Ah
b dw 2h
c dw 0
data ends
stack segment stack
db 100 dup(?)
stack ends
code segment
assume ds:data,cs:code,ss:stack
start:	mov ax,data
	mov ds,ax

	mov bx,offset a
	push bx
	mov bx,offset b
	push bx
	mov bx,offset c
	push bx

	call divideproc
	mov ah,4ch
	int 21h

divideproc proc
	mov bp,sp	; bp = sp
	mov bx,[bp+2]	; bx = address c
	mov ax,[bx]	; ax = c
	mov si,[bp+4]	; SI = address b
	mov dx,[si]	; dx = b
	mov di,[bp+6]	; di = address a
	mov cx,[di]	; cx = a
	
next:	cmp cx,0	
	je endloop
	sub cx,dx
	inc ax
	jmp next

endloop:mov [bx],ax
	ret 6

divideproc endp

code ends
end start
