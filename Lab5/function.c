#include <stdio.h>
#include <math.h>
#include "function.h"
void Tablet(float step, float startPoint , float endPoint ){
    printf(" x\t\t\t\ty \n");
    for (float currentPoint = startPoint; currentPoint < endPoint; currentPoint += step){
        printf("|%f\t-\t%f|\n", currentPoint, Formula(currentPoint));
    };
}
float Formula(float x){
    double y = sqrt(1 - cos(2*x));
    return y;
}