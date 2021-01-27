#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Stack{
    int data;
    struct Stack *next;
};


struct Stack *top = NULL;
struct Stack *list = NULL;


struct Stack* createNode(int data){
    struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack)); 
    node->data = data;
    node->next = NULL;
    return node;
}


int isEmpty(){
    return !top;
}


void push (int data){
    struct Stack* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
    printf("pushed %d \n",top->data);
}


int pop (){
    if(isEmpty(top)){printf("UNDERFLOW");return ;}
    int data = (top)->data;
    top = top->next;
    printf("poped %d \n",data);
    return data;
}

void traverse (){
  for(struct Stack* temp = top;temp != NULL;temp = temp->next){
    printf("%d \n",temp->data);
  }
}
void main(){
   
    push(10);
    push(20);
    push(30);
    push(40);;
    traverse ();
    pop();
    pop();
    pop();
   traverse ();
}
