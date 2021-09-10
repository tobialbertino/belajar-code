extern printf
extern fflush
extern scanf

section .data
	input db "%d",0
	pkempes db "kempes",10,0
	ppas db "pas",10,0
	pkeras db "keras",10,0
 
section .bss
	a resd 10

section .text
	global main
	
main:
	;baca
	push a
	push input
	call scanf
	add esp, 8
	
	;mov 
	mov eax,[a]
	
	;kondisi membandingkan
	cmp eax,29
	jb kempes
	
	cmp eax,35
	jle pas
	
	cmp eax,36
	jae keras

kempes:
	push pkempes
	call printf
	add esp, 8
	jmp exit
	
pas:	
	push ppas
	call printf
	add esp, 8
	jmp exit
	
keras:
	push pkeras
	call printf
	add esp, 8
	jmp exit

exit:
	mov eax, 1
	mov ebx, 0
	int 0x80
	 
	;clear
	push 0
	call fflush
	
	;return 0
	mov eax, 1
	mov ebx, 0
	int 0x80

