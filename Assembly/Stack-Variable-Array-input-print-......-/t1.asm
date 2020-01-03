code segment
        assume cs:code,ds:code
main: mov ax,code
      mov ds,ax
      mov dx,offset mess
      mov ah,9
      int 21h
      mov ax,4c00h
      int 21h
mess db 'Hi all!!!$'
code ends
end main
