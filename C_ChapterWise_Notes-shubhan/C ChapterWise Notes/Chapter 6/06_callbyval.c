#include<stdio.h>
int multiply(int a);
int main(){
    int a;
    printf("enter number\n");
    scanf("%d",&a);
    printf("10 times of a is %d\n", multiply(a));
    multiply(a);
    printf("10 times of a is %d\n", a);



    return 0;
}
int multiply(int a){
    a=(a)*10;
    return a;
}