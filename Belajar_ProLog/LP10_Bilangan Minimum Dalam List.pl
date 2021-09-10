program:- read(List), min(List,X), write(X), nl.
min([H],H).
min([H|T],H):- min(T,X), H=<X.
min([H|T],X):- min(T,X), H>X.
:- program.