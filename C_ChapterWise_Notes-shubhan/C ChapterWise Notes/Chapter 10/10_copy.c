#include<stdio.h>

int main(){
    FILE *ptr,*ptr2;
    char c;
    ptr=fopen("tables.txt","r");
    ptr2=fopen("twocopies.txt","a");
    for(int i=0;i<2;i++){
        ptr=fopen("tables.txt","r");
        while(1){
            c=fgetc(ptr);
            if(c==EOF){break;}
            fputc(c,ptr2);
        }
        fclose(ptr);
    }
    fclose(ptr2);
    return 0;
}