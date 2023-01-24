#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *arr;
    arr=(int *)calloc(10,sizeof(int));
    for(int i=0;i<10;i++){
        arr[i]=n*(i+1);
        printf("%d\n",arr[i]);
    }
    arr=(int *)realloc(arr,15*sizeof(int));
    for(int i=10;i<15;i++){
        arr[i]=n*(i+1);
        printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}