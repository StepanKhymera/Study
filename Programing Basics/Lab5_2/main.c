#include <stdio.h>
#include <math.h>
#include "functions2.h"

#define startPoint  0
#define endPoint 100*M_PI

int main() {
    float  h;
    printf("Enter step of the grid (should be below 314): ");
    scanf("%f", &h);
    if (h>314) {
        printf("Pleas enter number below 314");
        return 0;
    }
    Tablet(h, startPoint, endPoint);
}
