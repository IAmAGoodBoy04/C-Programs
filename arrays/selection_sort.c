
#include<stdio.h>
void sort (int arr[], int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                }
        }
    }
}
void printarray(int arr[], int n){
    printf("The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter number of elements to sort\n");
    scanf("%d",&n);
    int inputarray[n];
    printf("Enter all array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&inputarray[i]);
    }
    sort(inputarray,n);
    printarray(inputarray,n);
    return 0;
}