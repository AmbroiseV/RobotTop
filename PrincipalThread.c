#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "moveController.h"
#include "pathFinder.h"

#define TAILLE_MAX 32
#define TAILLE_COORDONNEES 5
#define RADIUS 30

void main{
    //TODO Definir le nombre de capteurs et leur donner un meilleur nom
    // Avant arriere
    bool capt_1 = 0; 
    bool capt_2 = 0;
    bool capt_3 = 0;

    //Pour definir si les cpateurs doivent être pris en compte
    //1 : Pris en compte
    //0 : Pas pris en compte
    bool etatCapteur = 1;

    //Créé un thread pour les capteurs en se basant sur la fonction
    //maincapteur
    pthread_t tcapteur;
    pthread_create(&tcapteur, NULL, maincapteur, NULL);

    //ouvre le fichier et la tache sera stocké dans action
    char action[TAILLE_MAX] = "";
    char Xcoord[TAILLE_COORDONNEES];
    char Ycoord[TAILLE_COORDONNEES];
    char anglecoord[TAILLE_COORDONNEES];

    FILE* commande = NULL;
    commande = fopen("commande.txt", "r");

    int i = 0;
    int j = 0;
    int k = 0;

    int x;
    int y;
    int angle;
    int radius = RADIUS;


    while (fgets(action, TAILLE_MAX, commande) != NULL){
        c = action[0]
        if ((c < '0') || (c > '9'))
            {
                while(action[i]!=" "){
                    Xcoord[i]=action[i];
                    i++;
                }
                Xcoord[i]="\0"
                
                while(action[i]!=" "){
                    Ycoord[j]=action[i]
                    i++;
                    j++:
                }
                Ycoord[j]="\0"
 
                while(action[i]!="\0"){
                    anglecoord[k]=action[i]
                    i++;
                    k++:
                }
                anglecoord[k]="\0"

                x = 
         
            }

        if(strcmp(chaine, "A") == 0)    
            

    }
    
    fclose(commande);
    return 0;

}
