#include<stdio.h>

int main(){
    int table[3][10],a,b,c;
    printf("enter 3 numbers\n");
    scanf("%d %d %d",&a,&b,&c);
    int array[3]={a,b,c};
    for(int i=0;i<3;i++){
        int c=array[i];
        for(int j=0;j<10;j++){
            table[i][j]=c*(j+1);
            printf(" %dx%d=%d \t",c,j+1,table[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}