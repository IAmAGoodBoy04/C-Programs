/* Given a number n, print following a pattern without using any loop.

Example:

Input: n = 16

Output: 16, 11, 6, 1, -4, 1, 6, 11, 16

Input: n = 10

Output: 10, 5, 0, 5, 10*/

#include<stdio.h>
void pattern(int n){
	if(n>0){pattern(n-5);}
	printf("%d  ",n);
	
}
void patternrev(int n){
	printf("%d  ",n);
	if(n>5){patternrev(n-5);}	
}


int main(){
	int n;
	printf("Enter a number\n");
	scanf("%d",&n);
	patternrev(n);
	pattern(n);
	
	return 0;
}
