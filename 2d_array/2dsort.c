#include<stdio.h>
void sort(int x,int *arr){//insertion sort
    int j,temp;
    for(int i=0;i<x-1;i++){
        j=i+1;
        while(j>0){
            if(arr[j-1]>arr[j]){
                temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
            j--;
        }
    }
}
int main(){
    int y,x;
    printf("Enter number of rows and columns:\n");
    scanf("%d %d",&y,&x);
    int arr[y][x];
    printf("Enter array elements:\n");
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<y;i++){
        sort(x,arr[i]);
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}