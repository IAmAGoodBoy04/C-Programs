#include<stdio.h>
int main(){
    int i,n,a,m=0;
    printf("enter number whose table is to be printed\n");
    scanf("%d",&n);
    printf("enter number of terms in table\n");
  
    scanf("%d", &i);
      printf("\n\n");
    for(a=1;a<=i;a++){
        m=m+n;
        printf("%d \n",m);

    }
    return 0;


}