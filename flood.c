#include<stdio.h>

#define TAILLE 19
#define VIDE 0
#define NOIR 1
#define BLANC 2


void compterlibertes(int visite[TAILLE][TAILLE], int i, int j, int libertes)

{if( i > 0 && visite[i-1][j]==0)
    {
        libertes++;
    }
    if(i < TAILLE - 1 && visite[i+1][j]==0)
    {
        libertes++;
    }

    if(j > 0 && visite[i][j-1]==0)
    {
        libertes++;
    }

    if(j < TAILLE - 1 && visite[i][j+1]==0)
    {
        libertes++;
    }
}



if (i>0 && visite[i - 1][j] == 0)
{
        if( plateau[i-1][j]==VIDE)
        {
            (*libertes)++;
        }
        else if (plateau[i-1][j]== ma_couleur)
        {
            visite[i-1][j]= 1;

            compter_libertes_groupe(plateau, i - 1, j, ma_couleur, visite, &libertes);
        }
}

if (i < TAILLE - 1 && visite[i + 1][j] == 0) {
    if (plateau[i + 1][j] == VIDE) {
        (*libertes)++;
    } else if (plateau[i + 1][j] == ma_couleur) {
        visite[i + 1][j] = 1;
        compter_libertes_groupe(plateau, i + 1, j, ma_couleur, visite, libertes);
    }
}

if (j > 0 && visite[i][j - 1] == 0) {
    if (plateau[i][j - 1] == VIDE) {
        (*libertes)++;
    } else if (plateau[i][j - 1] == ma_couleur) {
        visite[i][j - 1] = 1;
        compter_libertes_groupe(plateau, i, j - 1, ma_couleur, visite, libertes);
    }
}

if (j < TAILLE - 1 && visite[i][j + 1] == 0) {
    if (plateau[i][j + 1] == VIDE) {
        (*libertes)++;
    } else if (plateau[i][j + 1] == ma_couleur) {
        visite[i][j + 1] = 1;
        compter_libertes_groupe(plateau, i, j + 1, ma_couleur, visite, libertes);
    }
}




int flood()
{
    int visite[TAILLE][TAILLE];
    int libertes =0;

    for(int i=0; i<TAILLE; i++)
    {
        for(int j=0; j<TAILLE; j++)
        {
            visite[i][j]=0;
        }
    }
    compterlibertes(visite, 5, 5, &libertes);

    return libertes;
}



int main() {
    int resultat = flood();
    printf("Nombre de libertes trouvees : %d\n", resultat);
    return 0;
}

