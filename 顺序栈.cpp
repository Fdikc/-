# include<stdio.h>
# include<stdlib.h>
#define STACK_INIT_SIZE 100
typedef struct Stack{
	char *base;
	char *top;
	int stacksize;
}SqStack;

//��ʼ��
int InitStack(SqStack *S){
	S->base=(char *)malloc(STACK_INIT_SIZE*sizeof(SqStack));
	if(!S->base){
		printf("�洢����ʧ��");
	}
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return 1;

}

//Ԫ����ջ
int Push(SqStack *S, char e)
{
	if(S->top-S->base>=STACK_INIT_SIZE){
	return 0;
	}
	else{
		int n=0;
		printf("��������ջ����\n");
		scanf("%d",&n);
		printf("��������ջ���ַ�\n");
		for(int i=0;i<n;i++){
			scanf(" %c",&e);
			*S->top++=e;
		}
	  return 1;
	}
	
}

//GetTop
int GetTop(SqStack *S){
	char e;
	if(S->top==S->base) return 0;
	e=*(S->top-1);
	printf("%c",e);
	return 1;

}
//Ԫ�س�ջ
void Pop(SqStack *S){

	while (S->top != S->base)
	{
		char e;
		e = *--S->top;
		printf("%c", e);
	}
	
	
}

int StackLength(SqStack *S){	
	int a=S->top-S->base;
	return a;
}

int main(){
  SqStack S;
  int a=InitStack(&S);
  if(a==1){
   printf("��ջ��ʼ���ɹ�\n");
   }


int b=Push(&S,a);
if(b==1){
   printf("push�ɹ�");
  }
printf("\n");
  printf("Ԫ�ظ���");
  int len = StackLength(&S);
  printf("%d", len);
  printf("\n");
  printf("ȡջ��");
  GetTop(&S);
  printf("\n");
  printf("��ջ");

  Pop(&S);
  

  return 0;
}

