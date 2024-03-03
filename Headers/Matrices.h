#ifndef MATRICES_H
#define MATRICES_H

void lect2D (int Nl, int Nc, int T[Nl][Nc]); 
void ecrire2D (int Nl, int Nc, int T[Nl][Nc]); 
void pascal_triangle (int rows);
void mult_matrix (int NblA, int NbcA, int A[NblA][NbcA], int NblB, int NbcB, int B[NblB][NbcB], int *NblC, int *NbcC, int C[*NblC][*NbcC]);

#endif