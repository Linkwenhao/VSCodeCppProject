#include <stdio.h>

int ni(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else
    {
        return ni(n - 1) + 3;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        sum = ni(i) + sum;
    }
    printf("%d", sum);
}