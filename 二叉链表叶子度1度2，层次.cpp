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
    if (ch == '-')
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
}//Ҷ�ӽڵ�
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
}//���
//////�ӵĲ���
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
        printf("Ϊ��");
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

//��α���
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
//�����ʾ
void PrintTree(BiTree T,int j=0)
{
    int i;
    if(T) {
        PrintTree(T->lchild, j+1);
        for(i=0; i<j; i++) printf("-");
        printf("%c\n",T->data); 
        PrintTree(T->rchild, j+1);
    }
}
//��1
int Leaf1Tree(BiTree T){
	if(T==NULL){
		return 0;}
	if(T->lchild!=NULL && T->rchild==NULL){
		return 1+Leaf1Tree(T->lchild);
	}
	if(T->lchild==NULL && T->rchild!=NULL){
		return 1+Leaf1Tree(T->rchild);
	}

		return (Leaf1Tree(T->lchild)+Leaf1Tree(T->rchild));	
}

int Leaf2Tree(BiTree T){
	if(T==NULL){
		return 0;}
	if(T->lchild!=NULL && T->rchild!=NULL){
		return 1+Leaf2Tree(T->lchild)+Leaf2Tree(T->rchild);
	}

	 return (Leaf2Tree(T->lchild)+Leaf2Tree(T->rchild));	
}
int main(int argc, char const *argv[])
{

    int cnt=0, a,c=0;
    BiTree T;
    printf("����ֵ���ԣ�-����ʾ��\n"); 
    CreatBiTree(T);
    printf("�������У�");
    PreOrder(T);
    printf("\n");
	printf("�������У�");
    InOrder(T);
    printf("\n");
	printf("�������У�");
    PostOrder(T);
	printf("\n");
    a = Depth(T);
    printf("���������Ϊ��%d", a);
    printf("\n");
    CountLeaf(T, cnt);
    printf("Ҷ�ӽڵ����Ϊ��%d", cnt);
    printf("\n");
	printf("��α������Ϊ��");
    LevelOrder(T);
    printf("\n");
	int b =Leaf1Tree(T);
	printf("��Ϊ1�Ľڵ�:");
	printf("%d",b);
	printf("\n");
	c=Leaf2Tree(T);
	printf("��Ϊ2�ĸ���Ϊ��%d", c);
	printf("\n");
	printf("�������ʾ��\n");
	PrintTree(T);
    return 0;
}
