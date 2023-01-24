#include<stdio.h>
float avg(int a,int b,int c);
int main(){
    int x,y,z;
    float average;
    printf("enter 3 integers\n");
    scanf("%d %d %d", &x,&y,&z);
    average=avg(x,y,z);
    printf("\nthe average of the 3 numbers is %f \n", average);
    return 0;
}
float avg(int a,int b,int c){
    float mean= (float) (a+b+c)/3;
    return mean;

}