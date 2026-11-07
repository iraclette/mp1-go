#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./zobrist.c"

#define TAILLE 19

#define NOIR 0
#define BLANC 1
#define VIDE 2

char playerA[30], playerB[30];
int playerA_pick, playerB_guess;
char black_name[30], white_name[30];

int plateau[TAILLE][TAILLE];
const char *message[] = {
    "Welcome, dear players, to the game of Go, an ancient two-player strategy game.",
    "The rules are simple : two players will take turns placing stones on the intersections of the board.",
    "Your goal would be to conquer as much territory as you can by surrounding it.",
    "But don't forget, you can attack your opponents' stones by surrounding them and capturing them.",
    "You can choose the size of the board, be it 9x9, 13x13 or 19x19.",
    "If you happen to be alone, it is not a problem, a game engine may or may not be made in the future.",
    "Alright, let's first find out who will start first.",
    "Player A please give us a name we can call you : ",
    "Player B please give us a name we can call you : \n",
    "Perfect, %s, pick up a random amount of your stones, and tell us how many you have : \n",
    "Okay, now for %s to try and guess which if %s has an even or odd number of stones, 0 for even, 1 for odd : \n"
};

enum {
    MSG_INTRO_FIN = 6,
    MSG_NOM_A,
    MSG_NOM_B,
    MSG_PIOCHE_A,
    MSG_PIOCHE_B
};

void welcome() {
    const char *logo[] = {
        " ██████╗  ██████╗ ",
        "██╔════╝ ██╔═══██╗",
        "██║  ███╗██║   ██║",
        "██║   ██║██║   ██║",
        "╚██████╔╝╚██████╔╝",
        " ╚═════╝  ╚═════╝ ",
    };
    system("clear");
    for (int i = 0; i < 6; i++) {
        int r = 230 - i * 20, g = 60 + i * 15, b = 40;
        printf("\033[38;2;%d;%d;%dm%s\033[0m", r, g, b, logo[i]);
        printf("\t%s\n", message[i]);
    }
    printf("\n");
}

void setup() {
    // just a bunch of questions to determine who gets which colored stones
    printf("%s\n%s\n", message[MSG_INTRO_FIN], message[MSG_NOM_A]);
    scanf("%29s", playerA);
    printf("%s", message[MSG_NOM_B]);
    scanf("%29s", playerB);
    printf(message[MSG_PIOCHE_A], playerA);
    scanf("%d", &playerA_pick);
    printf("\033[1A\033[2K%s, no peeking\n", playerB);
    printf(message[MSG_PIOCHE_B], playerB, playerA);
    scanf("%d", &playerB_guess);

    // this is the "guessing" principle to determine who gets the black stones
    if (playerB_guess == playerA_pick % 2) {
        strcpy(black_name, playerB);
        strcpy(white_name, playerA);
        printf("%s well done, you were right, you get the black stones, and thus, the first move\n", playerB);
    } else {
        strcpy(black_name, playerA);
        strcpy(white_name, playerB);
        printf("Too bad %s, you missed, %s will get the black stones, and thus, the first move\n", playerB, playerA);
    }
}

void askAndParseCoords(int *ligne, char *colonne) {
    char lettreSaisie;
    int ligneSaisie;

    printf("Entrez les Coordonnees de votre choix : ");
    scanf(" %c%d", &lettreSaisie, &ligneSaisie);

    if (lettreSaisie >= 'a' && lettreSaisie <= 'z') {
        lettreSaisie = lettreSaisie - 32;
    }
    *ligne = ligneSaisie - 1;
    *colonne = lettreSaisie - 'A';
    if (lettreSaisie >= 'J') {
        (*colonne)--;
    }
}

void printGrid() {
    printf("   ");
    for (int j = 0; j < TAILLE; j++) {
        char lettre = 'A' + j;
        if (lettre >= 'I') {
            lettre = lettre + 1;
        }
        printf("%c ", lettre);
    }
    printf("\n");

    for (int i = 0; i < TAILLE; i++) {
        if (i < 9) {
            printf("%d  ", i + 1);
        } else {
            printf("%d ", i + 1);
        }
        for (int j = 0; j < TAILLE; j++) {
            if (plateau[i][j] == VIDE) {
                //top left corner
                if (i == 0 && j == 0) printf("\u250C");
                //top line
                else if (i == 0 && j > 0 && j < TAILLE - 1)printf("\u252C");
                //top right corner
                else if (i == 0 && j == TAILLE - 1) printf("\u2510");
                //left line
                else if (i > 0 && i < TAILLE - 1 && j == 0) printf("\u251C");
                //bottom left corner
                else if (i == TAILLE - 1 && j == 0) printf("\u2514");
                //bottom line
                else if (i == TAILLE - 1 && j > 0 && j < TAILLE - 1) printf("\u2534");
                //bottom right corner
                else if (i == TAILLE - 1 && j == TAILLE - 1) printf("\u2518");
                //right line
                else if (i > 0 && i < TAILLE - 1 && j == TAILLE - 1) printf("\u2524");
                //anything else
                else printf("\u253C");
            } else if (plateau[i][j] == NOIR) {
                printf("\u25CB");
            } else if (plateau[i][j] == BLANC) {
                printf("\u25C9");
            }
            if (j < TAILLE - 1) printf("\u2500");
        }
        printf("\n");
    }
}

void move(int ligne, int colonne, int joueurActuel) {
    add_stone(ligne, colonne, joueurActuel);
    // here we will add the check for possible captures
    swap_turn();
    if (check_ko()) {
        swap_turn();
        remove_stone(ligne, colonne, joueurActuel);
        add_stone(ligne, colonne, joueurActuel);
    } else {
        save_state();
    }

    system("clear");
}
