#include "Dico.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void selectionMot(char *pointeurMotSecret)
{


    FILE* fichier = NULL;
    char ligneFichier[20] = "";   // Definit nombre caractere a prendre par Ligne
    int i = 0;                                  // Iterateur
    int nombreAleatoire =0;

    fichier = fopen("dico.txt" , "r");
    srand(time(NULL));   // Initialise le Random en (marche via le temps et selon la minute ou seconde d'ouverture de l'application)


    if (fichier != NULL)
    {
       while(fgets(ligneFichier,20,fichier) != NULL)        // Passe de ligne en ligne avec fgets tant qu'il y a des caract�res sur la ligne suivante
       {
            //printf("%s", ligneFichier);   pour verifier si les mots �taient bien parcouru
            i++;
       }

        rewind(fichier);
         //printf("\nnombre de mots %d\n", i);
        nombreAleatoire = rand()%i;             // definit nombre al�atoire entre 0 et  i
        //printf("nombre aleatoire %d", nombreAleatoire);
       for(i=0; i != nombreAleatoire;i++)
       {
           fgets(ligneFichier,20,fichier);
        }
        *pointeurMotSecret = ligneFichier;
       //printf("\n mot aleatoire: %s", ligneFichier);
        fclose(fichier);

    }
    else
    {

        printf("Impossible d'ouvrir le fichier dico.txt");

    }

    return 0;
}
