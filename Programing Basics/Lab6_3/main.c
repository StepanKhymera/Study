#include <stdio.h>
#include <math.h>
#define SQR(a) a*a
#define MAX(a, b) a > b ? (a) : b
#define MIN(c, d) c > d ?  d  : c
#define SQRT(x) sqrt(x)
#define a 1
int main() {
   double x, z, y, result;
    printf("Enter x :  " );
    if(!scanf("%lf", &x)) {
        printf("Try to enter a number next time.");
        return 0;
    }
    printf("Enter y : ");
    if(!scanf("%lf", &y)) {
        printf("Try to enter a number next time.");
        return 0;
    }
    printf("Enter z : ");
    if(!scanf("%lf", &z)) {
        printf("Try to enter a number next time.");
        return 0;
    }

#if (a > 0)
    result = SQRT(x - y + MAX(SQR(x-z), (x-y)));
    if (isnan(result)) {
        printf("Square root from negative number.");
        return 0;
    }
#else
    result = MAX(x*y, x*z) +MIN(x-y , y - z);
#endif
    printf("%f", result);
}