#include<stdio.h>


 main(){
int a[10];
int geshu,weizhi,shuju;

printf("请输入个数：\n");
scanf("%d",&geshu);

printf("请输入%d个数字",geshu);
for(int i=0;i<geshu;i++){
	scanf("%d",&a[i]);

}
printf("你输入的数组为");
for(i=0;i<geshu;i++){
	printf("%d",a[i]);

}
printf("\n");
//增加
printf("请输入你要插入的位置：\n");
scanf("%d",&weizhi);
printf("请输入你要插入的数字：\n");
scanf("%d",&shuju);

if(weizhi<geshu){
	for(int k=geshu;k>=weizhi;k--){
		a[k]=a[k-1];
		a[k-1]=shuju;
	}


}
else{
printf("插入有误");
}


printf("你输入的数组为");
for( i=0;i<geshu+1;i++){
	printf("%d",a[i]);
}
//删除数据
printf("\n");
printf("请输入你要删除的位置：");


scanf("%d", &weizhi);
if(weizhi<=geshu){
	for(int k=weizhi;k<=geshu;k++){
		a[k-1]=a[k];
	
	}

}


printf("你输入的数组为");
for( i=0;i<geshu;i++){
	printf("%d",a[i]);
}
printf("\n");



// 删除指定具体元素
int b;
printf("请输入你要删除的具体元素：\n");
scanf("%d",&b);
for( i=0;i<geshu;i++){
	if(b==a[i]){
		for(int k=i+1;k<geshu;k++){
			a[k-1]=a[k];
		}
	}
}

printf("你输入的数组为");
for( i=0;i<geshu-1;i++){
	printf("%d",a[i]);
}
printf("\n");



// 定位

printf("请输入一个元素以便定位\n");
int c;
int d=0;
scanf("%d",&c);
for(i=0;i<geshu-1;i++){
	if(c==a[i]){
		printf("定位为第%d个",i+1);
		d=d+1;
	}

}
if(d<1){
printf("元素不在数组中");
}

return 0;
}