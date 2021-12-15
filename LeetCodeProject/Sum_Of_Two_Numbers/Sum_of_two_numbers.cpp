#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                int *ret = (int *)malloc(sizeof(int) * 2);
                ret[0] = i, ret[1] = j;
                *returnSize = 2;
                return ret;  //return 后面的代码不执行
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int len = sizeof(nums) / sizeof(int); //数组名/数据类型
    int returnSize = 0;
    int *Size = &returnSize;
    int *index;
    index = twoSum(nums, len, 18, Size);
    printf("对应下标数组为 [");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d", index[i]);
        if (i == 1) 
            break;
        printf(",");
    }
    printf("]");
}