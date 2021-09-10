extern scanf, printf, fflush
global main
 
section .data
    input   db  "%f", 0
    output  db  "%f", 10, 0             ; %f  --> float/(double)-->qword
 
section .bss
    diameter resd 1
    kell    resd 1
 
section .text
    main:   push diameter
            push input
            call scanf
            add esp, 8
 
            fldpi                       ;kell = phi * diameter
            fmul    dword[diameter]
            fst     qword[kell]
 
            push dword[kell+4]
            push dword[kell]
            push output 
            call printf
            add esp, 12
 
    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret