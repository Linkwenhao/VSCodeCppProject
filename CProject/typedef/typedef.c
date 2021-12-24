#include <stdio.h>

typedef int *P;
typedef P PP;

int main()
{
    int a = 0, b = 0, c = 0;
    int *pa = &a;
    P ppa = &a;
    PP pppa = &a;
    printf("%p,%p,%p", pa, ppa, pppa);
}