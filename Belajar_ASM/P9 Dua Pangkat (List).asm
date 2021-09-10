extern printf
extern fflush
extern scanf
 
section .data
   input  db  "%d", 0
   output db  "%d", 10, 0

section .bss
    a resd 1

section .text
    global main

    pangkatDua:                         ;loop pangkatDua jadi label
            mul ebx
            loop pangkatDua
            ret

    main:   
            push a                      ;scanf
            push input
            call scanf
            add esp, 8

            cmp dword[a], 0             ; if (a == 0) jmp exit
            je exit

            mov ecx, [a]                  ; ecx = a...
            mov eax, 1
            mov ebx, 2
            call pangkatDua

    print:  push eax                    ; printf
            push output
            call printf
            add esp, 8

            jmp main

    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret


    