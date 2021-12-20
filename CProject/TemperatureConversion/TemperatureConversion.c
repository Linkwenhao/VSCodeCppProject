#include <stdio.h>

int main()
{
    float F = 0.00;
    scanf("%f", &F);
    printf("c=%.2f", (5 * (F - 32) / 9));
}