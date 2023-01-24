#include<stdio.h>
void display(int a);
int main(){
    int n;
    printf("enter no of lines\n");
    scanf("%d",&n);
    display(n);
    return 0;
}
void display(int a)
{
    static int b=1;
    for(b=1;b<=a;b++)
    {
        int x=2*b-1;
        while(x > 0)
        {
            printf("*");
            x--;
        }
        if (x==0)
        {
            printf("\n");
        }
    }
};