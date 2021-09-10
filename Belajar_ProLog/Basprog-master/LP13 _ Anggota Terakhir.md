# Menulis Program Prolog

Buat sebuah program untuk mencari elemen terakhir dari sebuah List.

### Contoh Masukan

```
[1, 2, 3].
```

### Contoh Keluaran

```
3
```

### Code

```pl
program:- read(Lin), lastt(Lin, Last), write(Last),nl.
lastt([H], H) :- !.
lastt([_|T], Last) :- lastt(T, Last).
:- program.
```
