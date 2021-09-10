cari([H|_], 1, H).
cari([_|T], A, B):- A1 is A - 1, cari(T, A1, B).
 
program:- read(List), read(P), cari(List, P, A), write(A), nl.
:- program. 