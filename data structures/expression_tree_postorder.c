/*
 * File: expression_tree_postorder.c
 * Author: Siddhartha Chandra
 * Email: siddhartha_chandra@spit.ac.in
 * Created: October 17, 2023
 * Description: Create an expression tree from a postorder traversal. 
 *  Additionally, add function to evaluate a given expression tree
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.c"
//The program assumes that the given input is a valid postfix expression, error handling has not been done. The 
//input string does not contain any spaces, so it hac been assumed that operands are always single digit 
//integers.

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');//This function determines whether the given character is 
    //an operator or not
}

void displaytree(ExprTreeNode* root){//function for displaying the inorder traversal of the tree
    if(root==NULL){return;}
    displaytree(root->left);
    if(root->type==OPERAND){
        printf("%.2f ",root->data.operand);
    }
    else{
        printf("%c ",root->data.operation);
    }
    displaytree(root->right);
}

// Function to perform an operation on 2 operands
float perform_operation(char op, float left, float right){//function to return value of an operation
    switch (op) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                if (right != 0) {
                    return left / right;
                } else {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
            default:
                fprintf(stderr, "Error: Unknown operator %c\n", op);
                exit(EXIT_FAILURE);
        }
}


// TODO: To be completed
ExprTreeNode *create_node(OpType op_type, Data data){//function to create a new node and return it
    ExprTreeNode* newnode=malloc(sizeof(ExprTreeNode));//allocates memory for the node using malloc
    if(op_type==1)//sets the "type" field of the node
        newnode->type=OPERAND;
    else
        newnode->type=OPERATOR;
    newnode->data=data;
    newnode->left=newnode->right=NULL;//initialises the pointers to the left and right subtrees to NULL
    return newnode;
}

ExprTreeNode* wrapper_create_node(char c){//The newnode function requires two parameters, optype and data, this 
//function takes a character, determines the value of optype and data and passes it to the create node function 
//to create a new node.
    OpType type;
    Data dat;
    if(isOperator(c)){
        type=OPERATOR;
        dat.operation=c;
    }
    else{
        type=OPERAND;
        dat.operand=(c-'0');
    }
    ExprTreeNode* retval=create_node(type,dat);
    return retval;
}

// TODO: To be completed
// NOTE: Use the stack 'display' in this function to display stack state right after a given character in the 
//expression has been processed.
// Do this for all characters of the expression string
ExprTreeNode *create_ET_from_postfix(char *postfix_expression){
// This functions iterates through the postfix expression right to left. A postfix expression is just the 
// postorder traversal of the expression tree the expression. thus, the last element of the postfix expression 
// is the node, the one after that the right child and so on, until we encounter our first operand, since we 
// know that operands must be leaves, once we encounter an operand, we insert the next character as the left 
// child. if the left child is an operator, we then set it as our current node and follow the same steps of 
// inserting new elements to the right. whever we encounter a left leaf, we pop our stack of previously visited
//  nodes and set it as our current node. we push every node into the stack after assigning it a left child, 
//  though nodes with 2 children are not pushed, as they won't be able to accomodate another left child, so the
//   do not need to be visited once again.

    int index=strlen(postfix_expression)-1;
    Stack* nodestack=initialize_stack(index+1);
    ExprTreeNode* root=wrapper_create_node(postfix_expression[index]);
    index--;
    ExprTreeNode* current=root;
    while(index>=0){
        if(current->right==NULL){
            if(!isOperator(postfix_expression[index])){//if right child is null and next charater is not an 
            //operator, attach the next 2 elements as right and left children and if the left child is an 
            //operator, make it the current node.
                current->right=wrapper_create_node(postfix_expression[index]);
                current->left=wrapper_create_node(postfix_expression[index-1]);
                index-=2;
                if(isOperator(postfix_expression[index+1])){
                    current=current->left;
                }
                else{
                    //if the left child too is an operand, pop the stack and make it the current node
                    if(!isEmpty(nodestack)){
                        current=pop(nodestack);
                    }
                    else{
                        return root;
                    }
                }
            }
            else{//if next element is an operand and right child is null, attach next element as right child, 
            // push the current element,and make the right child the new current element.
                current->right=wrapper_create_node(postfix_expression[index]);
                push(nodestack,current);
                current=current->right;
                index--;
            }
        }
        else{//if right child is not null, i.e. left child is null(the program has been written such that cases 
        //where both children are null are managed within the if else statements itself).
            if(!isOperator(postfix_expression[index])){
                current->left=wrapper_create_node(postfix_expression[index]);
                index--;
                if(!isEmpty(nodestack)){
                    current=pop(nodestack);
                }
                else{
                    return root;
                }
            }
            else{
                current->left=wrapper_create_node(postfix_expression[index]);
                index--;
                current=current->left;
            }
        }
        display(nodestack);
    }
    
    return root;
}


// TODO: To be completed
float evaluate_ET(ExprTreeNode* root){//this function evaluates the value of the expression tree, the method used is
// taken from the ppt provided on moodle.
    if(root->left==root->right){
        return root->data.operand;
    }
    else{
        char op=root->data.operation;
        float left=evaluate_ET(root->left);
        float right=evaluate_ET(root->right);
        return perform_operation(op,left,right);
    }
}

int main(){
    printf("Enter the postfix expression:\n");
    char str[101];
    fgets(str,101,stdin);//reads the string until it encounters a '\n', including the '\n'
    str[strlen(str)-1]='\0';//replace the '\n' with a '\0', since we do not need a newline character at the end of 
    //our string.
    ExprTreeNode* root=create_ET_from_postfix(str);
    printf("The inrorder traversal of the tree is:\n");
    displaytree(root);
    printf("\nThe evaluation of the tree is:\n%.2f\n",evaluate_ET(root));
}