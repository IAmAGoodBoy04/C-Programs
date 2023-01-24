//Write a recursive function which returns the nth term of the fibonacci series.
//Call it from main() to find the 1st n numbers of the fibonacci series. 
#include<stdio.h>
int fib(int n){
	if(n==1){return 0;}
	if(n==2){return 1;}
	return fib(n-1)+fib(n-2);
}
int main(){
	int n;
	printf("Enter a number\n");
	scanf("%d",&n);
	printf("The first %d terms of Fibonacci series are as follows:\n",n);
	for(int i=1;i<=n;i++){
		printf("%d  ",fib(i));
		if(i>1){
		if(i%10==0){printf("\n");}
		}
		}
		printf("\n");
    return 0;
}
