data segment

msg1 db 'Enter arithmetic string, in the end enter . : $'
msg2 db 'Ok: $'
msg3 db 'Not Ok! $'

data ends

stack segment stack

db 100h dup(0)

stack ends


code segment
assume ds:data,cs:code,ss:stack
start:  mov ax,data
        mov ds,ax

	mov bx,300h ; set address for insert the chars
	mov si,sp	

	; print mes1
	mov dx,offset msg1	
        mov ah,9
        int 21h

	; enter letters loop

loop_in:mov ah,1
        int 21h
	mov [bx],al
	cmp al,'.'
	je end_input
	inc bx
	jmp loop_in
end_input:
	
	mov dl,10 ;new line
	mov ah,2
        int 21h

	mov bx,300h

loop1:	mov ah,0
	mov al,[bx]
	cmp al,'.'
	je sof1
	cmp al,'('
	je add_p
	cmp al,'['
	je add_p
	cmp al,'{'
	je add_p
	jmp next

add_p:	push ax
	jmp cont

next:	cmp al,')'
	je check1
	cmp al,']'
	je check2
	cmp al,'}'
	je check3
	jmp cont

check1: pop cx
	cmp cl,'('
	jne error
	jmp cont

check2:  pop cx
	cmp cl,'['
	jne error
	jmp cont

check3:  pop cx
	cmp cl,'{'
	jne error

cont:	inc bx	
	jmp loop1

sof1:	nop ;end loop1

	cmp sp,si
	jne error

	jmp good

error: 
	; print mes3
        mov dx,offset msg3
        mov ah,9
        int 21h

	mov dl,10 ;new line
	mov ah,2
        int 21h
	jmp end_all

good:
	; print mes2
        mov dx,offset msg2
        mov ah,9
        int 21h

	mov dl,10 ;new line
	mov ah,2
        int 21h

end_all:nop

     	mov ah,4ch
        int 21h
code ends
end start


