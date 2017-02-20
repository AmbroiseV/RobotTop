#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#include "/home/pi/RobotDriverV2/src/moveController.h"
//#include "capteurs.h"

#define TAILLE_MAX 32
#define TAILLE_COORDONNEES 5
#define RADIUS 30
#define STARTRADIUS 30

int readAndCall(FILE * file, char c);

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
        if(readAndCall(file, c))
	    return 0;

    fclose(file);
    return 0;
}

int readAndCall(FILE * file, char c)
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
      return 0;
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
	if(c != 255)
            printf("[FILE] PARSING ERROR: %d\n", c);
        return 1;
    }
    return 0;
}
