#include <stdio.h>
#include <time.h>

 /* PROTOTYPES FONCTIONS */

void init_carte(int tab[20][20], int posPersonnage[2]);
void afficher_carte(int tab[20][20], int posPersonnage[2]);
int deplace_personnage(int tab[20][20], int posPersonnage[2]);

/* FONCTION MAIN */

int main ()
{
    int carteJeu[20][20];
    int Personnage[2] = {0,0};

    init_carte(carteJeu,Personnage);
    afficher_carte(carteJeu, Personnage);
    deplace_personnage(carteJeu, Personnage);

    return(0);
}

/* ___________________________*/
/* INITIALISATION DE LA CARTE */
/* ___________________________*/

void init_carte(int tab[20][20], int posPersonnage[2])
{

	int i; //lignes
	int j; //colonnes
    int caseAleatoire;

    srand(time(0));

	/* Initialisation des objets présents sur la carte */

    for(i=0; i<20; i=i+1){

            for(j=0; j<20; j=j+1){
                tab[i][j]=0;
            }
	}
    // CASE ALEATOIRE pour Herbe, pierre etc.

    for(i=0;i<20;i++)
    {

            for(j=0; j<20; j=j+2)
        {
                caseAleatoire = (rand()% 10);
                tab[i][j] = caseAleatoire;


        }

    }
}

/* ___________________________*/
/* AFFICHAGE DE LA CARTE  */
/* ___________________________*/

void afficher_carte(int tab[20][20], int posPersonnage[2]){

	int l; //lignes
	int c; //colonnes
	int extremites;

	for (extremites=0; extremites<66; extremites++){
        printf("#");}

    printf("\n");
	for(l=0 ;l<20; l++){



		printf(" * ");
		for(c=0; c<20; c++){
			if((l==posPersonnage[1]) && (c==posPersonnage[0])){
				printf(" X ");
			}
              	 	else{
			printf(" %d ",tab[l][c]);
			}
		}
		printf("  *  \n");
	}
	for (extremites=0; extremites<66; extremites++)
	{
        printf("#");
    }


}

/* ___________________________*/
/* DEPLACEMENT DU PERSONNAGE  */
/* ___________________________*/

int deplace_personnage(int tab[20][20], int posPersonnage[2]){

    char deplacement[2] = {0};

	printf ("Deplacer le personnage :(4=gauche, 6=droite, 8=haut et 2=bas)\n") ;

	int quit = 0;

	while (quit == 0)
	{
		scanf ("%c", &deplacement);

		switch (deplacement[0])
		{
			case '\n':continue;
			case '4' :
				if (posPersonnage[0] == 0)
					printf("Le personnage ne peut pas aller à gauche \n");
				else
				{
					printf ("Personnage va à gauche \n") ;
				 	posPersonnage[0] -= 1;
				}
				break;
			case '6' :
				if (posPersonnage[0] == 19)
					printf("Le personnage ne peut pas aller à droite\n ");
				else
				{
					printf ("Personnage va à droite \n") ;
				 	posPersonnage[0] +=1;
				}
				break;
			case '8' :
				if (posPersonnage[1] == 19)
				 	printf("Le personnage ne peut pas aller en haut\n ");
				else
				{
					printf ("Personnage va en haut \n") ;
				 	posPersonnage[1] +=1;
				}
				break;
			case '2' :
                if (posPersonnage[1] == 19)
				 	printf("Le personnage ne peut pas aller en haut\n ");
				else
				{
					printf ("Personnage va en haut \n") ;
				 	posPersonnage[1] +=1;
				}
				break;
			case 'q' :
				quit = 1;
				break;
			default :
				printf("Déplacement inconnu\n");
				break;
		}
                afficher_carte(tab,posPersonnage);
	}
}

