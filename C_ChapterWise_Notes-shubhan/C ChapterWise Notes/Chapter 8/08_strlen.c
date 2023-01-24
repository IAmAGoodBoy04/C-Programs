#include<stdio.h>
int strlenf(char *arr){
    int len=0,i=0;
    while(arr[i]!='\0'){
        len++;
        i++;
    }
    return len;
}
int main(){
    char str[25];
    printf("enter a string\n");
    gets(str);
    int n;
    n=strlenf(str);
    printf("the length of the string is %d\n",n);
    return 0;
}