# Menguraikan List
Untuk keperluan efisiensi, sebuah list ditulis dalam bentuk [x,n] jika ada n elemen bernilai x yang bersebelahan dalam suatu list (untuk n>1).  Sebagai contoh, list [3,4,[a,3],[9,2]] adalah penyederhanaan dari list [3,4,a,a,a,9,9]. Buat program PROLOG untuk menguraikan sebuah list hasil penyederhanaan.

### Format Masukan
Sebuah list hasil penyederhanaan.

### Format Keluaran
Sebuah list seperti yang dijelaskan dalam deskripsi soal, dan diakhiri dengan newline.

### Contoh Masukan
```
[3,4,[a,3],[9,2]].
```

### Contoh Keluaran
```
[3,4,a,a,a,9,9]
```

### Code
```
program:- read(List), urai(List,X), write(X),nl.
urai([],[]).
urai([[H,1]|T],[H|New]) :- urai(T,New).
urai([[H,C]|T],[H|New]) :- C1 is C-1, urai([[H,C1]|T],New).
urai([H|T],[H|New]) :- urai(T,New).
:- program.
```
