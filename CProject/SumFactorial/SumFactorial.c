#include <stdio.h>

long Factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return Factorial(n - 1) * n;
    }
}

long sum(int n)
{
    long sum = 0;
    for (size_t i = n; i > 0; i--)
    {
        sum += Factorial(i);
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 20)
        return 0;
    printf("%ld", sum(n));
}