code    segment
	assume  cs:code, ds:code 
        
main:
	mov     ax, code         
	mov     ds, ax 
;--------------------------------------------------
	mov	si, 300h
	mov	dh, [si]	; Input Mark
	mov	dl, 3		; Start Value
	cmp 	dh, 70
	jb	t1
	mov	dl, 1
	jmp	sof
t1:	cmp	dh, 55
	jb	sof
	mov	dl, 2
sof:	mov	[si+100h], dl		
;--------------------------------------------------
        mov     ah, 4Ch
        int     21h
code    ends
        end     main

