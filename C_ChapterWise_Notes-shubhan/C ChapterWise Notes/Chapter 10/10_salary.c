#include<stdio.h>

int main(){
    FILE *ptr;
    ptr=fopen("salary.txt","w");
    int n,sal;
    char str[50];
    printf("Enter number of employees:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter name of employee %d:  ",i+1);
        fflush(stdin);
        gets(str);
        printf("Enter salary of employee %d: ",i+1);
        scanf("%d",&sal);
        fprintf(ptr,"%s, %d\n",str,sal);
    }
    fclose(ptr);
    printf("Operation complete\n");
    return 0;
}