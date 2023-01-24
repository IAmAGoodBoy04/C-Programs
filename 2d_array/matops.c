/* Write a program to perform Matrix Addition, Subtraction, Multiplication, Transpose of Matrix and Norm of Matrix. 
Dimensions of matrices will be decided by the user.*/
#include<stdio.h>
#include<time.h>

void print_matrix(int y,int x,int matrix[y][x]){
    int max=matrix[0][0];
    int maxdigits=0;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(matrix[i][j]>max){max=matrix[i][j];}
        }
    }
    while(max>0){
        maxdigits++;
        max=max/10;
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            printf("| %*d |",maxdigits+1,matrix[i][j]);
        }
        printf("\n");
    }
}
void print_sum_matrix(int y,int x,int matrix1[y][x],int a, int b,int matrix2[a][b]){
    int summatrix[y][x];
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            summatrix[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    print_matrix(y,x,summatrix);
}
void print_diff_matrix(int y,int x, int matrix1[y][x],int a,int b, int matrix2[a][b]){
    int diffmatrix[y][x];
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            diffmatrix[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
    print_matrix(y,x,diffmatrix);
}
void print_prod_matrix(int y,int x, int matrix1[y][x],int a,int b, int matrix2[a][b]){
    int prodmatrix[y][b];
    for(int i=0;i<y;i++){
        for(int j=0;j<b;j++){
            prodmatrix[i][j]=0;
        }
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<b;j++){
            for(int p=0;p<x;p++){
                prodmatrix[i][j]=prodmatrix[i][j]+matrix1[i][p]*matrix2[p][j];
            }
        }
    }
    print_matrix(y,b,prodmatrix);
}
void print_transpose_matrix(int y,int x,int matrix[y][x]){
    int transpose[x][y];
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            transpose[j][i]=matrix[i][j];
        }
    }
    print_matrix(x,y,transpose);
    printf("\n");
}
int print_norm_matrix(int y,int x, int matrix[y][x]){
    int norm=0,maxnorm=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            norm=norm+matrix[j][i];
        }
        if(i==0){maxnorm=norm;}
        if(norm>maxnorm){maxnorm=norm;}
    }
    return maxnorm;
}
int main(){
    int y,x,a,b,n1,n2;
    printf("Enter vertical dimensions of first matrix\n");
    scanf("%d",&y);
    printf("Enter horizontal dimensions of first matrix\n");
    scanf("%d",&x);
    printf("Enter vertical dimensions of second matrix\n");
    scanf("%d",&a);
    printf("Enter horizontal dimensions of second matrix\n");
    scanf("%d",&b);
    int matrix1[y][x];
    int matrix2[a][b];
    printf("Enter the elements of the first matrix(row by row, from left to right)\n");
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix(row by row, from left to right)\n");
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    if((y==a)&&(x==b)){
    printf("The sum of the two matrices is:\n");
    print_sum_matrix(y,x,matrix1,a,b,matrix2);
    }
    else{printf("The sum of these matrices doesnt exist\n");}
    if((y==a)&&(x==b)){
    printf("The difference of the two matrices is:\n");
    print_diff_matrix(y,x,matrix1,a,b,matrix2);
    }
    else{printf("The difference of these matrices doesnt exist\n");}
    if(x==a){
    printf("The product of the two matrices is:\n");
    print_prod_matrix(y,x,matrix1,a,b,matrix2);
    }
    else{printf("The product of these matrices doesnt exist\n");}
    printf("The transpose of the two matrices is:\n");
    print_transpose_matrix(y,x,matrix1);
    print_transpose_matrix(a,b,matrix2);
    n1=print_norm_matrix(y,x,matrix1);
    printf("The norm of matrix 1 is: %d\n",n1);
    n2=print_norm_matrix(a,b,matrix2);
    printf("The norm of matrix 2 is: %d\n",n2);
    return 0;
}