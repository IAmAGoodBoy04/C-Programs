#include<stdio.h>

int main(){
    int n;
    printf("enter a number\n");
    scanf("%d",&n);
    FILE *ptr;
    ptr=fopen("tables.txt","w");
    for(int i=0;i<10;i++){
        fprintf(ptr,"%d * %2d = %3d\n",n,i+1,n*(i+1));
    }
    fclose(ptr);
    return 0;
}