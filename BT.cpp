#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void CreatBiTree(BiTree &T){
    char ch;
    scanf(" %c",&ch);
    if (ch=='#')
    {
        T=NULL;
    }
    else{
        T=(BiTNode*)malloc(sizeof(BiTNode));
        T->data=ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    
}

void PreOrder(BiTree T)
{
    if (T)
    {
        printf("%c",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
    
}
void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}

int main(int argc, char const *argv[])
{

    BiTree T;
    printf(" ‰»Î÷µ\n");
    CreatBiTree(T);
    
    PreOrder(T);
    printf("\n");
    InOrder(T);
    printf("\n");
    PostOrder(T);
    return 0;
}
