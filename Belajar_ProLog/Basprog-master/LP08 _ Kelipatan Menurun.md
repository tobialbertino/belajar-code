# Kelipatan Menurun

Diketahui sebuah list berisi dua buah bilangan bulat a dan b. Buatlah program prolog yang dapat menemukan b kelipatan pertama dari a secara menurun.

### Format Masukan

Sebuah list berisi dua buah bilangan bulat a dan b

### Format Keluaran

Sebuah list berisi b kelipatan pertama dari a secara menurun

### Contoh Masukan

```
[2,5].
```

### Conton Keluaran

```
[10,8,6,4,2]
```

### Catatan

10 adalah 2x5, 8 adalah 2x4, 6 adalah 2x3, 4 adalah 2x2, 2 adalah 2x1.

### Code

```pl
program:- read(Lin), desc_mul(Lin, Lout), write(Lout),nl.
desc_mul([], []) :- !.
desc_mul([_, 0], []) :- !.
desc_mul([H, 1], [H]) :- !.
desc_mul([H, K], [R|Ti]) :- K > 1, R is H * K, K1 is K - 1, desc_mul([H, K1], Ti).
:- program.
```
