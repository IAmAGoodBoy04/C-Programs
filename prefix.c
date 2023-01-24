#include<stdio.h>
int minprefix(int n, int m, char s[]){

}
int main(){
    int t,n,m,x;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d,%d",&n,&m);
        char s[n*12+1];
        gets(s);
        x=minprefix(n,m,s);
        printf("&d",&x);
    }
    return 0;
}