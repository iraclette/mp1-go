# GAME OF GO IN C 

The game of Go consists in a 19x19 grid, where 2 players, called black and white, take turns to place their "tokens", also called *stones*, at the **intersections** of the grid, so technically speaking, we just have 361 points to take into account. Usually the black player has 181 stones, and the white has 180, but it's not that important for us, not for now at least.

## General rules
- The board starts empty (duh).
- Black makes the first move (hence the extra stone), after which they alternate.
- A *move* consists in placing a stone at any empty point on the board.
- A player may pass their turn at any moment.
- A stone, or a connected chain of stones, is considered at captured and removed from the board if there are no more free intersections directly adjacent to it.
- No move can be made as to recreate a former board position (genuinely not a clue on how to check it efficiently...)
- Two consecutive passes end the game
- A players area is considered as the amount of stones on the board and the amount of intersections surrounded by that color.
- The player with most area wins (duh).

## Going a bit more in detail for the rules 

The following section is optional for you, I just dont want to be reading the wiki everytime

1. **How the starting player is decided?** One takes a random amount of white stones and hides them behind their back. The other player will then take either one or two black stones, and place them on the board. The first player will then count the amount of stones they had taken, and if the second player guessed correctly (odd or even), they get the black stones and start the game, if not, they get the whites (duh).
2. The board consists of 19 vertical and horizontal lines, although beginners usually play on 9x9 or even 13x13 boards (we can make whichever you prefer, or maybe even all 3 as options, but its to be seen later). An intersection (which I'll be calling points), is the spot where a vertical and horizontal lines meet (this feels very stupid to say but bare with me for a moment). Two intersections are said to be *adjacent* if there is a straight horizontal or vertical line connecting them, so diagonals dont count. A point can't be adjacent to itself, a useful info for another rule later on.
3. At any moment in the game, each point has one of the 3 states:
    - Empty.
    - Occupied by white.
    - Occupied by black.
A *position* consists of an indication of the state of each intersection. It only reveals the current state of board, not a soul cares about whose turn it is, what was played or what were the previous states of the board.
4. Two intersections of the same state are said to be connected (no idea on why one would say that empty chains exist, but sure, apparently it's to define the player's score). The reason we define chains is to describe the conditions of a *capture*. A *liberty* of a stone is an empty point adjacent to that stone, or its chain, which is why most of the time we will be using liberties of a chain rather than a singular stone, since one stone is technically a one-long chain.
5. At the beginning, the board is empty (duh cpt obvious).
6. Black moves first, and then they alternate.
7. **What is a move.** (Holy shit this will be looong). Basically, a move is either a play or pass (a pass has to be announced explicitly). A play is where things get fun. It consists of 3 steps:
    - Step 1. Placing a stone
    - Step 2. Removing any opponents' stones that have no liberties
    - Step 3. Removing any stones of their own color that have no liberties. This step is kind of weird, this step is called *self-capture* or *suicide*, which is prohibited by some rulesets, allowed by others, we will see what we do with it.
8. A play is illegal if it would create a position that has occured previously in the game, this is called the **ko** rule (it would make an infinite loop possible, it's a rule similar to the repetition rule in chess, although instead of leading to a draw, it's straight up forbidden).
9. The game ends when both players have passed consecutively, and that is when the scores are counted.
10. **Definitions**
    - *Territory* : an empty intersection is said to belong to a player if all stones adjacent to it OR to an empty intersection connected to it are of that color (the or is important, because for example locking a territory in the corner surrounded by a players' stones would be considered as that player's territory). A point can never belong to both players, but it's possible that a point belongs to no one.
    - *Area* : in the final position, a point is said to belong to a player's *area* if it belongs to the territory or has a stone on it.
    - *Score* : the number of points in the final position

## What will limit us during the coding process

We don't have any GUI (graphical user interface) to keep track of the current position, the entire game has to be a bunch of `printf()`s. The code has to be at the very least clean, and not take eons between printing moves.

## What can be used to simplify our task

Since technically we only take into account points, rather than the grid itself, we can keep track of the board using a 2D array, such as `char board[19][19]`. Why `char`? Honestly, no clue... I mean, we can just use E for empty, B for black and W for white.

Since the game ends only when both players have passed, coding the ending phase of the game will be a lot easier than for chess. However it would mean that the entire game would be inside one huge `if` statement.

## What will be a genuine nightmare to code

The actual print, because if we want it to be visually appealing, the print statements would have to be really well written... 

The score counting, especially for the areas and territories.

The ko rule, because technically we would have to keep a "cache" of every single position.

## Approximate coding plan

### First submission

We can already simply make it print the blank grid, and create an array to keep count of the current position, as well as making the player color selection process, and asking the players where they would place their stones.

To make the grid, we could use what we learned in TP4. 

Keeping count of the current position seems simple enough, we just create a two dimensional array.

We can decide the player colors by asking player A to type a number (representing the random heap of stones grabbed) and for player B to type either the word even/odd, or a number 1 or 2.

To know where a player would place a stone, we could use
```c
char table[19][19];
char current_player = 'b'
int x, y;

for (int i=0; i<19; i++){
     for (int j=0; j<19; i++){
        char[i][j] = '+';
     }
}
if (current_player == 'b'){
    printf("give us the position where u want your stone in this format 'x y'";
    scanf("%d %d", &x, &y);
    table[x][y] = 'b';
}
else {
    printf("give us the position where u want yout stone in this format 'x y'");
    scanf("%d %d", &x, &y);
    table[x][y] = 'w';
}
```
This seems to be rather sufficient for a first submission, given the time frame.

### What will follow, in an approximate order

First we would add the actual stones in the grid printing.

Then we could, instead of asking the players for separate, explicit coordinates, that align with our interests, so using the 0-18 array notations, we could ask them to use the conventional coordinate system (Letters 'A' through 'T', skipping 'I' to avoid visual confusion, and a number after it, so instead of asking for `"%d %d"`, we could ask for `"%s"` that we separate and use as we need, obviously we check that it follows a guideline that we will force.


