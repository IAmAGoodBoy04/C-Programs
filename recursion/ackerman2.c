#include<stdio.h>
int ackerman(int a,int b){
    int x;
    if(a==0){x=b+1;}
    if((a!=0) && b==0){x=ackerman(a-1,1);}
    if((a!=0) && (b!=0)){x=ackerman(a-1,ackerman(a,b-1));}
    return x;
}
int main(){
    int x,m,n;
    printf("Enter value of m and n respectively\n");
    scanf("%d %d",&m,&n);
    x=ackerman(m,n);
    printf("The value of Ackerman function for %d and %d A(%d,%d) is: %d\n",m,n,m,n,x);
	return 0;
}