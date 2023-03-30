#include<stdio.h>
#include<stdlib.h>
void sort(int arr[],int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int answer(int diff){
    if(diff==1){
        return -1;
    }
    if(diff==3 || diff==4){
        return 4;
    }
    if(diff==2){
        return 6;
    }
}
int main(){
    int t,diff,ans;
    scanf("%d%*c",&t);
    char str[5];
    int arr[4];
    while(t--){
        diff=1;
        scanf("%s%*c",str);
        for(int i=0;i<4;i++){
            arr[i]=str[i]-'0';
        }
        sort(arr,4);
        for(int i=0;i<3;i++){
            if(arr[i+1]!=arr[i]){
                diff++;
            }
        }
        
        if(diff==2){
            if(arr[1]!=arr[2]){
                diff=3;
            }
        }
        
        ans=answer(diff);
        printf("%d\n",ans);
        
    }

return 0;
}