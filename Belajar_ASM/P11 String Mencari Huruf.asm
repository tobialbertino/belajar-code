; Panjang kata

extern scanf, printf, fflush
global main

section .data
	input	db	"%s", 0
	output	db	"%d", 10, 0
	tidakAda db "tidak ada", 10, 0

section .bss
	string	resb	51	; Maksimal 50 karakter
	kata 	resb	1

section .text

	fungsi1:
			push tidakAda
			call printf
			add esp, 4
			jmp exit
			
	main:	push string
			push input
			call scanf
			add esp, 8

			push kata
			push input
			call scanf
			add esp, 8

			cld
			mov 	al, [kata]		; search for NULL
			mov 	edi, string
			mov 	ecx, -1		; loop sampai nilai tertinggi int
			repne	scasb

			sub		edi, string		;edi = indeks utk al
			;dec	edi				;edi -= 1

			cmp 	edi, 52			; 50 karakter+NULL+\n
			je		fungsi1

	print:  push edi                   ; printf
            push output
            call printf
            add esp, 8

    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret