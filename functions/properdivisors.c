//  Write a function to find the sum of the proper divisors of a given number ‘n’.
//  The proper divisors of a number ‘n’ are the numbers less than n that divide it evenly.
//  they do not include n itself.
#include<stdio.h>
int divisors(int a){
    int div=0;
    for(int i=1;i<(a+2)/2;i++){
        if(a%i==0){
            div=div+i;
        }
    }
    return div;
}
int main(){
    int a,div;
    printf("Enter a number\n");
    scanf("%d",&a);
    div=divisors(a);
    printf("The sum of the proper divisors of %d is %d\n",a,div);
    return 0;
}