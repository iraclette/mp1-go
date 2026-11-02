// premier projet du jeu de GO!! by Hana loll
#include "./main.c"
#include <stdio.h>

#define VIDE 2
#define NOIR 0
#define BLANC 1
#define TAILLE 19

int plateau[TAILLE][TAILLE];

void printGrid(){
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
                printf("+ ");
            } else if (plateau[i][j] == NOIR) {
                printf("X ");
            } else if (plateau[i][j] == BLANC) {
                printf("O ");
            }
        }
        printf("\n");
    }

}

int main() {

    int joueuractuel = NOIR;

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = VIDE;
        }
    }


    printGrid();
    setup();
    char choixPasser;
    char confirmation;
    int tourPasse = 0;



    while(tourPasse<2)
   { printf("Joueur %d, voulez-vous passer votre tour ? (Y/N) : ", joueuractuel);
    scanf(" %c", &choixPasser);
    printf("%d", tourPasse);
    if (choixPasser == 'Y' || choixPasser == 'y') {
        printf("Etes-vous sur ? (P = Passer / R = Rester) : ");

        scanf(" %c", &confirmation);

        if (confirmation == 'P' || confirmation == 'p') {
            printf("Joueur %d passe son tour.\n", joueuractuel);

        }
        joueuractuel^=1;
        tourPasse ++;
    } else if(choixPasser == 'N' || choixPasser == 'n')
        {
        char lettresaisie;
        int ligneSaisie;

        printf("Entrez les Coordonnees de votre choix : ");
        scanf(" %c%d", &lettresaisie, &ligneSaisie);

        if (lettresaisie >= 'a' && lettresaisie <= 'z') {
            lettresaisie = lettresaisie - 32;
        }


        int j = lettresaisie - 'A';
        if (lettresaisie >= 'J') {
            j = j - 1;
        }

        int i = ligneSaisie - 1;
        printf("%c %d\n", lettresaisie, ligneSaisie);

        if (i >= 0 && i < TAILLE && j >= 0 && j < TAILLE) {

            if (plateau[i][j] == VIDE) {

                plateau[i][j] = joueuractuel;
            } else {
                printf("Erreur : Cette case est deja occupee !\n");
            }
        } else {
            printf("Erreur : Coordonnees hors du plateau !\n");
        }
        printGrid();
        tourPasse=0;
        joueuractuel ^= 1;
    }


   }
    return 0;
}
