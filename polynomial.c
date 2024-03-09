#include <stdio.h>
#include <stdlib.h>

struct term {
    int coef;
    int expo;
    struct term *adr;
};

typedef struct term *ptr;

// ABSTRACT MACHINE
void allocate_term (ptr *p);
void ass_expo (ptr p, int value);
void ass_coef (ptr p, int value);
void ass_adr_term (ptr p, ptr q);
ptr next_term (ptr p);
int exponent (ptr p);
int coefficient (ptr p);
// MODULES
ptr newTerm (int c, int e); // allocate, ass_expo, ass_coef
void createPol (ptr *head, int *N);
void displayPol (ptr head, int N);
int lengthPol (ptr head);
int valuePol (ptr head, int N, int x);
void derivatePol (ptr head, int *N);
void sumPol (ptr H1, ptr H2, ptr *H, int *N);
void multPol (ptr H1, ptr H2, ptr *H, int *N);

// MAIN
int main ()
{
    int choice;
    int flag=1;
    ptr head1, head2, head;
    int numTerm1, numTerm2, numTerm;
    int x;
    do {
        printf ("--------------------------- MENU ---------------------------\n");
        printf ("1. Calculate the value of the polynomial at a given point x\n");
        printf ("2. Find the derivative of a polynomial\n");
        printf ("3. Calculate the sum of two polynomials\n");
        printf ("4. Calculate the product of two polynomials\n");
        printf ("5. Exit\n");
        printf ("------------------------------------------------------------\n");
        printf ("Enter your choice : ");
        scanf ("%d", &choice);

        switch (choice) {
            case 1 :
                printf ("Calculating the value of the polynomial at a given point x : \n");
                printf ("Enter your polynomial : \n");
                printf ("Number of terms : ");
                scanf ("%d", &numTerm);
                createPol (&head,&numTerm);
                printf ("Enter the point x : ");
                scanf ("%d", &x);
                printf ("\nThe value of the polynomial for the point %d is : %d\n", x, valuePol(head,numTerm,x));
                break;
            case 2 :
                printf ("Finding the derivative of the polynomial : \n");
                printf ("Enter your polynomial : \n");
                printf ("Number of terms : ");
                scanf ("%d", &numTerm);
                createPol (&head,&numTerm);
                printf ("\nThe derivative of the polynomial is : \n");
                derivatePol (head,&numTerm);
                displayPol (head,numTerm);
                printf ("\n");
                break;
            case 3 :
                printf ("Calculating the sum of two polynomials : \n");
                printf ("Enter the first polynomial : \n");
                printf ("Number of terms : ");
                scanf ("%d", &numTerm1);
                createPol (&head1,&numTerm1);
                printf ("\nEnter the second polynomial : \n");
                printf ("Number of terms : ");
                scanf ("%d", &numTerm2);
                createPol (&head2,&numTerm2);
                printf ("\nThe sum of the two polynomials is : \n");
                sumPol (head1,head2,&head,&numTerm);
                displayPol (head,numTerm);
                printf ("\n");
                break;
            case 4 :
                printf ("Calculating the product of two polynomials : \n");
                printf ("Enter the first polynomial : \n");
                printf ("Number of terms : ");
                scanf ("%d", &numTerm1);
                createPol (&head1,&numTerm1);
                printf ("\nEnter the second polynomial : \n");
                printf ("Number of terms : ");
                scanf ("%d", &numTerm2);
                createPol (&head2,&numTerm2);
                printf ("\nThe product of the two polynomials is : \n");
                multPol (head1,head2,&head,&numTerm);
                displayPol (head,numTerm);
                printf ("\n");
                break;
            case 5 :
                flag = 0;
                printf ("\n------------- End of the program -------------\n");
                break;
            default :
                printf ("Invalid choice\n");
        }
        printf ("\n");
    } while (flag == 1);
    return 0;
}

// ABSTRACT MACHINE
void allocate_term (ptr *p)
{
    *p = malloc(sizeof(struct term));
}

void ass_expo (ptr p, int value)
{
    p->expo = value;
}

void ass_coef (ptr p, int value)
{
    p->coef = value;
}

void ass_adr_term (ptr p, ptr q)
{
    p->adr = q;
}

ptr next_term (ptr p)
{
    return p->adr;
}

int exponent (ptr p)
{
    return p->expo;
}

int coefficient (ptr p)
{
    return p->coef;
}

// MODULES
ptr newTerm (int c, int e)
{
    ptr p=NULL;
    allocate_term(&p);
    ass_coef(p,c);
    ass_expo(p,e);
    return p;
}

void createPol (ptr *head, int *N) // N can be modified (the example below)
{
    unsigned int x=1;
    unsigned int xp;
    int c, i;
    ptr p=NULL;
    ptr q=NULL;
    if (N == 0) {
        head = NULL;
    }
    else {
        printf ("The exponent : ");
        scanf ("%d", &xp);
        printf ("The coefficient of X^%d : ", xp);
        scanf ("%d", &c);
        p = newTerm (c,xp);
        *head = p;
        for (i=1; ((i<*N) && (x!=0)); i++) { // (x!=0) for example if N=4 and in the second term the exponent is 0 there is no third nor forth term
            do { // the exponent must be inferior to the exponent that precedes him
                printf ("The exponent : ");
                scanf ("%d", &x);
            } while (x >= xp);
            xp = x;
            printf ("The coefficient of X^%d : ", x);
            scanf ("%d", &c);
            q = newTerm (c,x);
            ass_adr_term(p,q);
            p = q;
        }
        ass_adr_term(p,NULL);
        *N = i;
    }

}

void displayPol (ptr head, int N)
{
    ptr p=head;
    if (N==0) {
        printf ("0");
    }
    else {
        if (coefficient(p)!=0 && exponent(p)!=0) { // for when we initialize with (0,0) and we don't want that to be displayed
            printf ("(%dX^%d)",coefficient(p),exponent(p));
        }
        p = next_term(p);
        for (int i=2; i<=N; i++) {
            printf ("+(%dX^%d)",coefficient(p),exponent(p));
            p = next_term(p);
        }
    }
}

int lengthPol (ptr head)
{
    int cpt=0;
    ptr p=head;
    while (p != NULL) {
        cpt++;
        p = next_term(p);
    }
    return cpt;
}

int valuePol (ptr head, int N, int x)
{
    int s=0, px;
    ptr p=head;
    while (p != NULL) {
        px = 1;
        for (int i=1; i<=exponent(p); i++) {
            px *= x;
        }
        s += px*coefficient(p);
        p = next_term (p);
    }
    return s;
}

void derivatePol (ptr head, int *N)
{
    ptr p=head, q=p;
    for (int i=1; (i<=*N); i++) {
        ass_coef(p,coefficient(p) * exponent(p));
        ass_expo(p, exponent(p) - 1);
        if (exponent(p)==(-1)) { // if it is a constant it's derivate is 0
            *N -= 1;
            ass_adr_term(q,NULL);
            free(p);
        }
        else {
            q = p;
            p = next_term(p);
        }
    }
}

void sumPol (ptr H1, ptr H2, ptr *H, int *N)
{
    ptr p=H1, q=H2;
    ptr t=NULL;
    *H = NULL;
    if (H1!=NULL && H2!=NULL) {
        // the head
        if (exponent(p)>=exponent(q)) {
            *H = H1;
            t = *H;
            if (exponent(p)==exponent(q)) {
                ass_coef(*H,coefficient(p)+coefficient(q));
                q = next_term(q);
            }
            p = next_term(p);
        }
        else {
            *H = H2;
            t = *H;
            q = next_term(q);
        }
        // the list (polynomial)
        while (p!=NULL && q!=NULL) {
            if (exponent(p)>=exponent(q)) {
                ass_adr_term(t,p);
                t = p;
                if (exponent(p)==exponent(q)) {
                    ass_coef(t,(coefficient(p)+coefficient(q)));
                    q = next_term(q);
                }
                p = next_term(p);
            }
            else {
                ass_adr_term(t,q);
                t = q;
                q = next_term(q);
            }
        }
        // if one of them ends we finish with the other
        if (p!=NULL) ass_adr_term(t,p);
        else ass_adr_term(t,q);
        *N = lengthPol(*H);
    }
}

void multPol (ptr H1, ptr H2, ptr *H, int *N)
{
    ptr p1=H1;
    ptr p2=H2;
    ptr q=NULL, tmp=NULL, sh, mh=NULL, ssh; // mh will contain the multiplication of one term of the first polynomial by the second polynomial
    sh=newTerm(0,0); // sh will contain the sum of the polynoms, each time we do the multiplication, we will add it to sh
    int n=0;
    while (p1 != NULL) {
        q = newTerm(0,0);
        mh = q;
        p2 = H2;
        while (p2 != NULL) {
            tmp = q;
            q = newTerm(coefficient(p1)*coefficient(p2),exponent(p1)+exponent(p2));
            ass_adr_term (tmp,q);
            p2 = next_term (p2);
        }
        ssh=sh; // we save sh
        sumPol(ssh,mh,&sh,&n);
        printf("\n");
        p1 = next_term(p1);
    }
    *H = sh;
    *N = n;
}