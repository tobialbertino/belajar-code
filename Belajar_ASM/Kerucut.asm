extern scanf, printf, fflush
global main
 
section .data
    input   db  "%f", 0
    output  db  "%f", 10, 0             ; %f  --> float/(double)-->qword
 
section .bss
    jari    resd 1
    tinggi  resd 1
    vol     resq 1
    temp    resd 1
 
section .text
    main:   push jari
            push input
            call scanf
            add esp, 8

            push tinggi
            push input
            call scanf
            add esp, 8
            mov dword[temp], 3
 
            fldpi                       ;kell = phi * diameter
            fmul    dword[jari]
            fmul    dword[jari]
            fmul    dword[tinggi]
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