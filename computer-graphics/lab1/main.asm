.model small
.code

ClearScreen macro
    xor   di, di
    mov   cx, 0ffffh
    mov   al, 0
    rep   stosb
endm

WaitKey macro
    xor   ax,ax       ; ожидание нажатия клавиши
    int   16h         ;
endm

WaitAndClear macro
    WaitKey
    ClearScreen
endm

SetMask macro mask
    mov dx, 3c4h
    mov al, 2
    out dx, al
    inc dx
    mov al, mask
    out dx, al
endm

mov ax, 010h          ; инициализация графического
int 10h
mov ax, 0a000h
mov es, ax
mov bx, 0h


;-----------------------------------------------
SetMask 0bh

mov es:[bx], 0ah
;-----------------------------------------------

WaitAndClear

;-----------------------------------------------
PrintPoint macro x, y
    mov ax, x
    mov bx, y
    mov dx, bx

    mov cl, 4       ; y*640 (bytes)
    sal bx, cl
    sal dx, cl

    mov cl, 2
    sal bx, cl
    add bx, dx

    mov cl, 3       ; y*640 + x (bytes)
    shr ax, cl
    add bx, ax

    push bx
    mov cx, x
    and cx, 07h     ; смещение внутри байта
    mov bx, 080h
    shr bl, cl

    mov dx, 3ceh
    mov al, 8
    out dx, al
    inc dx
    mov al, bl
    out dx, al

    pop bx
    mov es:[bx], 0ffh
endm

PrintPoint 1, 1
;-----------------------------------------------

WaitAndClear

mov ax,4c00h    ;выход
int 21h         ;
end