#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
    char name[1000];
    struct Node* next;
} node;

void create(node **head){
    *head = NULL;
}

void insert(node **head, char name[]){
    if(*head == NULL){
        node *temp = (node*)malloc(sizeof(node));
        strcpy(temp -> name, name);
        temp -> next = NULL;
        *head = temp;
        return;
    } else {
        node *temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        node *newNode = (node*)malloc(sizeof(node)) ;
        strcpy(newNode -> name, name);
        newNode -> next = NULL;
        temp -> next = newNode;
    }
}

void display(node **head){
    node *temp = *head;
    printf("List of names:\n");
    while(temp != NULL){
        printf("%s\n", temp -> name);
        temp = temp -> next;
    }
}

int main() {
    node *head;
    create(&head);
    int choice;
    char ch;
    char name[1000];
    do {
        printf("Menu:\n\t1.Insert\n\t2.Display\nPlease choose an option: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\tInsert\n");
                    printf("Enter a Name: ");
                    scanf("%s", name);
                    insert(&head, name);
                    break;
            case 2: printf("\tDisplay\n");
                    display(&head);
                    break;
            default: printf("Wrong Choice!\n");
        }
        printf("Do you want to continue ? (y/n)");
        scanf("%c", &ch);
        scanf("%c", &ch);
    }while(ch == 'y');
    return 0;
}