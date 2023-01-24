/* Perform search of a particular element on the above array using binary search.

Binary Search will search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty. We basically ignore half of the elements just after one comparison.


1. Compare x with the middle element.

2. If x matches with the middle element, we return the mid index.

3. Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for right half.

4. Else (x is smaller) recur for the left half.

*/
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
int binarysearch(int arr[], int n, int x){
    int ub=n-1,lb=0,m;
    m=(n-1)/2;
    while(ub>=lb){
        if(arr[m]==x){return m;}
        else if(arr[m]>x){ub=m-1;}
        else if(arr[m]<x){lb=m+1;}
        m=(ub+lb)/2;
    }
    return -1;
}
int main(){
    int n,x,b;
    printf("Enter number of elements in array\n");
    scanf("%d",&n);
    int inputarray[n];
    printf("Enter all array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&inputarray[i]);
    }
    printf("Enter value to be searched\n");
    scanf("%d",&x);
    sort(inputarray,n);
    b=binarysearch(inputarray,n,x);
    if(b==-1){printf("This number is not present in the array\n");}
    else{printf("%d is at position %d in the sorted array\n",x,b+1);}
    return 0;
}