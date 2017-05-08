#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

//#include "moveController.h"
//#include "pathFinder.h"
//#include "capteurs.h"

#define TAILLE_MAX 32
#define TAILLE_COORDONNEES 5
#define RADIUS 30
#define STARTRADIUS 30

void readAndCall(char *action,char c);


int main(){
    //TODO Definir le nombre de capteurs et leur donner un meilleur nom
    // Avant arriere
    int capt_1 = 0; 
    int capt_2 = 0;
    int capt_3 = 0;

    //Pour definir si les cpateurs doivent être pris en compte
    //1 : Pris en compte
    //0 : Pas pris en compte
    int etatCapteur = 1;
    
    //Créé un thread pour les capteurs en se basant sur la fonction
    //maincapteur
    pthread_t tcapteur;
    pthread_create(&tcapteur, NULL, maincapteur, NULL);
    
    //ouvre le fichier et la tache sera stocké dans action
    char action[TAILLE_MAX] = "";
    char c;
    FILE* commande = NULL;
    commande = fopen("commande.txt", "r");



    while (fgets(action, TAILLE_MAX, commande) != NULL){
        c = action[0];
        readAndCall(action, c);

    }

    fclose(commande);
    return 0;

}


void readAndCall(char *action,char c){
    char Xcoord[TAILLE_COORDONNEES];
    char Ycoord[TAILLE_COORDONNEES];
    char anglecoord[TAILLE_COORDONNEES];
    int i = 0;
    int j = 0;
    int k = 0;
    char *dechet;
    int x;
    int y;
    int angle;
    int radius = RADIUS;
    int startRadius = STARTRADIUS;
    //move_s pfinal; 

        if ((c >= '0') && (c <= '9')){
            while(action[i]!= ' '){
                Xcoord[i]=action[i];
                i++;
            }
            Xcoord[i]='\0';
            i++;                

            while(action[i]!=' '){
                Ycoord[j]=action[i];
                i++;
                j++;     
            }
            Ycoord[j]='\0';

            while(action[i]!='\n'){
                anglecoord[k]=action[i];
                i++;
                k++;
            }
            anglecoord[k]='\0';


            //TODO pour l'instant on passe par des variables, à
            //terme, directement à associer avec la structure 
            x = (int) strtol(Xcoord, &dechet, 10); 
            y = (int) strtol(Ycoord, &dechet, 10);
            angle = (int) strtol(anglecoord, &dechet, 10); 

            printf("x=%d, y=%d, angle=%d, radius=%d \n",x,y,angle,radius);
            i = 0;
            j = 0;
            k = 0;
            /*
               pfinal.x = x;
               pfinal.y = y;
               pfinal.angle = angle;
               pfinal.radius = radius;
               

               goto(startRadius,pfinal); 
             */    
        }

        else if(strcmp(action,"A\n") == 0){
            printf("It's an A \n");
        }

        else if(strcmp(action, "B\n") == 0){
            printf("It's a B \n");
        }

        else if(strcmp(action, "C\n") == 0){
            printf("It's a C \n");
        }

        else {
            printf("rien\n");
        }
}
