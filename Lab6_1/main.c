#include <stdio.h>
#include "Lab6_1.h"
#define stringSize 100
#define amountOfLines 10
int main() {
    char lines[amountOfLines][stringSize] = {0}, *longWord, *longestWord;
    int numberOfLines, maxLength ;
    printf("How many diffrent lines you want to enter? (max %d):\n", amountOfLines);
    scanf("%d", &numberOfLines);
    getchar();
    for (int counter = 0; counter < numberOfLines; ++counter){
        printf("Enter a line. (max %d symbols): ", stringSize);
       fgets(lines[counter], stringSize, stdin);
      int length = max(lines[counter], &(longWord));
        if((counter == 0) ||(length > maxLength)){
            longestWord = longWord;
            maxLength = length;
        }
    }
    printf("%s", longestWord);
  }
