#include <stdio.h>
#include <stdlib.h> // To use malloc

struct cell {
    int val;
    struct cell *adr;
};

typedef struct cell *ptr;

void allocate (ptr *p) 
{
    *p = malloc(sizeof(struct cell));
}

void ass_val (ptr p, int value) 
{
    p->val = value;
}

void ass_adr (ptr p, ptr q) 
{
    p->adr = q;
}

ptr next (ptr p)
{
    return p->adr;
}

int value (ptr p) 
{
    return p->val;
}

void createList (ptr *head, int N) 
{
    ptr p = NULL, q = NULL;
    int v;
    if (N == 0) {
        head = NULL;
    }
    else {
        allocate(&p);
        printf ("Cell 1 : ");
        scanf("%d", &v);
        ass_val(p,v);
        *head = p;
        for (int i=2; i<=N; i++) {
            allocate(&q);
            printf ("cell %d : ", i);
            scanf("%d", &v);
            ass_val(q,v);
            ass_adr(p,q);
            p = q;
        }
        ass_adr(p,NULL);
    }
}

void displayList (ptr head, int N)
{
    ptr p=head;
    for (int i=1; i<=N; i++) {
        printf ("cell %d : %d\n", i, value(p));
        p = next(p);
    }
}

int lengthList (ptr head)
{
    int cpt=0;
    ptr p=head;
    while (p != NULL) {
        cpt++;
        p = next(p);
    }
    return cpt;
}

int main ()
{ 
    ptr head;
    ptr p;
    int N, l;
    printf ("Enter the number of cells : ");
    scanf ("%d", &N);
    createList(&p,N);
    printf ("\n");
    
    l = lengthList(p);
    printf ("%d", l);
    printf ("\n");

    displayList(p,N);
    return 0;
}