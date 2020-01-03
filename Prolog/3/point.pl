point(X,Y).
seg(P1, P2).
triangle(P1, P2, P3).
%-------------------------

vertical( seg( point(X,Y), point(X,Y1) ) ).
horizontal( seg( point(X,Y), point(X1,Y) ) ).


vertical( seg( point(1,1), point(1,2) ) ).

