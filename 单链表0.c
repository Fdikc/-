#include<stdio.h>
#include<stdlib.h>

//�ṹ��
typedef struct Node{
    int data;
    struct Node *next;
}LNode;


int main(int argc, char const *argv[])
{
//��ʼ������
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
//����
p=head->next;
while (p!=NULL)
{
    printf("%c",p->data);
    p=p->next;
}
printf("\n");

//����
int weizhi;
char zifu;
printf("��ѡ�����λ��");
scanf("%d",&weizhi);
printf("����Ҫ������ַ�");
scanf(" %c",&zifu);


//����ռ�
q = (LNode *)malloc(sizeof(LNode));
q->data=zifu;
p=head;
for (int i = 0; i <weizhi-1; i++)
{
    p=p->next;
}

q->next=p->next;
p->next=q;
//��������
a = head->next;
while (a != NULL)
{
    printf("%c", a->data);
    a= a->next;
}
printf("\n");

//ɾ��
printf("��ѡ��ɾ��λ��");
scanf("%d", &weizhi);
p=head;
for (int i = 0; i < weizhi-1; i++)
{
    p=p->next;
}
q=p->next;
p->next=q->next;
free(q);
//����
//a->next = NULL;
a = head->next;
while (a != NULL)
{
    printf("%c", a->data);
    a = a->next;
}
return 0;
}
