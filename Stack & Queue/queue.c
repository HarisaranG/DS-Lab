#include<stdio.h>

int queue[5];
int front=-1,rear=-1;

int main() {
    int x,n;
    do {
        printf("\n1-Enqueue, 2-Dequeue, 3-Display, 4-isempty, 5-isfull, 6-Delete, 7-exit: ");
        scanf("%d",&x);
        switch(x) {
            case 1: printf("Enter the element to enqueue: ");
                    scanf("%d",&n);
                    enqueue(n);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: isempty();
                    break;
            case 5: isfull();
                    break;
            case 6: deletee();
                    break;
            case 7: exit(0);
                    break;
            default: printf("Innvalid option");
                    break;
        }
    }while(x!=7);
    return 0;
}
void enqueue(int a) {
    if(front==-1 && rear==-1) {
        front++;
        rear++;
        queue[rear]=a;
    } else if(rear>=4){
        printf("The queue is full");
    } else {
        rear++;
        queue[rear]=a;
    }
}
void dequeue() {
    if(front==-1 && rear==-1){
        printf("The queue is empty");
    }
    else if(front==rear) {
        printf("The dequeued element is %d",queue[front]);
        front=-1;
        rear=-1;
    } else {
        printf("The dequeued element is %d",queue[front]);
        front++;
    }
}

void display() {
    int i;
    if(front==-1 && rear==-1){
        printf("The queue is empty");
    } else {
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}

void isempty() {
    if(front==-1 && rear==-1){
        printf("The queue is empty");
    } else{
        printf("The queue is not empty");
    }
}

void isfull() {
    if(rear>=4){
        printf("The queue is full");
    } else {
        printf("The queue is not full");
    }
}
void deletee() {
    front=-1;
    rear=-1;
    printf("The queue is deleted");
}