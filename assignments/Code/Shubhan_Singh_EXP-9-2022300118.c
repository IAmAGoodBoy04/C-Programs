//to swap max and min element
// #include <stdio.h>
// void swap(int *y, int *x)
// {
//     int temp;
//     temp = *y;
//     *y = *x;
//     *x = temp;
// }
// void minmax(int *arr, int n)
// {
//     int *a;
//     int *b;
//     a = &arr[0];
//     b = &arr[0];
//     for (int i = 0; i < (n - 1); i++)
//     {
//         if (*a < arr[i + 1])
//         {

//             a = &arr[i + 1];
//         }
//     }
//     for (int i = 0; i < (n - 1); i++)
//     {
//         if (*b > arr[i + 1])
//         {
//             b = &arr[i + 1];
//         }
//     }
//     swap(b, a);
// }
// int main()
// {
//     int n = 0;
//     printf("Enter number of elements in array\n");
//     scanf("%d", &n);
//     int arr[n];
//     printf("Enter the array elements\n");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
    
//     minmax(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }


// Write a program to reverse the position of all elements in the 2D array using
// pointers.

// #include<stdio.h>
// void swap(int *a, int *b){
//     int temp;
//     temp=*a;
//     *a=*b;
//     *b=temp;
// }
// void printarr(int y,int x, int arr[y][x]){
//     int digitsmax=0,max=*(*(arr+0)+0);
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             if(*(*(arr+i)+j)>max){*(*(arr+i)+j);}
//         }
//     }
//     if(max<0){
//         digitsmax=1;
//         max=-1*max;
//     }
//     while(max>0){
//         digitsmax++;
//         max=max/10;
//     }
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             printf("%*d  ",digitsmax,*(*(arr+i)+j));
//         }
//         printf("\n");
//     }
// }
// void reversearr(int y,int x,int arr[y][x]){
//     int *start=(*(arr+0)+0);
//     int *end=(*(arr+y-1)+x-1);
//     for(int c=0;c<y*x/2;c++){
//         swap(start,end);
//         start++;
//         end--;
//     }
// }
// int main(){
//     int y,x;
//     printf("Enter the dimensions of the matrix(rows x columns): ");
//     scanf("%d%d",&y,&x);
//     int arr[y][x];
//     printf("Enter the elements of the array:\n");
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             scanf("%d",(*(arr+i)+j));
//         }
//     }
//     reversearr(y,x,arr);
//     printf("The reversed array is:\n");
//     printarr(y,x,arr);
// return 0;
// }

//to subtract matrices
//#include<stdio.h>
// void printarr(int y,int x, int arr[y][x]){
//     int digitsmax=0,max=*(*(arr+0)+0);
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             if(*(*(arr+i)+j)>max){*(*(arr+i)+j);}
//         }
//     }
//     if(max<0){
//         digitsmax=1;
//         max=-1*max;
//     }
//     while(max>0){
//         digitsmax++;
//         max=max/10;
//     }
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             printf("%*d  ",digitsmax,*(*(arr+i)+j));
//         }
//         printf("\n");
//     }
// }
// void arr_difference(int y, int x, int array1[y][x], int array2[y][x],int diffarray[y][x]){
//     int *start1=&array1[0][0];
//     int *start2=&array2[0][0];
//     int *start3=&diffarray[0][0];
//     for(int i=0;i<y*x;i++){
//         *start3=*start1-*start2;
//         start1++;
//         start2++;
//         start3++;
//     }
// }
// int main(){
//     int y,x;
//     printf("Enter dimensions of the matrices(rows*columns):  ");
//     scanf("%d %d",&y,&x);
//     int array1[y][x];
//     int array2[y][x];
//     printf("Enter elements of first matrix(marrix to be subjected from):\n");
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             scanf("%d",&array1[i][j]);
//         }
//     }
//     printf("Enter elements of second matrix(matrix to be subtracted):\n");
//     for(int i=0;i<y;i++){
//         for(int j=0;j<x;j++){
//             scanf("%d",&array2[i][j]);
//         }
//     }
//     int diffarray[y][x];
//     arr_difference(y,x,array1,array2,diffarray);
//     printarr(y,x,diffarray);
// return 0;
// }