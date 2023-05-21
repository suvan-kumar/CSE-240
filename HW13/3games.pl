/* Name: Suvan Kumar*/
/* CSE 240 Spring 2023 */

/* Facts */
genre(planetDrop, action). /* facts for different genres*/
genre(mechaTech, rpg).  

focus(planetDrop, gameplay).    /*facts for different focus combinations*/
focus(planetDrop, graphics).    
focus(mechaTech, story).     
focus(mechaTech, world).     

element(gameplay, mechanics).   /*facts for different element combinations*/
element(gameplay, framerate).   
element(graphics, rendering).   
element(graphics, meshes).   
element(story, characters).   
element(story, plot).   
element(world, design).   
element(world, culture).   

/* Rules */
/* Question 2.1 */
game(X,Y) :-
    genre(X,Y);   /* returns genre for X and Y */
    focus(X,Y).   /*returns focuses for type X with genre Y*/

/* Question 2.2 */
creation(X,Z) :-
    focus(X,Y),   /*returns focuses for type X with genre Y*/
    element(Y,Z).   /*returns elements for the focuses*/
