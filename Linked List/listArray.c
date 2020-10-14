#include<stdio.h>

#define MAX_SIZE 100000

struct ListArray {
    int data[MAX_SIZE];
    int size;
};

typedef struct ListArray la;

void create(la *head){
    head -> size = 0;
}

void insert(la *head, int pos, int data){
    for(int i = head -> size - 1; i >= pos - 1; --i){
        head -> data[i + 1] = head -> data[i];
    }
    head -> data[pos - 1] = data;
    ++head -> size;
}

void delete(la *head, int pos){
    for(int i = pos - 1; i < head -> size; ++i){
        head -> data[i] = head -> data[i + 1];
    }
    --head -> size;
}

int find(la *head, int ele){
    for(int i = 0; i < head -> size; ++i){
        if(head -> data[i] == ele){
            return i + 1;
        }
    }
    return -1;
}

int findKth(la *head, int k){
    if(k > head -> size){
        return -1;
    } else {
        return head -> data[k - 1];
    }
}

void printList(la *head){
    for(int i = 0; i < head -> size; ++i){
        printf("%d ", head -> data[i]);
    }
    printf("\n");
}

int isEmpty(la *head){
    if(head -> size == 0){
        return 1;
    } else {
        return 0;
    }
}

int isFull(la *head){
    if(head -> size == MAX_SIZE){
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int ch;
    la list;
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