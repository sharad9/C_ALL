#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue{
    int data;
    struct Queue *next;
};


struct Queue *front = NULL;
struct Queue *rear = NULL;

struct Queue *list = NULL;


struct Queue* createNode(int data){
    struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue)); 
    node->data = data;
    node->next = NULL;
    return node;
}


void push (int data){
    struct Queue* newNode = createNode(data);
    
    if(rear == NULL){front = rear  =  newNode;}
    else{
    rear->next = newNode;
    rear = newNode;
    }
    
    printf("pushed %d \n",rear->data);
}

void pop (){
  if(front == NULL){printf("UNDERFLOW");return ;}
    struct Queue* temp = front;
    int data = temp->data;
    front = front->next;
    
    if (front == NULL) {
        rear = NULL; 
    }
    printf("poped %d \n",data);
    free(temp);
}

void traverse (){
  for(struct Queue* temp = front;temp != NULL;temp = temp->next){
    printf("%d \n",temp->data);
  }
}

void main(){
   
    push(10);
    push(20);
    push(30);
    traverse ();
    push(40);
    traverse ();
    pop();
    pop();
    pop();
    traverse ();
    pop();
    
    pop();
   
}
