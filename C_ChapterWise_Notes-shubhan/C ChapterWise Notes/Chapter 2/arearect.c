#include<stdio.h>
int main()
{
    float length,breadth,area;
    printf("enter length and breadth respectively");
    scanf("%f %f", &length, &breadth);

    area=length*breadth;
    printf("area of rectangle is %f", area);
    return 0;
    }