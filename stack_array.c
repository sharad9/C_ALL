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
    stack-> array = (int*)malloc(stack->capacity *sizeof(int));
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
/*______________________________________________________________________________________________________________________________________________*/
// C program for linked list implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

// A structure to represent a stack 
struct StackNode { 
	int data; 
	struct StackNode* next; 
}; 

struct StackNode* newNode(int data) 
{ 
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
	stackNode->data = data; 
	stackNode->next = NULL; 
	return stackNode; 
} 
struct Stack { 
    struct StackNode* root; 
};
struct Stack* createQueue() 
{ 
    struct Stack* q = (struct Stack*)malloc(sizeof(struct Stack)); 
    q->root = NULL; 
    return q; 
} 

int isEmpty(struct Queue* q) 
{ 
	return q->root==NULL; 
} 

void push(struct  Queue* q,int data) 
{ 
	struct StackNode* stackNode = newNode(data); 
	stackNode->next = q->root; 
	q->root = stackNode; 
	printf("%d pushed to stack\n", q->root->data); 
} 

int pop(struct  Queue* q) 
{ 
	if (isEmpty( q->root)) 
		return INT_MIN; 
	struct StackNode* temp = q->root; 
	q->root = q->root->next; 
	int popped = temp->data; 
	free(temp); 

	return popped; 
} 

int peek(struct  Queue* q) 
{ 
	if (isEmpty(q->root)) 
		return INT_MIN; 
	return (q->root)->data; 
} 

int main() 
{ 
	struct Stacke* stack = createStack(); 

	push(stack,10); 
	push( stack,20); 
	push( stack,30); 

	printf("%d popped from stack\n", pop(stack)); 

	printf("Top element is %d\n", peek(stack)); 

	return 0; 
} 


/*___________________________________________________________________________________________________________________________________________________*/
// C program for linked list implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 

// A structure to represent a stack 
struct StackNode { 
	int data; 
	struct StackNode* next; 
}; 
struct StackNode* root;
struct StackNode* newNode(int data) 
{ 
	struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
	stackNode->data = data; 
	stackNode->next = NULL; 
	return stackNode; 
} 

int isEmpty() 
{ 
	return !root; 
} 

void push(int data) 
{ 
	struct StackNode* stackNode = newNode(data); 
	stackNode->next = root; 
	root = stackNode; 
	printf("%d pushed to stack\n", root->data); 
} 

int pop() 
{ 
	if (isEmpty()) 
		return INT_MIN; 
	struct StackNode* temp = root; 
	root = root->next; 
	int popped = temp->data; 
	free(temp); 

	return popped; 
} 

int peek() 
{ 
	if (isEmpty()) 
		return INT_MIN; 
	return root->data; 
} 

int main() 
{ 
	struct StackNode* root = NULL;

	push( 10); 
	push( 20); 
	push( 30); 

	printf("%d popped from stack\n", pop()); 

	printf("Top element is %d\n", peek()); 

	return 0; 
} 

