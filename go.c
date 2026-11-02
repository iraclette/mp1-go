// premier projet du jeu de GO!! by Hana loll
#include <stdio.h>

#define VIDE 0
#define NOIR 1
#define BLANC 2
#define TAILLE 19

int main()
{
    int plateau[TAILLE][TAILLE];
    int joueuractuel = NOIR;

        for(int i=0; i<TAILLE; i++)
            {
                for(int j=0; j<TAILLE; j++)
                {
                    plateau[i][j] = VIDE;
                }
            }

            printf("   ");
            for(int j = 0; j < TAILLE; j++)
            {
                char lettre = 'A' + j;
                if(lettre>='I')
                {
                    lettre=lettre + 1;

                }
                    printf("%c ", lettre);
            }
        printf("\n");



        for(int i=0; i<TAILLE; i++)
            { if(i<9){
                printf("%d  ", i + 1);}
                else{printf("%d ", i + 1);

                }
                for(int j=0; j<TAILLE; j++)
            {
        if(plateau[i][j] == VIDE)
            {
                printf(". ");
            }
        else if (plateau[i][j] == NOIR)
            {
                printf("X ");
            }
        else if (plateau[i][j] == BLANC)
            {
                printf("O ");
            }
        }
        printf("\n");
            }





            char choixPasser;
            char confirmation;
            int tourPasse = 0;


            printf("Joueur %d, voulez-vous passer votre tour ? (Y/N) : ", joueuractuel);

            scanf(" %c", &choixPasser);

            if (choixPasser == 'Y' || choixPasser == 'y')
            {
                printf("Etes-vous sur ? (P = Passer / R = Rester) : ");

                scanf(" %c", &confirmation);

            if (confirmation == 'P' || confirmation == 'p')
                {
                    printf("Joueur %d passe son tour.\n", joueuractuel);
                    tourPasse = 1;

                }
            }

            if (tourPasse == 0)
            {
                char lettresaisie;
                int ligneSaisie;

                printf("Entrez la lettre de la colonne (A-T): ");
                scanf(" %c", &lettresaisie);

                if (lettresaisie >= 'a' && lettresaisie <= 'z')
                {
                    lettresaisie = lettresaisie - 32;
                }

                printf("Entrez le chiffre de la ligne (1-%d): ", TAILLE);
                scanf("%d", &ligneSaisie);


                int j = lettresaisie - 'A';
                if (lettresaisie >= 'J')
                {
                    j = j - 1;
                }

                int i = ligneSaisie - 1;


                if (i >= 0 && i < TAILLE && j >= 0 && j < TAILLE)
                {

                    if (plateau[i][j] == VIDE)
                    {

                        plateau[i][j] = joueuractuel;
                    }
                    else
                    {
                        printf("Erreur : Cette case est deja occupee !\n");
                    }
                }
                else
                {
                    printf("Erreur : Coordonnees hors du plateau !\n");
                }
            }



            return 0;
}

