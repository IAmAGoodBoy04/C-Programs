#include<stdio.h>
void reversearr(int arr[],int n);
int main(){
    int array[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        printf("element %d = %d\n",i+1,array[i]);
    }
    reversearr(array,5);
     for(int i=0;i<5;i++){
        printf("element %d of reversed array = %d\n",i+1,array[i]);
    }
    return 0;
}
void reversearr(int arr[],int n){
    int temp;
    for(int i=0;i<n/2;i++){
      temp=arr[i];
      arr[i]=arr[n-i-1];
      arr[n-i-1]=temp;
    }
}