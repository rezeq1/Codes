code    segment
	assume  cs:code, ds:code 
        
main:
	mov     ax, code         
	mov     ds, ax 
;--------------------------------------------------
	mov	si, 230h
	mov	ah, [si]
	cmp	ah, [si+1]
	jne	t1
	cmp	ah, [si+2]
	jge	t1
	add	ah, [si+1]
	jmp	t2
t1:	sub	ah, [si+2]
t2:	mov	[si+4], ah	
;--------------------------------------------------
        mov     ah, 4Ch
        int     21h
code    ends
        end     main

