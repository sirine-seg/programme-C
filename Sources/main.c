#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Headers/LinkedLists.h"
#include "../Headers/Tableaux.h"
#include "../Headers/Strings.h"
#include "../Headers/Matrices.h"

int main ()
{ 
    ptr head;
    ptr p, q, r;
    int N, l, val;
    int T[5];
    printf ("Enter the number of cells : ");
    scanf ("%d", &N);
    createList (&p,N);
    printf ("\n");
    createList (&q,N);

    printf ("\n");
    mergeList(p,q,&r);
    l = lengthList(r);
    displayList(r,l);

    lect1D(T,5);
    printf ("\n");
    return 0;
}