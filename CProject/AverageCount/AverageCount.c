#include <stdio.h>

int main()
{
    int sum = 0;
    int nums[10], count = 0, average = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &nums[i]); //注意取地址符 &，不要遗忘哦
    }
    for (int i = 0; i < 10; i++)
    {
        sum += nums[i];
        average = sum / 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] > average)
        {
            count++;
        }
    }
    printf("%d", count);
}