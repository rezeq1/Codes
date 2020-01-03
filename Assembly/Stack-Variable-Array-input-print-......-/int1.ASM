code segment
assume cs: code, ds: code
main: mov ax, code
      mov ds, ax
      
	mov	bh, 0
	mov	dh, 5
	mov	dl, 5
	mov	ah, 2 ; place the cursor in line 5, col. 5s
	int	10h
	
	mov	ah, 4CH
	int	21H

	
code ends
end main
