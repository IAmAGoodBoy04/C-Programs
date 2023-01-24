/* Write a function which takes as parameters two positive integers and returns TRUE if
the numbers are amicable and FALSE otherwise. A pair of numbers is said to be amicable
if the sum of divisors of each of the numbers (excluding the no. itself) is equal to
the other number. Ex. 1184 and 1210 are amicable. */
#include<stdio.h>
int amicable(int a, int b){
    int div=0;
    for(int i=1;i<(a+2)/2;i++){
        if(a%i==0){
            div=div+i;
        }
    }
    if(div==b){return 1;}
    else{return 0;}
}
int main(){
    int a,b;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    if(amicable(a,b))
    printf("The numbers %d and %d are amicable\n",a,b);
    else printf("The numbers %d and %d are not amicable\n",a,b);
    return 0;
}