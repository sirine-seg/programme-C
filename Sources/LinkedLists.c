#include <stdio.h>
#include <stdlib.h> // To use malloc
#include "../Headers/LinkedLists.h"

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

void accessPVal (ptr head, int V, ptr *p, ptr *q)
{
    *p = head;
    *q = NULL;
    while (*p!=NULL && value(*p)!=V) {
        *q = *p;
        *p = next(*p);
    }
}

ptr accessPos (ptr head, int pos)
{
    ptr p=head;
    int i=0;
    while (p!=NULL && i<pos) {
        p = next(p);
        i++;
    }
    return p;
}

void accessPPos (ptr head, int pos, ptr *p, ptr *q)
{
    int i=0;
    *p = head;
    *q = NULL;
    while (*p!=NULL && i<pos) {
        *q = *p;
        *p = next(*p);
        i++;
    }
}

void deleteVal (ptr *head, int V)
{
    ptr p=*head;
    ptr q=NULL;
    accessPVal(*head,V,&p,&q);
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

void deletePos (ptr *head, int pos)
{
    ptr p=*head;
    ptr q=NULL;
    accessPPos(*head,pos,&p,&q);
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

void mergeList (ptr H1, ptr H2, ptr *H)
{
    ptr p=H1;
    ptr q=H2;
    ptr t;
    if (value(p)<value(q)) {
        *H = H1;
        p = next(p);
    }
    else {
        *H = H2;
        q = next(q);
    }
    t = *H;
    while ((p!=NULL) && (q!=NULL)) {
        if (value(p)<value(q)) {
            ass_adr(t,p);
            t = p;
            p = next(p);
        }
        else {
            ass_adr(t,q);
            t = q;
            q = next(q);
        }
    }
    if (p!=NULL) {
        ass_adr(t,p);
    }
    else {
        ass_adr(t,q);
    }
}

void insertPos (ptr *head, int V, int pos)
{
    ptr p, q, t;
    accessPPos(*head,pos,&p,&q);
    allocate(&t);
    ass_val(t,V);
    ass_adr(t,p);
    if (q != NULL) {
        ass_adr(q,t);
    }
    else {
        *head = t;
    }
}
