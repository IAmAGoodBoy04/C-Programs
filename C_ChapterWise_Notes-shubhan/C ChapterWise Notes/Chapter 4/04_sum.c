#include<stdio.h>
int main(){
    int a=1,sum=0,n=10;
    do{
        sum=sum+a;
        a++;
    }while(a<=n);
    printf("sum=%d",sum);
    return 0;
}