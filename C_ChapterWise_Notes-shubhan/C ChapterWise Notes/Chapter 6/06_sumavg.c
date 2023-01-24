#include<stdio.h>
void operate(float *a,int *b);
int main(){
    int b;
    float a;
    printf("enter two numbers\n");
    scanf("%f %d", &a,&b);
    operate(&a,&b);
    printf("the average of the two numbers is %.3f\n",a);
    printf("the sum of the two numbers is %d\n",b);
    return 0;
}
void operate(float *a, int *b){
    float c;
    int d;
    c=(*a+*b)/2;
    d=(*a+*b);
    *a=c;
    *b=d;
}