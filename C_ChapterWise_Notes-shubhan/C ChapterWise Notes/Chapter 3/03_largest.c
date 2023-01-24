#include<stdio.h>
int main(){
    int a,b,c,d;
    printf("enter four integers\n\n");
    scanf("%d %d %d %d", &a,&b,&c,&d);
    if(a>=b){
        if(a>=c){
            if(a>=d){
                printf("%d is the largest number",a);
            }
            else{
                printf("%d is the largest number",d);
    
            }
        }
        else{
            if(c>=d){
            printf("%d is the largest number",c);
                    }
                    else{
                        printf("%d is the largest number",d);
                    }
        }
    }
    else{
        if(b>=c){
            if(b>=d){
                printf("%d is the largest number",b);
            }
            else{
                printf("%d is the largest number",d);
            }
        }
        else{
            if(c>=d){
                printf("%d is the largest number",c);
            }
            else{
                printf("%d is the largest number",d);
            }
        }
    }
    return 0;
}