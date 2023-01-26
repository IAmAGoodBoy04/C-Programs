#include<stdio.h>

int main(){
    int t,n;
    scanf("%d",&t);
    char *arr;
    arr=(char *)malloc(sizeof(char));
    while(t--){
        int res=0;
        scanf("%d",&n);
        while((getchar())!='\n');
        arr=realloc(arr,(n+1)*sizeof(char));
        fgets(arr,n+1,stdin);
        while((getchar())!='\n');
        for(int i=0;i<n;i++){
            if(arr[i]=='1'){
                res++;
            }
            if(res>3){
                break;
            }
        }
        if(res==2 || res==3){
            printf("YES\n");
            continue;
        }
        if(res==1 && n>2){
            printf("YES\n");
            continue;
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}