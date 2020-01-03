data segment

arr db 23h,22h,10h,38h,99h,0ffh

data ends

stack segment stack

db 10 dup(0)

stack ends


code segment
assume ds:data,cs:code,ss:stack
start:  mov ax,data
        mov ds,ax
	
	mov cx,6
	mov bx,0
	mov dh,0
	
loopchk:mov al,arr[bx] ;xy
	mov dl,arr[bx]
	push cx
	mov cl,4
	shr al,cl ;0x
	shl dl,cl ;y0
	shr dl,cl ;0y
	cmp al,dl
	jne cont
	inc dh
cont:	inc bx
	pop cx
	loop loopchk
	
	add dh, '0'
	mov dl,dh
	mov ah,2
        int 21h


     	mov ah,4ch
        int 21h
code ends
end start


