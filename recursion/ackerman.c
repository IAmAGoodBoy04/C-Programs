/* Ackerman’s function is defined by:

A(m,n) =n+1 if m=0

=A(m-1,1) if m≠0 and n=0

=A (  m-1   ,   A(m,n-1)    ) if m≠0 and n≠0                      

Write a function which given m and n returns A(m,n).*/
#include<stdio.h>
int ackerman(int a,int b){
    int x;
    if(a==0){x=b+1;}
    if((a!=0) && b==0){x=ackerman(a-1,1);}
    if((a!=0) && (b!=0)){x=ackerman(a-1,ackerman(a,b-1));}
    return x;
}
int main(){
    int x;
    printf("Ackerman function table:\n\n");
    /*for formatting*/printf("       m=1         m=2         m=3\n\n");
    for(int j=1;j<=10;j++){
    /*for formatting*/if(j<10){printf("n=%d    ",j);}
    else{printf("n=%d   ",j);}
		for(int i=1;i<=3;i++){
			x=ackerman(i,j);
			printf("A(%d,%d)=%d  ",i,j,x);
			/*This part is just for formatting*/
			if(i==1){
				if(j<=7){printf("  ");}
				else if(j>7 && j<10){printf(" ");}
				}
			else if(i==2){
				if(j<=3){printf("  ");}
				else if(j>3 && j<10){printf(" ");}
				}/*till here*/
		}
		printf("\n");   
    }
	return 0;
}
