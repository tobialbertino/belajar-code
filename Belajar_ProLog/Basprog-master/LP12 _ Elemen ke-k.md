# Elemen ke-k

Buatlah sebuah program yang dapat mengembalikan elemen ke-k dari sebuah list

### Format Masukan

Masukan terdiri dari dua baris. Baris pertama berupa sebuah list, baris kedua berupa sebuah bilangan bulat k.

### Format Keluaran

Elemen list ke-k

### Contoh Masukan

```
[1,5,8,12,15].
3.
```

### Contoh Keluaran

```
8
```

### Code

```pl
program:- read(Lin), read(K), kth(K, Lin, Kth), write(Kth),nl.
kth(1, [H|_], H) :- !.
kth(K, [_|T], Kth) :- K > 1, K1 is K - 1, kth(K1, T, Kth).
:- program.
```
