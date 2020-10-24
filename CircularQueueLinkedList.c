#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct QNode{
    int data;
    struct QNode* next;  
};
struct QNode* createNode(int data){
    struct QNode* node = (struct QNode*)malloc(sizeof(struct QNode));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Queue{
    struct QNode *front,*rear;
};
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q-> rear = NULL;
    return q;
}


void enQueue(struct Queue* q, int data){
    struct QNode* newNode = createNode(data);
    if(q->front == NULL){
        q->front = newNode;   
    }else{
        q->rear->next = newNode;
    }
        
    q->rear = newNode;
    q->rear->next = q->front;
    
}
int deQueue(struct Queue* q){
    if(q->front == NULL)
        return INT_MIN;
        
    if(q->front == q->rear){
        int data = q->front->data;
        q->front = q->rear = NULL;
        return data;
        
    }else{  
        int data = q->front->data;
        q->front = q->front->next;
        q->rear->next= q->front;
        return data;
    }
}

void displayQueue(struct Queue* q){
    struct QNode* temp = q->front;
    printf("\nElements in Circular Queue are: "); 
    while(temp->next != q->front){
         printf("%d ", temp->data);
         temp = temp->next;
    }
   printf("%d ", temp->data);
    
}

int main(){
    struct Queue* q = createQueue();
    
   
  
    
    enQueue(q, 14); 
    enQueue(q, 22); 
    enQueue(q, 6); 
  
    
    displayQueue(q); 
  
   
    printf("\nDeleted value = %d", deQueue(q)); 
    printf("\nDeleted value = %d", deQueue(q)); 
  
  
    enQueue(q, 9); 
    enQueue(q, 20); 
    displayQueue(q); 
   
}
