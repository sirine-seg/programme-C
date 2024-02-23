#include <stdio.h>
#include <stdlib.h>

void lect1D (int T[], int taille);
// Read the elements of an array T

void ecrire1D (int T[], int taille);
// Write an array T

int RechN (int T[], int taille, int element);
// Search for an element in an array T, return the index if the element is found, else return -1

void intersectionTab (int T1[], int taille1, int T2[], int taille2, int T[], int *ptaille);
// Returm an array T that contains the commun elements of T1 and T2

int sumTab (int T[], int taille);
// Sum the elements of T

void insertEleTab (int T[], int *taille, int element, int pos);
// Insert an element in T at the position (the index) pos

void deleteEleTab (int T[], int *taille, int pos);
// Delete an element of T at the position (the index) pos

int freqEleTab (int T[], int taille, int element);
// Return the frequence of appearance of an element in an array

void selectionSort (int T[], int taille);
// Sort T (assending order)

void mergeSort (int T1[], int taille1, int T2[], int taille2, int T[], int *taille);
// From two sorted arrays we creat a sorted array containing the elemnts of T1 and T2 (without sorting)

int main()
{
    /* Initialization */
    int T1[5], tailleT1 = 5;
    int T2[5], tailleT2 = 5;
    int T[5], tailleT = 5;
    int *ptailleT = &tailleT;
    int N; // l'element a trouve
    int index; // l'index de l'element a trouve

    lect1D(T1,tailleT1);
    lect1D(T2,tailleT2);
    mergeSort(T1,tailleT1,T2,tailleT2,T,ptailleT);
    ecrire1D(T,tailleT);
    printf("%d\n",tailleT);

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