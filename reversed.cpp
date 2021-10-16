#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define M 100
typedef struct 
{
    int *base;
    int *top;
    int stacksize;
}SqStack;
typedef struct Queue
{
    int *base;
    int front;
    int rear;
} SqQueue;

//��ʼ��ջ
void InitStack(SqStack &S)
{
    S.base = (int *)malloc(STACK_INIT_SIZE* sizeof(int));
    // if (!S.base)
    // {
    //     printf("�洢����ʧ��");
    // }
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}
//Ԫ����ջ
//Ԫ����ջ
void Push(SqStack &S, int x)
{
    if (S.top - S.base >= STACK_INIT_SIZE)
    {
      printf("ջ��");
    }
    else
    {
        *S.top++=x;
    }

}

void Pop(SqStack &S,int &e)
{

    if (S.top != S.base)
    {
       
        e = *--S.top;
    }
}
////////����
//��ʼ������
int InitQueue(SqQueue &Q)
{

    Q.base = (int *)malloc(M * sizeof(SqQueue));
    Q.front = Q.rear = 0;
    return 1;
}
//��
int EnQueue(SqQueue &Q, int e)
{
    if ((Q.rear + 1) % M == Q.front)
    {
        return 0;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % M;
    return 0;
}
//��
void DeQueue(SqQueue &Q, int &e)
{
    if (Q.rear == Q.front)
    {
        printf("��");
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % M;
    
}

int main(int argc, char const *argv[])
{

    SqStack S;
    SqQueue Q;
    InitStack(S);
    InitQueue(Q);
    
    int a,e;
    int i=0;
    //printf("�������");
    scanf("%d",&a);
   // printf("����eԪ��");
    while (i<a)
    {
        scanf("%d",&e);
        EnQueue(Q, e);
        //
        ++i;
    }
    while (Q.front!=Q.rear)
    {
        DeQueue(Q, e);
       // printf("%d", e);
        Push(S, e);
    }
    
    //{
       
       
    // }
     while ( S.base!=S.top)
     {
         Pop(S,e);
         EnQueue(Q, e);
        
     }
    //     
    // }
   while (Q.front != Q.rear){
     DeQueue(Q, e);
     printf("%d ", e);
    }
    return 0;
}
