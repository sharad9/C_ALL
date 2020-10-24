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
    }
        q->rear->next = newNode;
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
        q->rear = q->front;
        return data;
    }
}

void DisplayCircularQ(struct Queue* q){
    struct QNode* temp = q->front;
    printf("\nElements in Circular Queue are: "); 
    while(temp->next != q->rear){
         printf("%d ", temp->data);
         temp = temp->next;
    }
    printf("%d ", temp->data);
    
}

int main(){
    struct Queue* q = createQueue();
    enQueue(q, 10); 
    /*
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    deQueue(q); 
    printf("Queue Front : %d \n", q->front->data);
    printf("Queue Rear : %d \n", q->rear->data);
    */
}
