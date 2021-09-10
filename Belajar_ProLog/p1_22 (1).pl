range(A,I,I,[I]).
range(A,I,K,[I|L]) :- I < K, I1 is I + 1, range(I1,K,L).
 
 program :- read(A), read(B), read(C), range(A, B, C, X), write(X), nl.
:- program.