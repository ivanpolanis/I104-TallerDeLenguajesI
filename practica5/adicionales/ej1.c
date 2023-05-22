#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    double frequency;
} LetterFrequency;

const LetterFrequency letterFrequencies[] = {
    {'A', 12.53}, {'B', 1.42}, {'C', 4.68}, {'D', 5.86}, {'E', 13.68}, {'F', 0.69}, {'G', 1.01}, {'H', 0.70},
    {'I', 6.25}, {'J', 0.44}, {'K', 0.01}, {'L', 4.97}, {'M', 3.15}, {'N', 6.71}, {'Ñ', 0.31}, {'O', 8.68},
    {'P', 2.51}, {'Q', 0.88}, {'R', 6.87}, {'S', 7.98}, {'T', 4.63}, {'U', 3.93}, {'V', 0.90}, {'W', 0.02},
    {'X', 0.22}, {'Y', 0.90}, {'Z', 0.52}
};

double getFrequency(char *);

int main(){
    return 0;
}

double getFrequency(char *str){
    double freq = 0;
    for (int i = 0; i < strlen(str); i++){
      freq += letterFrequencies[str[i] - 'A'].frequency;
    }
    return freq;
}

