#include <stdio.h>
#include "../Headers/Matrices.h"

//typedef int matrice[Nl][Nc];

void lect2D (int Nl, int Nc, int T[Nl][Nc]) 
{
    int i, j;
    for (i = 0; i < Nl; i++) {
        for (j = 0; j < Nc; j++) {
            printf ("T[%d,%d] = ", i, j);
            scanf ("%d", &T[i][j]);
        }
    }
}

void ecrire2D (int Nl, int Nc, int T[Nl][Nc]) 
{
    int i, j;
    for (i = 0; i < Nl; i++) {
        for (j = 0; j < Nc; j++) {
            printf("T[%d,%d] = %d\n", i, j, T[i][j]); 
        }
    }
}

void pascal_triangle (int rows)
{
    int T[rows][rows];
    int i, j;
    for (i = 0; i <= rows; i++) {
        T[i][0] = 1;
        T[i][i] = 1;
        for (j = 1; j < i; j++) {
            T[i][j] = T[i-1][j-1] + T[i-1][j];
        }
    }
    for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d \t", T[i][j]);
        }
        printf("\n");
    }
}

void mult_matrix (int NblA, int NbcA, int A[NblA][NbcA], int NblB, int NbcB, int B[NblB][NbcB], int *NblC, int *NbcC, int C[*NblC][*NbcC])
{   
    int i, j, k;
    //if (NbcA == NblB) {
        NblC = &NblA;
        NbcC = &NbcB;
        for (i = 0; i < *NblC; i++) {
            for (j = 0; j < *NbcC; j++) {
                C[i][j] = 0;
                for (k = 0; k < NbcA; k++) {
                    C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
                }
            }
        }
   // }
}