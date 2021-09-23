#include <stdio.h>
int main(int argc, char const *argv[])
{
    int arr[] = {5, 7, 2, 9, 33, 55, 11};
    int len = sizeof(arr) / sizeof(int);
    for (int i = 0; i <len-1;i++){
        for(int j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }

    for ( int i = 0; i < len; i++)
    {
       printf("%d\n",arr[i]);
    }
    

    return 0;
}
