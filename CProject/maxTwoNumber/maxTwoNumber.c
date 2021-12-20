#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b;
    while (~scanf("%d %d", &a, &b))
    {
        printf("a+b=%d\n", a + b);
        printf("max(a,b)=%d\n", max(a,b));
    }
    return 0;
}