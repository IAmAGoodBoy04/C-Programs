#include<stdio.h>
void printarr(int y,int x, int arr[y][x]){
    int digitsmax=0,max=*(*(arr+0)+0);
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(*(*(arr+i)+j)>max){*(*(arr+i)+j);}
        }
    }
    if(max<0){
        digitsmax=1;
        max=-1*max;
    }
    while(max>0){
        digitsmax++;
        max=max/10;
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            printf("%*d  ",digitsmax,*(*(arr+i)+j));
        }
        printf("\n");
    }
}
void arr_difference(int y, int x, int array1[y][x], int array2[y][x],int diffarray[y][x]){
    int *start1=&array1[0][0];
    int *start2=&array2[0][0];
    int *start3=&diffarray[0][0];
    for(int i=0;i<y*x;i++){
        *start3=*start1-*start2;
        start1++;
        start2++;
        start3++;
    }
}
int main(){
    int y,x;
    printf("Enter dimensions of the matrices(rows*columns):  ");
    scanf("%d %d",&y,&x);
    int array1[y][x];
    int array2[y][x];
    printf("Enter elements of first matrix(marrix to be subjected from):\n");
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&array1[i][j]);
        }
    }
    printf("Enter elements of second matrix(matrix to be subtracted):\n");
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&array2[i][j]);
        }
    }
    int diffarray[y][x];
    arr_difference(y,x,array1,array2,diffarray);
    printarr(y,x,diffarray);
return 0;
}