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
    printf ("Enter the number of cells : ");
    scanf ("%d", &N);
    createList (&p,N);
    insertPos(&p,1,2);

    printf ("\n");
    displayList(p,lengthList(p));

    printf ("\n");
    return 0;
}