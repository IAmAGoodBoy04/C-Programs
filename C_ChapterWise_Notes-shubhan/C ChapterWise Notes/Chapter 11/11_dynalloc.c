#include<stdio.h>
#include <stdlib.h>
int main(){
    int *arr;
    arr=(int *)calloc(5,sizeof(int));
    for(int i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    arr=(int *)realloc(arr,10*sizeof(int));
    for(int i=5;i<10;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is:\n");
    for(int j=0;j<10;j++){
        printf("%d ",arr[j]);
    }
    free(arr);

    return 0;
}