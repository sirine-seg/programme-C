#ifndef TABLEAUX_H
#define TABLEAUX_H

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

#endif