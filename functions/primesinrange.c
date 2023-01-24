//Write a function which takes a range as input. Print all the numbers in the range with ‘*’ in front of prime numbers only.
#include<stdio.h>
void primes(int start, int end){
    int count=1,x,offset,digits=1,digitsmax=1,y,z,o=1;
    printf("the numbers in the range %d to %d with the primes starred are:\n",start,end);
    x=y=start;
    z=end;

    offset=start%10;
    while(y>=10){
        y=y/10;
        digits++;
    }
    while(z>=10){
        z=z/10;
        digitsmax++;
    }
    for(int o=0;o<(offset-1)*(2+digits);o++){
        printf(" ");
    }
    if(start==1){
        start++;
        printf("%*d  ",digitsmax,o);
    }
    for(int i=start; i<=end; i++){
        for(int j=2;j<i/2;j++){
            if(i%j==0){count++;break;}
        }
        if(count>1){printf("%*d  ",digitsmax,i);}
        else{printf("%*d* ",digitsmax,i);}
        if((i-x+offset)%10==0){printf("\n");}
        count=1;
    }
}
int main(){
    int a,b,temp;
    printf("Enter the range(positive numbers)\n");
    scanf("%d %d",&a,&b);
    if(a>b || b<1){printf("invalid input\n");return 0;}
    if(a<1){a=1;}
    primes(a,b);
    return 0;
}
