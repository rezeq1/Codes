member( X, [X | Tail] ).
member( X, [Head | Tail] ) :-
    member( X, Tail).

%----------------------------
conc([], L, L).
conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).

%----------------------------
member1(X, L) :-
conc( Ll, [X | L2], L).

%----------------------------
reverse([], []).
reverse([Head|Tail], RevList) :-
    reverse(Tail, RevTail),
    conc(RevTail,[Head], RevList).
%----------------------------

del( X, [X | Tail], Tail).
del(X, [Y|Tail], [Y|Tail1]):-del(X,Tail, Tail1).
%----------------------------
insert(X, List, BiggerList) :- del(X, BiggerList, List).
%-----------------------------
member2(X, List) :-
    del( X, List, _).
%----------------------------

sublist( S, L) :-
conc( L1, L2, L),
conc( S, L3, L2).

%-----------------------------
permutation( [], [] ).
permutation([X|L], P) :-
    permutation(L,L1),
length1( [_ I Tail], N) :-
N = 1+N1,
lengthl( Tail, N1).
    insert(X,L1,P).
%------------------------------
ordered([]).
ordered([_]).
ordered([X, Y|Tail]):-
    X =<Y,
    ordered([Y|Tail]).

%------------------------------
max(X, Y, X):- Y =< X.
max(X, Y, Y):- X < Y.



maxlist([X], X).
maxlist([X|Tail], Max):-
    maxlist(Tail, Y),
    max(X,Y, Max).


%------------------------------
sumlist([], 0).
sumlist([X], X).
sumlist([X|Tail], Sum):-
    sumlist(Tail, TailSum),
    Sum is X + TailSum.








