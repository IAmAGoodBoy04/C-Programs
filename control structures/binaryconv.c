#include<stdio.h>
#include<math.h>
int main(){
    int i,n,bin=0,temp,dec=0,x=1,binary=0;
    printf("enter 1 for decimal to binary conversion, 2 for binary to decimal conversion\n");
    scanf("%d",&i);
    if(i==1){//decimal to binary
        printf("enter non negative decimal number\n");
        scanf("%d",&n);
        while(n>=1){
            if(n%2==1){
                binary=binary+x;
            }
            n=n/2;
            x=x*10;
        }
        printf("the binary form of the number is: %d",binary);
    }
    else if(i==2){//binary to decimal
        printf("enter binary number\n");//any number other than 0 will be considered 1
        scanf("%d",&bin);
        for(i=0;i>=0;i++){
            if(bin%10==1){dec=dec+pow(2,i);}
            bin=bin/10;
            if(bin==0){break;}
        }
        printf("the decimal form of the given number is: %d",dec);
    }
    else{//invalid choice(not 1 or 2)
        printf("invalid input\n");
    }
    return 0;
}