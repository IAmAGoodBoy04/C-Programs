/*
 * File: max_heap.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: November 5, 2023
 * Description: Create a max-heap ADT using array and implement various operations
 */


//We will be assuming 1 based indexing in the heap array


#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>

// Define MaxHeap ADT
typedef struct {
    int *array;
    int size;
    int capacity;
} MaxHeap;

void swap(int *a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

/// @brief Creates an empty max-heap of size 'capacity'
/// @param capacity - max size of heap
/// @return Pointer to MaxHeap
MaxHeap *initHeap(int capacity){
    MaxHeap* newheap=malloc(sizeof(MaxHeap));
    newheap->capacity=capacity;
    newheap->size=0;
    newheap->array=calloc(newheap->capacity+1,sizeof(int));
    return newheap;
}

// Delete and free the max-heap structure
void destroyHeap(MaxHeap* heap){
    free(heap->array);
    free(heap);
}

/// @brief This restores the heap-order property for max-heap array at index 'i'
/// @param heap 
/// @param i - index of the max-heap array, which might potentialy be breaking the heap order
void heapify(MaxHeap* heap, int i){
    int *parent,*left,*right;
    parent=heap->array+i;
    if(2*i<=heap->size){
        left=heap->array+2*i;
    }
    else{left=NULL;}
    if((2*i+1)<=heap->size){
        right=heap->array+(2*i+1);
    }
    else{right=NULL;}
    if(left==NULL && right==NULL){
        return;
    }
    if(left==NULL){
        if(*right>*parent){
            swap(parent,right);
            heapify(heap,2*i+1);
        }
        else{return;}
    }
    else if(right==NULL){
        if(*left>*parent){
            swap(parent,left);
            heapify(heap,2*i);
        }
        else{return;}
    }
    else{
        int *max;
        if(*parent>*left){max=parent;}
        else{max=left;}
        if(*right>*max){max=right;}
        if(max==parent){return;}
        if(max==right){
            swap(right,parent);
            heapify(heap,2*i+1);
        }
        else{
            swap(left,parent);
            heapify(heap,2*i);
        }
    }
}

/// @brief This inserts a value into a max-heap
/// @param heap 
/// @param value 
void insert(MaxHeap* heap, int value){
    if(heap->size==heap->capacity){
        printf("Heap is full!\n");
        return;
    }
    heap->size++;
    heap->array[heap->size]=value;
    int parent=heap->size/2;
    while(parent>=1){
        heapify(heap,parent);
        parent=parent/2;
    }
}

// displays the max element in the MaxHeap array
void peek_max(MaxHeap* heap){
    if(heap->size==0){
        printf("Heap is empty!\n");
        return;
    }
    printf("The maximum element in the given MaxHeap array is: %d\n",heap->array[1]);
}

// extracts the max element from the MaxHeap array
int extractMax(MaxHeap* heap){
    int retval=heap->array[1];
    heap->array[1]=heap->array[heap->size];
    heap->size--;
    if(heap->size>1){
        heapify(heap,1);
    }
    return retval;
}


/// @brief - Display the given MaxHeap in a visually clear way.
/// @param heap 
/// @param stop_idx - This index in the MaxHeap array corresponds to the last item of the heap
void display_heap(MaxHeap* heap, int stop_idx){
    printf("[");
    for(int i=1;i<stop_idx;i++){
        printf("%d, ",heap->array[i]);
    }
    printf("%d]\n",heap->array[stop_idx]);
}



/// @brief Build max-heap using the Floyd's method. This method should call initHeap
/// @param heap 
MaxHeap *constructHeap(int *arr, int arr_length){
    MaxHeap* heap=initHeap(arr_length);
    for(int i=0;i<arr_length;i++){
        heap->array[i+1]=arr[i];
    }
    heap->size=arr_length;
    for(int i=arr_length/2;i>=1;i--){
        heapify(heap,i);
    }

    return heap;
}


// Sorts the given MaxHeap array in ascending order. 
// Post running this function, heap->array should contain the elements in the sorted order
// NOTE: This function should not use any additional data structures
void heapSort_ascending(MaxHeap* heap){
    int initialsize=heap->size;
    swap(&(heap->array[1]),&(heap->array[heap->size]));
    heap->size--;
    for(int i=0;i<initialsize-1;i++){
        heapify(heap,1);
        swap(&(heap->array[1]),&(heap->array[heap->size]));
        heap->size--;
    }
    heap->size=initialsize;
}

int main(){
    printf("Enter capacity of heap: ");
    int cap,n;
    scanf("%d",&cap);
    MaxHeap* Heap=initHeap(cap);
    int choose=1,val;
    while(choose){
        printf("Enter\n1 for insert\n2 for extract_max\n3 for peek_max\n4 for heapsort\n5 to display heap\n6 to construct heap\n0 to exit\n");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                printf("Enter number of values to insert: ");
                scanf("%d",&n);
                printf("Enter all %d values\n",n);
                for(int i=0;i<n;i++){
                    scanf("%d",&val);
                    insert(Heap,val);
                }
                while((getchar())!='\n');//deletes any extra integers if entered
                break;
            case 2:
                if(Heap->size==0){
                    printf("Heap is empty!\n");
                }
                else{
                    val=extractMax(Heap);
                    printf("The extracted value is %d\n",val);
                }
                break;
            case 3:
                peek_max(Heap);
                break;
            case 4:
                heapSort_ascending(Heap);
                printf("The array sorted using heapsort is:\n");
                display_heap(Heap,Heap->size);
                break;
            case 5:
                printf("The heap array is as follows(starting from index 1, the first index is empty):\n");
                display_heap(Heap,Heap->size);
                break;
            case 6:
            {
                printf("Enter size of heap: ");
                scanf("%d",&n);
                int arr[n];
                printf("Enter elements of array:\n");
                for(int i=0;i<n;i++){
                    scanf("%d",&arr[i]);
                }
                MaxHeap* floyds=constructHeap(arr,n);
                printf("The constructed heap is as follows:\n");
                display_heap(floyds,n);
                break;
            }
            default:
                break;
        }
    }
    destroyHeap(Heap);

return 0;
}