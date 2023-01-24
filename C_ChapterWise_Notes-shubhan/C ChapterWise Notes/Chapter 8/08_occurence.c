#include<stdio.h>
int occurence(char *arr,char c){
    int count=0;
    while(*arr!='\0'){
        if(*arr==c){count++;}
        arr++;
    }
    return count;
}
int main(){
    char str[25],c;
    int n;
    printf("enter a string\n");
    gets(str);
    printf("enter a character to find its number of occurences in the given string: ");
    scanf("%c",&c);
    n=occurence(str,c);
    printf("the number of occurences of the character %c in the given string are %d\n",c,n);
    return 0;
}