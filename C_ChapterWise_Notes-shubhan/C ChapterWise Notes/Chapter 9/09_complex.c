#include<stdio.h>
typedef struct complex{
    int real;
    int img;
}comp;
void display(comp arr[]){
    comp *a=arr;
    printf("The complex numbers are:\n");
    for(int i=0;i<5;i++){
        printf("%d+%di\n",a->real,a->img);
        a++;
    }
}
int main(){
    //use of arrow operator
    // comp *a,c1;
    // a=&c1;
    // a->img=2;
    // a->real=1;
    // printf("the complex number is: %d+%di\n",c1.real,c1.img);
    comp arr[5];
    comp *a=arr;
    for(int i=0;i<5;i++){
    printf("Enter complex number %d(only coefficients):",i+1); 
    scanf("%d %d",&a->real,&a->img);
    a++;
    }
    display(arr);
    return 0;
}