; Posisi titik
 
extern scanf, printf, fflush
global main
 
section .data
    input   db  "%s", 0
    output  db  "%d", 10, 0
 
section .bss
    string  resb    41  ; Maksimal 20 karakter
 
section .text

    noll:
            mov ebx, 0
            jmp print

    main:   push string
            push input
            call scanf
            add esp, 8
 
            cld
            mov     al, "."     ; search for NULL
            mov     edi, string
            mov     ecx, 42        ; loop sampai nilai tertinggi int
            repne   scasb
 
            sub     edi, string     ;edi = indeks utk NULL
            mov     ebx, edi
            
            cmp ebx, 42
            je  noll
 
            cld
            mov     al, 0       ; search for NULL
            mov     edi, string
            mov     ecx, 41        ; loop sampai nilai tertinggi int
            repne   scasb
 
            sub     edi, string     ;edi = indeks utk NULL
            dec     edi
            sub     edi, ebx
            mov     ebx, edi
 
    print:  push ebx                   ; printf
            push output
            call printf
            add esp, 8
 
    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret