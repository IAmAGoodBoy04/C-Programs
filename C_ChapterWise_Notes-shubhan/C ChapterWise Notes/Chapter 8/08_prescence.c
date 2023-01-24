#include<stdio.h>
void prescence(char *arr,char c){
    int count=0;
    while(*arr!='\0'){
        if(*arr==c){
            count++;
            break;
        }
        arr++;
    }
    if(count==1){printf("\nthe character %c is present in the string\n");}
    else{printf("\nthe character %c is not present in the string\n");}
}
int main(){
    char str[25],c;
    int n;
    printf("enter a string\n");
    gets(str);
    printf("enter a character to find its number of occurences in the given string: ");
    scanf("%c",&c);
    prescence(str,c);
    return 0;
}