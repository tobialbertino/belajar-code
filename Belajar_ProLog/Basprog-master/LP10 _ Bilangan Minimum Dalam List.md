# Bilangan Minimum Dalam List
Diketahui sebuah list sederhana yang berisi bilangan bulat. Buat program prolog untuk mencari nilai minimum dari list tersebut. Sebagai contoh, jika diberi masukan list [10,2,3,4,9] maka keluarannya adalah 2 sebagai nilai minimum dari list tersebut. Asumsi: Tidak ada anggota list yang bernilai sama.

### Format Masukan
Sebuah list sederhana yang berisi bilangan bulat.

### Format Keluaran
Sebuah bilangan bulat yang merupakan nilai minimum dari list masukan

### Contoh Masukan
```
[10,2,3,4,9].
```

### Contoh Keluaran
```
2
```

### Code
```
program:- read(List), min(List,X), write(X), nl.
min([H],H).
min([H|T],H):- min(T,X), H=<X.
min([H|T],X):- min(T,X), H>X.
:- program.
```
