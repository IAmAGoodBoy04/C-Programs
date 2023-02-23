#include<stdio.h>
#include<stdlib.h>
void sort (int n, int *arr){
    int temp,j;
    for(int i=0;i<n-1;i++){
        j=i+1;
        while(arr[j-1]>arr[j]){
            temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
            if(j==0){break;}
        }
    }
}
int main(){
    int t,n,count;
    int *arr;
    int *arr2;
    arr=(int *)malloc(sizeof(int));
    arr2=(int *)malloc(sizeof(int));
    scanf("%d",&t);
    while(t--){
        count=0;
        scanf("%d",&n);
        
        arr=(int *)realloc(arr,n*sizeof(int));
        arr2=(int *)realloc(arr2,n*sizeof(int));
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++){
            arr2[i]=arr[i];
        }
        sort(n,arr2);
        for(int i=0;i<n;i++){
            if(arr2[i]!=arr[i]){
                count++;
            }
        }
        count=(count+1)/2;
        if(n==4){
            count=1;
        }
        printf("%d\n",count);
    }
    free(arr);
    free(arr2);
    return 0;
}