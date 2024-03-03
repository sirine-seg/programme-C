#include <stdio.h>
#include <string.h>
#include <ctype.h> // tests and transformations on characters
#include "../Headers/Strings.h"

int hammingDistance (char W1[], char W2[]) 
{
    int size1 = strlen(W1), size2 = strlen(W2);
    int i, cpt=0;
    if (size1 != size2) {
        printf ("The two words must be of the same size!\n");
    } 
    else {
        for (i = 0; i < size1; i++) {
            if (W1[i] != W2[i]) {
                cpt++;
            }
        }
    }
    return cpt;
}

int freqChar (char str [], char c)
{
    int i, cpt=0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            cpt ++;
        }
    }
    return cpt;
}

int numWords (char str[])
{
    // We've could also used directly : [ freqChar(str,' ')+1 ]
    int i, cpt=0;
    for (i = 0; /*i <= strlen(str)*/str[i]!='\0'; i++) { 
        if (str[i] == ' '/* || str[i] == '\0'*/) {
            cpt++;
        }
    }
    return /*cpt*/(cpt+1);
}

void ASCIIval (char str[])
{
    int i;
    printf ("Characters \t ASCII value\n");
    printf ("---------- \t -----------\n");
    for (i = 0; str[i] != '\0'; i++) {
        printf ("%c \t\t %d\n", str[i], str[i]);
    }
}