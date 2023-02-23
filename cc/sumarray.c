#include<stdio.h>
void printarray(int n){
    int a=1;
    printf("YES\n");
    for(int i=0;i<n-1;i++){
        printf("%d ",a);
        a=-a;
    }
    printf("%d",a);
}
int main(){
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        if(n%2!=0){printf("NO\n");}
        else{printarray(n);}
        if(i<t-1){printf("\n");}
    }
    return 0;
}