#include<stdio.h>

int main(){
    int table[10];
    for(int i=0;i<10;i++){
        table[i]=5*(i+1);
    }
    for(int j=0;j<10;j++){
    printf("5x%d=%d\n",j+1,table[j]);
    }
    return 0;
}