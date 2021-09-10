program:- read(Lin), lastt(Lin, Last), write(Last),nl.
lastt([H], H) :- !.
lastt([_|T], Last) :- lastt(T, Last).
:- program.