jumlah( [_|0], [] ).
jumlah( [H|T], [D|B] ) :- D is H * T, T1 is T - 1, jumlah( [H|T1],B).

program :- read(List), jumlah(List, A), write(A), nl.
:- program. 