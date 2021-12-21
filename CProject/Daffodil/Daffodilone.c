#include <stdio.h>
#include <math.h>

int is(int x)
{
    int a = x;
    if (99 < x < 1000)
    {
        int digit1, digit2;
        digit1 = x % 10;
        x /= 10;
        digit2 = x % 10;
        x /= 10;
        if (a == pow(x, 3) + pow(digit2, 3) + pow(digit1, 3))
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}

int main()
{
    for (size_t i = 100; i < 1000; i++)
    {
        if (is(i))
            printf("%d\n", i);
    }
}