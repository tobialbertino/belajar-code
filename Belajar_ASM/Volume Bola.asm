extern scanf, printf, fflush
global main
 
section .data
    input   db  "%f", 0
    output  db  "%.4lf", 10, 0             ; %f  --> float/(double)-->qword
 
section .bss
    jari    resd 1
    vol     resq 1
    temp    resd 1
    empat   resd 1
 
section .text
    main:   push jari
            push input
            call scanf
            add esp, 8

            mov dword[empat], 4
            mov dword[temp], 3
 
            fldpi                       ;kell = phi * r
            fmul    dword[jari]
            fmul    dword[jari]
            fmul    dword[jari]
            fimul   dword[empat]
            fidiv   dword[temp]
            fst     qword[vol]
 
            push dword[vol+4]
            push dword[vol]
            push output 
            call printf
            add esp, 12
 
    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret