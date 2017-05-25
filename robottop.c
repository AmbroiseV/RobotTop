#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <robotdriver/movecontroller.h>
#include <robotdriver/motordriver.h>
#include <robotdriver/timing.h>
//#include "capteurs.h"

#define TAILLE_MAX 32
#define TAILLE_COORDONNEES 5
#define RADIUS 30
#define STARTRADIUS 30

int readAndCall(FILE * file, char c);

// 0: translation, 1: rotation
static int mov = 0;
// 0: forward, 1: backward
static int dir = 0;

int main()
{
    //TODO Definir le nombre de capteurs et leur donner un meilleur nom
    // Avant arriere
    /*int capt_1 = 0;
    int capt_2 = 0;
    int capt_3 = 0;

    //Pour definir si les cpateurs doivent être pris en compte
    //1 : Pris en compte
    //0 : Pas pris en compte
    int etatCapteur = 1;*/

    //ouvre le fichier et la tache sera stocké dans action
    char c;
    FILE* file = NULL;
    file = fopen("command_tests.txt", "r");
    c = fgetc(file);
    while(c != EOF && c != '\0')
    {
        if(readAndCall(file, c))
	    return 0;
        c = fgetc(file);
    }
    fclose(file);
    return 0;
}

int readAndCall(FILE * file, char c)
{
    if((c >= '0') && (c <= '9')) {
	if(!mov){
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
    	    point_t dest = {x, y};
            goForward(&dest);
            return 0;
	}
        else {
    	    char rot_str[TAILLE_COORDONNEES];
    	    rot_str[0] = c;
    	    int i = 1;
    	    while((c = fgetc(file)) != '\n')
    	        rot_str[i++] = c;
    	    int rot = atoi(rot_str);
    	    printf("[FILE] go to [%ddeg]\n", rot / 10);
            rotate(rot);
            return 0;
	}
    }
    while(fgetc(file) != '\n');
    if(c == 'P'){
        printf("[FILE] It's an P \n");
    }
    else if(c == 'S'){
        printf("[FILE] It's a S \n");
    }
    else if(c == 'L'){
        printf("[FILE] It's a L \n");
    }
    else if(c == 'A'){
        printf("[FILE] It's an A \n");
	mov = 0;
	dir = 0;
    }
    else if(c == 'R'){
        printf("[FILE] It's a R \n");
	mov = 0;
	dir = 1;
    }
    else if(c == 'D'){
        printf("[FILE] It's a D \n");
	mov = 1;
    }
    else if(c == '#'){}
    else if(c == '\n'){}
    else {
	if(c != 255)
            printf("[FILE] PARSING ERROR: %d\n", c);
        return 1;
    }
    return 0;
}
