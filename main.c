#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "moveController.h"
//#include "capteurs.h"

#define TAILLE_MAX 32
#define TAILLE_COORDONNEES 5
#define RADIUS 30
#define STARTRADIUS 30

void readAndCall(FILE * file, char c);

int main()
{
    //TODO Definir le nombre de capteurs et leur donner un meilleur nom
    // Avant arriere
    int capt_1 = 0;
    int capt_2 = 0;
    int capt_3 = 0;

    //Pour definir si les cpateurs doivent être pris en compte
    //1 : Pris en compte
    //0 : Pas pris en compte
    int etatCapteur = 1;

    //ouvre le fichier et la tache sera stocké dans action
    char c;
    FILE* file = NULL;
    file = fopen("commande.txt", "r");

    while((c = fgetc(file)) != EOF)
        readAndCall(file, c);

    fclose(file);
    return 0;
}

void readAndCall(FILE * file, char c)
{
    if((c >= '0') && (c <= '9')) {
      char Xcoord[TAILLE_COORDONNEES];
      char Ycoord[TAILLE_COORDONNEES];
      Xcoord[0] = c;
      int i = 1;
      while((c = fgetc(file)) != ' ')
        Xcoord[i++] = c;
      i = 0;
      while((c = fgetc(file)) != '\n')
        Ycoord[i++] = c;
      int x = atoi(Xcoord);
      int y = atoi(Ycoord);
      printf("[FILE] go to [%d,%d]\n", x, y);
      //point_t dest = {x, y};
      //goForward(&dest);
      return;
    }
    fgetc(file);
    if(c == 'A'){
        printf("[FILE] It's an A \n");
    }
    else if(c == 'B'){
        printf("[FILE] It's a B \n");
    }
    else if(c == 'C'){
        printf("[FILE] It's a C \n");
    }
    else {
        printf("[FILE] PARSING ERROR\n");
        return;
    }
}
