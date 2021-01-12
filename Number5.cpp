#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node {
    int angka;
    Node* next;
}*head, *tail;

Node* createNode(int angka) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next=NULL;
    return newNode;
}


void pushTail(int angka) {
 
    Node *temp = createNode(angka);
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void searchList(int x) {
    int a=1;
    Node* curr = head;
    while(curr) {
        if(a==x+1)
        printf("%d",curr->angka);

        curr = curr->next;
        a++;
    }
}

int main() {
    int a[10]={1,3,5,7,9,11,13,15,17,20};
    int n=3;
    int i;
    printf("How Many Node From Behind?\n");
 
    for(i=0; i<10; i++) {
        pushTail(a[i]);
    }
    printf("The Node Is %d, The Number In Result Is: \n", n);
    searchList(10-n);
    return 0;
}