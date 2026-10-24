// Ceci est le fameux jeu de Go, ecris en C par

#include <stdio.h>

#define DIM 19

char current_table[DIM][DIM];
char playerA[30], playerB[30];
int playerA_pick, playerB_guess;
char black_name[30], white_name[30];
char current_turn = 'B';
int x,y, game_state;

// Temporary function since we have yet to see <String.h>

void copyString(char destination[], char source[]){
    int i=0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void printGrid(){
    for (int i=0; i<DIM; i++){
        for (int j=0; j<DIM; j++){
            printf("%c", current_table[i][j]);
        }
        printf("\n");
    }
}

void setup(){
    for (int i=0; i<DIM; i++){
        for (int j=0; j<DIM; j++){
            current_table[i][j] = '+';
        }
    }

    printf("%s", "Hello, we will determine which player gets the black stones and which player gets the white stones. "
            "But first, let's get your names, player A give us your name and choose a random number from 1 to 20\n");
    scanf("%29s %d", playerA, &playerA_pick);
    printf("%s", "Perfect, now for player B to give us your name and pick between even and odd, just type 0 for even and 1 for odd.\n");
    scanf("%29s %d", playerB, &playerB_guess);

    if(playerB_guess == playerA_pick % 2){
        copyString(black_name, playerB);
        copyString(white_name, playerA);
    } else {
        copyString(black_name, playerA);
        copyString(white_name, playerB);
    }

}

int main(){
    
    if (current_turn == 'B'){
        printf("%s please enter the coordinates of the desired stone placement: \n", black_name);
        scanf("%d %d", &x, &y);
        current_table[x-1][y-1] = 'B';
    } else {
        printf("%s please enter the coordinates of the desired stone placement: \n", white_name);
        scanf("%d %d", &x, &y);
        current_table[x-1][y-1] = 'W';
    }

    printGrid();
}
