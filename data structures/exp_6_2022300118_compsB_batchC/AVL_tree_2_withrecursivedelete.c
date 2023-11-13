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

typedef struct AVLNode {
    char* data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

int max(int a, int b){
    if(a>=b){return a;}
    return b;
}
int abs(int a){
    if(a>=0){return a;}
    return -1*a;
}
void remove_newline(char* str){//function to remove newline from fgets input
    char* ptr = strchr(str, '\n'); 
    if (ptr) { 
        *ptr = '\0'; 
    }
}
// complete this function
AVLNode* createNode(char* data){
    AVLNode* newnode=malloc(sizeof(AVLNode));
    int len=strlen(data);
    newnode->data=malloc((len+1)*sizeof(char));
    strcpy(newnode->data,data);
    newnode->left=newnode->right=NULL;
    newnode->height=0;
    return newnode;
}

// Display the in-order traversal of the Tree
void displayAVLTree(AVLNode* root){
    if(root==NULL){return;}
    displayAVLTree(root->left);
    printf("%s ",root->data);
    displayAVLTree(root->right);
}

void displaypreorder(AVLNode* root){
    if(root==NULL){return;}
    printf("%s ",root->data);
    displaypreorder(root->left);
    displaypreorder(root->right);
}

void displaytree(AVLNode* root, void (*dispfunc)(AVLNode* a)){
    printf("[ ");
    dispfunc(root);
    printf("]\n");
}

int getHeight(AVLNode* node){
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
    if(balance>1){
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
    root->height=getHeight(root);
    return root;
}

void insertNode(AVLNode** root, char* str){
    if(strcmp((*root)->data,str)>=0){
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
    (*root)->height=getHeight((*root));
    if(abs(getBalance((*root)))==2){
        (*root)=fixsubtree((*root),getBalance((*root)));
    }
}

void actuallydelete(AVLNode** top,AVLNode* grandparent,AVLNode* parent,AVLNode* child,int dir);

char* predecessordata(AVLNode* root){
    while(1){
        if(root->right!=NULL){
            root=root->right;
        }
        else{
            return root->data;
        }
    }
}

void deletepredecessor(AVLNode** top,AVLNode* grandparent,AVLNode* root,AVLNode* child,int dir){
    if(child->right!=NULL){
        deletepredecessor(top,root,child,child->right,1);
    }
    else{
        actuallydelete(top,grandparent,root,child,dir);
    }
    root->height=getHeight(root);
    if(abs(getBalance(root))==2){
        if(grandparent==NULL)
        (*top)=fixsubtree(root,getBalance(root));
        else{
            if(grandparent->right==root){
                grandparent->right=fixsubtree(root,getBalance(root));
            }
            else{
                grandparent->left=fixsubtree(root,getBalance(root));
            }
        }
    }
}
void actuallydelete(AVLNode** top,AVLNode* grandparent,AVLNode* parent,AVLNode* child,int dir){//dir=1 for right, 0 for left
    if(child->left==child->right){//child is a leaf
        if(dir==1){
            parent->right=NULL;
        }
        else{
            parent->left=NULL;
        }
        free(child);
    }
    else if(child->left==NULL){
        if(dir==1){
            parent->right=child->right;
        }
        else{
            parent->left=child->right;
        }
        free(child);
    }
    else if(child->right==NULL){
        if(dir==1){
            parent->right=child->left;
        }
        else{
            parent->left=child->left;
        }
        free(child);
    }
    else{
        strcpy(child->data,predecessordata(child->left));
        deletepredecessor(top,parent,child,child->left,0);
    }
    parent->height=getHeight(parent);
    if(abs(getBalance(parent))==2){
        if(grandparent==NULL)
        (*top)=fixsubtree(parent,getBalance(parent));
        else{
            if(grandparent->right==parent){
                grandparent->right=fixsubtree(parent,getBalance(parent));
            }
            else{
                grandparent->left=fixsubtree(parent,getBalance(parent));
            }
        }
    }
}

void findparent(AVLNode** top,AVLNode* parent,AVLNode* root,char* data){
    if(strcmp(root->data,data)<0){
        if(root->right!=NULL){
            if(strcmp(root->right->data,data)==0){
                actuallydelete(top,parent,root,root->right,1);
                return;
            }
            else{
                findparent(top,root,root->right,data);
            }
        }
        else{
            printf("Data not found\n");
            return;
        }
    }
    else{
        if(root->left!=NULL){
            if(strcmp(root->left->data,data)==0){
                actuallydelete(top,parent,root,root->left,0);
                return;
            }
            else{
                findparent(top,root,root->left,data);
            }
        }
        else{
            printf("Data not found\n");
            return;
        }
    }
    root->height=getHeight(root);
    if(abs(getBalance(root))==2){
        if(parent==NULL)
        (*top)=fixsubtree(root,getBalance(root));
        else{
            if(parent->right==root){
                parent->right=fixsubtree(root,getBalance(root));
            }
            else{
                parent->left=fixsubtree(root,getBalance(root));
            }
        }
    }
}

// This deletes a node with 'data' into the AVL tree
// Please ensure that your function covers all 4 possible rotation cases
void deleteNode(AVLNode** root, char* data){
    if(strcmp((*root)->data,data)!=0){
        findparent(root,NULL,(*root),data);
    }
    else{
        strcpy((*root)->data,predecessordata((*root)->left));
        deletepredecessor(root,NULL,&(**root),(&(**root))->left,0);
    }
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
    remove_newline(str);
    AVLNode* root=createNode(str);
    displaytree(root,displayAVLTree);
    while(n){
        printf("Enter 1 to insert, 2 to delete, 0 to exit\n");
        scanf("%d",&n);
        while((getchar())!='\n');
        if(n==0){break;}
        if(n==1){
            printf("Enter string to insert:");
            fgets(str,101,stdin);
            remove_newline(str);
            insertNode(&root,str);
            printf("The inrorder traversal of the tree is:\n");
            displaytree(root,displayAVLTree);
            printf("The preorder traversal of the tree is:\n");
            displaytree(root,displaypreorder);
        }
        if(n==2){
            printf("Enter data to delete: ");
            fgets(str,101,stdin);
            remove_newline(str);
            deleteNode(&root,str);
            printf("The inrorder traversal of the tree is:\n");
            displaytree(root,displayAVLTree);
            printf("The preorder traversal of the tree is:\n");
            displaytree(root,displaypreorder);
        }
        if(n==0){
            break;
        }
    }
    freeAVLTree(root);
}