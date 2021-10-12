#include<stdio.h>
#include<stdlib.h>

typedef struct QNode
{
    char data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct Queue
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    Q.front->next=NULL;
}
int QueueEmpty(LinkQueue &Q) {
    if (Q.front==Q.rear)
    {
        return 1;
    }else{
        return 0;
    }
}
int QueueLength(LinkQueue &Q) {

    QNode *p = Q.front->next;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
    
}
void GetHead(LinkQueue &Q,char &e) {
    if (!QueueEmpty(Q))
    {
       e = Q.front->next->data;
    }
}
void EnQueue(LinkQueue &Q, char e) {
    QNode *q;
    q = (QueuePtr)malloc(sizeof(QNode));
    q->data=e;
    q->next=NULL;
    Q.rear->next=q;
    Q.rear=q;
}
void DeQueue(LinkQueue &Q, char &e) {
    QNode *q;
    q=Q.front->next;
    e=q->data;
    Q.front->next=q->next;
    if (q==Q.rear)
    {
        Q.rear=Q.front;
    }
    
    free(q);
}
void PrintFun(LinkQueue &Q){
    QueuePtr p;
    p=Q.front->next;
    while (p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    
}

void menue()
{
    printf("-----1. Ԫ�����-----\n");
    printf("-----2. ��ȡ��ͷ-----\n");
    printf("-----3. Ԫ�س���-----\n");
    printf("-----4. ���г���-----\n");
    printf("-----5. ��ӡ��Ԫ��-----\n");
    printf("-----6. �˳��˵�-----\n");
}
int main(int argc, char const *argv[])
{

    menue();
    int i;
  
    char e;
    LinkQueue Q;
    InitQueue(Q);
    //printf("��ʼ���ɹ�\n");
    //
    while (true)
    {
        int sel;
        printf("�������ѡ��");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            printf("�������Ԫ��");
            scanf(" %c", &e);
            EnQueue(Q, e);
            printf("��ӳɹ�");
            printf("\n");
            break;
        case 2:
            printf("��ͷΪ");
            GetHead(Q, e);
            printf("%c",e);
            printf("\n");
            break;
        case 3:
            printf("����Ԫ��");
            DeQueue(Q, e);
            printf("%c", e);
            printf("\n");
            break;
       case 4:
           printf("���г���");
           i = QueueLength(Q);
           printf("%d", i);
           printf("\n");
           break;
       case 5:
            printf("��ǰ����Ԫ��");
           PrintFun(Q);
           printf("\n");
           break;
       case 6:
           exit(0);
           break;
       default:
           printf("����������������");
           break;
       }
    }
}
