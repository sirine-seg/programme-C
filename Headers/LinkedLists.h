#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

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
void mergeList (ptr H1, ptr H2, ptr *H);
void insertPos (ptr *head, int V, int pos);

#endif