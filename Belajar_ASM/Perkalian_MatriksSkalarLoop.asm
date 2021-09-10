extern scanf
extern printf
extern fflush
    
section .data
    M       dd  7,   11,  10,  6
            dd  5,   8,   9,   2
            dd  1,   3,   12,  4
    ncol    dd  4
    input   db  "%d %d",0
    output  db  "%d",10,0

section .bss
    a resd 10
       
section .text
    global main
        
main:
	push a
    push input
    call scanf
    add esp, 8
    
    ;process  ;   proses: val = M[i][j] --> M[i*ncol + j] --->{posisi elemen} ----dword[M + 4*eax]-->{posisi alamat}
    mov ecx, 12
    mov ebx, [a]    ;ebx = skalar
    mov edx, 0

loop1:
    mov eax, [M + 4*edx]
    mul ebx
    add edx, 1
    ;   print eax
    push eax
    push output
    call printf
    add esp, 8

    loop loop1

    ;clear
    push 0
    call fflush
        
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80
