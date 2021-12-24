#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    char elem;
    struct LinkedList *next;
    // 提示，由于指针域中的指针要指向的也是一个节点，因此要声明为 Link 类型（这里要写成 struct Link* 的形式）。
} link;

//返回头指针，它的特点是永远指向链表第一个节点的位置。
link *initLink_without_headpoint()
{
    link *p = NULL;                            //创建头指针
    link *temp = (link *)malloc(sizeof(link)); //创建首元节点

    temp->elem = 1;
    temp->next = NULL;

    p = temp; //头指针指向首元节点

    //从第二个节点开始创建
    for (int i = 2; i < 5; i++)
    {
        //创建一个新节点并初始化
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;
        //指针temp每次都指向新链表的最后一个节点，其实就是 a节点，这里写temp=a也对
        temp = temp->next;
    }

    return p;
}

void displayNO(link *p)
{
    link *temp = p;
    while (temp)
    {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}

int main()
{
    link *p = initLink_without_headpoint();
    displayNO(p);
}