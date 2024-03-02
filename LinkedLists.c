#include <stdio.h>
#include <stdlib.h> // To use malloc

struct cell {
    int val;
    struct cell *adr;
};

typedef struct cell *ptr;

// Abstract Machine
void allocate (ptr *p);
void ass_val (ptr p, int value);
void ass_adr (ptr p, ptr q); 
ptr next (ptr p);
int value (ptr p);
// Modules
void createList (ptr *head, int N);
void displayList (ptr head, int N);
int lengthList (ptr head);
int freq (ptr head, int N);
int greatestFreq (ptr head);
ptr accessVal (ptr head, int V);
void accessPos (ptr head, int pos, ptr *p, ptr *q); // p is the adr of pos, q is the adr of pos-1
void deletePos (ptr *head, int pos);

int main ()
{ 
    ptr head;
    ptr p, q, r;
    int N, l, val;
    printf ("Enter the number of cells : ");
    scanf ("%d", &N);
    createList (&p,N);
    printf ("\n");
    
    l = lengthList(p);
    printf ("%d", l);
    printf ("\n");

    displayList(p,N);

    printf ("position : ");
    scanf ("%d", &val);
    deletePos(&p,val);
    N = lengthList(p);
    displayList(p,N);
    //accessPos(p,val,&q,&r);
    //printf ("%p\n%p", q, r);
    //printf ("greatest occurence : %d", greatestFreq(p));


    printf ("\n");
    return 0;
}

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
        printf ("cell %d : %d\tadr : %p\n", i, value(p), p);
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

int freq (ptr head, int N)
{
    int cpt=0;
    ptr p=head;
    while (p!=NULL) {
        if (value(p)==N) {
            cpt++;
        }
        p = next(p);
    }
    return cpt;
}

int greatestFreq (ptr head)
{
    ptr p=head;
    int max=value(head);
    while (next(p)!=NULL) {
        p = next(p);
        if (freq(head,value(p))>freq(head,max)) {
            max = value(p);
        }
    }
    return max;
}

ptr accessVal (ptr head, int V)
{
    ptr p=head;
    while (p!=NULL && value(p)!=V) {
        p = next(p);
    }
    return p;
}

void accessPos (ptr head, int pos, ptr *p, ptr *q)
{
    int i=0;
    *p = head;
    *q = NULL;
    while (p!=NULL && i<pos) {
        *q = *p;
        *p = next(*p);
        i++;
    }
}

void deletePos (ptr *head, int pos)
{
    ptr p=*head;
    ptr q=NULL;
    accessPos(*head,pos,&p,&q);
    if (p != NULL) {
        if (q != NULL) {
            ass_adr (q,next(p));
        }
        else {
            *head = next(*head);
        }
        free(p);
    }
}