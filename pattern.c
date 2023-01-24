#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,m=0;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int arr[2*n-1][2*n-1];
    for(int x=0;x<2*n-1;x++){
        for(int i=0, j=n; i<n, j>0; i++, j--){
        arr[x][i]=j;
        arr[x][2*n-1-i-1]=arr[x][i];
        }
    }
    for(int a=n;a<2*n-1;a++){
        for(int b=n-1;b<a;b++){
          arr[a][b]=arr[a][b]+m-(b-n); 
        }
        m++;
    }
    for(int c=n;c<2*n-1;c++){
        for(int i=0;i<n;i++){
            arr[c][i]=arr[c][2*n-1-i-1];
        }
    }
    for(int i=0;i<2*n-1;i++){
        for(int c=0;c<n;c++){
            arr[c][i]=arr[2*n-1-c-1][i];
        }
    }
    for(int k=0;k<2*n-1;k++){
        for(int l=0;l<2*n-1;l++){
            printf("%d ",arr[k][l]);
        }
        printf("\n");
    }
    
    return 0;
}