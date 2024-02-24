#include <stdio.h>
#include <stdlib.h> // To use malloc

struct node {
    int val;
    struct node *adr;
};

void allocate (struct node *ptr) 
{
    ptr = (struct node *)malloc(sizeof(struct node));
}

void ass_val (struct node *ptr, int value) 
{
    ptr->val = value;
}

void ass_adr (struct node *ptr1, struct node *ptr2) 
{
    ptr1->adr = ptr2;
}

void createList (struct node *head, int N) 
{
    struct node *p, *q;
    int value;
    allocate(p);
    scanf("%d\n", &value);
    ass_val(p,value);
    head = p;
    for (int i=1; i<N; i++) {
        allocate(q);
        scanf("%d\n", &value);
        ass_val(q,value);
        ass_adr(p,q);
        p = p->adr;
    }
    ass_adr(p,NULL);
}

/*
void countNodes (struct node *head) {
    int cpt = 0;
    if (head == NULL) {
        printf ("Linked List is empty");
    }
    else {
        struct node *ptr = NULL;
        ptr = head;
        while (ptr != NULL) {
            cpt++;
            ptr = ptr->adr;
        }
        printf ("%d", count);
    }
}*/

int main ()
{ 
    struct node *H = NULL;
    struct node *p;
    struct node *q;
    allocate(p);
    H = p;
    createList(H,3);
    printf ("\n");
    p = H;
    while (p!=NULL){
        printf("%d",p->val);
        p = p->adr;
    }
    return 0;
}