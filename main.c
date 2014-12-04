#include <stdio.h>
#include <time.h>

void AfficherCarte(int carte[20][20], int posPerso[2]);
void arene();
void init_carte();

char Personnage = 'X';

int main ()
{
    int carteJeu[20][20];
    init_carte(carteJeu);
    carteJeu[5][5]=Personnage;


return(0);
}

/*                             */
/*  INITIALISATION DE LA CARTE */
/*                             */

void init_carte(int carte[20][20])
{

    int i;
    int j;

        for(i=0; i<20;i++)
{
            printf("\n0", carte[i]);

        for (j=0; j<20; j++){
            printf("0", carte[j]);

        }
}
}
void AfficherCarte(int carte[20][20], int posPerso[2])
{

}
