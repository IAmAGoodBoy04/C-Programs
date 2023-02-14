// Write a program to reverse the position of all elements in the 2D array using
// pointers.

#include<stdio.h>
void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
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
void reversearr(int y,int x,int arr[y][x]){
    int *start=(*(arr+0)+0);
    int *end=(*(arr+y-1)+x-1);
    for(int c=0;c<y*x/2;c++){
        swap(start,end);
        start++;
        end--;
    }
}
int main(){
    int y,x;
    printf("Enter the dimensions of the matrix(rows x columns): ");
    scanf("%d%d",&y,&x);
    int arr[y][x];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",(*(arr+i)+j));
        }
    }
    reversearr(y,x,arr);
    printf("The reversed array is:\n");
    printarr(y,x,arr);
return 0;
}