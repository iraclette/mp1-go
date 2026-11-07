// premier projet du jeu de GO!! by Hana loll
#include "./flood.c"
#include <stdio.h>

char colonneDesiree;
int ligneDesiree;

int main() {
    int joueurActuel = NOIR;

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = VIDE;
        }
    }
    welcome();
    setup();
    char choixPasser;
    char confirmation;
    int tourPasse = 0;

    while (tourPasse < 2) {
        printf("%s, voulez-vous passer votre tour ? (Y/N) : ", joueurActuel == 0 ? black_name : white_name);
        scanf(" %c", &choixPasser);
        if (choixPasser == 'Y' || choixPasser == 'y') {
            printf("Etes-vous sur ? (P = Passer / R = Rester) : ");
            scanf(" %c", &confirmation);

            if (confirmation == 'P' || confirmation == 'p') {
                printf("%s passe son tour.\n", joueurActuel == 0 ? black_name : white_name);
            }
            joueurActuel ^= 1;
            tourPasse++;
        } else if (choixPasser == 'N' || choixPasser == 'n') {
            askAndParseCoords(&ligneDesiree, &colonneDesiree);
            if (ligneDesiree >= 0 && ligneDesiree < TAILLE
                && colonneDesiree >= 0 && colonneDesiree < TAILLE) {
                if (plateau[ligneDesiree][colonneDesiree] == VIDE) {
                    plateau[ligneDesiree][colonneDesiree] = joueurActuel;
                    move(ligneDesiree, colonneDesiree, joueurActuel);
                } else {
                    printf("Erreur : Cette case est deja occupee !\n");
                }
            } else {
                printf("Erreur : Coordonnees hors du plateau !\n");
            }
            printGrid();
            tourPasse = 0;
            joueurActuel ^= 1;
        }
    }
    return 0;
}
