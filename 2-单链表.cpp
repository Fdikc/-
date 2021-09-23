#include <stdio.h>
#include <stdlib.h>

//结构体
typedef struct Node
{
    int data;
    struct Node *next;
} LNode;
//1 初始化链表
void initFun(LNode *head, LNode *p, LNode *q, int geshu)
{
    p=head;
    printf("输入%d个字符", geshu);
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
//2 输出链表的值
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
//3 按位置删除
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



//4 插入
void addFun(LNode *head, LNode *p, LNode *q ,int weizhi, char zifu)
{
    //分配空间
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
//5 查找
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

//6 按数据删除
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
    //printf("创建一个链表\n");
    printf("输入个数\n");
    scanf(" %d", &geshu);
	p=NULL;
	q=NULL;
    initFun(head,p,q,geshu);//初始化字符
    showFun(head,p);//展示
//插入
    printf("请选择插入位置");
    scanf("%d", &weizhi);
    printf("输入要插入的字符");
    scanf(" %c", &zifu);
    addFun(head,p,q,weizhi,zifu);
    showFun(head,p);
//按位置删除
    printf("请选择删除位置");
    scanf("%d", &weizhi);
    delFun(head,p,q,weizhi);
    showFun(head,p);
//查找
    printf("输入字符，返回查找位置");   
    scanf(" %c",&zifu);
    int t=serchFun(head,p,zifu);
	printf("%d",t);
//  按值删除
	printf("\n");
	printf("请输入要删除的字符\n");
	scanf(" %c",&zifu);
	delFun1(head, p, q,zifu);
	showFun(head,p);
    return 0;
}
