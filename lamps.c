#include<stdio.h>
int lamps(int n, char s[]){
    int countl=0,countr=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L'){countl=1;break;}
    }
    for(int i=0;i<n;i++){
        if(s[i]=='R'){countr=1;break;}
    }
    if(countl==0 || countr==0){return -1;}
    for(int j=0;j<n;j++){
        if(s[j]=='R' && s[j+1]=='L'){return 0;}
    }
    for (int k=0;k<n;k++){
        if(s[k]=='L' && s[k+1]=='R'){return k+1;}
    }
}
int main(){
    int t,n,x;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        char s[n+1];
        scanf("%s",&s);
        x=lamps(n,s);
        printf("%d\n",x);
    }
    return 0;
}