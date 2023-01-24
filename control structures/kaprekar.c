/* Write a program to find out whether a number is kaprekar or not. Consider an n-digit number k. Square it and add the right n digits to the left n or n-1 digits. If the resultant sum is k, then k is called a Kaprekar number. For example, 9 is a Kaprekar number since

9^2=81 and  8+1=9

and 297 is a Kaprekar number since

297^2=88209 and 88+209=297
The first few are 1, 9, 45, 55, 99, 297, and 703. */
#include<stdio.h>
#include<math.h>
int main(){
	int n,digits=0,sq,temp,left,l,r,kap;
	printf("Enter a positive number\n");
	scanf("%d",&n);
	if(n<=0){
		printf("invalid input");
		return 0;
	}
	sq=n*n;
	temp=sq;
	while(1){
		if(temp!=0){digits++;}
		else{break;}
		temp=temp/10;
	}
	left=digits/2;
	temp=sq;
	temp=sq/pow(10,digits-left);
	l=temp;
	temp=temp*pow(10,digits-left);
	r=sq-temp;
	kap=r+l;
	if(kap==n){
	printf("%d is a Kaprekar number",n);}
	else{printf("%d is not a Kaprekar number",n);}
	
return 0;
}

