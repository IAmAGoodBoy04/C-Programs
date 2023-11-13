/*
 * File: dll_operations2.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: September 24, 2023
 * Description: This implements ADT for storing a DLL and performing listed operations on it. 
 * Use dummy nodes - header and trailer, in your implementation
 */


#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;


Node* create_node(int val){
    Node* header=malloc(sizeof(Node));
    Node* trailer=malloc(sizeof(Node));
    Node* first=malloc(sizeof(Node));
    header->val=trailer->val=0;
    header->next=first;
    first->prev=header;
    header->prev=trailer->next=NULL;
    first->next=trailer;
    trailer->prev=first;
    first->val=val;
    return header;
}

// pos == 0 indicates start of the DLL
// pos == -1 indicates end of the DLL
// pos == n indicates intermediate node pos
// val --> val that needs to be inserted
// is_after = true => insert after 'pos'
// is_after = false => insert after 'pos'
void insert_at_pos(Node* header, Node* trailer, int val, int pos, bool is_after) {
    Node* iter;
    if(pos==-1){
        iter=trailer->prev;
        is_after=true;
    }
    else if(pos==0){
        iter=header->next;
        is_after=false;
    }
    else{
        iter=header->next;
        for(int i=0;i<pos;i++){
            if(iter->next==trailer){
                break;
            }
            iter=iter->next;
        }
    }
    Node* new=malloc(sizeof(Node));
    new->val=val;
    if(is_after){
        new->prev=iter;
        new->next=iter->next;
        iter->next=new;
        new->next->prev=new;
    }
    else{
        new->next=iter;
        new->prev=iter->prev;
        iter->prev=new;
        new->prev->next=new;
    }
}

// pos == 0 indicates start of the DLL
// pos == -1 indicates end of the DLL
// pos == n indicates intermediate node pos
void delete_at_pos(Node* header, Node* trailer, int pos) {
    Node* iter;
    if(pos==-1)
    iter=trailer->prev;
    else{
        iter=header->next;
        for(int i=0;i<pos;i++){
            if(iter->next==trailer){
                break;
            }
            iter=iter->next;
        }
    }
    iter->prev->next=iter->next;
    iter->next->prev=iter->prev;
    free(iter);
}


// delete every alternate node starting from the first node in the list.
// ex: delete_alternates([header, 1, 2, 3, 4, trailer]) => [header, 2, 4, trailer]
void delete_alternates(Node* header){
    Node* iter=header->next;
    int i=0;
    while(true){
        if(i%2==0){
            iter->prev->next=iter->next;
            iter->next->prev=iter->prev;
            Node* temp=iter;
            iter=iter->next;
            free(temp);
        }
        else{
            iter=iter->next;
        }
        if(iter->next==NULL){
            break;
        }
        i++;

    }
}

// merge 2 sorted DLL's. Ensure that the order property is preserved
// ex: merge_sorted_dlls([1,3,5], [2,4,6]) => [1, 2, 3, 4, 5, 6]
void merge_sorted_dlls(Node* header1, Node* header2){
    Node* liter=header1->next;
    Node* riter=header2->next;
    Node* temp;
    while(true){
        if(riter->next==NULL){
            free(riter);
            break;
        }
        if(liter->val >= riter->val){
            temp=riter->next;
            riter->next=liter;
            riter->prev=liter->prev;
            liter->prev->next=riter;
            liter->prev=riter;
            riter=temp;
        }
        else{
            liter=liter->next;
        }
        if(liter->next==NULL){
            riter->prev=liter->prev;
            liter->prev->next=riter;
            free(liter);
            break;
        }
    }
}


void display(Node *header, Node* trailer){
    Node* iter=header->next;
    while(true){
        if(iter==trailer){
            break;
        }
        if(iter!=header->next){
            printf("<-->");
        }
        printf("%d",iter->val);
        iter=iter->next;
    }
    printf("\n");
}

void freelist(Node* header,Node* trailer){
    Node* temp;
    Node* iter=header->next;
    while(iter!=trailer){
        temp=iter;
        iter=iter->next;
        free(temp);
    }
    free(header);
    free(trailer);
}

void operate(Node* header,Node* trailer, int operator){
    if(operator==0){
        return;
    }
    else if(operator==1){
        int no;
        printf("Enter number of elements to insert: ");
        scanf("%d",&no);
        int temp,pos,after;
        bool isafter;
        while((getchar())!='\n');
        for(int i=0;i<no;i++){
            printf("Enter value, position, whether to insert before or after that position(0 for before, 1 for after):\n");
            scanf("%d%d%d",&temp,&pos,&after);
            isafter=after==0?false:true;
            insert_at_pos(header,trailer,temp,pos,isafter);
        }
        return;
    }
    else if(operator==2){
        printf("Enter position to delete:\n");
        int pos;
        scanf("%d",&pos);
        delete_at_pos(header,trailer,pos);
    }
    else if(operator==3){
        delete_alternates(header);
    }
    else if(operator==4){
        Node* header1;
        Node* header2;
        int temp;
        int size1,size2;
        printf("Enter the size of 2 sorted DLLs\n");
        scanf("%d%d",&size1,&size2);
        printf("Enter the elements of the first DLL\n");
        scanf("%d",&temp);
        header1=create_node(temp);
        Node* trailer1=header1->next->next;
        for(int i=0;i<size1-1;i++){
            scanf("%d",&temp);
            insert_at_pos(header1,trailer1,temp,-1,true);
        }
        printf("Enter the elements of the second DLL\n");
        scanf("%d",&temp);
        header2=create_node(temp);
        Node* trailer2=header2->next->next;
        for(int i=0;i<size2-1;i++){
            scanf("%d",&temp);
            insert_at_pos(header2,trailer2,temp,-1,true);
        }
        merge_sorted_dlls(header1,header2);
        trailer1=header1->next;
        while(trailer1->next!=NULL){
            trailer1=trailer1->next;
        }
        printf("The merged DLL is:\n");
        display(header1,trailer1);
    }
    else if(operator==5){
        display(header,trailer);
    }
    else if(operator==6){
        freelist(header,trailer);
    }
    else{
        printf("Invalid input\n");
    }
}

int main(){
    int val;
    printf("Enter the first value of the list:\n");
    scanf("%d",&val);
    Node* header=create_node(val);
    Node* trailer=header->next->next;
    int input=-1;
    while(input){
        printf("Enter\n1 to insert at position\n2 to delete at position\n3 to delete alternate elements\n4 to merge dorted DLLs\n5 to display DLL\n6 to free the DLL\n0 to end program\n");
        scanf("%d",&input);
        operate(header,trailer,input);
        if(input==6){input=0;}
    }
}