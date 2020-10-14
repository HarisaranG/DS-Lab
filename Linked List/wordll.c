#include<stdio.h>
#include<stdlib.h>

struct Node {
    char ch;
    struct Node *next;
};

typedef struct Node node;
int size = 0;

void insertAtBegin(node **head, char data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> ch = data;
    newNode -> next = NULL;
    if(head == NULL){
        head = &newNode;
    } else {
        newNode -> next = *head;
        head = &newNode;
    }
}

void insertAtEnd(node **head, char data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode -> ch = data;
    newNode -> next = NULL;
    if(*head == NULL){
        head = &newNode;
    } else {
        node *temp = *head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void insert(node **head, int pos, char data){
    if(pos == 1){
        insertAtBegin(head, data);
    } else if(size <= pos){
        insertAtEnd(head, data);
    } else {
        node *temp = *head;
        int i = 0;
        while(i < pos){
            temp = temp -> next;
            ++i;
        }
        node *newNode = (node*)malloc(sizeof(node));
        newNode -> ch = data;
        newNode -> next = temp -> next;
        temp -> next = newNode;
        ++size;
    }
}

void deleteAtBegin(node **head){
    if(*head == NULL){
        return;
    } else {
        node *temp = *head;
        head = &(temp -> next);
    }
}

void deleteAtEnd(node **head){
    if(*head == NULL){
        return;
    } else {
        node *temp = *head, *secondLast = *head;
        while(temp -> next != NULL){
            secondLast = temp;
            temp = temp -> next;
        }
        secondLast -> next = NULL;
    }
}

void delete(node **head, int pos){
    if(pos == 1){
        deleteAtBegin(head);
    } else if(size <= pos){
        deleteAtEnd(head);
    } else {
        node *temp = *head, *secondLast = *head;
        int i = 0;
        while(i <= pos){
            secondLast = temp;
            temp = temp -> next;
            ++i;
        }
        secondLast -> next = temp -> next;
    }
}

void display(node **head){
    node *temp = *head;
    while(temp != NULL){
        printf("%c", temp -> ch);
    }
}

void vowels(node **head){
    if(*head == NULL){
        return;
    } else {
        int i = 0;
        node *temp = *head;
        while(temp != NULL){
            char j = temp -> ch;
            if(j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u'){
                printf("Postion %c : %d\n", j, i + 1);
            }
        }
    }
}

void characters(node **head){
    for(char a = 'A'; a <= 'Z'; ++a){
        printf("%c: ", a);
        search(head, a);
        printf("\n");
    }
}

void serach(node **head, char ele){
    node *temp = *head;
    int i = 0;
    while(temp != NULL){
        ++i;
        if(temp -> ch == ele){
            printf("%d ", i);
        }
    }
}

int main(){
    char arr[100];
    printf("Enter Name(with Initial): ");
    scanf("%s", arr);
    node *head = NULL;
    for(int i = 0; arr[i] != '\0'; ++i){
        insert(&head, i + 1, arr[i]);
    }
    display(&head);
    volwels(&head);
    characters(&head);
    node *newHead = NULL;
    node *temp = head;
    node *newTemp = newHead;
    insert(&newTemp, 1, head -> ch);
    while(temp -> next != NULL){
        int i = 1;
        while(newTemp -> ch < temp -> ch){
            ++i;
            newTemp = newTemp -> temp;
            if(newTemp -> next == NULL){
                break;
            }
        }
        insert(&newHead, i, temp -> next);
        temp = temp -> next;
    }
    head = newHead;
    display(&head);
    volwels(&head);
    characters(&head);
    reutrn 0;
}