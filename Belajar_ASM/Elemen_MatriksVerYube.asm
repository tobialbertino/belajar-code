extern printf
extern fflush
extern scanf
    
section .data
    fmt_i db "%d %d", 0
    fmt_o db "%d", 10, 0
    
    input dd 7, 11, 10, 6
		  dd 5, 8, 9, 2
		  dd 1, 3, 12, 4 
        
section .bss
    a resd 1
    b resd 1
       
section .text
    global main
        
main:
	push b
	push a
    push fmt_i
    call scanf
    add esp, 3*4
    
	mov eax, 4
	mov ebx, [a]
	mul ebx
	
	add eax, [b]
	
	mov ebx, eax
	
	mov eax, [input + 4*ebx]
	
    push eax
    push fmt_o
    call printf
    add esp, 2*4
 
    push 0
    call fflush
        
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80
