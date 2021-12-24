#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    char elem;
    struct LinkedList *next;
    // 提示，由于指针域中的指针要指向的也是一个节点，因此要声明为 Link 类型（这里要写成 struct Link* 的形式）。
} link;

link *initLink_with_headpoint()
{
    link *p = (link *)malloc(sizeof(link)); //创建一个头结点
    link *temp = p;                         //声明一个指针指向头结点
    //生成链表
    for (int i = 1; i < 5; i++)
    {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

void displayYes(link *p)
{
    link *temp = p;    //将temp指针重新指向头结点
    while (temp->next) // temp指向头结点，因为头结点为空
    {
        temp = temp->next;
        printf("%d ", temp->elem);
    }
    printf("\n");
}

// p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link *insertLink(link *p, int elem, int add)
{
    link *temp = p;
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
    }
    //创建插入结点c
    link *c = (link *)malloc(sizeof(link));
    c->elem = elem;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return p;
}

// p为原链表，add表示新元素要删除的位置
link *delLink(link *p, int add)
{
    link *temp = p;
    for (size_t i = 1; i < add; i++)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            printf("没有该结点\n");
            return p;
        }
    }
    link *del = temp->next;        //单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    free(del);                     //手动释放该结点，防止内存泄漏
    return p;
}

// p为原链表，elem表示被查找元素、
int findElem(link *p, int elem)
{
    //新建一个指针t，初始化为头指针 p
    link *temp = p;
    int i = 1;
    //由于头节点的存在，因此while中的判断为t->next
    while (temp->next)
    {
        temp = temp->next;
        if (temp->elem == elem)
        {
            return i;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return -1;
}

link *changeElem(link *p, int add, int newElem)
{
    link *temp = p;
    temp = temp->next; //在遍历之前，temp指向首元结点
    //遍历到待更新结点
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

link *anotherchangeElem(link *p, int add, int newElem)
{
    link *temp = p;
    //遍历到待更新结点
    for (int i = 1; i <= add; i++)
    {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

int main()
{
    //初始化链表（1，2，3，4）
    printf("初始化链表为：\n");
    link *p = initLink_with_headpoint();
    displayYes(p);

    printf("在第4的位置插入元素5：\n");
    p = insertLink(p, 5, 4);
    displayYes(p);

    printf("删除元素3:\n");
    p = delLink(p, 3);
    displayYes(p);

    printf("查找元素2的位置为：\n");
    int address = findElem(p, 2);
    if (address == -1)
    {
        printf("没有该元素");
    }
    else
    {
        printf("元素2的位置为：%d\n", address);
    }

    printf("更改第3的位置上的数据为7:\n");
    p = changeElem(p, 3, 7);
    displayYes(p);

    printf("更改第3的位置上的数据为77:\n");
    p = changeElem(p, 3, 77);
    displayYes(p);
    return 0;
}