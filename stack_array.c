#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack{
   int top;
   unsigned capacity;
   int* array;
    
};
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity*(sizeof(int)));
    return stack;
    
}

int isFull(struct Stack* stack){
    return stack->top==stack->capacity-1;
}

int isEmpty(struct Stack* stack){
    return stack->top==-1;
}
void push(struct Stack* stack,int item){
    if(isFull(stack)){return;}
    stack->array[++stack->top]= item;
    printf("%d pushed to stack\n",item);
}
int pop(struct Stack* stack){
    if(isEmpty(stack)){return INT_MIN;}
    int item = stack->array[stack->top--];
    stack->capacity--;
    //printf("%d poped from stack\n",item);
    return item;
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