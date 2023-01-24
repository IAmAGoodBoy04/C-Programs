#include<stdio.h>

int main(){
    int numbers[100];
    for(int i=0;i<100;i++){
        numbers[i]=i;
    } 
    printf("hello\n");
    int *ptr=&numbers[0];
    printf("number=%d\n",*ptr);
    ptr=ptr+20;
    printf("number=%d\n",*ptr);
    ptr-=15;
    printf("number=%d\n",*ptr);
    int *ptr2=&numbers[50];
    int c=ptr2-ptr;
    printf("number=%d\n",c);
    ptr++;
    printf("number=%d\n",*ptr);
    if(ptr==ptr2){
        printf("pointers are equal\n");
    }
    else{printf("not equal");};

    return 0;
}