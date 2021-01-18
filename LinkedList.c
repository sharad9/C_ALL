#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct List{
    int data;
    struct List *next;
};
struct List* createNode(int data){
    struct List* node = (struct List*)malloc(sizeof(struct List)); 
    node->data = data;
    node->next = NULL;
    return node;
}
int isEmpty(struct List* start){//only check in List
    return !start;
}
void push (struct List** start,int data){//changes in List
    struct List* newNode = createNode(data);
    newNode->next = *start;
    *start = newNode;
    printf("pushed %d \n",data);
}
int pop (struct List** start,int position){
    
    if(isEmpty(*start)){printf("poped %d \n", INT_MIN);return INT_MIN;}
    
   
    struct List* tempPrev  = *start;
    struct List* tempCurrent = *start;
    for(int count = 1;count < position ; count ++ ){
        tempPrev = tempCurrent;
        tempCurrent = tempCurrent->next;
        
    }
    printf("poped %d \n",tempCurrent->data);
    tempPrev->next = tempCurrent->next;
    free(tempCurrent);
    
    
}

void main(){
    struct List* list = NULL;
    push(&list,10);
    push(&list,20);
    push(&list,108);
    push(&list,280);
    pop(&list,4);
   
  
}
