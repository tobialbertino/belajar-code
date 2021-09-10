extern printf
extern fflush
extern scanf
 
section .data
    input db "%d%d",0
    output db "%d",10,0
     
section .bss
    a resd 10
    b resd 10
 
section .text
    global main

main :
    ;baca
    push a
    push b
    push input
    call scanf
    add esp, 12
     
    ;mov
    mov eax, [a]
    mov ebx, [b]
    mov edx, 0
    mov ecx, 2
    mul ebx
    div ecx
     
    ;print
    push eax
    push output
    call printf
    add esp, 8
     
    ;clear
    push 0
    call fflush
     
    ;return 0
    mov eax, 1
    mov ebx, 0
    int 0x80
