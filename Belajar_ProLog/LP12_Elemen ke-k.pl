program:- read(Lin), read(K), kth(K, Lin, Kth), write(Kth),nl.
kth(1, [H|_], H) :- !.
kth(K, [_|T], Kth) :- K > 1, K1 is K - 1, kth(K1, T, Kth).
:- program.