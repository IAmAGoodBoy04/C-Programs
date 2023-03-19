#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        if((a+b)==c){
            printf("+\n");
        }
        else{
            printf("-\n");
        }
    }

return 0;
}