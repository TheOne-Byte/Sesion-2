#include<stdio.h> 
#include<stdlib.h> 
#include <string.h>

struct Node{ 
    int data; 
    struct Node* next; 
}; 

void MoveNode(struct Node** TemptRef, struct Node** Reference); 

struct Node* SortedMerge(struct Node* a, struct Node* b){ 
    struct Node trial; 
    struct Node* tail = &trial; 
    trial.next = NULL; 
    while (1){ 
        if(a == NULL){ 
            tail->next = b; 
            break; 
        } 
        else if (b == NULL){ 
            tail->next = a; 
            break; 
        } 
        if(a->data <= b->data) 
            MoveNode(&(tail->next), &a); 
        else
            MoveNode(&(tail->next), &b); 
  
        tail = tail->next; 
    } 
    return(trial.next); 
} 
  
void MoveNode(struct Node** TemptRef, struct Node** Reference){ 
    struct Node* newNode = *Reference; 
    *Reference = newNode->next; 
    newNode->next = *TemptRef; 
    *TemptRef = newNode; 
} 
void push(struct Node** head_ref, int new_data){ 
    struct Node* new_node = 
    (struct Node*) malloc(sizeof(struct Node)); 
    new_node->data  = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node; 
} 
  

void printList(struct Node *node){ 
    while (node!=NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  

int main(){ 
    struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL; 
  

    push(&a, 2); 
    push(&a, 3); 
    push(&a, 5); 
  
    push(&b, 10); 
    push(&b, 15); 
    push(&b, 20); 
    res = SortedMerge(a, b); 
    printf("The Result Of The Merged Linked List is: \n"); 
    printList(res); 
    return 0; 
} 