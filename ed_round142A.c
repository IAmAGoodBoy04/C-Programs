#include<stdio.h>
#include<stdlib.h>
int main(){
    int t,n;
    int *arr;
    arr=(int*)malloc(sizeof(int));
    scanf("%d",&t);
    while(t--){
        int count=0;
        scanf("%d",&n);
        arr=(int *)realloc(arr,n*sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            if(arr[i]==1){count++;}
        }
        printf("%d\n",n-(count/2));
    }
    return 0;
}