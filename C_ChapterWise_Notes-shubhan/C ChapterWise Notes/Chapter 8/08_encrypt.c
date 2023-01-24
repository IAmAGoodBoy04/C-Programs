#include<stdio.h>
void encrypt(char *arr){
    while(*arr!='\0'){
        *arr=(char)*arr+1;
        arr++;
    }
}
void decrypt(char *arr){
    while(*arr!='\0'){
        *arr=(char)*arr-1;
        arr++;
}
}
int main(){
    char str[50];
    printf("enter a string\n");
    gets(str);
    encrypt(str);
    printf("the encrypted string is: %s\n",str);
    decrypt(str);
    printf("the decrypted string is: %s",str);
    return 0;
}