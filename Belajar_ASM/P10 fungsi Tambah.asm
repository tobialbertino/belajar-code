global main
extern printf
extern fflush
extern scanf
%define arg(n)	ebp + (n+1)*4
%define var(n)	ebp - (n)*4


section .data
   input  db  "%d %d", 0
   output db  "%d", 10, 0

section .bss
    a resd 1
    b resd 1

section .text
				
	tambah :
				enter	4, 0

				mov	eax, [arg(1)]			;eax = a
				add eax, [arg(2)]			;eax += b
				
				leave
				ret
	main :		
				;scan
				push b
				push a
				push input
				call scanf
				add esp, 12

				;fungsi tambah
				push dword [b]
				push dword [a]
				call tambah
				add esp, 8
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