InitGraphic macro
    mov ax, 010h          ; инициализация графического
    int 10h
    mov ax, 0a000h
    mov es, ax
    mov bx, 0h
endm

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

WaitAndClear proc
    WaitKey
    ClearScreen
    ret
WaitAndClear endp

SetMask macro mask
    mov dx, 3c4h
    mov al, 2
    out dx, al
    inc dx
    mov al, mask
    out dx, al
endm
