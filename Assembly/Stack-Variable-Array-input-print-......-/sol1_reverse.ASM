data segment

msg1 db 'Enter string, in the end put . : $'
msg2 db 'the reverse string is: $'
str1 db 30 dup (0)
str2 db 30 dup (0)

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

        mov bx, offset str1

	; enter letters loop

loop_in:mov ah,1
        int 21h
	mov [bx],al
	cmp al,'.'
	je end_input
	inc bx
	jmp loop_in
end_input:

        inc bx
        mov byte ptr [bx],'$' ;add $ to end
	
	mov dl,10 ;new line
	mov ah,2
        int 21h

        ;add string to stack
        
        mov bx,0

loop_s: cmp str1[bx],'$'
        je end_add_stack
        mov al,str1[bx]
        mov ah,0
        push ax
        inc dl
        inc bx
        jmp loop_s

end_add_stack:
        mov cx,bx
        mov bx,0

loop_s1:pop ax           ;reverse add to str2
        mov str2[bx],al
        inc bx
        loop loop_s1

        mov str2[bx],'$'


        ; print mes2
        mov dx,offset msg2
        mov ah,9
        int 21h

	mov dl,10 ;new line
	mov ah,2
        int 21h
        

        ; print str2 
        mov dx,offset str2
        mov ah,9
        int 21h

	mov dl,10 ;new line
	mov ah,2
        int 21h



     	mov ah,4ch
        int 21h
code ends
end start


