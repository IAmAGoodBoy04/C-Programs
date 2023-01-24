#include<stdio.h>

int main(){
    int a=0,b=0,c=0;
    FILE *ptr;
    ptr=fopen("newfile.txt","r");
    fscanf(ptr,"%d %d %d",&a,&b,&c);
    fclose(ptr);
    ptr=fopen("newfile.txt","a");
    fprintf(ptr,"%d\t %d\t %d",a,b,c);
    printf("%d %d %d \n",a,b,c);
    fclose(ptr);
    return 0;
}