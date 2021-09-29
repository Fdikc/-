# include<stdio.h>
# include<stdlib.h>
#define STACK_INIT_SIZE 100
typedef struct Stack{
	char *base;
	char *top;
	int stacksize;
}SqStack;

//初始化
int InitStack(SqStack *S){
	S->base=(char *)malloc(STACK_INIT_SIZE*sizeof(SqStack));
	if(!S->base){
		printf("存储分配失败");
	}
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return 1;

}

//元素入栈
int Push(SqStack *S, char e)
{
	if(S->top-S->base>=STACK_INIT_SIZE){
	return 0;
	}
	else{
		int n=0;
		printf("请输入入栈个数\n");
		scanf("%d",&n);
		printf("请输入入栈的字符\n");
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
//元素出栈
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
   printf("空栈初始化成功\n");
   }


int b=Push(&S,a);
if(b==1){
   printf("push成功");
  }
printf("\n");
  printf("元素个数");
  int len = StackLength(&S);
  printf("%d", len);
  printf("\n");
  printf("取栈顶");
  GetTop(&S);
  printf("\n");
  printf("出栈");

  Pop(&S);
  

  return 0;
}

