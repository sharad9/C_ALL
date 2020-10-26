#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
    unsigned capacity;
    int front,rear,size;
    int *array;
};
struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front =  queue->size =  0;
    queue->rear = capacity-1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int)); 
    return queue;
}
int isFull(struct Queue* queue){
    return  queue->size == queue->capacity;
}
int isEmpty(struct Queue* queue){
    return queue->size == 0;
}
void enqueue(struct Queue* queue, int data){
    if(isFull(queue)){printf("Queue is FULL\n");return INT_MIN;}
    queue->size = queue->size<queue->capacity? queue->size+1: queue->size;
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = data;
    printf("%d enqueued to queue\n", data);
}
int dequeue(struct Queue* queue){
    if(isEmpty(queue)){printf("Queue is EMPTY\n");return INT_MIN;}
    queue->size = queue->size>0? queue->size-1: queue->size;
    int data = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    return data;
}
int Front(struct Queue* queue){
    if(isEmpty(queue)){printf("Queue is EMPTY\n");return INT_MIN;}
    return queue->array[queue->front];
}
int Rear(struct Queue* queue){
    if(isEmpty(queue)){printf("Queue is EMPTY\n");return INT_MIN;}
    return queue->array[queue->rear];
}
void displayAll(struct Queue* queue){
    printf("Elements in the queue :\n");
    if(isEmpty(queue)){printf("Queue is EMPTY\n");return INT_MIN;}
    
    for(int i = 0; i<queue->size;i++){
        printf("   _ %d  \n",queue->array[i]);
    }
    printf("");
        
}
int main(){
    struct Queue* queue = createQueue(3);
    enqueue(queue,1);
    enqueue(queue,2);
    printf("Front item is %d\n", Front(queue)); 
    printf("Rear item is %d\n", Rear(queue)); 
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("Front item is %d\n", Front(queue)); 
    printf("Rear item is %d\n", Rear(queue)); 
    enqueue(queue,3);
    enqueue(queue,4);
    printf("Front item is %d\n", Front(queue)); 
    printf("Rear item is %d\n", Rear(queue)); 
    displayAll( queue);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("%d dequeued from queue\n\n",dequeue(queue));
    displayAll( queue);
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    enqueue(queue,4);
    displayAll(queue);
    printf("Front item is %d\n", Front(queue)); 
    printf("Rear item is %d\n", Rear(queue)); 
  
    return 0;
}
