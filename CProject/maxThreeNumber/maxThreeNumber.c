#include <stdio.h>

int max(int a, int b, int c)
{
    int max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;
    return max;
}

int main()
{
    int a = 10, b = 20, c = 30;
    // scanf("%d %d %d", &a, &b, &c);
    printf("%d", max(a, b, c));
}