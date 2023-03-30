#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define ll long long int
int main(){
    int t;
    ll num,sqroot;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&num);
        num--;
        sqroot=sqrt(num);
        printf("%lld\n",sqroot);
        
    }

return 0;
}