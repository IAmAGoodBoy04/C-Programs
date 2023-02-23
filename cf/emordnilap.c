#include<stdio.h>
#define N 1000000007
int main(){
    long long t,n;
    long long ans;
    scanf("%lld",&t);
    for(int i=0;i<t;i++){
        scanf("%lld",&n);
        ans=n*(n-1);
        ans=ans%N;
        for(int j=1;j<=n;j++){
            ans=(ans*j)%N;
        }
        printf("%lld\n",ans);
    }
    return 0;
}