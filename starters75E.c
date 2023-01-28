#include<stdio.h>
#include<stdlib.h>
int answer(int n,char *str){
    if(str[0]=='0'){
        int i=0,ans=0,max=0;
        while(i<n){
            ans=0;
            while(str[i]=='1'){
                if(str[i]==str[i+1]){
                    ans++;
                }
                else{ans++;}
                i++;
            }
            if(ans>max){
                max=ans;
            }
            i++;
        }
        return max;
    }
    else{
        int j=0,leading1=0,ans=0,max=0;
        while(str[j]=='1'){
            leading1++;
            j++;
        }
        while(j<n){
            ans=0;
            while(str[j]=='1'){
                if(str[j]==str[j+1]){
                    ans++;
                }
                else{ans++;}
                j++;
            }
            if(ans>max){
                max=ans;
            }
            j++;
        }
        return leading1+max;
    }
}
int main(){
    int t,n,res;
    scanf("%d",&t);
    char* str;
    str=(char *)malloc(sizeof(char));
    while(t--){
        scanf("%d",&n);
        str=realloc(str,(n+1)*sizeof(char));
        while((getchar())!='\n');
        fgets(str,n+1,stdin);
        while((getchar())!='\n');
        res=answer(n,str);
        printf("%d\n",res);
    }
    return 0;
}