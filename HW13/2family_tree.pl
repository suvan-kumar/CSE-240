/* Name: Suvan Kumar*/
/* CSE 240 Spring 2023 */

/* Database for family tree. It consists of facts and rules. */
/* The section in the highlighted box above has been completed for you */

/* Facts */
male(abe).
male(rob).
male(jim).
male(mac).
male(ben).
male(bud).
male(kai).
male(tex).
male(roy).
male(lee).
female(joy).
female(ana).
female(mia).
female(kim).
female(zoe).
female(val).
female(mae).
female(amy).
female(pam).

father_of(abe, ana). /* abe is the father of ana */
father_of(abe, rob). /* abe is the father of ana */
father_of(abe, jim). /* abe is the father of ana */
/* filling in rest of the family tree */
father_of(jim, mac).
father_of(jim, kim).
father_of(ben, bud).
father_of(ben, amy).
father_of(bud, zoe).
father_of(bud, val).
father_of(bud, tex).
father_of(bud, roy).
father_of(kai, lee).
father_of(kai, pam).
mother_of(joy, rob). /* joy is the mother of rob */
mother_of(joy, jim). /* joy is the mother of rob */
mother_of(joy, ana). /* joy is the mother of rob */
mother_of(mia, mac).
mother_of(mia, kim).
mother_of(mae, bud).
mother_of(mae, amy).
mother_of(ana, zoe).
mother_of(ana, val).
mother_of(ana, tex).
mother_of(ana, roy).
mother_of(amy, lee).
mother_of(amy, pam).


/* Complete the facts given in the diagram above */

/* Rules */
/* Question 2.1 */
is_male(X) :-
    male(X);                /* true if male X exist s*/
    father_of(X, _).        /* true if father X exists */
	
/* Question 2.2 */
is_female(X) :- 
    female(X);              /* true if female X exists */
    mother_of(X, _).        /* true if mother X exists */
	
/* Question 2.3 */
grandmother_of(X, Z) :-	
    mother_of(X, Y),        /* true if X is mother of Y */
    parent_of(Y, Z).        /* returns parent Y of Z */

grandfather_of(X, Z) :-
    father_of(X, Y),        /* true if X is father of Y */
    parent_of(Y, Z).        /* returns parent Y of Z */

/*Question 2.4 */
sibling_of(X, Y) :-
    father_of(Z,X),         /* checks if Z is parent of X */
    father_of(Z,Y),         /* checks if Z is parent of Y */
    X \= Y.                 /* checks if X = Y since you can't be your own sibling */


/* Question 2.5 */
parent_of(X, Y) :- 	
    mother_of(X, Y);        /* true if X is mother of Y */
    father_of(X, Y).        /* true if X is father of Y */

/* Question 2.6 */
descendent_of(X, Y) :- 
    parent_of(Y,X).         /* true if Y is parent of X */
descendent_of_extended(X, Y) :- 
    parent_of(Y,Z),         /* true if Y is parent of Z */
    parent_of(Z,X).         /* return parent Z of X */
