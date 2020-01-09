#include <stdio.h>
#include <math.h>
#include "functions2.h"
void Tablet(float h, float start, float end){
    float y;
    printf(" x\t\t\t\tParameter\ty \n");
    for (float currentPoint = start; currentPoint < end; currentPoint += h){
        int parameter = Formula(currentPoint, &y);
        printf("|%f\t-\t% d\t\t-\t%f|\n", currentPoint,parameter, y  );
    };
}
int Formula(float x, float* p)
{
    *p = sqrt(1 - cos(2*x));
    if (*p>0) return 1;
    if (*p==0) return 0;
    return -1;
}