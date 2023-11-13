/*
Linked List - swap nodes in pairs


Given a linked list, swap every two adjacent nodes and return the head of the new linked list. 
You must solve the problem without modifying the values in the list's 
nodes.

Example 1:

input: 1 -> 2 -> 3 -> 4
output: 2 -> 1 -> 4 -> 3

Example 2:

input: 1 -> 2 -> 3
output: 2 -> 1 -> 3

Example 3:

input: 1 
output: 1

*/

#include "linked_list.c"


// This function should take a head node of a linked list, swap nodes in pairs, and return the new head node
Node* swap_pairs(Node* head){
    int pos=0;
    Node* temp;
    int tem;
    while(1){
        temp=get_node_at_pos(&head,pos);
        if(temp==NULL || temp->next==NULL){
            break;
        }
        tem=temp->data;
        delete_at_pos(&head,pos);
        pos++;
        insert_at_pos(&head,pos,tem);
        pos++;
    }
    return head;
}

int main(){
    int n,dat;
    printf("Enter no of elements in list\n");
    scanf("%d",&n);
    printf("Enter all the elements of the list, seperated by spaces\n");
    scanf("%d",&dat);
    Node* list=create_node(dat);
    for(int i=1;i<n;i++){
        scanf("%d",&dat);
        insert_at_pos(&list,-1,dat);
    }
    list=swap_pairs(list);
    printf("The list after swapping the pairs is:\n");
    display(list);
    free_linkedlist(list);
    return 0;
}