#include <stdio.h>

int *Bubble(int *s, int len)
{
    int flag;
    do
    {
        flag = 0;
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = 0; j < len - 1 - i; j++)
            {
                if (s[j] > s[j + 1])
                {
                    int temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                    flag = 1;
                }
            }
        }
    } while (flag == 1);
    return s;
}

int main()
{
    int nums[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &nums[i]); //注意取地址符 &，不要遗忘哦
    }
    Bubble(nums, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *(nums + i));
    }
    return 0;
}