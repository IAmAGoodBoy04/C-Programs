#include<stdio.h>

int main(){
    char str[30];
    char str2[30];
    char c=0;
    int i=0;
    //by %s
    printf("enter a string\n");
    scanf("%s",&str);
    printf("%s\n",str);
    //by %c now
    printf("enter a string alphabet by alphabet\n");
    while(c!='\n'){
        fflush(stdin);
        scanf("%c",&c);
        str2[i]=c;
        
        i++;
    }
    str2[i]='\0';
    printf("%s",str2);
    return 0;
}