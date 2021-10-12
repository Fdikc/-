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
    printf("-----1. 元素入队-----\n");
    printf("-----2. 获取队头-----\n");
    printf("-----3. 元素出队-----\n");
    printf("-----4. 队列长度-----\n");
    printf("-----5. 打印队元素-----\n");
    printf("-----6. 退出菜单-----\n");
}
int main(int argc, char const *argv[])
{

    menue();
    int i;
  
    char e;
    LinkQueue Q;
    InitQueue(Q);
    //printf("初始化成功\n");
    //
    while (true)
    {
        int sel;
        printf("输入你的选择");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            printf("输入入队元素");
            scanf(" %c", &e);
            EnQueue(Q, e);
            printf("入队成功");
            printf("\n");
            break;
        case 2:
            printf("队头为");
            GetHead(Q, e);
            printf("%c",e);
            printf("\n");
            break;
        case 3:
            printf("出队元素");
            DeQueue(Q, e);
            printf("%c", e);
            printf("\n");
            break;
       case 4:
           printf("队列长度");
           i = QueueLength(Q);
           printf("%d", i);
           printf("\n");
           break;
       case 5:
            printf("当前队里元素");
           PrintFun(Q);
           printf("\n");
           break;
       case 6:
           exit(0);
           break;
       default:
           printf("输入有误，重新输入");
           break;
       }
    }
}
