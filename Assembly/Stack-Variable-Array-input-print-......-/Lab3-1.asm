code    segment
	assume  cs:code, ds:code 
        
main:
	mov     ax, code         
	mov     ds, ax 
;--------------------------------------------------
	mov	bx, 300h	; pointer
	mov	ax, [bx]	; first word number
	add	ax, [bx+200h]	; add second word number
	mov	[bx+100h], ax	; storage result
	mov	ax, [bx]	; first word number
	sub	ax, [bx+200h]	; sub second word number
	mov	[bx+102h], ax	; storage result
;--------------------------------------------------
        mov     ah, 4Ch
        int     21h
code    ends
        end     main

