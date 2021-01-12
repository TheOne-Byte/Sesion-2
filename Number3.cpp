#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int Values;
    node *next;
} *head, *tail;

int count = 0;

node *createNode(int score){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->Values = score;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int score){
    node *temp = createNode(score);

    if (!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    count++;
}

void pushTail (int score){
    node *temp = createNode(score);
    if(!head){
        head = tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
    count++;
}

void popHead(){
    if (!head){
        return;
    }else if  (head == tail){
        free(head);
        head = tail = NULL;
    }else{
        node *temp = head->next;
        head->next = NULL;
        free(head);
        head = NULL;
    }
    count--;
}

void popTail(){
    if (!head)return;
    else if (head == tail){
        free(head);
        head = tail = NULL;
    }else{
        node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        free(tail);
        tail = temp;
    }
    count--;
}

int middle(){
    int n = count/2;
    int pilihan;
    node *curr = head;
    while(n > 0){
        pilihan = curr->Values;
        curr = curr->next;
        n--;
    }
    return pilihan;
}

int main(){

    pushHead(54);
    pushTail(97);
    pushTail(51);
    pushHead(32);
    pushTail(65);
    pushTail(103);

    printf("The Number That Is Located In The Middle Is : %d",middle());
    return 0;
}