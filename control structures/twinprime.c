/*Twin primes are consecutive odd numbers, both of which are prime numbers. Write a program which inputs two positive integers A and B and outputs all twin primes in range A to B.     A   = 51     B=97            51 53   ,   53 55 ,        ….. 95..97

 A twin prime are those numbers which are prime and having a difference of two ( 2 ) between the two prime numbers. In other words, a twin prime is a prime that has a prime gap of two. */

#include<stdio.h>

int main(){
	int a,b,j,x,i;
	printf("Enter the range\n");
	scanf("%d %d",&a,&b);
	if(a<0 && b<=0){
		printf("invalid input");
		return 0;
	}
	printf("All pairs of twin primes in this range are: ");
	if(a<=2){
		a=3;
	}
	if(a>2){
	for(i=a;i<=b-2;i++){
		int count=2;
		for(j=2;j<i/2;j++){
			if(i%j==0){count++;break;}
			}
		for(x=2;x<(i/2+1);x++){
			if((i+2)%x==0){count++;break;}
		}
		if(count==2){printf("[%d,%d]\n",i,i+2);};
	}
	}
return 0;
}
