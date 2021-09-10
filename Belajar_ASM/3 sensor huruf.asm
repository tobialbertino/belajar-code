; Posisi titik

extern scanf, printf, fflush
global main

section .data
	input	db	"%s ", 0
	output	db	"%s ", 0

section .bss
	string	resb	41	; Maksimal 40 karakter
    kata    resb    2  


section .text
	main:	push string
			push input
			call scanf
			add esp, 8

            push string
			push kata
			call scanf
			add esp, 8
			
			mov esi, "_"

			cld
			mov 	al, kata		; search for kata
			mov 	edi, string
			mov 	ecx, 41		; loop sampai nilai tertinggi int
			repne	movsb   

            

	print:  push edi                   ; printf
            push output
            call printf
            add esp, 8

    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret