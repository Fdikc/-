# include<stdio.h>
# include<stdlib.h>
# define M 10
typedef struct Queue
{
    char *base;
    int front;
    int rear;
}SqQueue;
//初始化
int InitQueue(SqQueue &Q){

    Q.base = (char *)malloc(M * sizeof(SqQueue));
    Q.front=Q.rear=0;
    return 1;
}

//判空
bool QueueEmpty(SqQueue &Q){
	if (Q.rear==Q.front)
    {
        return true;
    }
	else{
		return false;
	}

}
//入
int EnQueue(SqQueue &Q,char e){
    if ((Q.rear + 1) % M == Q.front)
    {
        return 0;
    }

    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%M;
    return 0;
}
//出队
int DeQueue(SqQueue &Q, char &e)
{

    if (QueueEmpty(Q))
    {
		printf("为空");
        return 0;
    }
	else{
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%M;
    return 1;
    }
}
//长度
int QueueLength(SqQueue &Q){
    if(Q.rear>=Q.front){
		int a=Q.rear-Q.front;
		printf("队列的长度");
		return a;
	}
	else{
		int a=M-(Q.front-Q.rear);
		printf("队列的长度");
		return a;
	}
}
//队列头
int GetHead(SqQueue &Q,char &e){
	 if (QueueEmpty(Q))
    {
	    printf("为空");
        return 0;
    }

     e=Q.base[Q.front];
	return 1;

}


void menue(){

printf("-----1. 元素入队-----\n");
printf("-----2. 获取队头-----\n");
printf("-----3. 元素出队-----\n");
printf("-----4. 队列长度-----\n");
printf("-----5. 退出菜单-----\n");

}



 void main(int argc, char const *argv[])
{

menue();
    int n,a,j,i,b;
    char e;
    SqQueue Q;
    InitQueue(Q);

while(true){
	int sel;
printf("输入您的选择\n");
scanf("%d",&sel);
	switch(sel){
	case 1:
    printf("输入入队元素个数\n");
    scanf("%d",&n);
    printf("输入字符");
    for ( i = 0; i < n; i++)
    {
        scanf(" %c",&e);
        EnQueue(Q,e);
    }
	printf("\n");
     break;

	case 2:

	printf("队列头元素");
    GetHead(Q,e);
    printf("%c",e);
	printf("\n");
	printf("\n");
	break;

	case 3:


		  printf("输入出队元素个数\n");
    scanf("%d", &n);
	printf("出队的元素为：");
	 a= QueueLength(Q);
	if(a<n){
	  n=a;
	}
    for ( j = 0; j < n; j++)
    {
        DeQueue(Q,e);
        printf("%c",e);
    }
	printf("\n");
	break;
	case 4:
		 b =QueueLength(Q);
	 printf("%d",b);
	 printf("\n");
	 break;
	case 5:
			exit(0);

	default:
		printf("输入有误，重新输入");
		break;
	
	
	
	
	
	
	
	}

   
   
}}