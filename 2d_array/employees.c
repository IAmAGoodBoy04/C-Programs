/* Write a program which reads the current year followed by N followed by a list of N employee numbers and their current 
ages. Produce a list showing the years in which the employees retire (become 65 years old). If more than one employee 
retires in a given year then include them all under the same heading.*/
#include<stdio.h>
void sort (int n,int m, int arr[n][m]){
    int temp,j,temp2,temp3;
    for(int i=0;i<n-1;i++){
        j=i+1;
        while(arr[j-1][2]>arr[j][2]){
            temp=arr[j-1][2];
            arr[j-1][2]=arr[j][2];
            arr[j][2]=temp;
            temp2=arr[j-1][1];
            arr[j-1][1]=arr[j][1];
            arr[j][1]=temp2;
            temp3=arr[j-1][0];
            arr[j-1][0]=arr[j][0];
            arr[j][0]=temp3;
            j--;
            if(j==0){break;}
        }
    }
}
int main(){
    int y,N,flag,k=0,m=3;
    printf("Enter current year: ");
    scanf("%d",&y);
    printf("\nEnter number of employees(N): ");
    scanf("%d",&N);
    int arremployee[N][3];
    printf("\nenter %d sets of employee numbers and ages(seperated by spaces):\n",N);
    for(int i=0;i<N;i++){
        scanf("%d",&arremployee[i][0]);
        scanf("%d",&arremployee[i][1]);
    }
    for(int i=0;i<N;i++){
        arremployee[i][2]=y-arremployee[i][1]+65;
    }
    sort(N,m,arremployee);
    while(k<N){
        flag=arremployee[k][2];
        printf("Year of retirement: %d\n",arremployee[k][2]);
        printf("List of employees: ");
        while(arremployee[k][2]==flag){
        printf("%d   ",arremployee[k][0]);
        k++;
        }
        printf("\n");
    }
    return 0;
}