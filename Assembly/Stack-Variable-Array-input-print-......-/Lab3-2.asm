code    segment
	assume  cs:code, ds:code 
        
main:
	mov     ax, code         
	mov     ds, ax 
;--------------------------------------------------
	mov	si, 200h
	mov	di, 500h
	mov	dl, 0
	mov	bx, [si]
	cmp	bx, [di]
	jbe	t1
	mov	dl, 1
t1:	mov	[si+100h], dl
;--------------------------------------------------
        mov     ah, 4Ch
        int     21h
code    ends
        end     main

