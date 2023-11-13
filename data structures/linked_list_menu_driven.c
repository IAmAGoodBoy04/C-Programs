// Create a Linked List ADT using the Struct 'Node'. 
// The Linked List should support all operations that are listed as functions in this file

#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data; 
    struct Node *next;
    } Node;


// create a LinkedList node with 'data'
Node* create_node(int data){
    Node* genesis_node=malloc(sizeof(Node));
    genesis_node->data=data;
    genesis_node->next=NULL;
    return genesis_node;
}

// pos=-1 indicates insert at end
// pos=0 indicates add at beginning
// This creates a new LinkedList node and inserts it at position 'pos' in the current linked list originating from head
void insert_at_pos(Node **head, int pos, int data){
    Node* iterator=*(head);
    Node* temp;
    Node* prevnode=NULL;
    if(pos<0){pos=INT_MAX;}
    for(int i=0;i<pos;i++){
        prevnode=iterator;
        temp=iterator->next;
        if(temp==NULL){
            pos=-1;
            break;
        }
        iterator=temp;
    }
    if(pos<0){
        iterator->next=malloc(sizeof(Node));
        iterator=iterator->next;
        iterator->data=data;
        iterator->next=NULL;
    }
    else if(pos==0){
        Node* newhead=malloc(sizeof(Node));
        newhead->data=data;
        newhead->next=iterator;
        head=&newhead;
    }
    else{
        Node* newnode=malloc(sizeof(Node));
        newnode->data=data;
        newnode->next=iterator;
        prevnode->next=newnode;
    }
}

// pos=-1 indicates delete last node
// pos=0 indicates delete first node
// This deletes the LinkedList node at position 'pos' in the current linked list originating from head
void delete_at_pos(Node **head, int pos){
    Node* iterator=*(head);
    if(iterator->next==NULL){
        printf("Cannot delete only element in the list\n");
        return;
    }
    Node* temp;
    Node* prevnode=NULL;
    if(pos<0){pos=INT_MAX;}
    for(int i=0;i<pos;i++){
        temp=iterator->next;
        if(temp==NULL){
            pos=-1;
            break;
        }
        prevnode=iterator;
        iterator=temp;
    }
    if(pos<0){
        free(iterator);
        prevnode->next=NULL;
    }
    else if(pos==0){
        *head=iterator->next;
        free(iterator);
    }
    else{
        prevnode->next=iterator->next;
        free(iterator);
    }
}

// delete linkedlist node with first occurrence of given value from linked list originating from 'head'
void delete_by_value(Node **head, int value){
    Node* prevnode=*(head);
    if(prevnode->data==value){
        head=&(prevnode->next);
        free(prevnode);
        return;
    }
    while(1){
        if(prevnode->next==NULL){
            printf("This value does not exist in the list\n");
            return;
        }
        if(prevnode->next->data==value){
            Node* temp=prevnode->next;
            prevnode->next=temp->next;
            free(temp);
            return;
        }
        prevnode=prevnode->next;
    }
}


// gets the node at position 'pos' in linkedlist originating from 'head'
// return 'null' if no node found along with informative message
Node* get_node_at_pos(Node **head, int pos){//assuming 0 based indexing
    int isnull=0;;
    Node* iterator=*(head);
    for(int i=0;i<pos;i++){
        if(iterator->next!=NULL)
        iterator=iterator->next;
        else{
            isnull=1;
            break;
        }
    }
    if(!isnull){
        return iterator;
    }
    else{
        printf("This index doesn't exist in the list\n");
        return NULL;
    }
}

// Return the node with the first occurrence of value
// return 'null' if no node found along with informative message
Node* find_first(Node **head, int value){
    Node* iterator=*(head);
    while(iterator->data!=value){
        iterator=iterator->next;
        if(iterator==NULL){
            printf("This value doesn'e exist in the list\n");
            return NULL;
        }
    }
    return iterator;
}

// display entire linked list, starting from head, in a well-formatted way
void display(Node *head){
    Node* iterator=head;
    while(iterator!=NULL){
        printf("%d ",iterator->data);
        iterator=iterator->next;
    }
    printf("\n");
}


// deallocate the memory being used by the entire linkedlist, starting from head
void free_linkedlist(Node *head){
    Node* current=head;
    Node* next=current->next;
    while(next!=NULL){
        free(current);
        current=next;
        next=current->next;
    }
    free(current);
}


// reverse a linkedlist - reverse a given linked list
Node* reverse(Node *head){
    Node* next=head->next;
    if(next==NULL){
        return head;
    }
    head->next=NULL;
    Node* current=head;
    Node* twoahead=next->next;
    while(twoahead!=NULL){
        next->next=current;
        current=next;
        next=twoahead;
        twoahead=next->next;
    }
    next->next=current;
    head=next;
    return head;
}

int main(){
    printf("Enter data for head of list\n");
    int data,pos;
    scanf("%d",&data);
    Node* head=create_node(data);
    int choose=1;
    while(choose){
        printf("Enter\n1.To insert into list\n2.To delete by position\n3.To delete by value\n4.To get node at pos\n5.Find first occurence of value\n6.Display list\n7.Reverse list\n8.Free list\nanything else To exit\n");
        scanf("%d",&choose);
        switch(choose){
            case 1:
            printf("Enter value to insert into list and position to insert it at(-1 for inserting at end)\n");
            scanf("%d%d",&data,&pos);
            insert_at_pos(&head,pos,data);
            break;
            case 2:
            printf("Enter position to delete(-1 for end)\n");
            scanf("%d",&pos);
            delete_at_pos(&head,pos);
            break;
            case 3:
            printf("Enter value to delete from list(only first occurence will be deleted)\n");
            scanf("%d",&data);
            delete_by_value(&head,data);
            break;
            case 4:
            printf("Enter position to fetch node from\n");
            scanf("%d",&pos);
            Node* temp=get_node_at_pos(&head,pos);
            if(temp!=NULL)
            printf("The fetched node had data: %d\n",temp->data);
            break;
            case 5:
            printf("Enter a value to get node with the first occurence of that value\n");
            scanf("%d",&data);
            Node* templ= find_first(&head,data);
            if(templ!=NULL)
            printf("The fetched node had data: %d\n",templ->data);
            break;
            case 6:
            printf("The list from head to tail is:\n");
            display(head);
            break;
            case 7:
            head=reverse(head);
            printf("The reversed list is:\n");
            display(head);
            break;
            case 8:
            free_linkedlist(head);
            choose=0;
            break;
            default: 
            choose=0;
            break;
        }
    }
    free_linkedlist(head);
}