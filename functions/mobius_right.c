/* The Mobius function M (N) is defined as

M (N) = 1         if N=1

          = 0     if any prime factor is contained in N more than once

          = (-1)   if N is the product of p different prime factors */
#include<stdio.h>
int mobius(int n){
	int count=1,product=1;
	if(n==1){return 1;}
	for(int i=2;i<=n;i++){
		if(n%i==0){
			for(int j=2;j<i/2;j++){
				if(i%j==0){count++;break;}
			}
			if(count==1){product=product*i;}
		}
		count=1;
	}
	if(product==n){return -1;}
	return 0;
}
int main(){
	int n,m;
	printf("Enter a number\n");
	scanf("%d",&n);
	m=mobius(n);
	printf("The value of M(%d) is (M(n) is mobius function): %d\n",n,m);
return 0;
}
