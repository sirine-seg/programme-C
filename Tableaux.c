#include <stdio.h>
#include <stdlib.h>

void lect1D (int T[], int taille);
// Lecture des elements d'un tableau a une dimension

void ecrire1D (int T[], int taille);
// Ecriture des elements d'un tableau a une dimension

int RechN (int T[], int taille, int element);
// Recherche d'un element dans un tableau (1D)

void intersectionTab (int T1[], int taille1, int T2[], int taille2, int T[], int *taille);
// Renvoie un tableau T qui contient les elements communs de T1 et T2

int main()
{
    /* Initialization */
    int T1[5], tailleT1 = 5;
    int T2[5], tailleT2 = 5;
    int T[5], tailleT = 5;
    int *ptailleT = &tailleT;
    int N; // l'element a trouve
    int index; // l'index de l'element a trouve
    /* Lecture et ecriture du  tableau */
    printf("Tableau 1 : \n");
    lect1D(T1,tailleT1);
    printf("\n");
    ecrire1D(T1,tailleT1);
    printf("\nTableau 2 : \n");
    lect1D(T2,tailleT2);
    printf("\n");
    ecrire1D(T2,tailleT2);
    printf("\n");
    /* Element a trouve */
    printf("N = ");
    scanf("%d", &N);
    index = RechN(T1,tailleT1,N);
    if (index != -1){
        printf("L'element %d a ete trouve a l'index %d.\n", N, index);
    }
    else {
        printf("L'element %d n'a pas ete trouve dans le tableau.\n", N);
    }
    /* intersection */
    printf("\n================\n");
    intersectionTab(T1,tailleT1,T2,tailleT2,T,ptailleT);
    printf("taille = %d\n", *ptailleT);
    ecrire1D(T,*ptailleT);
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

void intersectionTab (int T1[], int taille1, int T2[], int taille2, int T[], int *ptaille)
{
    int i;
    int tailleTmp = 0;
    for (i = 0; i < taille1; i++){
        if (RechN(T2,taille2,T1[i]) != (-1)){
            T[tailleTmp] = T1[i];
            tailleTmp += 1;
        }
    }
    *ptaille = tailleTmp;
}