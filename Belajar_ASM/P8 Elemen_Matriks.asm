extern printf
extern fflush
extern scanf
 
section .data
    M       dd  7,   11,  10,  6
            dd  5,   8,   9,   2
            dd  1,   3,   12,  4
    ncol    dd  4
    input   db  "%d %d",0
    output  db  "%d",10,0

section .bss
    i       resd    10 
    j       resd    10
    val     resd    10

section .text
    global main

main:
    ;   scanf("%d %d", &i,&j);
    push j
    push i
    push input
    call scanf
    add esp, 12

    ;   val = M[i][j] --> M[i*ncol + j] {Rumus mencari nilai}
    mov eax, [i]
    mul dword [ncol]
    add eax, [j]
    mov ebx, [M + eax*4]          ;ebx = M[eax]
    mov [val], ebx  

    ;print
    push dword [val]
    push output
    call printf
    add esp, 8

    ;clear
    push 0
    call fflush

    ;exit
    mov eax, 1
    mov ebx, 0
    int 0x80