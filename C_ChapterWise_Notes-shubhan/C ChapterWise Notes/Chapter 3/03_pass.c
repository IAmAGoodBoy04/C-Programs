#include<stdio.h>
int main(){
    int sub1,sub2,sub3;
    float mean;
    printf("enter percentage of marks obtained in the 3 subjects respectively \n");
    scanf("%d %d %d" ,&sub1,&sub2,&sub3);
    mean=(sub1+sub2+sub3)/3;
    if((mean>=40)&&(sub1>=33 && sub2>=33 && sub3>=33)){
        printf("you have passed the exam");
    }
    else{
        printf("you have failed in the exam");
    }
    return 0;

}
