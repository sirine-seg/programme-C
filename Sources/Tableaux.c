#include <stdio.h>
#include <stdlib.h>
#include "../Headers/Tableaux.h"

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

int sumTab (int T[], int taille) 
{
    int i, sum=0;
    for (i = 0; i < taille; i++) {
        sum = sum + T[i];
    }
    return sum;
}

void insertEleTab (int T[], int *taille, int element, int pos)
{
    int i;
    for (i = *taille; i >= pos; i--) {
        T[i+1] = T[i];
    }
    *taille += 1;
    T[pos] = element;
}

void deleteEleTab (int T[], int *taille, int pos)
{
    int i;
    *taille -= 1;
    for (i = pos; i < *taille; i++) {
        T[i] = T[i+1];
    }
}

int freqEleTab (int T[], int taille, int element)
{
    int i, cpt=0;
    for (i = 0; i < taille; i++) {
        if (T[i] == element) {
            cpt += 1;
        }
    }
    return cpt;
}

void selectionSort (int T[], int taille)
{
    int i ,j, tmp;
    for (i = 0; i < (taille-1); i++) {
        for (j = (i+1); j < taille; j++) {
            if (T[i] > T[j]) {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp; 
            }
        }
    }
}

void mergeSort (int T1[], int taille1, int T2[], int taille2, int T[], int *taille)
{
    *taille = taille1 + taille2;
    int i=0, j=0, k=0;
    while (i < taille1 && j < taille2) {
        if (T1[i] <= T2[j]) {
            T[k] = T1[i];
            i++;
        }
        else {
            T[k] = T2[j];
            j++;
        }
        k++;
    }
    while (i < taille1) {
        T[k] = T1[i];
        i++;
        k++;
    }
    while (j < taille2) {
        T[k] = T2[j];
        j++;
        k++;
    }
}