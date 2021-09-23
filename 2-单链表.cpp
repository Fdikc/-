#include <stdio.h>
#include <stdlib.h>

//�ṹ��
typedef struct Node
{
    int data;
    struct Node *next;
} LNode;
//1 ��ʼ������
void initFun(LNode *head, LNode *p, LNode *q, int geshu)
{
    p=head;
    printf("����%d���ַ�", geshu);
    for (int i = 0; i < geshu; i++)
    {
        char value;
        q = (LNode *)malloc(sizeof(LNode));
        scanf(" %c",&value);
        q->data = value;
        p->next = q;
        p = q;
    }
    p->next = NULL;
}
//2 ��������ֵ
void showFun(LNode *head, LNode *p)
{
    p = head->next;
    while (p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}
//3 ��λ��ɾ��
void delFun(LNode *head, LNode *p, LNode *q,int weizhi)
{
    p = head;
    for (int i = 0; i < weizhi - 1; i++)
    {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}



//4 ����
void addFun(LNode *head, LNode *p, LNode *q ,int weizhi, char zifu)
{
    //����ռ�
    q = (LNode *)malloc(sizeof(LNode));
    q->data = zifu;
    p = head;
    for (int i = 0; i < weizhi - 1; i++)
    {
        p = p->next;
    }
    q->next = p->next;
    p->next = q;
}
//5 ����
int serchFun(LNode *head, LNode *p, char zifu)
{
    int cot=0;
    p=head->next;
    while (p != NULL)
    {
        if(p->data==zifu){
            return cot+1;
        }
        p = p->next;
        cot+=1;
    }
	return 0;
}

//6 ������ɾ��
void delFun1(LNode *head, LNode *p, LNode *q,char zifu){
	int weizhi=serchFun(head, p, zifu);
      delFun(head, p, q,weizhi);
}

int main(int argc, char const *argv[])
{
    LNode *head,*p, *q;
    int weizhi,geshu;
    char zifu;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    //printf("����һ������\n");
    printf("�������\n");
    scanf(" %d", &geshu);
	p=NULL;
	q=NULL;
    initFun(head,p,q,geshu);//��ʼ���ַ�
    showFun(head,p);//չʾ
//����
    printf("��ѡ�����λ��");
    scanf("%d", &weizhi);
    printf("����Ҫ������ַ�");
    scanf(" %c", &zifu);
    addFun(head,p,q,weizhi,zifu);
    showFun(head,p);
//��λ��ɾ��
    printf("��ѡ��ɾ��λ��");
    scanf("%d", &weizhi);
    delFun(head,p,q,weizhi);
    showFun(head,p);
//����
    printf("�����ַ������ز���λ��");   
    scanf(" %c",&zifu);
    int t=serchFun(head,p,zifu);
	printf("%d",t);
//  ��ֵɾ��
	printf("\n");
	printf("������Ҫɾ�����ַ�\n");
	scanf(" %c",&zifu);
	delFun1(head, p, q,zifu);
	showFun(head,p);
    return 0;
}
