code segment
        assume cs:code,ds:code
main: mov ax,code
      mov ds,ax
      
      MOV BX,600H 
      mov byte ptr [bx],34h
      MOV AL,[BX]
      MOV SI,605H
      MOV [SI],AL

code ends
end main
