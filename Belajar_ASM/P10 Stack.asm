global main
extern printf
extern fflush
extern scanf
%define arg(n)	ebp + (n+1)*4
%define var(n)	ebp - (n)*4

 

section .data
   input  db  "%d", 0
   output db  "%d", 10, 0

section .bss
    a resd 1
    b resd 1

section .text
				; int segitiga(int a, int t){
				;	int z = 2;
				;	return ((a*b)/z);
				;}
	segitiga :
				;push	ebp
				;mov	ebp, esp
				;sub	esp, 4
				enter	4, 0				;jika membutuhkan sebanyak 1*(4) var lokal

				mov dword [var(1)], 2		;(var_lokal)z = 2
				mov	eax, [arg(1)]			;eax = a
				mul dword[arg(2)]			;eax *= t
				cdq							;mov edx, 0
				div dword[var(1)]			;eax /= z 

				;mov esp, ebp
				;pop	ebp
				leave
				ret
	main :		
				push dword 5
				push dword 10
				call segitiga
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