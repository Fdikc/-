#include<stdio.h>
#include<stdlib.h>

//结构体
typedef struct Node{
    int data;
    struct Node *next;
}LNode;


int main(int argc, char const *argv[])
{
//初始化数据
LNode *head,*p,*q,*a;
head=p=(LNode*)malloc(sizeof(LNode));
for (int i = 0; i < 4; i++)
{
    q = (LNode *)malloc(sizeof(LNode));
    q->data = 'A'+i;
    p->next = q;
    p = q;
}
p->next=NULL;
//遍历
p=head->next;
while (p!=NULL)
{
    printf("%c",p->data);
    p=p->next;
}
printf("\n");

//插入
int weizhi;
char zifu;
printf("请选择插入位置");
scanf("%d",&weizhi);
printf("输入要插入的字符");
scanf(" %c",&zifu);


//分配空间
q = (LNode *)malloc(sizeof(LNode));
q->data=zifu;
p=head;
for (int i = 0; i <weizhi-1; i++)
{
    p=p->next;
}

q->next=p->next;
p->next=q;
//插入后遍历
a = head->next;
while (a != NULL)
{
    printf("%c", a->data);
    a= a->next;
}
printf("\n");

//删除
printf("请选择删除位置");
scanf("%d", &weizhi);
p=head;
for (int i = 0; i < weizhi-1; i++)
{
    p=p->next;
}
q=p->next;
p->next=q->next;
free(q);
//遍历
//a->next = NULL;
a = head->next;
while (a != NULL)
{
    printf("%c", a->data);
    a = a->next;
}
return 0;
}
