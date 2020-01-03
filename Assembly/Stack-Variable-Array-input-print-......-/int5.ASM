data segment
msg1 db 'Enter letter: $'
msg2 db 'Enter digit: $'
data ends
code segment
assume ds:data,cs:code
start:  mov ax,data
        mov ds,ax


	; print mes1
        mov dx,offset msg1	
        mov ah,9
        int 21h

	; enter letter from input
        mov ah,1
        int 21h
	

        mov bl,al  ;code ASCII letter
		
	mov dl,10 ;new line
	mov ah,2
        int 21h
	

	; print mes2
        mov dx,offset msg2
        mov ah,9
        int 21h

	;enter digit from input
        mov ah,1
        int 21h


	;number from code ASCII digit
        sub al,'0' 
	mov cx,0
	mov cl,al

	mov dl,10 ;new line
	mov ah,2
        int 21h

;output
        mov dl,bl
next:   mov ah,2
        int 21h
        loop next
        mov ah,4ch
        int 21h
code ends
end start


