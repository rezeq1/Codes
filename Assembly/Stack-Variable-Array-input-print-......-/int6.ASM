data segment

msg1 db 'Enter letters, in the end enter . : $'
msg2 db 'your string in reverse mode: $'
data ends
code segment
assume ds:data,cs:code
start:  mov ax,data
        mov ds,ax

	mov bx,100h ; set address for insert the chars

	; print mes1
	mov dx,offset msg1	
        mov ah,9
        int 21h

	; enter letters loop

loop_in:mov ah,1
        int 21h
	cmp al,'.'
	je end_input
	mov [bx],al
	inc bx
	jmp loop_in
end_input:
	
	mov dl,10 ;new line
	mov ah,2
        int 21h

	; print mes2
        mov dx,offset msg2
        mov ah,9
        int 21h

	mov dl,10 ;new line
	mov ah,2
        int 21h

;output
	dec bx
loop_o: mov dl,[bx]
	mov ah,2
        int 21h
	dec bx
        cmp bx,100h
	jnb loop_o


        mov ah,4ch
        int 21h
code ends
end start


