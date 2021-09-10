urai([],[]).
urai([[H,1]|T],[H|New]) :- urai(T,New).
urai([[H,C]|T],[H|New]) :- C1 is C-1, urai([[H,C1]|T],New).
urai([H|T],[H|New]) :- urai(T,New).

program:- read(List), urai(List,X), write(X),nl.
:- program.