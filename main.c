// Ceci est le fameux jeu de Go, ecris en C par Irakli Pavliashvili et Hana Ziani

#include <stdio.h>
// these defines are for later
#define EMPTY 0
#define BLACK 1
#define WHITE 2
// the dimension of the playing board
#define DIM 19

char current_table[DIM][DIM];
char playerA[30], playerB[30];
int playerA_pick, playerB_guess;
char black_name[30], white_name[30];
int current_turn = BLACK;
int x,y, game_state;

/* Temporary function since we have yet to see <String.h>
 * Basically what it does : runs through the source array 
 * (for example playerA[30])
 * character by character, and checks if the character is empty or not
 * We have a counter `i`
 * if the character from the source array at the index `i` is not empty
 * we take it and say that the destination's character at index `i` is 
 * this same character.
 * 
 * As soon as we encounter an empty character, so the "chaine de caracteres"
 * is finished, we stop going through the array, and say that this character 
 * is empty `\0`
 *
 * Example:
 * source[30] = ['I', 'r', 'a', 'k', 'l', 'i', '\0', '\0', ...];
 * destination[30] = ['', '', ...]; its completely empty
 *
 * the function will go through the source array one by one, 
 * the character at index `i=0` is 'I', so we will say that 
 * destination[0] = 'I', so now the destination array is :
 * destination[30] = ['I', '', '', '', ...]
 * etc etc etc
 *
 * When we reach the '' in the source, and index `i=6`, we will simply put
 * in the destination at that index an '\0', symbolizing the end of the array
*/
void copyString(char destination[], char source[]){
    int i=0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

/*
 * This is to print the actual grid of the game
 * Imagine the current_table as a matrix (you've seen matrices... right?)
 * with `i` being its row index and `j` being its column
 * */

void printGrid(){
    for (int i=0; i<DIM; i++){
        for (int j=0; j<DIM; j++){
            printf("%c", current_table[i][j]);
        }
        printf("\n");
    }
}

void setup(){
    // for now, the grid will be using `+` to mark an empty intersection
    // `B` and `W` respectively for black and white stones
    //
    // this double `for` loop will print the grid row by row
    // `i` being the rows and `j` being the columns
    for (int i=0; i<DIM; i++){
        for (int j=0; j<DIM; j++){
            current_table[i][j] = '+';
        }
    }

    // just a bunch of questions to determine who gets which colored stones
    printf("%s", "Hello, we will determine which player gets the black stones and which player gets the white stones. "
            "But first, let's get your names, player A give us your name and choose a random number from 1 to 20\n");
    scanf("%29s %d", playerA, &playerA_pick);
    printf("%s", "Perfect, now for player B to give us your name and pick between even and odd, just type 0 for even and 1 for odd.\n");
    scanf("%29s %d", playerB, &playerB_guess);

    // this is the "guessing" principle to determine who gets the black stones
    if(playerB_guess == playerA_pick % 2){
        copyString(black_name, playerB);
        copyString(white_name, playerA);
    } else {
        copyString(black_name, playerA);
        copyString(white_name, playerB);
    }

}

int main(){
    setup();

    if (current_turn == 1){
        printf("%s please enter the coordinates of the desired stone placement: \n", black_name);
        scanf("%d %d", &x, &y);
        current_table[x-1][y-1] = 'B';
    } else if(current_turn == 2) {
        printf("%s please enter the coordinates of the desired stone placement: \n", white_name);
        scanf("%d %d", &x, &y);
        current_table[x-1][y-1] = 'W';
    }

    printGrid();
}
