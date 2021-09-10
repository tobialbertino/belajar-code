# Pembagi Persekutuan Terbesar

Buat program logika untuk menentukan nilai FPB (Faktor Persekutuan Terbesar) dari dua bilangan. Ingat definisi bahwa FPB(a,b) adalah sebuah bilangan bulat terbesar yang habis membagi a dan b. Sebagai contoh, FPB(12,18) adalah 6.

### Format Masukan
Dua bilangan bulat tidak negatif.

### Format Keluaran
Sebuah bilangan bulat sesuai ketentuan, yang diakhiri dengan newline.

### Contoh Masukan
```
12.
18.
```

### Contoh Keluaran
```
6
```

### Code
```
program:- read(A), read(B), fpb(A,B,X), write(X),nl.
fpb(A,0,A).
fpb(A,B,X) :- A1 is B, B1 is mod(A,B), fpb(A1,B1,X). 
:- program.
```
