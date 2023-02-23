#include<stdio.h>

void sort (int arr[], int n){
    int temp,i,j;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(arr[j]>temp && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void min_coins(int n, int *arr, int x){
    static int count=0;
    if(x==0){
        printf("The minimum number of coins required is %d\n",count);
        count=0;
        return;
    }
    count++;
    int i=n-1;
    int next_coin=arr[i];
    while(1){
        if((x-next_coin)>=next_coin || (x-next_coin)==0){break;}
        else{
            i--;
            if(i<0){
                printf("The value cannot be acheived\n");
                return;
            }
            next_coin=arr[i];
        }
    }
    min_coins(n,arr,x-next_coin);
}
int main(){
    int n,x,t,ans;
    printf("Enter number of distinct coins available: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d denominations: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    printf("Enter number of trials: ");
    scanf("%d",&t);
    while(t--){
        printf("Enter a value: ");
        scanf("%d",&x);
        min_coins(n,arr,x);
    }

return 0;
}