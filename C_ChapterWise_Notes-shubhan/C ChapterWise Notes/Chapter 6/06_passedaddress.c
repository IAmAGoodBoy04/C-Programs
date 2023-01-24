#include<stdio.h>
void pass (int a);
int main(){
    int a=5;
    printf("the address of a is %u\n", &a);
    pass(a);
    return 0;
}
void pass (int a){
    printf("a in function=%d\n",a);
    printf("address of a in function=%u\n",&a);
}