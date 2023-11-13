// Given two integer arrays preorder and inorder 
// where preorder is the preorder traversal of a binary tree and 
// inorder is the inorder traversal of the same tree, construct and return the binary tree.


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  } TreeNode;

typedef struct Queue
{
    int front;
    int rear;
    unsigned size;
    TreeNode** array;
    bool prev;
}que;

struct Queue* initialize_queue(unsigned size){
    que* queue=malloc(sizeof(que));
    queue->size=size;
    queue->array=malloc(size*sizeof(TreeNode*));
    queue->rear=0;
    queue->front=0;
    queue->prev=true;
}

int isEmpty(struct Queue* queue){
    if(queue->front==queue->rear){
        if(queue->prev){
            return 1;
        }
    }
    return 0;
}

int isFull(struct Queue* queue){
    if(queue->front==queue->rear){
        if(!(queue->prev)){
            return 1;
        }
    }
    return 0;
}
 
void enqueue(struct Queue *queue, TreeNode* item){
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

TreeNode* dequeue(struct Queue* queue){
    if(!isEmpty(queue)){
        queue->prev=true;
        TreeNode* retval=queue->array[queue->front];
        queue->front++;
        queue->front%=queue->size;
        return retval;
    }
    else{
        printf("Queue is empty!\n");
        return 0;
    }
}


// complete this function
TreeNode* create_node(int val);
// complete this function
TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);

TreeNode* create_node(int val){
    TreeNode* root=malloc(sizeof(TreeNode));
    root->val=val;
    root->left=root->right=NULL;
    return root;
}

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize==0){return NULL;}
    if(preorderSize==1){
        TreeNode* root=create_node(preorder[0]);
        return root;
    }
    TreeNode* right=NULL;
    TreeNode* left;
    TreeNode* centre;
    int porder,iorder,root=preorder[0];
    preorderSize--;//for 0 based indexing
    while(preorderSize>=0){//constructs right subtree with root
        porder=preorder[preorderSize];
        iorder=inorder[preorderSize];
        if(iorder==porder){
            centre=create_node(porder);
            centre->right=right;
            right=centre;
            preorderSize--;
            continue;
        }
        centre=create_node(iorder);
        if(iorder==root){
            centre->right=right;
            preorderSize--;
            break;
        }
        left=create_node(porder);
        centre->right=right;
        centre->left=left;
        right=centre;
        preorderSize-=2;
    }
    if(preorderSize>=0){
        left=buildTree((++preorder),preorderSize+1,inorder,preorderSize+1);
        centre->left=left;
    }
    return centre;
}

void displaytree(TreeNode* root,int size,int nullatend){//level order traversal
    printf("[ ");
    int counter=0;
    que* q=initialize_queue(size);
    TreeNode* temp,left,right;
    enqueue(q,root);
    while(!isEmpty(q)){
        temp=dequeue(q);
        if(temp!=NULL){
            printf("%d ",temp->val);
            counter++;
            if(counter==size){
                break;
            }
        }
        else
        printf("NULL ");
        if(temp!=NULL){
            enqueue(q,temp->left);
            enqueue(q,temp->right);
        }
    }
    if(nullatend){
        printf("NULL ");
    }
    printf("]");
}

int main(){
    int size;
    printf("Enter number of nodes in tree: ");
    scanf("%d",&size);
    int inorder[size];
    int preorder[size];
    printf("Enter preorder traversal:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&preorder[i]);
    }
    printf("Enter inorder traversal:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&inorder[i]);
    }
    TreeNode* root = buildTree(preorder,size,inorder,size);
    int nullatend=0;
    if(inorder[size-1]!=preorder[size-1]){
        nullatend=1;
    }
    displaytree(root,size,nullatend);
    return 0;
}