data segment

MSG db 'Hello!!!$'

data ends

code segment
assume cs: code, ds: data
main: mov ax, data
      mov ds, ax
      
	mov	ah, 1
	int	21h

	
	
	mov	ah, 4CH
	int	21H

	
code ends
end main

