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
    queue->front = queue->size = 0;
    queue->rear = capacity-1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int)); 
    return queue;
}
int isFull(struct Queue* queue){
    return queue->rear == queue->capacity;
}
int isEmpty(struct Queue* queue){
    return queue->size == 0;
}
void enqueue(struct Queue* queue, int data){
    if(isFull(queue)){printf("Queue is FULL\n");return;}
    queue->rear = (queue->rear+1)%queue->capacity;
    queue->array[queue->rear] = data;
    queue->size = queue->size+1;
    printf("%d enqueued to queue\n", data);
}
int dequeue(struct Queue* queue){
    if(isEmpty(queue)){printf("Queue is EMPTY\n");return INT_MIN;}
    int data = queue->array[queue->front];
    queue->front = (queue->front+1)%queue->capacity;
    queue->size = queue->size-1;
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
int main(){
    struct Queue* queue = createQueue(10);
    enqueue(queue,1);
    enqueue(queue,2);
    enqueue(queue,3);
    printf("%d dequeued from queue\n\n",dequeue(queue));
    printf("Front item is %d\n", Front(queue)); 
    printf("Rear item is %d\n", Rear(queue)); 
  
    return 0;
}
