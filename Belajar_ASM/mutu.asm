extern scanf
extern fflush
extern printf

section	.data
	input	db "%d%d%d%d",0
	a	db "A",10,0
	b	db "B",10,0
	c	db "C",10,0
	d	db "D",10,0
	e	db "E",10,0
	
segment	.bss
	i1 resd 100
	i2 resd 100
	i3 resd 100
	i4 resd 100
	
section	.text
	global main
	
main:
	;read
	push i1
	push i2
	push i3
	push i4
	push input
	call scanf
	add esp,20
	
	;add
	mov eax,[i1]
	add eax,[i2]
	add eax,[i3]
	add eax,[i4]
	
	;div
	mov edx,0
	mov ebx,4
	div ebx
	
	;compare
	cmp eax,80
	jae kaloa
	
	cmp eax,60
	jae kalob
	
	cmp eax,50
	jae kaloc
	
	cmp eax,40
	jae kalod
	
	cmp eax,0
	jge kaloe
	
	
	kaloa:
	push a
	call printf
	add esp,4
	jmp exit
	
	kalob:
	push b
	call printf
	add esp,4
	jmp exit
	
	kaloc:
	push c
	call printf
	add esp,4
	jmp exit
	
	kalod:
	push d
	call printf
	add esp,4
	jmp exit
	
	kaloe:
	push e
	call printf
	add esp,4
	jmp exit


	exit:
	push 0
	call fflush
	add esp,4
	mov eax,1
	mov ebx,0
	int 80h
	

