/* Take two numbers as input and calculate their LCM and GCD (HCF). 

Hint :

1. Take two numbers as input.
2. Find the greater of the two numbers.
3. Keep on dividing the greater number by the smaller number until remainder becomes 0.
4. When the remainder becomes 0 store the smaller number as the GCD of two numbers.

Find the GCD of two numbers using a while-loop and LCM of two numbers using the formula LCM=num1*num2/GCD */

// #include <stdio.h>

// int hcf(int x, int y)
// {
//     int r;
//     while (y != 0)
//     {
//         r = x % y;
//         x = y;
//         y = r;
//     }
//     return x;
// }

// int main(void)
// {
//     int x, y;

//     printf("Enter two integers: ");
//     scanf("%d %d", &x, &y);

//     printf("The highest common factor of %d and %d is %d.\n", x, y, hcf(x, y));

//     return 0;
// }
#include<stdio.h>
int main(){
	int a,b,temp,gcd,lcm;
	printf("enter two numbers\n");
	scanf("%d %d",&a,&b);
	if(a<b){
	temp=a;
	a=b;
	b=temp;}//a is bigger

	temp=b;
	printf("temp=%d\n",temp);
	while( a%temp!=0 || b%temp!=0 ){
	temp--;
	}
	gcd=temp;
	lcm=a*b/gcd;
	printf("the GCD of the two numbers=%d, and their LCM=%d",gcd,lcm);
	
	return 0;
	}
