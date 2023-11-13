/*
 * File: stack.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program implements a Stack ADT
 */

#include<stdio.h>
#include<stdlib.h>

// Build a Stack Abstract Data structure and perform operations on it 
// Operations:
// 1. Push
// 2. Pop
// 3. Peek
// 4. isEmpty
// 5. isFull
// 6. display

typedef struct Stack
{
    int top;
    unsigned size;
    char *array;

}stacks;

// 0 -> display
void display(struct Stack* stack){
    int i=stack->top-1;
    printf("The elements of the stack are(top to bottom):\n");
    while(i>=0){
        printf("%c\n",stack->array[i]);
        i--;
    }
}

struct Stack* initialize_stack(unsigned size){
    stacks* stak=malloc(sizeof(stacks));
    stak->size=size;
    stak->array=calloc(size,sizeof(char));
    stak->top=0;
    return stak;
}
void destruct(stacks* s){
    free(s);
}
// 2 -> isFull
// TODO: Complete the function. It should check if the stack provided to it is full
int isEmpty(struct Stack* stack){
    if(stack->top==0){
        return 1;
    }
    return 0;
}

// 3 -> isEmpty
// TODO: Complete the function. It should check if the stack provided to it is empty
int isFull(struct Stack* stack){
    if(stack->top==stack->size){
        return 1;
    }
    return 0;
}

// 4 -> push
void push(struct Stack *stack, char item){
    if(!isfull(stack)){
        stack->array[stack->top]=item;
        stack->top++;
    }
    else{
        printf("Stack is full!\n");
    }
}

// 5 -> peek
void peek(struct Stack* stack){
    if(!isEmpty(stack)){
        printf("The element at top of the stack is: %c\n",stack->array[stack->top-1]);
    }
    else{
        printf("stack is empty!\n");
    }
}

// 6 -> pop
// TODO: Complete the function. It should pop an element from the stack and return it. For an empty stack, it should throw an error message
char pop(struct Stack* stack){
    if(!isEmpty(stack)){
        stack->top--;
        return stack->array[stack->top];
    }
    else{
        printf("stack is empty!\n");
        return 0;
    }
}

