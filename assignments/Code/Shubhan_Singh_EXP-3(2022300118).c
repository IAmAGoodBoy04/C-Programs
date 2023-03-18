//Write a function which takes a range as input. Print all the numbers in the range with ‘*’ in front of prime numbers only.
// #include<stdio.h>
// void primes(int start, int end){
//     int count=1,x,offset,digits=1,y;
//     printf("the numbers in the range %d to %d with the primes starred are:\n",start,end);
//     x=start;
//     y=start;
//     offset=start%10;
//     while(y>=10){
//         y=y/10;
//         digits++;
//     }
//     for(int o=0;o<(offset-1)*(2+digits);o++){
//         printf(" ");
//     }
//     if(start==1){
//         start++;
//         printf("1  ");
//     }
//     for(int i=start; i<=end; i++){
//         for(int j=2;j<i/2;j++){
//             if(i%j==0){count++;break;}
//         }
//         if(count>1){printf("%d  ",i);}
//         else{printf("%d* ",i);}
//         if((i-x+offset)%10==0){printf("\n");}
//         count=1;
//     }
// }
// int main(){
//     int a,b,temp;
//     printf("Enter the range(positive numbers)\n");
//     scanf("%d %d",&a,&b);
//     if(a>b || b<1){printf("invalid input\n");return 0;}
//     if(a<1){a=1;}
//     primes(a,b);
//     return 0;
// }



/* Write a function which takes as parameters two positive integers and returns TRUE if
the numbers are amicable and FALSE otherwise. A pair of numbers is said to be amicable
if the sum of divisors of each of the numbers (excluding the no. itself) is equal to
the other number. Ex. 1184 and 1210 are amicable. */
// #include<stdio.h>
// int amicable(int a, int b){
//     int div=0;
//     for(int i=1;i<(a+2)/2;i++){
//         if(a%i==0){
//             div=div+i;
//         }
//     }
//     if(div==b){return 1;}
//     else{return 0;}
// }
// int main(){
//     int a,b;
//     printf("Enter two numbers\n");
//     scanf("%d %d",&a,&b);
//     if(amicable(a,b))
//     printf("The numbers %d and %d are amicable\n",a,b);
//     else printf("The numbers %d and %d are not amicable\n",a,b);
//     return 0;
// }



//  Write a function to find the sum of the proper divisors of a given number ‘n’.
//  The proper divisors of a number ‘n’ are the numbers less than n that divide it evenly.
//  they do not include n itself.
// #include<stdio.h>
// int divisors(int a){
//     int div=0;
//     for(int i=1;i<(a+2)/2;i++){
//         if(a%i==0){
//             div=div+i;
//         }
//     }
//     return div;
// }
// int main(){
//     int a,div;
//     printf("Enter a number\n");
//     scanf("%d",&a);
//     div=divisors(a);
//     printf("The sum of the proper divisors of %d is %d\n",a,div);
//     return 0;
// }




/* The Mobius function M (N) is defined as

M (N) = 1         if N=1

          = 0     if any prime factor is contained in N more than once

          = (-1)   if N is the product of p different prime factors */
// #include<stdio.h>
// #include<math.h>
// int mobius(int n){
// 	if(n==1){return 1;}
// 	int sqr,count=1;
// 	sqr=sqrt(n);
// 	for(int i=2;i<=sqr;i++){
// 		for(int j=2;j<i/2;j++){
// 			if(i%j==0){count++;break;}
// 		}
// 		if(count==1){
// 			if(n%(i*i)==0){return 0;}
// 		}
// 		count=1;
// 	}
// 	return -1;
	
// }
// int main(){
// 	int n,m;
// 	printf("Enter a number\n");
// 	scanf("%d",&n);
// 	m=mobius(n);
// 	printf("The value of M(%d) is (M(n) is mobius function): %d\n",n,m);
// return 0;
// }