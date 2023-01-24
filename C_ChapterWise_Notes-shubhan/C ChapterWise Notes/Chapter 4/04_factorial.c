#include<stdio.h>
int main(){
    int n,i=0;
    long long int f=0;
    printf("enter number for factorial\n");
    scanf("%d",&n);
    f=n;
    for(i=n-1;i>0;i--){
        f=f*i;

    }
    printf("\nfactorial of the given number is %lld",f);
    return 0;
}