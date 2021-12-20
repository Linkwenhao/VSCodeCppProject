#include <stdio.h>

int i = 2;

int Cow(int n)
{
    if (n < 4)
    {
        return n;
    }
    else
    {
        return Cow(n - 1) + Cow(n - 3);
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        printf("%d\n", Cow(n));
    }

    return 0;
}
