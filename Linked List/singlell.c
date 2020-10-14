#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int data){
    if(*head == NULL){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode -> data = data;
        newNode -> next = NULL;
        *head = newNode;
    } else {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)), 
            *temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        newNode -> data = data;
        newNode -> next = NULL;
        temp -> next = newNode;
    }
}

void insertAtMiddle(struct Node **head, int data, int pos){
    struct Node *temp = *head;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL; 
    int i = 0;
    while(i < pos - 1){
        temp = temp -> next;
        ++i;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void display(struct Node *temp){
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main() {
    int n = 10;
    struct Node *head = NULL;
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0; i < n; ++i){
        insertAtEnd(&head, data[i]);
    }
    display(head);
    insertAtMiddle(&head, 11, 3);
    display(head);
    return 0;
}