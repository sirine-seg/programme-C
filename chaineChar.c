#include <stdio.h>
#include <string.h>

#define MAX_MOTS 15
#define NB_MOT_MAX 200

typedef struct {
    char mot[MAX_MOTS];
    int ligne_mot;
    int position_mot;
} enregistrement;

int main ()
{
    char str[] = "Hi! Je suis heureuse de vous rencontrer. Et vous? nouvelle ligne troisieme ligne";
    enregistrement enrgInfoMot[MAX_MOTS];

    int nbMots = 0;
    int ligne = 1;
    int position = 1;

    const char *separateurs = " ,.!?'-_";
    char *strtoken = strtok(str, separateurs);

    while ((strtoken != NULL) && (nbMots < NB_MOT_MAX)) {
        strcpy(enrgInfoMot[nbMots].mot, strtoken);
        enrgInfoMot[nbMots].ligne_mot = ligne;
        enrgInfoMot[nbMots].position_mot = position;
        nbMots++;
        position++;
        strtoken = strtok(NULL, separateurs);
        if (strtoken != NULL && strtoken[0] == '\n') {
            ligne++;
            position = 1;
        }
    }
    
    // Output //
    for (int i = 0; i < nbMots; i++) {
        printf("Mot : %s, Ligne : %d, Position : %d\n", enrgInfoMot[i].mot, enrgInfoMot[i].ligne_mot, enrgInfoMot[i].position_mot);
    }
    return 0;
}