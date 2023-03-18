//program for selection sort
// #include<stdio.h>
// void sort (int arr[], int n){
//     int temp;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//                 }
//         }
//     }
// }
// void printarray(int arr[], int n){
//     printf("The sorted array is: ");
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
// }
// int main(){
//     int n;
//     printf("Enter number of elements to sort\n");
//     scanf("%d",&n);
//     int inputarray[n];
//     printf("Enter all array elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",&inputarray[i]);
//     }
//     sort(inputarray,n);
//     printarray(inputarray,n);
//     return 0;
// }


//program for binary search
// #include<stdio.h>
// void sort (int arr[], int n){
//     int temp;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
// }
// int binarysearch(int arr[], int n, int x){
//     int ub=n-1,lb=0,m;
//     m=(n-1)/2;
//     while(ub>=lb){
//         if(arr[m]==x){return m;}
//         else if(arr[m]>x){ub=m-1;}
//         else if(arr[m]<x){lb=m+1;}
//         m=(ub+lb)/2;
//     }
//     return -1;
// }
// int main(){
//     int n,x,b;
//     printf("Enter number of elements in array\n");
//     scanf("%d",&n);
//     int inputarray[n];
//     printf("Enter all array elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",&inputarray[i]);
//     }
//     printf("Enter value to be searched\n");
//     scanf("%d",&x);
//     sort(inputarray,n);
//     b=binarysearch(inputarray,n,x);
//     if(b==-1){printf("This number is not present in the array\n");}
//     else{printf("%d is at position %d in the sorted array\n",x,b+1);}
//     return 0;
// }


//program for calculationg frequency(batch practice problem)
// #include<stdio.h>
// void sort (int arr[], int n){
//     int temp;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 temp=arr[i];
//                 arr[i]=arr[j];
//                 arr[j]=temp;
//             }
//         }
//     }
// }
// void frequency(int arr[],int n){
//     int flag,count=0,i=0;
//     flag=arr[0];
//     while(i<n){
//     while(flag==arr[i]){
//         count++;
//         i++;
//     }
//     printf("%d is appearing %d times\n",flag,count);
//     count=0;
//     flag=arr[i];
// }
// }
// int main(){
//     int n;
//     printf("Enter number of elements in input\n");
//     scanf("%d",&n);
//     int array[n];
//     printf("Enter input elements\n");
//     for(int i=0;i<n;i++){
//         scanf("%d",&array[i]);
//     }
//     sort(array,n);
//     frequency(array,n);
//     return 0;
// }