

know(sophie,harry).
know(arthur,sophie).
know(sophie,emma).
know(emma,teddy).
know(grace,lucas).
know(harry,grace).
know(teddy,harry).

use(sophie,facebook).
use(sophie,instagram).
use(teddy,whatsapp).
use(lucas,skype).
use(emma,facebook).
use(grace,whatsapp).
use(grace,facebook).
use(harry,facebook).

allow(whatsapp,photo).
allow(whatsapp,talk).
allow(whatsapp,chat).
allow(instagram,photo).
allow(facebook,chat).
allow(facebook,photo).
allow(skype,talk).

rule1(X,Y):-use(X,Z),allow(Z,Y).
rule2(X,Y):-know(X,Y);know(Y,X).
rule3(X,Y):-not(rule2(X,Y)),rule2(X,Z),rule2(Z,Y).
rule4(X):-rule2(X,Y),write(Y),nl,fail.
rule4(_).
rule5(X):-allow(Y,X),use(Z,Y),write(Z),nl,fail.
rule5(_).
rule6(X,Y):-	(know(X,Y);know(Y,X)),use(X,P),use(Y,P);
		(know(X,P);know(P,X)),(know(Y,P);know(P,Y)),
		use(X,A),use(Y,A),use(P,A).

rule7(X):-write('Name - '),write(X),nl,fail.
rule7(X):-use(X,Y),write(Y),nl,fail.
rule7(X):-(know(X,Y);know(Y,X)),write(Y),nl,fail.
rule7(_).

men(harry).
men(lucas).
men(teddy).
men(arthur).
worman(sophie).
worman(emma).
worman(grace).

rule8(X,Y):-men(X),men(Y),(know(X,Y);know(Y,X)).
rule9(X,Y):-(men(X),worman(Y);men(Y),worman(X)),not(rule2(X,Y)),use(X,Z),use(Y,Z).
rule10(X,Y):-	worman(X),worman(Y),X\==Y,((know(X,Y);know(Y,X)),use(X,P),use(Y,P);
		(know(X,P);know(P,X)),(know(Y,P);know(P,Y)),men(P),
		use(X,A),use(Y,A),use(P,A)).
