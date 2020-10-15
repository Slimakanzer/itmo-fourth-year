.model small
.stack 256

.data
    TL  DB  11111111b  ; таблица
        DB  01111111b  ; таблица
        DB  00111111b  ; таблица
        DB  00011111b  ; таблица
        DB  00001111b  ; таблица
        DB  00000111b  ; таблица
        DB  00000011b  ; таблица
        DB  00000001b  ; таблица

    TR  DB  10000000b  ; таблица
        DB  11000000b  ; таблица
        DB  11100000b  ; таблица
        DB  11110000b  ; таблица
        DB  11111000b  ; таблица
        DB  11111100b  ; таблица
        DB  11111110b  ; таблица
        DB  11111111b  ; таблица

    VL  DB  10000000b
        DB  01000000b
        DB  00100000b
        DB  00010000b
        DB  00001000b
        DB  00000100b
        DB  00000010b
        DB  00000001b
    
    PRN DB  1ah

.code

include helper.inc

PrintHorizontalLine macro x_start, x_end, y
    mov bx, x_start
    mov cl, 3
    shr bx, cl
    mov dx, bx
    inc dx

    mov ax, y
    mov cl, 4
    sal ax, cl
    add bx, ax
    mov cl, 2
    sal ax, cl
    add bx, ax

    mov ax, x_start
    and ax, 07h
    mov si, ax

    mov al, TL+[si]
    mov es:[bx], al
    inc bx
    
    mov ax, x_end
    mov cl, 3
    shr ax, cl
    sub ax, dx
    mov cx, ax
    mov di, bx
    mov al, 0ffh
    rep stosb

    mov ax, x_end
    and ax, 07h
    mov si, ax

    mov bx, di
    mov al, TR+[si]
    mov es:[bx], al
endm

PrintVerticalLine macro x, y_start, y_end
    LOCAL @@loop
    mov bx, x
    mov cl, 3
    shr bx, cl

    mov ax, x
    and ax, 07h
    mov si, ax
    mov dl, VL+[si]

    mov ax, y_start
    mov cl, 4
    sal ax, cl
    add bx, ax
    mov cl, 2
    sal ax, cl
    add bx, ax

    mov ax, y_end
    sub ax, y_start
    mov cx, ax
    mov al, dl

@@loop:
    mov es:[bx], al
    add bx, 80
    loop @@loop
endm

PrintGleb proc

    call CalcNew
    SetMask [PRN]

    ;--------- G
    PrintVerticalLine 50, 50, 110
    PrintHorizontalLine 50, 80, 50
    PrintHorizontalLine 50, 90, 110
    PrintVerticalLine 90, 80, 110
    PrintHorizontalLine 70, 90, 80

    ;--------- L
    PrintVerticalLine 100, 50, 110
    PrintHorizontalLine 100, 140, 110

    ;--------- E
    PrintVerticalLine 150, 50, 110
    PrintHorizontalLine 150, 190, 50
    PrintHorizontalLine 150, 190, 80
    PrintHorizontalLine 150, 190, 110

    ;--------- B
    PrintVerticalLine 200, 50, 110
    PrintVerticalLine 240, 80, 110
    PrintHorizontalLine 200, 230, 50
    PrintHorizontalLine 200, 240, 80
    PrintHorizontalLine 200, 240, 110

    call WaitAndClear

    ret
PrintGleb endp

CalcNew proc
    int 2ch
    mov ax, 25173          ; LCG Multiplier
    mul word ptr [PRN]     ; DX:AX = LCG multiplier * seed
    add ax, 13849          ; Add LCG increment value
    add ax, dx
    ; Modulo 65536, AX = (multiplier*seed+increment) mod 65536
    mov [PRN], ah          ; Update seed = return value
    ret
CalcNew endp

Entry:
    mov ax, @data   ;make DS point to our DATA segment
    mov ds, ax

    InitGraphic

    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb
    call PrintGleb

    mov ax,4c00h    ;выход
    int 21h         ;
end Entry