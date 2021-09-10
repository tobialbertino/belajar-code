banding(A, B, 0) :- A =:= B.
banding(A, B, 1) :- A =< B.
banding(A, B, -1) :- A >= B.


program :- read(A), read(B),banding(A, B, X), write(X), nl.
:- program.