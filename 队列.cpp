# include<stdio.h>
# include<stdlib.h>
# define M 10
typedef struct Queue
{
    char *base;
    int front;
    int rear;
}SqQueue;
//��ʼ��
int InitQueue(SqQueue &Q){

    Q.base = (char *)malloc(M * sizeof(SqQueue));
    Q.front=Q.rear=0;
    return 1;
}

//�п�
bool QueueEmpty(SqQueue &Q){
	if (Q.rear==Q.front)
    {
        return true;
    }
	else{
		return false;
	}

}
//��
int EnQueue(SqQueue &Q,char e){
    if ((Q.rear + 1) % M == Q.front)
    {
        return 0;
    }

    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%M;
    return 0;
}
//����
int DeQueue(SqQueue &Q, char &e)
{

    if (QueueEmpty(Q))
    {
		printf("Ϊ��");
        return 0;
    }
	else{
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%M;
    return 1;
    }
}
//����
int QueueLength(SqQueue &Q){
    if(Q.rear>=Q.front){
		int a=Q.rear-Q.front;
		printf("���еĳ���");
		return a;
	}
	else{
		int a=M-(Q.front-Q.rear);
		printf("���еĳ���");
		return a;
	}
}
//����ͷ
int GetHead(SqQueue &Q,char &e){
	 if (QueueEmpty(Q))
    {
	    printf("Ϊ��");
        return 0;
    }

     e=Q.base[Q.front];
	return 1;

}


void menue(){

printf("-----1. Ԫ�����-----\n");
printf("-----2. ��ȡ��ͷ-----\n");
printf("-----3. Ԫ�س���-----\n");
printf("-----4. ���г���-----\n");
printf("-----5. �˳��˵�-----\n");

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
printf("��������ѡ��\n");
scanf("%d",&sel);
	switch(sel){
	case 1:
    printf("�������Ԫ�ظ���\n");
    scanf("%d",&n);
    printf("�����ַ�");
    for ( i = 0; i < n; i++)
    {
        scanf(" %c",&e);
        EnQueue(Q,e);
    }
	printf("\n");
     break;

	case 2:

	printf("����ͷԪ��");
    GetHead(Q,e);
    printf("%c",e);
	printf("\n");
	printf("\n");
	break;

	case 3:


		  printf("�������Ԫ�ظ���\n");
    scanf("%d", &n);
	printf("���ӵ�Ԫ��Ϊ��");
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
		printf("����������������");
		break;
	
	
	
	
	
	
	
	}

   
   
}}