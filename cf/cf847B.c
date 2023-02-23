#include<stdio.h>
#include<stdlib.h>
int main(){
    int t,n,s,r,rem,div,max,k,temp;
    scanf("%d",&t);
    int *arr;
    arr=(int *)malloc(sizeof(int));
    while(t--){
        k=1;
        scanf("%d %d %d",&n,&s,&r);
        arr=(int *)realloc(arr,n*sizeof(int));
        arr[0]=s-r;
        max=s-r;
        rem=r%(n-1);
        div=r/(n-1);
        for(int i=1;i<n;i++){
            arr[i]=div;
        }
        while(rem>0){
            if(max-arr[k]>=rem){
                arr[k]=arr[k]+rem;
                break;
            }
            if(max-arr[k]<rem){
            temp=arr[k];
            arr[k]=arr[k]+(max-arr[k]);
            rem=rem-(max-temp);
            }
            k++;
        }
        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
    return 0;
}