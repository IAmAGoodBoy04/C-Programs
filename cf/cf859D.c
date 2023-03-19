#include<stdio.h>

int main(){
    int t,n,q,l,r,k,sumarr,newsumarr,i;
    scanf("%d",&t);
    while(t--){
        sumarr=0;
        scanf("%d",&n);
        scanf("%d",&q);
        int arr[n];
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            sumarr=sumarr+arr[i];
        }
        while(q--){
            newsumarr=sumarr;
            scanf("%d",&l);
            scanf("%d",&r);
            scanf("%d",&k);
            for(i=l-1;i<r;i++){
                newsumarr=newsumarr-arr[i];
            }
            newsumarr=newsumarr+k*(r-l+1);
            if(newsumarr%2==0){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }

        }
    }

return 0;
}