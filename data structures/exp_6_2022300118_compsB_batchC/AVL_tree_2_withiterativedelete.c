// Create an AVLNode ADT and complete the following functions:
// 1. createNode  
// 2. displayAVLTree 
// 3. getHeight 
// 4. rotateRight
// 5. rotateLeft
// 6. getBalance
// 7. delete
// 8. freeAVLTree

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct AVLNode {//description of node of an AVL tree which holds strings
    char* data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

int max(int a, int b){//function to find max of two integers
    if(a>=b){return a;}
    return b;
}
int abs(int a){
    if(a>=0){return a;}
    return -1*a;
}
void remove_newline(char* str){//function to remove newline from fgets input
    char* ptr = strchr(str, '\n'); //strchr returns pointer to location where given character was found
    if (ptr) { 
        *ptr = '\0'; 
    }
}
// complete this function
AVLNode* createNode(char* data){//function to initialise a node containing given data
    AVLNode* newnode=malloc(sizeof(AVLNode));
    int len=strlen(data);
    newnode->data=malloc((len+1)*sizeof(char));
    strcpy(newnode->data,data);
    newnode->left=newnode->right=NULL;
    newnode->height=0;
    return newnode;
}

// Display the in-order traversal of the Tree
void displayAVLTree(AVLNode* root){//function for inorder traversal of tree
    if(root==NULL){return;}
    displayAVLTree(root->left);
    printf("%s ",root->data);
    displayAVLTree(root->right);
}

void displaypreorder(AVLNode* root){//function for preorder traversal of tree
    if(root==NULL){return;}
    printf("%s ",root->data);
    displaypreorder(root->left);
    displaypreorder(root->right);
}

void displaytree(AVLNode* root, void (*dispfunc)(AVLNode* a)){//wrapper function for adding square brackets ar the
//start and end of the traversal outputs;
    printf("[ ");
    dispfunc(root);
    printf("]\n");
}

int getHeight(AVLNode* node){//function to find height of any given node based on height of its children
//height of NULL node has been takes as -1 for calculation purposes
    if(node==NULL){return -1;}
    if(node->right!=NULL && node->left!=NULL){
        return max(node->right->height,node->left->height)+1;
    }
    else if(node->left==NULL && node->right!=NULL){
        return node->right->height+1;
    }
    else if(node->left!=NULL && node->right==NULL){
        return node->left->height+1;
    }
    else{return 0;}
}

// function for performing a right rotate
AVLNode* rotateRight(AVLNode* node){
    AVLNode* moved=node->left->right;
    AVLNode* newroot= node->left;
    newroot->right=node;
    node->left=moved;
    return newroot;
}

// function for performing a left rotate
AVLNode* rotateLeft(AVLNode* node){
    AVLNode* moved=node->right->left;
    AVLNode* newroot= node->right;
    newroot->left=node;
    node->right=moved;
    return newroot;
}
// get balance factor of given node
int getBalance(AVLNode* node){
    if(node->left==node->right){//they can be equal only when both are null
        return 0;
    }
    if(node->right==NULL){
        return -1-node->left->height;
    }
    if(node->left==NULL){
        return node->right->height+1;
    }
    return node->right->height-node->left->height;
}

AVLNode* fixsubtree(AVLNode* root,int balance){
    if(balance>1){//4 cases of rotations described here.
        if(getBalance(root->right)>=0){
            root=rotateLeft(root);
        }
        else{
            root->right=rotateRight(root->right);
            root=rotateLeft(root);
        }
    }
    else{
        if(getBalance(root->left)<0){
            root=rotateRight(root);
        }
        else{
            root->left=rotateLeft(root->left);
            root=rotateRight(root);
        }
    }
    root->left->height=getHeight(root->left);
    root->right->height=getHeight(root->right);
    root->height=getHeight(root);//set new values of heights after performing roations
    return root;
}

void insertNode(AVLNode** root, char* str){
    if(strcmp((*root)->data,str)>=0){//search for correct position to insert node at
        if((*root)->left!=NULL)
            insertNode(&((*root)->left),str);
        else
            (*root)->left=createNode(str);
    }
    else{
        if((*root)->right!=NULL)
            insertNode(&((*root)->right),str);
        else
            (*root)->right=createNode(str);
    }
    (*root)->height=getHeight((*root));//after inserting, check for imbalance at all the nodes in the path and fix that
    if(abs(getBalance((*root)))==2){
        (*root)=fixsubtree((*root),getBalance((*root)));
    }
}
// This deletes a node with 'data' into the AVL tree
// Please ensure that your function covers all 4 possible rotation cases

int delete3cases(AVLNode* current,AVLNode* parent,int d){//this part was repeated twice in the code, 
//so i made a function to make it shorter
    if(current->left==current->right){
        if(d==1)
            parent->right=NULL;
        else
            parent->left=NULL;
        
        free(current);
    }
    else if(current->left==NULL){
        if(d==1)
            parent->right=current->right;
        else
            parent->left=current->right;
        free(current);
    }
    else if(current->right==NULL){
        if(d==1)
            parent->right=current->left;
        else
            parent->left=current->left;
        free(current);
    }
    else{return 1;}
    return 0;
}
void deleteNode(AVLNode** root, char* data){
    //the delete function works by finding the node to be deleted, delete it as it would be deleted in a binary tree,
    //then check all the nodes visited in the path to the deleted node and check for imbalances and fix them.
    //we use an array to store all the nodes previously visited, we use this array as a stack, though without formally creating an ADT
    AVLNode* nodestack[(*root)->height + 1];
    AVLNode* current=(*root);
    if(current->left==current->right){
        printf("Cannot delete only node left\n");
        return;
    }
    AVLNode* parent;
    int index=0,cmp,d=0;
    while(1){//find node to be delelted while storing all visited nodes in the stack
        if(current==NULL){
            printf("Data not found\n");
            return;
        }
        cmp=strcmp(current->data,data);
        if(cmp>0){
            nodestack[index]=current;
            index++;
            current=current->left;
        }
        else if(cmp<0){
            nodestack[index]=current;
            index++;
            current=current->right;
        }
        else{break;}
    }
    if(index>0){//this condition is used so that the index doesn't become negative if he
    // root itself was the node to be deleted
        parent=nodestack[index-1];
        if(parent->right==current){d=1;}
        else{d=0;}
    }
    int doelse=0;
    doelse=delete3cases(current,parent,d);//deletes the node if either one or both children are null,
    //or returns that no children are null
    if(doelse){//in that case, find inorder predecessor, coopy its data to the node to be deleted,
    // and then delte the node the data was copied
        AVLNode* temp=current;
        nodestack[index]=current;
        index++;
        current=current->left;
        while(current->right!=NULL){
            nodestack[index]=current;
            index++;
            current=current->right;
        }
        parent=nodestack[index-1];
        if(parent->right==current){d=1;}
        else{d=0;}
        strcpy(temp->data,current->data);
        doelse=delete3cases(current,parent,d);//an inorder predecessor would have no right child, in that 
        //case we don't have to worry about deletion of nodes with 2 children
    }
    index-=2;
    for(int i=index;i>=0;i--){//visit all previously visited nodes, check for imbalance and restore AVL property
        current=nodestack[index+1];
        parent=nodestack[index];
        current->height=getHeight(current);
        if(abs(getBalance(current))==2){
            if(parent->right==current)
                parent->right=fixsubtree(current,getBalance(current));
            else
                parent->left=fixsubtree(current,getBalance(current));
        }
    }
    (*root)->height=getHeight((*root));
    (*root)=fixsubtree((*root),getBalance((*root)));
}

// This frees the memory used by the AVL tree
void freeAVLTree(AVLNode* root){
    if(root==NULL){return;}
    if(root->left==NULL && root->right==NULL){
        free(root);
        return;
    }
    freeAVLTree(root->left);
    freeAVLTree(root->right);
}

int main(){
    int n=1;
    printf("Enter first element in tree (string):");
    char str[101];
    fgets(str,101,stdin);
    remove_newline(str);//fgets also takes the '\n' in the input, so it has to be removed
    AVLNode* root=createNode(str);//initialises root
    displaytree(root,displayAVLTree);
    while(n){
        printf("Enter 1 to insert, 2 to delete, 0 to exit\n");
        scanf("%d",&n);
        while((getchar())!='\n');//removes newline character from buffer, or else fgets will red this and ignore the string
        if(n==0){break;}
        if(n==1){
            printf("Enter string to insert:");
            fgets(str,101,stdin);
            remove_newline(str);//takes string
            insertNode(&root,str);//inserts it
            printf("The inrorder traversal of the tree is:\n");//displays inorder and preorder traversals of the tree
            //both are displayed because inorder traversal would always just be the sorted order.
            displaytree(root,displayAVLTree);
            printf("The preorder traversal of the tree is:\n");
            displaytree(root,displaypreorder);
        }
        if(n==2){//similar procedure for delete
            printf("Enter data to delete: ");
            fgets(str,101,stdin);
            remove_newline(str);
            deleteNode(&root,str);
            printf("The inrorder traversal of the tree is:\n");
            displaytree(root,displayAVLTree);
            printf("The preorder traversal of the tree is:\n");
            displaytree(root,displaypreorder);
        }
    }
    freeAVLTree(root);
}