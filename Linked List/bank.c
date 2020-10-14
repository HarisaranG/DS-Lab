#include<stdio.h>
#include<string.h>

struct BankQueue {
    char Queue[100][100];
    int size;
};

typedef struct BankQueue BQ;

void insert(BQ *queue, char name[]){
    if(queue -> size == 100){
        printf("Queue Overflow! Try Coming Someother time :) ");
        return;
    } else {
        strcpy(queue -> Queue[queue -> size], name);
        ++(queue -> size);
    }
}

void delete(BQ *queue){
    if(queue -> size == 0){
        printf("Queue Underflow ! Everybody is cleared !\n");
        return;
    } else {
        char name[100];
        strcpy(name, queue -> Queue[0]);
        for(int i = 0; i < queue -> size - 1; ++i){
            strcpy(queue -> Queue[i + 1], queue -> Queue[i]);
        }
        --(queue -> size);
        printf("%s\n", name);
        return;
    }
}

void display(BQ *queue){
    printf("Bank Queue: \n");
    if(queue -> size == 0){
        printf("Empty !");
        return;
    } else {
        for(int i = 0; i < queue -> size; ++i){
            printf("%d. %s\n", i + 1, queue -> Queue[i]);
        }
    }
}

int main(){
    BQ queue;
    queue.size = 0;
    char choice;
    char name[100];
    int queueChoice;
    do {
        printf("Menu:\n\t1. Add person to Queue (enqueue)\n\t2.Fullfilled (dequeue)\n\t3.Display bank Queue\nPlease enter your choice: ");
        scanf("%d", &queueChoice);
        switch(queueChoice){
            case 1: printf("Enter name of the person to be added in the Bank Queue: ");
                    scanf("%s", name);
                    insert(&queue, name);
                    break;
            case 2: printf("Fullfilled Customer: ");
                    delete(&queue);
                    break;
            case 3: display(&queue);
                    break;
            default: printf("Wrong Choice\n");
                     break;
        }
        printf("Do you want to continue ? (y/n) \n");
        scanf("%c", &choice);
    } while(choice == 'y');
    return 0;
}