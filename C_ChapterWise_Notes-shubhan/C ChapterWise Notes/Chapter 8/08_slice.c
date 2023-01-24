//slicing means to start at m and end the string at n-1, ex slicing 'shubhan' at 1 and 5 will give 'hubh'
#include<stdio.h>
void slice(char *str,int m, int n){
    int i=0;
    while((i+m)<n){//not <= because slicing does not include nth char
        str[i]=str[i+m];
        i++;
    }
    str[i]='\0';
}
int main(){
    char str[25];
    int m,n;
    printf("enter a string\n");
    gets(str);
    printf("enter positions on which to slice the string\n");
    scanf("%d %d",&m,&n);
    slice(str,m,n);
    printf("now the string is\n %s\n",str);
    return 0;
}