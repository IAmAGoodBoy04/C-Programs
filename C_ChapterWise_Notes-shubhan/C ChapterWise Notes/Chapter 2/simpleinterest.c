#include<stdio.h>
int main()
{
    float principle,n,r,interest;
    printf("enter principle,no of years and rate of interest(in percentage) respectively\n\n");
    scanf("%f %f %f", &principle, &n, &r);
    interest=principle*(r/100)*n;
    printf("\n The amount of simple interest is %f", interest);
    return 0;
    

}
