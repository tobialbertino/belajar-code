# Menulis Program Prolog

Buat program PROLOG untuk membuat list dari 3 elemen input.

### Format Masukan

Tiga (3) bilangan input.

### Format Keluaran

Sebuah list berisi 3 elemen input, dan diakhiri dengan newline.

### Contoh Masukan
```
3.
4.
5.
```
### Contoh Keluaran
```
[3,4,5]
```
### Code

```pl
program:- read(A), read(B), read(C), write([A, B, C]), nl.
:- program.
```
