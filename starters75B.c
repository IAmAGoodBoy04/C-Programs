#include<stdio.h>

int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&a,&b);
        printf("%d\n",b+(a/10));
    }
    return 0;
}