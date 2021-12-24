#include <stdio.h>

#define N 3

void Sort(float w[], float p[])
{
    int i, j;
    float temp;
    float v[N] = {0};
    //用v[]存商品的收益率
    for (i = 0; i < N; i++)
        v[i] = p[i] / w[i];
    //根据 v 数组记录的各个商品收益率的大小，同时对 w 和 p 数组进行排序
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (v[i] < v[j]) //如果后比前大，三个数值同时交换位置，从大到小排序
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

//修改if中的条件，使得冒泡排序后为大到小排序
void sortValueandMore(float *value, float *w, float *p, int len)
{
    int flag;
    do
    {
        flag = 0;
        for (size_t i = 0; i < len - 1; i++)
        {
            for (size_t j = 0; j < len - 1 - i; j++)
            {
                if (value[j] < value[j + 1])
                {
                    float temp = value[j];
                    value[j] = value[j + 1];
                    value[j + 1] = temp;
                    temp = w[j];
                    w[j] = w[j + 1];
                    w[j + 1] = temp;
                    temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                    flag = 1;
                }
            }
        }

    } while (flag == 1);
}

/*
贪心算法解决部分背包问题
w：记录各个商品的总重量
p：记录各个商品的总价值
result：记录各个商品装入背包的比例
W：背包的容量
*/
void fractional_knapsack(float *w, float *p, float *result, float W)
{
    float temp = 0; //装入背包的东西
    int i = 0;

    //根据收益大小进行排序
    float value[N] = {0};
    for (size_t i = 0; i < N; i++)
    {
        value[i] = p[i] / w[i]; //计算收益
    }
    int len = sizeof(value) / sizeof(float);
    sortValueandMore(value, w, p, len);
    // Sort(w, p);
    while (W > 0) //当容量大于0
    {
        temp = W > w[i] ? w[i] : W; //还有容量就放w[i] , 否则就按剩余容量放入
        result[i] = temp / w[i];    //比例  容量充足时为1
        W -= temp;                  //减去放入的为当前容量
        i++;
    }
}

int main()
{
    int i;
    //统计背包中商品的总收益
    float values = 0;
    //各个商品的重量
    float w[N] = {10, 30, 20};
    //各个商品的收益
    float p[N] = {60, 100, 120};
    float result[N] = {0};
    fractional_knapsack(w, p, result, 50);

    for (i = 0; i < N; i++)
    {
        if (result[i] == 1)
        {
            printf("总重量为 %f,总价值为 %f 的商品全部装入\n", w[i], p[i]);
            values += p[i];
        }
        else if (result[i] == 0)
            printf("总重量为 %f,总价值为 %f 的商品不装\n", w[i], p[i]);
        else
        {
            printf("总重量为 %f,总价值为 %f 的商品装入 %f%%\n", w[i], p[i], result[i] * 100);
            values += p[i] * result[i];
        }
    }
}