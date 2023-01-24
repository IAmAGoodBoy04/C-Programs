#include<stdio.h>

int main(){
    long long int t;
    long long int result,min,max,maxjokes;
    scanf("%lld",&t);
    long long int arr[4];
    while(t--){
        maxjokes=0;
        for(int i=0;i<4;i++){
            scanf("%lld",&arr[i]);
            maxjokes=maxjokes+arr[i];
        }
        min=arr[1]<=arr[2]?arr[1]:arr[2];
        result=arr[0]+2*min;
        if((result+arr[0]+1)<maxjokes){
            result=result+arr[0]+1;
        }
        else{
            result=maxjokes;
        }
        if(arr[0]==0){
            result=1;
        }
        
        printf("%lld\n",result);
    }
    return 0;
}