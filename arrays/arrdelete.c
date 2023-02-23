//To delete repeated elements from array
#include<stdio.h>
#include<stdlib.h>
void arrdelete(int *arr, int n,int *size){
    int y=0,z=0,x=1,count=0;
    int check=arr[y];
    int temparr[n];
    while(x<n){
    for(int i=x;i<n;i++){
        if(arr[i]==check){
            count=1;
            y++;
            check=arr[y];
            break;
            }
        
    }
    if(count==0){
        temparr[z]=check;
        z++;
        y++;
        check=arr[y];
    }
    count=0;
    x++;
    }
    temparr[z]=arr[n-1];
    z++;//last element of arr isnt checked, and it will never be a duplicate, because only the last number among duplicates is considered
    for(int i=0;i<z;i++){
        arr[i]=temparr[i];
    }
    *size=z;
}
int main(){
    int n;
    int size;
    int *p=&size;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arrdelete(arr,n,p);
    printf("The new array is:\n");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    free(arr);
return 0;
}