#include <stdio.h>
int main()
{
    int m, n, temp, i;
    printf("Input m & n: ");
    scanf("%d%d", &m, &n);
    if (m < n) /*比较大小，使得m中存储大数，n中存储小数*/
    {
        temp = m;
        m = n;
        n = temp;
    }
    for (i = m; i > 0; i++) /*从大数开始寻找满足条件的自然数*/
        if (i % m == 0 && i % n == 0)
        { /*输出满足条件的自然数并结束循环*/
            printf("The LCM of %d and %d is: %d\n", m, n, i);
            break;
        }

    return 0;
}