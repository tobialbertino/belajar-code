# Elemen Posisi Ganjil
Buatlah program logika (Prolog) yang membaca sebuah list sederhana dan menampilkan list tersebut dengan elemen-elemen pada posisi ganjil. 
Sebagai contoh, jika diberikan list [10,20,30] maka program menghasilkan list [10, 30].

### Format Masukan
Sebuah list sederhana.

### Format Keluaran
Sebuah list sederhana sesuai ketentuan, yang diakhiri dengan newline.

### Contoh Masukan
```
[2,4,8,10].
```

### Contoh Keluaran
```
[2,8]
```

### Code
```
program:- read(List), posganjil(List,1,X), write(X),nl.
posganjil([],_,[]).
posganjil([H|T],Pos,[H|X]):- 1 is mod(Pos,2), Pos1 is Pos+1, posganjil(T,Pos1,X).
posganjil([_|T],Pos,X):- Pos1 is Pos+1, posganjil(T,Pos1,X).
:- program.
```
