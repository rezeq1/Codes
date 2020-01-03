code segment
  assume cs:code,ds:code
main :
        mov ax,code
        mov ds,ax
 mov si,100h              ;put 10 values starting with the adress 100h
 mov byte ptr [si],2h
 mov byte ptr [si+1h],9h
 mov byte ptr [si+2h],0f2h
 mov byte ptr [si+3h],0ah
 mov byte ptr [si+4h],1h
 mov byte ptr [si+5h],43h
 mov byte ptr [si+6h],0adh
 mov byte ptr [si+7h],99h
 mov byte ptr [si+8h],0aah
 mov byte ptr [si+9h],23h
 mov al,0             ;counter of the nigatve numbers
 mov ah,0             ;counter of the positive numbers
 mov di,400h          ;pointer to set starting from this adress all of the positve numbers
 mov bx,300h          ;to set all of the nigative numbers
 mov cx,0ah           ;loop runing 10 times
L1:cmp byte ptr [si],0             ;check if the number is nigative
   jg l2    ;jumping to line L2 if the number is nigative
   inc al             ;counting the nigative numbers
   mov dl,[si]        ;save the nigative number in the requested adress
   mov [bx],dl
   inc bx             ;go to the next adress 
   inc si             ;go to the next adress of the number
   jmp L3             ; jumping to the line L3
   L2:
   inc ah                ;count the positive numbers
   mov dl,[si]            ;save the positive number in the requested adress
   mov [di],dl
   inc di            ;go to the next adress
   inc si            ; go to next number
L3:
loop L1

mov si,500h
mov [si],ah       ;save the counter of the positive numbers  in adress 500h
mov si,600h
mov [si],al      ;save the counter of the nigative numbers in adress 600h

  mov ah,4ch
    int 21h
    sof:nop
    code ends
    end main
