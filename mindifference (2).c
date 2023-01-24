#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
int mindiff(int *arr, int n){
    int diff;
    int diffarray[n+1];
    mergeSort(arr,0,2*n-1);
    for(int i=0;i<n+1;i++){
        diffarray[i]=arr[i+n-1]-arr[i];
    }
    mergeSort(diffarray,0,n);
    diff=diffarray[0];
    return diff;
}
int main(){
    int t,n,x;
    int *arr;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        arr=(int *)malloc(2*n*sizeof(int));
        for(int j=0;j<2*n;j++){
            scanf("%d",&arr[j]);
        }
        x=mindiff(arr,n);
        printf("%d\n",x);
        free(arr);
    }
    return 0;
}