split(A, 0, [], A).
split([H|T], B, [H|T1], C) :- B1 is B - 1, split(T, B1, T1, C).
putar(L1, L2, X) :- append(L1, L2, X).

program :- read(A), read(B), split(A, B, L1, L2), putar(L1, L2, X), write(X), nl.
:- program.