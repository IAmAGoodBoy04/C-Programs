#include<stdio.h>

int main(){
    int a;
    int *b=&a;
    int **c=&b;
    printf("enter a number\n");
    scanf("%d",&a);
    printf("the value of a is %d",**c);
    return 0;
}