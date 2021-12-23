#include <stdio.h>

int fac(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fac(n - 1) + fac(n - 2);
    }
}

void fibonacci(int n)
{
    int num1 = 1;
    int num2 = 1;
    for (size_t i = 1; i <= n; i++)
    {
        printf("%d ", num1);
        int nexNum = num1 + num2;
        num1 = num2;
        num2 = nexNum;
    }
}

int main()
{
    int n;
    fibonacci(5);
    // while (~scanf("%d", &n))
    // {
    //     for (size_t i = 1; i <= n; i++)
    //     {
    //         printf("%d ", fac(i));
    //         if (i == n)
    //         {
    //             printf("\n");
    //             break;
    //         }
    //     }
    // }

}