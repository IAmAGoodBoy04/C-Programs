#include<stdio.h>
#include<stdlib.h>

void merge(long long int arr[], long long int l, 
           long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 = r - m;
  
    // Create temp arrays
    long long int L[n1], R[n2];
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    // Merge the temp arrays back 
    // long long into arr[l..r]
    // Initial index of first subarray
    i = 0; 
  
    // Initial index of second subarray
    j = 0; 
  
    // Initial index of merged subarray
    k = l; 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    // Copy the remaining elements 
    // of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
  
// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void mergeSort(long long int arr[], 
               long long int l, long long int r)
{
    if (l < r) 
    {
        // Same as (l+r)/2, but avoids 
        // overflow for large l and h
        long long int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
}


int main(){
    long long int t,yes,n,prevsum;
    scanf("%lld",&t);
    while(t--){
        yes=1;
        scanf("%lld",&n);
        long long int arr[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
        }
        if(n>1){
        mergeSort(arr,0,n-1);
        }
        if(arr[0]!=1){
            yes=0;
        }
        for(int i=1;i<n;i++){
            prevsum=0;
            for(int j=0;j<i;j++){
                prevsum=prevsum+arr[j];
            }
            if(prevsum<arr[i]){
                yes=0;
                break;
            }
        }
        if(yes==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }

return 0;
}