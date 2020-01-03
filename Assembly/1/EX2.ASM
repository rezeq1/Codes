code segment
        assume cs:code,ds:code
main: mov ax,code
    mov  ds,ax


   mov si,200h                 ;pointer rigster for adress 200h
   mov byte ptr [si],1h        ;put the first number of the series
   mov byte ptr [si+1],1h      ;put the seconde number of the series
   mov si,202h  
   mov di,1000h                ;pointer register for adress 1000h for the sum of the first 15 number of the series
   mov byte ptr [di],2h        ;sum the first two number of the series
   mov cx,0dh                  ; loop that runs 13 times
L1:
mov al,0                       ;register to find the new number of the series
add al,[si-1]     
add al,[si-2]
mov [si],al                    ;set the new number in his adress
add [di],al                    ;sum the new number
add si,1h                      ;promote the pointer to the next adress

loop l1

mov ah,4ch
int 21h
sof:nop
code ends
end main


