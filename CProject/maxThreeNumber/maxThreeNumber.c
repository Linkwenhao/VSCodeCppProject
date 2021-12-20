#include <stdio.h>

int max(int a, int b, int c)
{
    int max = a;
    if (b > a)
        max = b;
    if (c > b)
        max = c;
    return max;
}

int main()
{
    int a = 10, b = 20, c = 30;
    // scanf("%d %d %d", &a, &b, &c);
    printf("%d", max(a, b, c));
}