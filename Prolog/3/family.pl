parent(pam,bob).
parent(tom,bob).
parent(bob,ann).
parent(bob,pat).
parent(pat, jim).
parent(tom,liz).

%----------------------------------
female(pam).
male(tom).
male(bob).
female(liz).
female(pat).
female(ann).
male(jim).
%----------------------------------

offspring(X,Y):-parent(Y,X).
%----------------------------------
mother(X, Y):-
    female(X),
    parent(X,Y).
%----------------------------------
different(X, Y):-X\=Y.
%----------------------------------
sister(X, Y):-
    female(X),
    parent(Z, X),
    parent(Z, Y),
    X \= Y.
%----------------------------------
hasTwoChildren(X):-
    parent(X,Y),
    parent(X,Z),
    Z \= Y,
    sister(Y,Z).
%----------------------------------
unt(X,Y):-
     sister(X, Z),
     parent(Z,Y).

%----------------------------------
predecessor(X, Z):- parent(X, Z).
predecessor(X, Z):-
    parent(X, Y),
    predecessor(Y,Z).
%----------------------------------



