#include<stdio.h>
int fib(int a);
int main(){
    int n,v;
    printf("enter position of element in fibonacci series\n");
    scanf("%d", &n);
    v=fib(n);
    printf("the number at %dth position in fibonacci series is %d",n,v);
    return 0;
}
int fib(int a){
    static int f=0;
    if(a>2){
        return f=fib(a-2)+fib(a-1);
    }
    else if(a==2){
        return 1;
    }
    else{
        return 0;
    }
}