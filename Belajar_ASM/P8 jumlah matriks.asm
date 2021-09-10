extern scanf
extern printf
extern fflush
    
section .data
    fmt_i db "%d", 0
    fmt_o db "%d", 10, 0
    
    input dd 7, 11, 10, 6
		  dd 5, 8, 9, 2
		  dd 1, 3, 12, 4 
        
section .bss
    a resd 1
       
section .text
    global main
        
main:
	push a
    push fmt_i
    call scanf
    add esp, 2*4
    
    mov ecx, 4
    mov eax, 4
	mov ebx, [a]
	mul ebx
	mov ebx, 0

sub_loop:
	add ebx, dword[input+4*eax]
	add eax, 1
	loop sub_loop
	
    push ebx
    push fmt_o
    call printf
    add esp, 2*4
 
    push 0
    call fflush
        
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80
