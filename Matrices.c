#include <stdio.h>

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

int main () 
{
    int *N_ligne, *N_colone;
    int N_ligneA, N_coloneA;
    int N_ligneB, N_coloneB;
    printf ("Number of lines de A : ");
    scanf ("%d", &N_ligneA);
    printf ("Number of colones de A : ");
    scanf ("%d", &N_coloneA);

    printf ("Number of lines de B : ");
    scanf ("%d", &N_ligneB);
    printf ("Number of colones de B : ");
    scanf ("%d", &N_coloneB);

    int A[N_ligneA][N_coloneA];
    int B[N_ligneB][N_coloneB];
    N_ligne = &N_ligneA;
    N_colone = &N_coloneB;
    int C[*N_ligne][*N_colone];

    printf ("Matrix A : ");
    lect2D (N_ligneA,N_coloneA,A);
    printf ("Matrix B : ");
    lect2D (N_ligneB,N_coloneB,B);
    //printf ("The matrix is : \n");
    //ecrire2D (N_ligne,N_colone,A);

    //printf ("Pascal triangle : \n");
    //pascal_triangle(N_ligne);
    //ecrire2D(N_ligne,N_ligne,A);
    mult_matrix(N_ligneA,N_coloneA,A,N_ligneB,N_coloneB,B,N_ligne,N_colone,C);
    ecrire2D (*N_ligne,*N_colone,C);

    return 0;
}