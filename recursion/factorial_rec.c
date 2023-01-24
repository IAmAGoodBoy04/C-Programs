//Write a recursive function to find the factorial of a number and test it.
#include<stdio.h>

long long factorial(int n){
    if(n==0){return 1;}
    if(n==1){return 1;}
    return n*factorial(n-1);
}
int main(){
    int n;
    long long fac;
    printf("enter a non negative number\n");
    scanf("%d",&n);
    if(n<0){printf("invalid input\n");}
    fac=factorial(n);
    printf("The factorial of %d is %lld\n",n,fac);
    return 0;
}
