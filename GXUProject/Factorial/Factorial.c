#include <stdio.h>

int Factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return Factorial(n - 1) * n;
    }
}

int sum(int n)
{
    int sum = 0;
    for (size_t i = 1; i <= n; i++)
    {
        sum = Factorial(i) + sum;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", Factorial(n));
    printf("%d", sum(n));
}