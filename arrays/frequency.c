/* Write a program in C to calculate frequency count of each number in ARRAY.

Suppose input array is [ 1 2 1 4 5 2 3 1 4 5 6 2 2 3 ]

output :  1 is appearing 3 times , 2 is appearing  4 times ,  4 is appearing 2 times….
5 is appearing 2 times ,  3 is appearing 2 times ,  6 is appearing 1 times*/
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
void frequency(int arr[],int n){
    int flag,count=0,i=0;
    flag=arr[0];
    while(i<n){
    while(flag==arr[i]){
        count++;
        i++;
    }
    printf("%d is appearing %d times\n",flag,count);
    count=0;
    flag=arr[i];
}
}
int main(){
    int n;
    printf("Enter number of elements in input\n");
    scanf("%d",&n);
    int array[n];
    printf("Enter input elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    sort(array,n);
    frequency(array,n);
    return 0;
}