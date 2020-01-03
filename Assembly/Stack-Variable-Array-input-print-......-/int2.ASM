data segment

MSG db 'Hello!!!$'

data ends

code segment
assume cs: code, ds: data
main: mov ax, data
      mov ds, ax
      
	mov dx, offset MSG
	mov ah,9
	int 21h
	
	
	mov	ah, 4CH
	int	21H

	
code ends
end main

