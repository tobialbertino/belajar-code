program:- read(List), read(K), sumgenap(List,K,X), write(X),nl.
sumgenap(_,0,0).
sumgenap([H|T],K,X):- K>0, 0 is mod(H,2), K1 is K-1, sumgenap(T,K1,X1), X is X1+H.
sumgenap([_|T],K,X):- sumgenap(T,K,X).
:- program.