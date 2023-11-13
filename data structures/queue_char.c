/*
 * File: queue.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 1, 2023
 * Description: This program implements a Queue ADT with a circular array
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// Build a Queue Abstract Data structure and perform operations on it 
// Operations:
// 1. display
// 2. isFull
// 3. isEmpty
// 4. enqueue
// 5. dequeue
// 6. front
// 7. rear


typedef struct Queue
{
    int front;
    int rear;
    unsigned size;
    char *array;
    bool prev;//this stores the previous operation performed(push or pop), which helps in ascertaining whether the queue is full or empty
    //true=pop,false=push
}que;

int isEmpty(struct Queue* queue);
char rear(struct Queue* queue);

// 0 -> Initialize
struct Queue* initialize_queue(unsigned size){
    que* queue=malloc(sizeof(que));
    queue->size=size;
    queue->array=calloc(size,sizeof(char));
    queue->rear=0;
    queue->front=0;
    queue->prev=true;
}


// 0 -> display
void display(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty!\n");
        return;
    }
    int f=queue->front;
    int r=queue->rear;
    printf("The elements in the queue(from front to rear) are:\n");
    while(true){
        printf("%c ",queue->array[f]);
        f++;
        f%=queue->size;
        if(f==r){
            break;
        }
    }
    printf("\n");
}

// 1 -> isEmpty
int isEmpty(struct Queue* queue){
    if(queue->front==queue->rear){
        if(queue->prev){
            return 1;
        }
    }
    return 0;
}

// 3 -> isFull
int isFull(struct Queue* queue){
    if(queue->front==queue->rear){
        if(!(queue->prev)){
            return 1;
        }
    }
    return 0;
}

// 4 -> enqueue
void enqueue(struct Queue *queue, char item){
    if(!isFull(queue)){
        queue->array[queue->rear]=item;
        queue->rear++;
        queue->rear%=queue->size;
        queue->prev=false;
    }
    else{
        printf("Queue if full!\n");
    }
}

// 5 -> dequeue
char dequeue(struct Queue* queue){
    if(!isEmpty(queue)){
        queue->prev=true;
        char retval=queue->array[queue->front];
        queue->front++;
        queue->front%=queue->size;
        return retval;
    }
    else{
        printf("Queue is empty!\n");
        return 0;
    }
}

// 6 -> front
char front(struct Queue* queue){
    if(!isEmpty(queue)){
        return queue->array[queue->front];
    }
    else{
        printf("Queue is empty!\n");
        return 0;
    }
}

// 7 -> rear
char rear(struct Queue* queue){
    if(!isEmpty(queue)){
        int i=queue->rear-1;
        if(i<0){
            i=queue->size-1;
        }
        return queue->array[i];
    }
    else{
        printf("Queue is empty!\n");
        return 0;
    }
}

void destruct_q(que* qu){
    free(qu);
}


//driver code


void operate(que* operand, int operator){
    if(operator==0){
        return;
    }
    else if(operator==1){
        int no;
        printf("Enter number of elements to enqueue: ");
        scanf("%d",&no);
        char temp;
        char str[no+1];
        while((getchar())!='\n');
        printf("Enter elements to enqueue (in a string):\n");
        fgets(str,no+1,stdin);
        while((getchar())!='\n');
        for(int i=0;i<no;i++){
            temp=str[i];
            enqueue(operand,temp);
        }
    }
    else if(operator==2){
        int temp=dequeue(operand);
    }
    else if(operator==3){
        printf("The element at the front of the stack is: %c\n",front(operand));
    }
    else if(operator==4){
        printf("The element at the rear of the stack is: %c\n",rear(operand));
    }
    else if(operator==5){
        display(operand);
    }
    else if(operator==6){
        if(isEmpty(operand)){printf("The queue is empty\n");}
        else{
            printf("The queue is not empty\n");
        }
    }
    else if(operator==7){
        if(isFull(operand)){printf("The queue is full\n");}
        else{
            printf("The queue is not full\n");
        }
    }
    else{
        printf("Invalid input\n");
    }
}


int main(){
    unsigned size;
    printf("Enter size of queue\n");
    scanf("%u",&size);
    que* queue=malloc(sizeof(que));
    queue=initialize_queue(size);
    int input=-1;
    while(input){
        printf("Enter\n1 to enqueue\n2 to dequeue\n3 to see front\n4 to see rear\n5 to display queue\n6 to check if empty\n7 to check if full\n0 to end program\n");
        scanf("%d",&input);
        operate(queue,input);
    }
    destruct_q(queue);
return 0;
}