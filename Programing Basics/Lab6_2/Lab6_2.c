//
// Created by andrii on 07.11.18.
//
#include <stdio.h>
#include <stdarg.h>
#include "Lab6_2.h"
void PrimeNumbers(int a, ...)
{
    va_list parg;
    int arg = a, check, ifpresent = 0;
    va_start(parg,a );
    printf("Prime numbers ");
    while ( arg > 0)
    {
        check = 0;
        for(int div = 2; div < arg/2; ++div) {
            if (arg % div == 0) {
                ifpresent = 1;
                check = 1;
                break;
            }
        }
        if(!check && arg != 1) printf("%d\t", arg);
        arg = va_arg(parg,int);
    }
    va_end(parg);
    if (!ifpresent) printf("are not found.");
}
