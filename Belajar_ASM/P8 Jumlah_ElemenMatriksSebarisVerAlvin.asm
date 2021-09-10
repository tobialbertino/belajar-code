extern scanf
extern printf
extern fflush
    
section .data
    input db "%d", 0
    output db "%d", 10, 0
    
    M     dd 7, 11, 10, 6
          dd 5, 8, 9, 2
          dd 1, 3, 12, 4 
    ncol  dd 4
        
section .bss
    a resd 1
       
section .text
    global main
        
main:
    ;   scanf("%d", &a);
    push a
    push input
    call scanf
    add esp, 8

    ;   proses: val = M[i][j] --> M[i*ncol + j]
    mov eax,[a]  ; eax=a , a itu baris ke berapanya berdasarkan inputan
    mov ebx, 16  ; ebx=16    ;karena sebaris ada 4 elemen
    mul ebx ; eax=eax*ebx   ;nentuin letak baris yg dicari inputan
    mov ecx,eax ; ecx = eax , nilai diatas disimpan di ecx
    mov eax,0 ; eax=0

    add eax,[M+ecx] ; eax=eax+kolom1

    add eax,[M+ecx+4]; eax=eax + kolom 2

    add eax,[M+ecx+8]; eax=eax+kolom3

    add eax,[M+ecx+12]; eax = eax+kolom 4

    push eax
    push output
    call printf
    add esp, 8
 
    push 0
    call fflush
        
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80


