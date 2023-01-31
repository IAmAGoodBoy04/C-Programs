#include<stdio.h>
#include<stdlib.h>
int stringlength(char* str1){
    int i=0,length=0;
    while((*(str1+i))!='\0'){
        length++;
        i++;
    }
    return length;
}
void strcopy(char* str1,char* str2){
    int len=stringlength(str1);
    len++;
    for(int i=0;i<len;i++){
        str1[i]=str2[i];
    }
}
void stringrev(char* str1){
    int len=stringlength(str1);
    int temp;
    for(int i=0;i<len/2;i++){
        temp=str1[i];
        str1[i]=str1[len-i-1];
        str1[len-i-1]=temp;
    }
}
void concatentates(char * str1,char * str2){
    int len1=stringlength(str1);
    int len2=stringlength(str2);
    str1=(char *)realloc(str1,(len1+len2+1)*sizeof(char));
    for(int i=len1;i<len1+len2;i++){
        str1[i]=str2[i-len1];
    }
    str1[len1+len2]='\0';

}
void capitalisestr(char *str){
    int len=stringlength(str);
    for(int i=0;i<len;i++){
        if(str[i]>=97 && str[i]<=122){
            str[i]=(char)str[i]-32;
        } 
    }
}
void stringcompare(char *str1,char*str2){
    int res;
    int len1=stringlength(str1);
    int len2=stringlength(str2);
    int min=len1>len2?len1:len2;
    for(int i=0;i<min;i++){
        if(str1[i]>str2[i]){
            res=1;
            break;
        }
        if(str1[i]<str2[i]){
            res=-1;
            break;
        }
    }
    if(len1>len2){res=1;}
    else if(len1<len2){res=-1;}
    else{res=0;}
    if(res==0){
        printf("The strings are equal\n");
    }
    else if(res==1){
        printf("The first string comes first lexicographically\n");
    }
    else{
        printf("The second string comes first lexicographically\n");
    }
}
int main(){
    int n,code,temp;
    char *str;
    char *str2;
    str=(char *)malloc(250*sizeof(char));
    str2=(char *)malloc(250*sizeof(char));
    printf("Enter first string:\n");
    scanf("%[^\n]%*c",str);
    printf("Enter second string:\n");
    scanf("%[^\n]%*c",str2);
    str=(char *)realloc(str,(stringlength(str)+1)*sizeof(char));
    str2=(char *)realloc(str2,(stringlength(str2)+1)*sizeof(char));
    printf("Legend for actions:\n 1:Print length of string\n 2:copy strings\n 3:reverse strnig\n 4:Concatenate string\n 5:Convert to uppercase\n 6:Compare strings\n");
    printf("Enter number of actions to execute:\n");
    scanf("%d",&n);
    while(n--){
        printf("Enter action number: ");
        scanf("%d",&code);
        switch(code)
        {
            case 1:printf("Enter number of string whose length you want to find: ");
                    scanf("%d",&temp);
                    if(temp==1){
                        printf("Length of string 1 is %d characters\n",stringlength(str));
                    }
                    else if(temp==2){
                        printf("Length of string 2 is %d characters\n",stringlength(str2));
                    }
                    else{printf("invalid input!\n");}
                    break;
            case 2:printf("Enter number of source string: ");
                    scanf("%d",&temp);
                    if(temp==1){
                        strcopy(str2,str);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else if(temp==2){
                        strcopy(str,str2);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else{printf("invalid input!\n");}
                    break;
            case 3:printf("Enter string number to reverse: ");
                    scanf("%d",&temp);
                    if(temp==1){
                        stringrev(str);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else if(temp==2){
                        stringrev(str2);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else{printf("invalid input!\n");}
                    break;
            case 4:printf("Enter string number of string to concatenate to: ");
                    scanf("%d",&temp);
                    if(temp==1){
                        concatentates(str,str2);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else if(temp==2){
                        concatentates(str2,str);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else{printf("invalid input!\n");}
                    break;
            case 5:printf("Enter string number to capitalize: ");
                    scanf("%d",&temp);
                    if(temp==1){
                        capitalisestr(str);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else if(temp==2){
                        capitalisestr(str2);
                        printf("string 1 is: %s\n",str);
                        printf("string 2 is: %s\n",str2);
                    }
                    else{printf("invalid input!\n");}
                    break;
            case 6:stringcompare(str,str2);
        }
    }
    free(str);
    free(str2);
    return 0;
}