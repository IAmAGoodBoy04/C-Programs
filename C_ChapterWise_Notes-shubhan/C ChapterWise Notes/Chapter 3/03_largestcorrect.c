#include<stdio.h>
int main(){
    int a=0,b=0,c=0,d=0,max1,max2,max;
    printf("enter 4 integers\n");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    max1=(a>=b)?a:b;
    max2=(c>=d)?c:d;
    max=(max1>=max2)?max1:max2;
    printf("%d is the largest number",max);
    return 0;
}