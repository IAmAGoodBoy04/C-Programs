#include<stdio.h>

int main(){
    int a=12;
    printf("the address of a is %u\n", &a);
    int b=*(&a);
    printf("b is equal to value stored in address of a, b=%d",b);
    return 0;
}