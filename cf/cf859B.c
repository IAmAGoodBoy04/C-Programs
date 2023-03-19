#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,n,sumeven,sumodd;
    scanf("%d",&t);
    while(t--){
        sumeven=0;
        sumodd=0;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                sumeven=sumeven+arr[i];
            }
            else{
                sumodd=sumodd+arr[i];
            }
        }
        if(sumeven>sumodd){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

return 0;
}