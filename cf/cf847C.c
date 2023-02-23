#include<stdio.h>
int main(){
    int t,n,sameterm,k,diffarray;
    scanf("%d",&t);
    while(t--){
        k=0;
        scanf("%d",&n);
        int arr[n][n-1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        if(arr[0][0]==arr[0][1]){
            sameterm=arr[0][0];
        }
        else if(arr[1][0]==arr[2][0]){
            sameterm=arr[1][0];
        }
        else{sameterm=arr[0][0];}
        while(k<n){
            if(arr[k][0]!=sameterm){
                diffarray=k;
            }
            k++;
        }
        printf("%d ",sameterm);
        for(int x=0;x<n-1;x++){
            printf("%d ",arr[diffarray][x]);
        }
        printf("\n");
    }
    return 0;
}