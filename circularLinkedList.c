#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node{
    int data;
    struct Node* next;
};


struct Node* createNode(int data){
    
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    
    return node;
};


struct List{
    struct Node* head;
    struct Node* temp;
};

struct List* createCirLinkedList(){
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    list->temp = NULL;
    return list;
};

void add(struct List* l ,int data){
    
    struct Node* n = createNode(data);
    
    if(l->head == NULL){
        l->head = n;
        l->temp = n;
        
    }else{
        l->temp->next = n;
        l->temp = n;
        n->next = l->head;
    }
    
}

void popAll(struct List* l ){
    
    struct Node* p = l->head;
    
    while(p->next != NULL){
        
        printf("%d",p->data);
       
        if(p->next  == l->head){break;}
        
         
         p = p->next;
    }
    
}

void main(){
    
    struct List* l = createCirLinkedList();
    
    add(l,1);
    add(l,2);
    add(l,3);
    add(l,4);
    popAll(l);
    
}
