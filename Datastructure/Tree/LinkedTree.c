#include <stdio.h>
#include <stdlib.h>
#define TreeElemType int

// typedef struct BinaryTreeNode *BinaryTree;
// typedef BinaryTree Tree;

typedef struct BinaryTreeNode
{
    TreeElemType data;
    struct BinaryTreeNode *lchild, *rchild;
    struct BinaryTreeNode *parent;
} BTnode, *BinaryTree;

void CreateBinaryTree(BinaryTree *T)
{
    *T = (BTnode *)malloc(sizeof(BTnode));
    (*T)->data = 1;
    (*T)->lchild = (BTnode *)malloc(sizeof(BTnode));
    (*T)->lchild->data = 2;
    (*T)->rchild = (BTnode *)malloc(sizeof(BTnode));
    (*T)->rchild->data = 3;

    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild = NULL;

    (*T)->lchild->lchild = (BTnode *)malloc(sizeof(BTnode));
    (*T)->lchild->lchild->data = 4;

    (*T)->lchild->rchild = NULL;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}
int main()
{
    BinaryTree Tree;
    CreateBinaryTree(&Tree);
    printf("%d", Tree->lchild->lchild->data);
    return 0;
}