#include<stdio.h>

int main(){
    int n;
    FILE *ptr;
    ptr=fopen("newfile.txt","r");
    fscanf(ptr,"%d",&n);
    fclose(ptr);
    ptr=fopen("newfile.txt","w");
    fprintf(ptr,"%d",2*n);
    fclose(ptr);
    return 0;
}