# List Elemen pada posisi ganjil

Diketahui sebuah list sederhana yang berisi bilangan bulat. Buat program logika (prolog) untuk mengambil setiap elemen dari list pada posisi ganjil dan membentuk sebuah list yang baru. Sebagai contoh, jika diberi masukan list [6,5,4,3,2,1] maka dibuat list baru yaitu [6,4,2] karena bilangan 6,4, dan 2 berada pada posisi ganjil.

### Format Masukan
Sebuah list sederhana yang berisi bilangan bulat.

### Format Keluaran
Sebuah list yang berisi elemen pada posisi ganjil dari list masukan. Output diakhiri dengan newline.

### Contoh Masukan
```
[2,5,10,17,9]
```

### Contoh Keluaran
```
[2,10,9]
```

## Code
```
program:- read(List), posganjil(List,1,X), write(X),nl.
posganjil([],_,[]).
posganjil([H|T],Pos,[H|X]):- 1 is mod(Pos,2), Pos1 is Pos+1, posganjil(T,Pos1,X).
posganjil([_|T],Pos,X):- Pos1 is Pos+1, posganjil(T,Pos1,X).
:- program.
```
