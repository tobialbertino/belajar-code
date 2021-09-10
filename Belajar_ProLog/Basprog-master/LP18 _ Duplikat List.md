# Duplikat List

Buatlah program Prolog untuk menduplikasi elemen list sederhana sebanyak N kali. Sebagai contoh:

```pl
?- duplikat([a,b],4,L).
L = [a,a,a,a,b,b,b,b]
```

### Format Masukan

Sebuah list dan sebuah bilangan bulat positif tidak nol.

### Format Keluaran

Sebuah list yang diakhiri dengan newline.

### Contoh Masukan
```
[a,b].
3.
```
### Contoh Keluaran
```
[a,a,a,b,b,b]
```
### Code

```pl
program:- read(Lin), read(N), dup(Lin, 1, N, Lout), write(Lout), nl.
dup([], _, _, []) :- !.
dup([H|Tin], I, N, [H|Tout]) :- I < N, I1 is I + 1, dup([H|Tin], I1, N, Tout).
dup([H|Tin], I, N, [H|Tout]) :- I =:= N, dup(Tin, 1, N, Tout).
:- program.
```
