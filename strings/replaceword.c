#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **strarr;
    char findstr[250];
    char replacestr[250];
    char tempstr[250];
    int i=0,templen,lenreplace;
    printf("Enter the string (all words before newline will be read):\n");
    scanf("%s",tempstr);
    templen=strlen(tempstr);
    strarr=(char**)malloc(sizeof(char*));
    strarr[i]=(char*)malloc((templen+1)*sizeof(char));
    strcpy(strarr[i],tempstr);
    i++;
    while(1){
        if(getchar()=='\n'){
            break;
        }
        strarr=(char**)realloc(strarr,(i+1)*sizeof(char*));
        scanf("%s",tempstr);
        templen=strlen(tempstr);
        strarr[i]=(char*)malloc((templen+1)*sizeof(char));
        strcpy(strarr[i],tempstr);
        
        i++;
    }
    printf("Enter word to find:\n");
    scanf("%s",findstr);
    printf("Enter word to replace:\n");
    scanf("%s",replacestr);
    lenreplace=strlen(replacestr);
    for(int j=0;j<i;j++){
        if(strcmp(strarr[j],findstr)==0){
            strarr[j]=(char*)calloc((lenreplace+1),sizeof(char));
            strcpy(strarr[j],replacestr);
        }
    }
    for(int k=0;k<i;k++){
        printf("%s ",strarr[k]);
    }
    printf("\n");
    free(strarr);
    return 0;
}