#include <stdio.h>

void put(int rev, int end)
{
    while (rev != 0)
    {
        printf("%d ", rev % 10);
        rev /= 10;
        if (rev == end)
        {
            printf("%d\n", rev);
            break;
        }
    }
}

int main()
{
    int num, end;
    int count = 0, rev = 0, digit = 0;
    scanf("%d", &num);
    end = num % 10;
    while (num != 0)
    {
        digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
        count++;
    }
    printf("%d\n", count);
    put(rev, end);
    printf("%d", rev);
}