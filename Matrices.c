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

int main () 
{
    int N_ligne, N_colone;
    printf ("Number of lines : ");
    scanf ("%d", &N_ligne);
    printf ("Number of colones : ");
    scanf ("%d", &N_colone);

    int A[N_ligne][N_colone];

    lect2D (N_ligne,N_colone,A);
    printf ("The  matrix is : \n");
    ecrire2D (N_ligne,N_colone,A);

    return 0;
}