extern scanf, printf, fflush
global main
 
section .data
    inputInt db "%d", 0
    input   db  "%lf", 0
    output  db  "%.1f", 10, 0               ; %f  --> float/(double)-->qword
 
section .bss
    n       resd 1
    nol     resq 1
    suhu    resq 1
    rata    resq 1
 
section .text
     
     
    main:   push n
            push inputInt
            call scanf
            add esp, 8
 
            mov ebx, dword[n]   ;ebx = n
                                ;cuman bisa EBX, EDI
                                 
            fld qword[nol]      ;isi ST0 = 0 untuk loop1 jumlah
             
    loop1:  push suhu
            push input
            call scanf
            add esp, 8
            fadd qword[suhu]
             
    banding:    
            dec ebx             ;eax -= 1
            cmp ebx, 0
            ja loop1
 
    fBagi:  ;fsub dword[suhu]
            fidiv dword[n]
            fst  qword[rata]
 
            push dword[rata+4]
            push dword[rata]
            push output 
            call printf
            add esp, 12
 
    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret