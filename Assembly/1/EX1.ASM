code segment
assume cs:code,ds:code
main:
mov ax,code
mov ds,ax


mov si,150h             ;a pointer register for adress 150h
mov di,200h             ; a pointer register for adress 200h
mov byte ptr [si],4h    ; put an value to adress 150h
mov byte ptr [di],7h    ;put an value to adress 200h
mov al,0                ; counter of the product of the two numbers
mov cx,[si]             ; loop run  [si] times
L1: add al,[di]         ; sum  the value [di] with loop that runs [si] times
loop l1

mov si,300h
mov [si],al             ;put the product of the two numbers in the adress 300h


 mov ah ,4ch
 int 21h
 sof:nop
code ends
end main


