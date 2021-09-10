# Mengkompres List dengan Elemen Sama

Buat program Prolog untuk mengkompres list dengan elemen yang sama dan bersebelahan. Sebagai contoh, list `[2,3,3,4,4,4]` dikompres menjadi `[[2,1],[3,2],[4,3]]`.

### Format Masukan
Sebuah list sederhana.

### Format Keluaran
Sebuah list hasil kompresi seperti pada contoh.

### Contoh Masukan
```
[2,3,3,4,4,4,2,2,2,2,2,2].
```
### Contoh Keluaran
```
[[2,1],[3,2],[4,3],[2,6]]
```
### Code

```pl
program:- read(Lin), encode(Lin, Lout), write(Lout), nl.
encode([], []) :- !.
encode([A, A|Tin], [[A, N]|Tout]) :- encode([A|Tin], [[A,N1]|Tout]), N is N1 + 1.
encode([A, B|Tin], [[A, 1]|Tout]) :- encode([B|Tin], Tout).
encode([A|Tin], [[A, 1]|Tout]) :- encode(Tin, Tout).
:- program.
```
