#include <stdio.h>
#include <stdlib.h>

#define Size 5

typedef struct Table
{
    int *head;  //声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length; //记录当前顺序表的长度
    int size;   //记录顺序表分配的存储容量
} table;

// 建立顺序表需要做如下工作
// 给 head 动态数据申请足够大小的物理空间；
// 给 size 和 length 赋初值

table initTable()
{
    table t;                                    //结构体变量t
    t.head = (int *)malloc(Size * sizeof(int)); //构造一个空的顺序表，动态申请存储空间
    if (!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;  //空表的长度初始化为0
    t.size = Size; //空表的初始存储空间为Size
    return t;
}

void display(table t)
{
    for (size_t i = 0; i < t.length; i++)
    {
        printf("%d ", t.head[i]);
    }
    printf("\n");
}

//插入函数，其中，elem为插入的元素，add为插入到顺序表的位置,此处add为人直观的add从1开始
table addTable(table t, int elem, int add)
{
    //判断插入本身是否存在问题（如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作为提示并自动退出）
    if (add > t.length + 1 || add < 1)
    {
        printf("插入位置有问题\n");
        return t;
    }
    //做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
    if (t.length == t.size)
    {
        t.head = (int *)realloc(t.head, (t.size + 1) * sizeof(int)); //分配多一个int 5*int --> 6*int
    }
    if (!t.head)
    {
        printf("存储分配失败\n");
        return t;
    }
    t.size += 1;

    //插入操作，需要将从插入位置开始的后续元素，逐个后移
    for (size_t i = t.length - 1; i >= add - 1; i--)
    {
        t.head[i + 1] = t.head[i];
    }
    //后移完成后，直接将所需插入元素，添加到顺序表的相应位置
    t.head[add - 1] = elem;
    t.length++;
    return t;
}

//删除函数
table delTable(table t, int add)
{
    if (add > t.length || add < 1)
    {
        printf("被删除元素的位置有误\n");
        return t;
    }

    for (size_t i = add - 1; i < t.length - 1; i++)
    {
        t.head[i] = t.head[i + 1];
    }
    t.length--;
    return t;
}

//查找函数，其中，elem表示要查找的数据元素的值
int findTable(table t, int elem)
{
    for (size_t i = 0; i < t.length; i++)
    {
        if (elem == t.head[i])
        {
            return i + 1;
        }
    }
    return -1;
}

//更改函数，其中，elem为要更改的元素，newElem为新的数据元素
table changeTable(table t, int elem, int newElem)
{
    int add = findTable(t, elem);
    t.head[add - 1] = newElem; //由于返回的是元素在顺序表中的位置，所以-1就是该元素在数组中的下标
    return t;
}

int main()
{
    table t1 = initTable();
    for (int i = 1; i <= Size; i++)
    {
        t1.head[i - 1] = i;
        t1.length++;
    }
    printf("原顺序表:\n");
    display(t1);

    printf("删除元素1:\n");
    t1 = delTable(t1, 1);
    display(t1);

    printf("在第2的位置插入元素5:\n");
    t1 = addTable(t1, 5, 2);
    display(t1);

    printf("查找元素3的位置:\n");
    int add = findTable(t1, 3);
    printf("%d\n", add);

    printf("将元素3改为6:\n");
    t1 = changeTable(t1, 3, 6);
    display(t1);
    return 0;
}
