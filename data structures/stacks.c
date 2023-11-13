#include<stdio.h>
#include<stdlib.h>


typedef struct stackstruct{
    int size;
    int *stackarr;
    int *topplus1;

}stack;
void stackinit(stack* stak){
    printf("Enter size of stack: ");
    scanf("%d",&(stak->size));
    stak->stackarr=calloc(stak->size,sizeof(int));
    stak->topplus1=stak->stackarr;
}
void popstack(stack* stak){
    if(stak->topplus1!=stak->stackarr){
        stak->topplus1--;
    }
    else{
        printf("stack is empty!\n");
    }
}
void pushstack(stack* stak,int element){
    if(stak->topplus1<(stak->stackarr+stak->size)){
        *(stak->topplus1)=element;
        stak->topplus1++;
    }
    else{
        printf("Stack is full!\n");
    }
}
void peekstack(stack stak){
    printf("The element at top of the stack is: %d\n",*(stak.topplus1-1));
}
void displaytack(stack stak){
    int* sp=stak.topplus1-1;
    printf("The elements of the stack are(top to bottom):\n");
    while(sp>=stak.stackarr){
        printf("%d\n",*(sp));
        sp--;
    }
}
void stackstatus(stack stak){
    if(stak.topplus1==stak.stackarr){
        printf("Stack is empty\n");
    }
    else if(stak.topplus1==(stak.stackarr+stak.size)){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is partially filled\n");
    }
}
void operate(stack* operand, int operator){
    if(operator==0){
        return;
    }
    else if(operator==1){
        int nos,temp;
        printf("Enter number of elements to push: ");
        scanf("%d",&nos);
        printf("Enter the elements:\n");
        while(nos--){
            scanf("%d",&temp);
            pushstack(operand,temp);
        }
    }
    else if(operator==2){
        popstack(operand);
    }
    else if(operator==3){
        peekstack(*operand);
    }
    else if(operator==4){
        stackstatus(*operand);
    }
    else if(operator==5){
        displaytack(*operand);
    }
    else{
        printf("Invalid input\n");
    }
}
int main(){
    stack example;
    stackinit(&example);
    int input=-1;
    while(input){
        printf("Enter\n1 to push\n2 to pop\n3 to peek\n4 to check status of stack\n5 to display stack\n0 to end program\n");
        scanf("%d",&input);
        operate(&example,input);
    }

    return 0;
}