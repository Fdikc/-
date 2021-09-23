#include <stdio.h>


int main(int argc, char const *argv[])
{
    int geshu,weizhi,shuzi;
    int a[10];
    printf("请输入个数:");
    scanf("%d",&geshu);
    printf("请输入%d个数字:",geshu);

    for (int i = 0; i < geshu; i++)
    {
        scanf("%d",&a[i]);

    }
    printf("你输入的数组为");
    for (int i = 0; i < geshu; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    printf("请选择插入位置");
    scanf("%d",&weizhi);
    printf("请选择插的数字");
    scanf("%d", &shuzi);
    if(weizhi<geshu){
    for (int k = geshu; k>=weizhi ; k--)
    {
        a[k]=a[k-1];
        a[k-1] = shuzi;
    }}
    
    printf("你输入的数组为");
    for (int i = 0; i < geshu+1; i++)
    {
        printf("%d", a[i]);
    }


    printf("删除的位置");
    scanf("%d",&weizhi);

    if (weizhi<=geshu+1)
    {
        for (int k = weizhi; k <geshu+1 ; k++)
        {
            a[k-1]=a[k];
        }
        
    }
    printf("你输入的数组为");
    for (int i = 0; i < geshu ; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
}
