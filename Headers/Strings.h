#ifndef STRINGS_H
#define STRINGS_H

int hammingDistance (char W1[], char W2[]);
// If two words have the same length -> Returns the number of differences (EX : united - untied -> 2)

int freqChar (char str [], char c);
// Returns the frequency of a character in a string

int numWords (char str[]);
// Returns the number of words in a sentence

void ASCIIval (char str[]);
// Print ASCII value of each character

#endif