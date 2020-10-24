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
    struct QNode* temp = createNode(data);
    if(q->rear == NULL){
        q->rear = q->front = temp;   
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void deQueue(struct Queue* q){
    if(q->front == NULL)
        return;
    q->front = q->front->next;
   
    if(q->front == NULL){
        q->rear = NULL;
    }
}
int main(){
    struct Queue* q = createQueue();
    enQueue(q, 10); 
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    deQueue(q); 
    printf("Queue Front : %d \n", q->front->data);
    printf("Queue Rear : %d \n", q->rear->data);
}
