#include <stdio.h>
#include <string.h>
#include <ctype.h> // tests and transformations on characters

int hammingDistance (char W1[], char W2[]);
// If two words have the same length -> Returns the number of differences (EX : united - untied -> 2)

int freqChar (char str [], char c);
// Returns the frequency of a character in a string

int numWords (char str[]);
// Returns the number of words in a sentence

void ASCIIval (char str[]);
// Print ASCII value of each character

int main ()
{
    char word1[20], word2[20], string[50];
    int N;
    
    gets(string);
    N = freqChar(string,' ');
    printf("%d\n", N);
    return 0;
}

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