extern scanf
extern printf
extern fflush
    
section .data
    M       dd  7,   11,  10,  6
            dd  5,   8,   9,   12
            dd  11,  13,  12,  15
    ncol    dd  4
    input   db  "%d",0
    output  db  "%d ",0
    outputEndl  db  "%d",10, 0

section .bss
    a resd 1
       
section .text
    global main
        
main:
    push a
    push input
    call scanf
    add esp, 8
    
    ;process
    mov ebx, [a]    ;ebx = skalar
    mov eax, [M]
    mul ebx
    
    ;   print eax
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*1]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*2]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*3]
    mul ebx
    push eax
    push outputEndl
    call printf
    add esp, 8

    mov eax, [M + 4*4]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*5]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*6]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*7]
    mul ebx
    push eax
    push outputEndl
    call printf
    add esp, 8

    mov eax, [M + 4*8]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*9]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*10]
    mul ebx
    push eax
    push output
    call printf
    add esp, 8

    mov eax, [M + 4*11]
    mul ebx
    push eax
    push outputEndl
    call printf
    add esp, 8

    ;clear
    push 0
    call fflush
        
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80