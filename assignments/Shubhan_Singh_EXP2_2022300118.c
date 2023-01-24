// gcd

// #include<stdio.h>
// int main(){
// 	int a,b,temp,gcd,lcm;
// 	printf("enter two numbers\n");
// 	scanf("%d %d",&a,&b);
// 	if(a<b){
// 	temp=a;
// 	a=b;
// 	b=temp;}//a is bigger

// 	temp=b;
// 	printf("temp=%d\n",temp);
// 	while( a%temp!=0 || b%temp!=0 ){
// 	temp--;
// 	}
// 	gcd=temp;
// 	lcm=a*b/gcd;
// 	printf("the GCD of the two numbers=%d, and their LCM=%d",gcd,lcm);
	
// 	return 0;
// 	}

// binary to decimal and decimal to binary

// #include<stdio.h>
// #include<math.h>
// int main(){
//     int i,n,bin=0,temp,dec=0,x=1,binary=0;
//     printf("enter 1 for decimal to binary conversion, 2 for binary to decimal conversion\n");
//     scanf("%d",&i);
//     if(i==1){//decimal to binary
//         printf("enter non negative decimal number\n");
//         scanf("%d",&n);
//         while(n>=1){
//             if(n%2==1){
//                 binary=binary+x;
//             }
//             n=n/2;
//             x=x*10;
//         }
//         printf("the binary form of the number is: %d",binary);
//     }
//     else if(i==2){//binary to decimal
//         printf("enter binary number\n");//any number other than 0 will be considered 1
//         scanf("%d",&bin);
//         for(i=0;i>=0;i++){
//             if(bin%10==1){dec=dec+pow(2,i);}
//             bin=bin/10;
//             if(bin==0){break;}
//         }
//         printf("the decimal form of the given number is: %d",dec);
//     }
//     else{//invalid choice(not 1 or 2)
//         printf("invalid input\n");
//     }
//     return 0;
// }

// twin primes

// #include<stdio.h>

// int main(){
// 	int a,b,j,x,i;
// 	printf("Enter the range\n");
// 	scanf("%d %d",&a,&b);
// 	if(a<0 && b<=0){
// 		printf("invalid input");
// 		return 0;
// 	}
// 	printf("All pairs of twin primes in this range are: ");
// 	if(a<=2){
// 		a=3;
// 	}
// 	if(a>2){
// 	for(i=a;i<=b-2;i++){
// 		int count=2;
// 		for(j=2;j<i/2;j++){
// 			if(i%j==0){count++;break;}
// 			}
// 		for(x=2;x<(i/2+1);x++){
// 			if((i+2)%x==0){count++;break;}
// 		}
// 		if(count==2){printf("[%d,%d]\n",i,i+2);};
// 	}
// 	}
// return 0;
// }

// kaprekar numbers

// #include<stdio.h>
// #include<math.h>
// int main(){
// 	int n,digits=0,sq,temp,left,l,r,kap;
// 	printf("Enter a positive number\n");
// 	scanf("%d",&n);
// 	if(n<=0){
// 		printf("invalid input");
// 		return 0;
// 	}
// 	sq=n*n;
// 	temp=sq;
// 	while(1){
// 		if(temp!=0){digits++;}
// 		else{break;}
// 		temp=temp/10;
// 	}
// 	left=digits/2;
// 	temp=sq;
// 	temp=sq/pow(10,digits-left);
// 	l=temp;
// 	temp=temp*pow(10,digits-left);
// 	r=sq-temp;
// 	kap=r+l;
// 	if(kap==n){
// 	printf("%d is a Kaprekar number",n);}
// 	else{printf("%d is not a Kaprekar number",n);}
	
// return 0;
// }