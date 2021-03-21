#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Queue{
    int data;
    struct Queue *next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

struct Queue* createNode(int data){
    struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue)); 
    node->data = data;
    node->next = NULL;
    return node;
}

void push (int data){//changes in stack
    struct Queue* newNode = createNode(data);
    
    if(rear == NULL){front = rear = newNode;}
    else{
        rear->next = newNode;
        rear = newNode;
    }
   
    printf("pushed %d \n",data);
}
int pop (){//changes in stack

   if(front==NULL){printf("poped %d \n", INT_MIN);return INT_MIN;}
    struct Queue* temp = front;
    
    int data = temp->data;
    front  = front->next;
    
    if(front == NULL){
        rear = NULL;
    }
    printf("poped %d \n",data);
    return data;
}
void display(){
    for(struct Queue* temp = front ;temp!= NULL;temp = temp->next){
        printf("%d\n",temp->data);
    }
}
void main(){
    
    push(10);
    push(11);
    push(19);
     display();
    pop();
    pop();
     pop();
      pop();
   
}
