//Write a program to convert a decimal number to binary or convert a binary number to decimal

#include<stdio.h>

int main(){
	int n,bits=1,temp;
	printf("enter a non negative number\n");
	scanf("%d",&n);
	temp=n;
	while(!(temp<2)){
	temp=temp/2;
	bits++;}
	int arr[bits];
	for(int i=0;i<bits;i++){
		if(n%2==0){arr[bits-i-1]=0;}
		else{arr[bits-i-1]=1;}
		n=n/2;
	}
	printf("the binary form of the given number is: ");
	for(int j=0;j<bits;j++){
	printf("%d",arr[j]);
	}
	return 0;
	}
