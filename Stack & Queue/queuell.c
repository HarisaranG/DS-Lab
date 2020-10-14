#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node*next;
};

struct node*front=NULL;
struct node*rear=NULL;

int main() {
    int x,n;
    do
 {
 printf("\n1-Enqueue, 2-Dequeue, 3-Display, 4-isempty, 5-Delete, 6-Front and rear, 7-Exit: ");
 scanf("%d",&x);
 switch(x)
 {
 case 1:
 printf("Enter the element to enqueue: ");
 scanf("%d",&n);
 enqueue(n);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 display();
 break;
 case 4:
 isempty();
 break;
 case 5:
 deletee();
 break;
 case 6:
 frontrear();
 break;
 case 7:
 exit(0);
 break;
 default:
 printf("Invalid option");
 break;
 }}
 while(x!=7);
 return 0;
}
void enqueue(int n)
{
 struct node*newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
 newnode->data=n;
 newnode->next=NULL;
 if(front==NULL && rear==NULL)
 front=rear=newnode;
 else
 {
 rear->next=newnode;
 rear=newnode;
 }
}
void dequeue()
{
 struct node*temp;
 temp=front;
 if(front==NULL && rear==NULL)
 printf("The queue is empty");
 else if(front==rear && front!=NULL)
 {
 printf("The dequeued element is %d",front->data);
 front=NULL;
 rear=NULL;
 free(temp);
 }
 else
 {
 printf("The dequeued element is %d ",front->data);
 front=front->next;
 free(temp);
 }
}
void display()
{
 struct node*temp;
 if(front==NULL && rear==NULL)
 printf("The queue is empty");
 else
 {
 temp=front;
 while(temp!=NULL)
 {
 printf("%d ",temp->data);
 temp=temp->next;
 }
 }
}
void isempty()
{
 if(front==NULL && rear==NULL)
 printf("The queue is empty");
 else
 printf("The queue is not empty");
}
void deletee()
{
 front=NULL;
 rear=NULL;
 printf("The queue is deleted");
}
void frontrear()
{
 if(front==NULL && rear==NULL)
 printf("The queue is empty");
 else
 {
 printf("The front element is %d\n", front->data);
 printf("The rear element is %d", rear->data);
 }
}