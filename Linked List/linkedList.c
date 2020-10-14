#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void deleteMiddleNode(struct node **head, int position) {
    int i;
    struct node *toDelete, *prevNode; 
    if(*head == NULL) {
        printf("List is already empty.");
    } else {
        toDelete = *head;
        prevNode = *head;
        for(i = 2; i <= position; i++){
            prevNode = toDelete;
            toDelete = toDelete->next;
            if(toDelete == NULL)
                break;
        }
        if(toDelete != NULL) {
            if(toDelete == head)
                head = &(head->next);
            prevNode->next = toDelete->next;
            toDelete->next = NULL;
            free(toDelete);
        } else {
            printf("Invalid position unable to delete.");
        }
    }
}

void deleteFirstNode(struct node **head) {
    struct node *toDelete;
    if(*head == NULL) {
        printf("List is already empty.");
    } else {
        toDelete = *head;
        head = &(head->next);
        printf("\nData deleted = %d\n", toDelete->data);
        free(toDelete);
    }
}

void deleteLastNode(struct node **head) {
    struct node *toDelete, *secondLastNode; 
    toDelete = *head;
    secondLastNode = *head;
    while(toDelete->next != NULL) {
       secondLastNode = toDelete;
       toDelete = toDelete->next;
    }
    if(toDelete == head) {
       head = NULL;
    } else {
       secondLastNode->next = NULL;
    }
    free(toDelete);
}

int main(){
    int ch;
    struct node* list;
    create(&list);
    do {
        printf("Menu:\n\t1.Insert\n\t2.Delete\n\t3.Find\n\t4.FindKth\n\t5.Print List\n\t6.Is Full\n\t7.Is Empty");
        printf("\nEnter Option: ");
        scanf("%d", &ch);
        int pos, data;
        switch(ch){
            case 1:
                printf("Enter Position and Data: ");
                scanf("%d %d", &pos, &data);
                insert(&list, pos, data);
                break;
            case 2:
                printf("Enter Position: ");
                scanf("%d", &pos);
                delete(&list, pos);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &pos);
                find(&list, pos);
                break;
            case 4:
                printf("Enter Position: ");
                scanf("%d", &pos);
                findKth(&list, pos);
                break;
            case 5:
                printList(&list);
                break;
            case 6:
                printf("%d", isEmpty(&list));
                break;
            case 7:
                printf("%d", isFull(&list));
                break;
        }
        printf("Do you want to continue ?(y(1)/n(0)): ");
        scanf("%d", &ch);
    } while (ch != 0);
    return 0;
}