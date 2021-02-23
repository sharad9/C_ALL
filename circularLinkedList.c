#include <studio.h>
#include <stdlib.h>
#include <limits.h>

struct Node{
    int data;
    struct Node* next;
}
struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    
    return node;
} 

struct List{
    struct Node* head;
}

struct List* createCirLinkedList(){
    struct Node* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

void add(struct List* l ,int data){
    struct Node* n = createNode(data);
    if(l->next == NULL){
        n->next = 
    }
    
}

void main(){
    struct List* l = createCirLinkedList();
    
}

