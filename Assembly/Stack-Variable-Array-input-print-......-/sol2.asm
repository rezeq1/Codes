data segment
N dw 0A1H, 0B2h, 0C3h, 0D4h, 0E5h
len dw 5
data ends
stack segment stack
db 100 dup(?)
stack ends
code segment
assume ds:data,cs:code,ss:stack
start:	mov ax,data
	mov ds,ax

	mov bx,offset N
	push bx
	push len

	call reverseproc
	mov ah,4ch
	int 21h

reverseproc proc
	mov bp,sp	; bp = sp
	mov cx,[bp+2]	; cx = len
	
	mov si,[bp+4]	; SI = address N array
	
	
pusharr:push [si]
	add si,2
	loop pusharr

	mov cx,[bp+2]; 	cx = len
	mov si,[bp+4];  si = address N array

poparr: pop [si]
	add si,2
	loop poparr
	
	ret 4

reverseproc endp

code ends
end start

