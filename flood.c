#include <stdio.h>
#include "./helper.c"

int visite[TAILLE][TAILLE];
int libertes = 0;

void compterlibertes(int i, int j, int ma_couleur) {
    if (i > 0 && visite[i - 1][j] == 0) {
        visite[i - 1][j] = 1;
        if ( plateau[i - 1][j] == VIDE) {
            libertes++;
        } else if (plateau[i - 1][j] == ma_couleur) {
            compterlibertes(i - 1, j, ma_couleur);
        }
    }

    if (i < TAILLE - 1 && visite[i + 1][j] == 0) {
        visite[i + 1][j] = 1;
        if (plateau[i + 1][j] == VIDE) {
            libertes++;
        } else if (plateau[i + 1][j] == ma_couleur) {
            compterlibertes(i + 1, j, ma_couleur);
        }
    }

    if (j > 0 && visite[i][j - 1] == 0) {
        visite[i][j - 1] = 1;
        if (plateau[i][j - 1] == VIDE) {
            libertes++;
        } else if (plateau[i][j - 1] == ma_couleur) {
            compterlibertes(i, j - 1, ma_couleur);
        }
    }

    if (j < TAILLE - 1 && visite[i][j + 1] == 0) {
        visite[i][j + 1] = 1;
        if (plateau[i][j + 1] == VIDE) {
            libertes++;
        } else if (plateau[i][j + 1] == ma_couleur) {
            compterlibertes(i, j + 1, ma_couleur);
        }
    }
}

int flood(int i, int j, int couleur) {
    libertes = 0;
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            visite[i][j] = 0;
        }
    }
    visite[i][j] = 1;
    compterlibertes(i, j, couleur);

    return libertes;
}
