#include<stdio.h>
typedef struct vector{
   int x;
   int y;
}vec;
vec sumvector(vec a,vec b){
    vec sum;
    sum.x=a.x+b.x;
    sum.y=a.y+b.y;
    return sum;
}
int main(){
    vec sum;
    vec a,b;
    printf("enter x and y components of first vector:\n");
    scanf("%d %d",&a.x,&a.y);
    printf("enter x and y components of second vector:\n");
    scanf("%d %d",&b.x,&b.y);
    printf("the vector a is: %di+%dj\n",a.x,a.y);
    printf("the vector b is: %di+%dj\n",b.x,b.y);
    sum=sumvector(a,b);
    printf("the vector sum of a and b is is %di+%dj\n",sum.x,sum.y);
    return 0;
}