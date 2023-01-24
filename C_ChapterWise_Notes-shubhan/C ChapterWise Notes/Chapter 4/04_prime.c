#include<stdio.h>
int main(){
    int i=0,n,r,c=1;
    printf("enter a number\n");
    scanf("%d",&n);
    for(i=1;i<=n/2;i++){
        r=n%i;
        if(r==0){
            c++;
        }
        }
        if(c>2){
            printf("\n %d is not a prime number",n);
        }
        else{
            printf("\n %d is a prime number",n);
        }
        return 0;

}