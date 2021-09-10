# Menulis Program Prolog
### Format Masukan
Dua buah bilangan bulat dengan format sesuai ketentuan program SWI-Prolog atau GNU-Prolog.

### Format Keluaran
Sebuah bilangan bulat hasil penjumlahan dua bilangan masukan, dan diakhiri dengan newline.

### Contoh Masukan
```
10.
15.
```
### Contoh Keluaran
```
25
```
### Code
```
program :- read(A), read(B), jumlah(A,B,C), write(C), nl.
jumlah(A,B,X) :- X is A+B.
:- program.
```
