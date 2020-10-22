#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
struct Stack* createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack-> array = (int*)malloc(sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack){
    return stack->top==-1;
}
int isFull(struct Stack* stack){
    return stack->top==stack->capacity-1;
}
void push(struct Stack* stack,int data){
    if(isFull(stack)){printf("Overflow");}
    stack->array[++stack->top]=data;
    printf("%d pushed to stack\n",data);
}
int pop (struct Stack* stack){
    if(isEmpty(stack))printf("Overflow");
    return stack->array[stack->top--];
}
int peek(struct Stack* stack){
     if(isEmpty(stack))printf("Overflow");
      return stack->array[stack->top];
}
     
int main(){
    struct Stack* stack = createStack(4);
    push(stack,1);
    push(stack,2);
    
    push(stack,4);
    push(stack,5);
    printf("%d poped from stack\n",pop(stack));
    
    while(!isEmpty(stack)){
        
        printf("%d ",pop(stack));
   }
   /*
   for(int i =  stack->capacity-1;i>=0; i--){
       printf("%d ",stack->array[i]);
   }
   */
}
