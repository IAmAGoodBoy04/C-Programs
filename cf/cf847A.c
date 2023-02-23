#include<stdio.h>
#include<string.h>
int main(){
    int t,ans;
    char str[31]="314159265358979323846264338327";
    char input[35];
    scanf("%d",&t);
    while((getchar())!='\n');
    while(t--){
        ans=0;
        scanf("%[^\n]%*c",input);
        for(int i=0;i<strlen(input);i++){
            if(input[i]==str[i]){
                ans++;
            }
            else{break;}
        }
        printf("%d\n",ans);
    }
    return 0;
}