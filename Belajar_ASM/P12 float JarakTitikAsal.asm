extern scanf, printf, fflush
global main
  
section .data
    input   db  "%lf %lf", 0
    output  db  "%lf", 10, 0             ; %f  --> float/(double)-->qword
  
section .bss
    x       resq 1
    y       resq 1
    jarak   resq 1
  
section .text
    main:   push y
            push x
            push input
            call scanf
            add esp, 12
  
            fld     qword[x]            ;ST0 = y
            fmul    qword[x]            ;STO *= y ->y^2
            fabs                        ;fungsi Absolut (mutlak)
            fld     qword[y]            ;ST0 = x -- ST1 = y^2
            fmul    qword[y]            ;ST0 = x^2 -- ST1 = y^2
            fabs
            faddp                       ;STO += ST1 -> x^2+y^2
            fsqrt                       ; sqrt(ST0)
            fst     qword[jarak]
  
            push dword[jarak+4]
            push dword[jarak]
            push output 
            call printf
            add esp, 12
  
    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret