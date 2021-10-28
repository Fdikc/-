#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BTree;

void CreatBTree(BTree &T){
	char ch;
	scanf(" %c",&ch);
	if(ch=='-'){
		T=NULL;
	}
	else{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=ch;
		CreatBTree(T->lchild);
		CreatBTree(T->rchild);
	}
}


void PreOrder(BTree T){
	if(T){
	printf("%c",T->data);
	PreOrder(T->lchild);
	PreOrder(T->rchild);
}
}
void InOrder(BTree T){
	if(T){
	InOrder(T->lchild);
	printf("%c",T->data);
	InOrder(T->rchild);
}
}
void PostOrder(BTree T){
	if(T){
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c",T->data);
}
}

void PreOrderRL(BTree T){
	if(T){
	printf("%c",T->data);
	PreOrderRL(T->rchild);
	PreOrderRL(T->lchild);
}
}

void PrintTree(BTree T,int j=0)
{
    int i;
    if(T) {
        PrintTree(T->lchild, j+1);
        for(i=0; i<j; i++) printf("-");
        printf("%c\n",T->data); 
        PrintTree(T->rchild, j+1);
    }
}

void PrintTree1(BTree T,int j=0)
{
    int i;
    if(T) {

		for(i=0; i<j; i++) printf("-");
		printf("%c\n",T->data);
        PrintTree1(T->lchild, j+1);
      
		PrintTree1(T->rchild, j+1);
    }
}

int main(){
	BTree T;
	printf("输入字符（‘-’为空）\n");
	CreatBTree(T);
	printf("先序序列：");
	PreOrder(T);
	printf("\n");
	printf("中序序列：");
	InOrder(T);
	printf("\n");
	printf("后序序列：");
	PostOrder(T);
	printf("\n");
	printf("交换左右子树的先序遍历：");
	PreOrderRL(T);
	printf("\n");
	printf("以中序缩进：\n");
	PrintTree(T);
	printf("以先序缩进：\n");
	PrintTree1(T);
	return 0;
}