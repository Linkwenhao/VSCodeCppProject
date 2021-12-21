#include <stdio.h>

int Cal()
{
    int x;
    scanf("%d", &x);
    if (x < 1)
    {
        return x;
    }
    else if (x >= 1 && x < 10)
    {
        return 2 * x - 1;
    }
    else
    {
        return 3 * x - 11;
    }
}

int main()
{
    printf("%d", Cal());
}