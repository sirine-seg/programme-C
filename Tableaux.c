#include <stdio.h>
#include <stdlib.h>

void lect1D (int T[], int taille);
// Lecture des elements d'un tableau a une dimension

void ecrire1D (int T[], int taille);
// Ecriture des elements d'un tableau a une dimension

int RechN (int T[], int taille, int element);
// Recherche d'un element dans un tableau (1D)

int main()
{
    /* Initialization */
    int T[10], tailleT = 10;
    int N; // l'element a trouve
    int index; // l'index de l'element a trouve
    /* Lecture et ecriture du  tableau */
    lect1D(T,tailleT);
    printf("\n");
    ecrire1D(T,tailleT);
    /* Element a trouve */
    printf("N = ");
    scanf("%d", &N);
    index = RechN(T,tailleT,N);
    if (index != -1){
        printf("L'element %d a ete trouve a l'index %d.\n", N, index);
    }
    else {
        printf("L'element %d n'a pas ete trouve dans le tableau.\n", N);
    }
    /* Fin */
    return 0;
}


// modules

void lect1D (int T[], int taille)
{
    int i;
    for (i = 0; i < taille; i++){
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
}

void ecrire1D (int T[], int taille)
{
    int i;
    for (i = 0; i < taille; i++){
        printf("T[%d] = %d\n", i, T[i]);
    }
}

int RechN (int T[], int taille, int element)
{
    int i, a;
    for (i = 0; i < taille; i++){
        if (T[i] == element){
            return i;
        }
    }
    return -1;
   /* a = -1;
    for (i = 0; i < taille; i++){
        if (T[i] == element){
            a = i;
            break;
        }
    }
    return a;*/
}
