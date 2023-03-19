#include<stdio.h>
#include<stdlib.h>

int main(){
    int t,n,flag;
    scanf("%d",&t);
    while(t--){
        flag=0;
        int n;
        scanf("%d%*c",&n);
        int evenarr[26]={0};
        int oddarr[26]={0};
        char str[n+1];
        scanf("%[^\n]%*c",str);
        for(int i=0;i<n;i++){
            if(i%2==0){
                evenarr[str[i]-'a']++;
            }
            else{
                oddarr[str[i]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(evenarr[i]>0 && oddarr[i]>0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }

return 0;
}