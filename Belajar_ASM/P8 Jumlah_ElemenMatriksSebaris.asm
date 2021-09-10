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
    mov ecx, dword[ncol]    ; loop 4x
    mov eax, dword[ncol]    ; ada 4 kolom
    mov ebx, [a]    ;ebx = a , menentukan posisi baris yg mau dijumlah      
    mul ebx         ;eax = ncol*a // posisi traverse matriks(1d) dari awal(kolom-baris)
    mov ebx, 0      ;ebx = 0

loop1:
    add ebx, dword[M + 4*eax]
    add eax, 1      ; eax = eax + 1 -->[M + 4*eax] // traverse matriks
    loop loop1
    
    push ebx
    push output
    call printf
    add esp, 8
    ;   clear
    push 0
    call fflush
        
exit:
    mov eax, 1
    mov ebx, 0
    int 0x80
