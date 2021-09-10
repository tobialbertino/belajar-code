; Panjang kata

extern scanf, printf, fflush
global main

section .data
	input	db	"%s", 0
	output	db	"%d", 10, 0

section .bss
	string	resb	21	; Maksimal 20 karakter

section .text
	main:	push string
			push input
			call scanf
			add esp, 8

			cld
			mov 	al, 0		; search for NULL
			mov 	edi, string
			mov 	ecx, -1		; loop sampai nilai tertinggi int
			repne	scasb

			sub		edi, string		;edi = indeks utk NULL
			dec		edi				;edi -= 1

	print:  push edi                   ; printf
            push output
            call printf
            add esp, 8

    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret