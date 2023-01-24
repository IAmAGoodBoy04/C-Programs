/* The Mobius function M (N) is defined as

M (N) = 1         if N=1

          = 0     if any prime factor is contained in N more than once

          = (-1)   if N is the product of p different prime factors */
#include<stdio.h>
#include<math.h>
int mobius(int n){
	if(n==1){return 1;}
	int sqr,count=1;
	sqr=sqrt(n);
	for(int i=2;i<=sqr;i++){
		for(int j=2;j<i/2;j++){
			if(i%j==0){count++;break;}
		}
		if(count==1){
			if(n%(i*i)==0){return 0;}
		}
		count=1;
	}
	return -1;
	
}
int main(){
	int n,m;
	printf("Enter a number\n");
	scanf("%d",&n);
	m=mobius(n);
	printf("The value of M(%d) is (M(n) is mobius function): %d\n",n,m);
return 0;
}
