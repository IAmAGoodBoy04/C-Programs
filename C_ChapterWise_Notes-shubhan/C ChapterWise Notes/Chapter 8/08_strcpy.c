#include<stdio.h>
void strcpyf(char arr2[],char arr1[]){
    int i=0;
    while(arr1[i]!='\0'){
        arr2[i]=arr1[i];
        i++;
    }
    arr2[i]='\0';
}
int main(){
    char str[25],str2[25];
    printf("enter a string\n");
    gets(str);
    printf("the string is\n %s\n",str);
    strcpyf(str2,str);
    printf("the copy of the string is\n %s",str2);
    return 0;
}