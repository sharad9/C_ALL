#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Stack{
    int data;
    struct Stack *next;
};
struct Stack* createNode(int data){
    struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack)); 
    node->data = data;
    node->next = NULL;
    return node;
}
int isEmpty(struct Stack* root){//only check in stack
    return !root;
}
void push (struct Stack** root,int data){//changes in stack
    struct Stack* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
    printf("pushed %d \n",data);
}
int pop (struct Stack** root){//changes in stack
    if(isEmpty(*root)){printf("poped %d \n", INT_MIN);return INT_MIN;}
    int data = (*root)->data;
    *root = (*root)->next;
    printf("poped %d \n",data);
    return data;
}
int peek(struct Stack* root){//only check in stack
    if(isEmpty(root)){printf("peek element %d \n", INT_MIN);return INT_MIN;}
    int data = (root)->data;
    printf("peek element %d \n",data);
    return data;
}
void main(){
    struct Stack* root = NULL;
    push(&root,10);
    push(&root,20);
    pop(&root);
    pop(&root);
    pop(&root);
    peek(root);
}
