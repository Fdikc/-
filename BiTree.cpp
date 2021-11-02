#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct QNode
{
    BiTNode *data;
    struct QNode *next;
} QNode,*QueuePtr;

typedef struct LinkQueue{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

void CreatBiTree(BiTree &T)
{
    char ch;
    scanf(" %c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
}
////
void PreOrder(BiTree T)
{
    if (T)
    {
        printf("%c", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
////
void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%c", T->data);
        InOrder(T->rchild);
    }
}
////
void PostOrder(BiTree T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c", T->data);
    }
}
void CountLeaf(BiTree T, int &cnt)
{
    if (T)
    {
        if (!T->lchild && !T->rchild)
        {
            cnt++;
        }
        CountLeaf(T->lchild, cnt);
        CountLeaf(T->rchild, cnt);
    }
}
///
int Depth(BiTree T)
{
    int depval, decLeft, decRight;
    if (!T)
    {
        depval = 0;
    }
    else
    {
        decLeft = Depth(T->lchild);
        decRight = Depth(T->rchild);
        depval = 1 + (decLeft > decRight ? decLeft : decRight);
    }
    return depval;
}//深度
//////队的操作
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    Q.front->next = NULL;
}
void EnQueue(LinkQueue &Q, BiTree e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}
void DeQueue(LinkQueue &Q, BiTree &e)
{
    
    if (Q.front==Q.rear)
    {
        printf("为空");
    }
    else{
    QNode *q;
    q = Q.front->next;
    e= q->data;
    Q.front->next = q->next;
    if (q == Q.rear)
    {
        Q.rear = Q.front;
    }
    free(q);
}
}


void LevelOrder(BiTree T)
{
    BiTree P;
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,T);
    while (Q.front!=Q.rear)
    {
        DeQueue(Q, P);
        printf("%c",P->data);
        if (P->lchild!=NULL)
        {
           EnQueue(Q,P->lchild);
        }
        if (P->rchild!= NULL)
        {
            EnQueue(Q, P->rchild);
        }
    }

}

int main(int argc, char const *argv[])
{

    int cnt=0, a;
    BiTree T;
    printf("输入值\n");
    CreatBiTree(T);

    // PreOrder(T);
    // printf("\n");
    // InOrder(T);
    // printf("\n");
    // PostOrder(T);
    a = Depth(T);
    printf("%d", a);
    printf("\n");
    CountLeaf(T, cnt);
    printf("%d", cnt);
    printf("\n");
    LevelOrder(T);
    
     return 0;
}
