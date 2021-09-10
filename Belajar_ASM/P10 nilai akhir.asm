global main
extern printf
extern fflush
extern scanf
%define arg(n)  ebp + (n+1)*4
%define var(n)  ebp - (n)*4


section .data
   input  db  "%d %d %d %d %d %d %d", 0
   output db  "%d", 10, 0

section .bss
    tugas   resd 1
    kuis    resd 1
    proj    resd 1
    uasp    resd 1
    utsp    resd 1
    uas     resd 1
    uts     resd 1

section .text   ; nilai_akhir = (uts*30 + uas*30 + utsp*10 + uasp*10 + proj*10 + kuis*5 + tugas*5) / 100

                
    nilai_akhir :
                enter 44, 0     ;jika membutuhkan sebanyak 1*(4) var lokal
                    
                mov dword [var(1)], 30      ; var(1) = 30
                mov dword [var(2)], 10      ; var(2) = 10
                mov dword [var(3)], 5       ; var(3) = 5
                mov dword [var(4)], 100     ; var(4) = 100

                mov eax, [arg(1)]
                mul dword[var(1)]
                mov dword[var(5)], eax

                mov eax, [arg(2)]
                mul dword[var(1)]
                mov dword[var(6)], eax

                mov eax, [arg(3)]
                mul dword[var(2)]
                mov dword[var(7)], eax

                mov eax, [arg(4)]
                mul dword[var(2)]
                mov dword[var(8)], eax

                mov eax, [arg(5)]
                mul dword[var(2)]
                mov dword[var(9)], eax

                mov eax, [arg(6)]
                mul dword[var(3)]
                mov dword[var(10)], eax

                mov eax, [arg(7)]
                mul dword[var(3)]
                mov dword[var(11)], eax

                mov eax, dword[var(5)]
                add eax, dword[var(6)]
                add eax, dword[var(7)]
                add eax, dword[var(8)]
                add eax, dword[var(9)]
                add eax, dword[var(10)]
                add eax, dword[var(11)]
                
                leave
                ret
    bulatAtas:
                add ecx, 50
                jmp pembagian
                
    main :      
                ;scan
                push tugas
                push kuis
                push proj
                push uasp
                push utsp
                push uas
                push uts
                push input
                call scanf
                add esp, 32

                ;fungsi nilai_akhir(tambah doang)
                push dword [tugas]
                push dword [kuis]
                push dword [proj]
                push dword [uasp]
                push dword [utsp]
                push dword [uas]
                push dword [uts]
                call nilai_akhir
                add esp, 28

                ;eax % 100
                mov ecx, eax
                mov edx, 0
                mov ebx, 100
                div ebx
                mov eax, edx

                ;kondisi pembulatan
                cmp eax, 50
                jae bulatAtas
    
    pembagian:
                mov eax, ecx
                mov edx, 0
                div ebx

    print:  
                push eax                    ; printf
                push output
                call printf
                add esp, 8
    exit:   
                push 0                      ; fflush(0)
                call fflush
                add esp, 4
                mov eax, 0                  ; return 0
                ret