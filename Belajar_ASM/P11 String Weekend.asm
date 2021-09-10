; Panjang kata

extern scanf, printf, fflush
global main

section .data
	input	db	"%s", 0
	output	db	"%d", 10, 0
	p_weekend db "weekend", 10, 0
	p_weekday db "weekday", 10, 0

section .bss
	string	resb	4	; Maksimal 4 karakter

section .text

	lain:
			push p_weekend
			call printf
			add esp, 4
			jmp exit

	main:	push string
			push input
			call scanf
			add esp, 8

			cld
			mov 	al, "S"		; search for NULL
			mov 	edi, string
			mov 	ecx, 10		; loop sampai 10x
			repne	scasb

			sub		edi, string		;edi = indeks utk al
			;dec	edi				;edi -= 1

			cmp edi, 1
			je  lain

	print:  
            push p_weekday
            call printf
            add esp, 4

    exit:   push 0                      ; fflush(0)
            call fflush
            add esp, 4
            mov eax, 0                  ; return 0
            ret