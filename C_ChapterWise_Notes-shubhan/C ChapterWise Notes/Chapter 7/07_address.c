#include<stdio.h>

int main(){
    int a,b,c;
    printf("enter dimensions of array(3 numbers)");
    scanf("%d %d %d",&a,&b,&c);
    int array[a][b][c];
    int *ptr=&array[0][0][0];
    for(int i=0;i<a*b*c;i++){
        printf("the address of location no. %d in array is %u\n",i+1,ptr);
        ptr++;
    }


    return 0;
}