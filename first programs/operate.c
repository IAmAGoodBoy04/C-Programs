// Write a C program to input 2 numbers. Perform addition, subtraction, multiplication, division and modulus and display output.

#include<stdio.h>
int main(){
    int a,b,sum,difference,modulus,product;
    float division;
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    sum=a+b;
    difference=a-b;
    product=a*b;
    division=(float)a/b;
    modulus=a%b;
    printf("the sum of the two numbers is: %d\n",sum);
    printf("the difference between the two numbers is: %d\n",difference);
    printf("the product of the two numbers is: %d\n",product);
    printf("the division of the two numbers is: %f\n",division);
    printf("the modulus of the two numbers is: %d\n",modulus);
    return 0;
}