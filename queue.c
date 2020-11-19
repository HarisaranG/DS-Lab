#include<stdio.h>
#include<string.h>

struct Library {
    char bookNames[100][1000];
    int front, rear;
};
typedef struct Library library;

void create(library* lib) {
    lib -> front = -1;
    lib -> rear = -1;
}

void enqueue(library* lib, char bookName[]){
    if(lib -> front == -1){
        ++(lib -> front);
        strcpy(lib -> bookNames[++(lib -> rear)], bookName);
        return;
    } else if(lib -> rear == 99){
        printf("Queue Overflow !\n");
        return;
    } else {
        strcpy(lib -> bookNames[++(lib -> rear)], bookName);
    }
}

void dequeue(library* lib){
    if(lib -> front == -1){
        printf("Queue Underflow !\n");
        return;
    } else if(lib -> front == lib -> rear){
        printf("Book which is being removed: %s\n", lib -> bookNames[lib -> front]);
        lib -> front = lib -> rear = -1;
        return;
    } else {
        printf("Book which is being removed: %s\n", lib -> bookNames[lib -> front]);
        ++(lib -> front);
    }
}

void display(library* lib){
    printf("Items in Queue:\n");
    for(int i = lib -> front; i <= lib -> rear; ++i){
        printf("%s\n", lib -> bookNames[i]);
    }
}

int main() {
    library lib;
    create(&lib);
    int choice;
    char ch;
    char bookName[1000];
    do {
        printf("Menu:\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\nPlease choose an option: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\tEnqueue\n");
                    printf("Enter a Book Name: ");
                    scanf("%s", bookName);
                    enqueue(&lib, bookName);
                    break;
            case 2: printf("\tDequeue\n");
                    dequeue(&lib);
                    break;
            case 3: printf("\tDisplay\n");
                    display(&lib);
                    break;
            default: printf("Wrong Choice!\n");
        }
        printf("Do you want to continue ? (y/n)");
        scanf("%c", &ch);
        scanf("%c", &ch);
    }while(ch == 'y');
    return 0;
}