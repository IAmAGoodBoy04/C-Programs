#include<stdio.h>
#include<stdlib.h>
int main(){
    int t,a,b,c,d,len1,len2,temp,max;
    scanf("%d",&t);
    while(t--){
        int res=0;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a>c){
            temp=a;
            a=c;
            c=temp;
            temp=b;
            b=d;
            d=temp;
        }
        len1=b-a+1;
        len2=d-c+1;
        max=len1>len2?len1:len2;
        if(a==c){
            printf("%d\n",max);
            continue;
        }
        if(c>b){
            printf("%d\n",len1+len2);
            continue;
        }
        if(b>d){
            printf("%d\n",len1);
            continue;
        }
        if(c<=b){
            printf("%d\n",len1+len2-(b-c+1));
        }   
    }
    return 0;
}