code segment
        assume cs:code,ds:code
main: mov ax,code
      mov ds,ax
      
      MOV BL, 12H 
      MOV BH, 14H
      MOV CL, BL
      MOV BL, BH
      MOV BH, CL

code ends
end main
