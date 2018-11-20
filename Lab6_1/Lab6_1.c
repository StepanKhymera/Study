//
// Created by andrii on 07.11.18.
//

#include <string.h>
#include "Lab6_1.h"

int max(char* str, char** maxWord){
    const char dividers[] = " ";
    char* word = strtok(str, dividers);
    int maxLength = strlen(word), length;
    *maxWord = word;
    while (word)
    {
        length = strlen(word);
        if (length > maxLength) {
            maxLength = length;
            *maxWord = word;
        };
        word = strtok(0, dividers);
    }
    return maxLength;
}
