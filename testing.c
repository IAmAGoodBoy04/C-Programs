#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    if(strcmp(a,b)>0){return 1;}
    else{return 0;}
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    if(strcmp(a,b)<0){return 1;}
    else{return 0;}
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int len1,len2,sim1=0,sim2=0;
    len1=strlen(a);
    len2=strlen(b);
    char arr1[len1+1],arr2[len2+1];
    strcpy(arr1,a);
    strcpy(arr2,b);
    for(int i=0;i<len1-1;i++){
        for(int j=i+1;j<len1;j++){
            if(arr1[i]==arr1[j]){
                sim1++;
                break;
            }
              }
    }
    for(int i=0;i<len2-1;i++){
        for(int j=i+1;j<len2;j++){
            if(arr2[i]==arr2[j]){
                sim2++;
                break;
            }
        }
    }
    if((len1-sim1)>(len2-sim2)){return 1;}
    else if((len1-sim1)<(len2-sim2)){return 0;}
    else if(strcmp(arr1,arr2)>0){return 1;}
    else{return 0;}
}
int sort_by_length(const char* a, const char* b) {
    int len1,len2;
    len1=strlen(a);
    len2=strlen(b);
    if(len1>len2){return 1;}
    else if(len2>len1){return 0;}
    else if(strcmp(a,b)>0){return 1;}
    else
      {return 0;}
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char temp[2501];
    //temp=(char*)malloc(sizeof(char));
    for(int i=0;i<len-1;i++){
        int j=i+1;
        while(cmp_func(arr[j-1],arr[j])){
            //temp=(char*)realloc(temp, (strlen(arr[j-1])+1)*sizeof(char));
            strcpy(temp,arr[j-1]);
            strcpy(arr[j-1],arr[j]);
            strcpy(arr[j],temp);
            j--;
            if(j==0){break;}
        }
    }
    //free(temp);
}
int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}