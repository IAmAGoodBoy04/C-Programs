
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; 
    struct Node *next;
    } Node;

int main(){
    int *arr;
    arr=malloc(5*sizeof(int));
    arr[3]=6;
    printf("%p\n",&arr[3]);

return 0;
}