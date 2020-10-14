#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct namelist {
    char name[1000];
    char team[5];
    char role;          // role 'c' - captian, 'p' - normal player
    struct namelist* next;
};

//  insert in linked list
struct namelist* insert(struct namelist* head, char name[], char role, char team[]){
    if(head == NULL){
        struct namelist* temp = (struct namelist*)malloc(sizeof(struct namelist));
        strcpy(temp -> name, name);
        strcpy(temp -> team, team);
        temp -> role = role;
        temp -> next = NULL;
        head = temp;
        return head;
    } else {
        struct namelist* temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        struct namelist* cache = (struct namelist*)malloc(sizeof(struct namelist));
        strcpy(cache -> name, name);
        strcpy(cache -> team, team);
        cache -> role = role;
        cache -> next = NULL;
        temp -> next = cache;
        return head;
    }
}

void display(struct namelist* head){
    if(head == NULL){
        return;
    }
    struct namelist* temp = head;
    while (temp != NULL) {
        printf("%s %c %s\n", temp -> name, temp -> role, temp -> team);
        temp = temp -> next;
    }
    
}

struct namelist* delete(struct namelist* head, struct namelist* tobedeleted){
    if(head == NULL){
        return NULL;
    } else if(tobedeleted == head) {
        head = head -> next;
        return head;
    } else {
        struct namelist* temp = head;
        struct namelist* cache = NULL;
        while(temp != NULL){
            if(temp == tobedeleted && cache != NULL){
                cache -> next = temp -> next;
                return head;
            }
            cache = temp;
            temp = temp -> next;
        }
        return NULL;
    }
}

int main() {
    struct namelist* head = NULL;
    struct namelist* temp = NULL;
    struct namelist* cache = NULL;
    char rednames[5][1000] = {"Adhi", "Hari", "Vinoth", "Jhon", "Zane"}, 
    bluename[5][1000] = {"Aravind", "Chiti", "Santhosh", "Pierce", "Zaniel"};
    //  inserting red team name
    for(int i = 0; i < 5; ++i){
        if(i == 0){
            head = insert(head, rednames[i], 'c', "red");
        } else {
            head = insert(head, rednames[i], 'p', "red");
        }
    }
    if(head == NULL){
        printf("NULL");
    }
    printf("Intial Red Team List: \n");
    display(head);
    printf("\nBlue + Red Team List:\n");
    struct namelist* newhead = NULL;
    for(int i = 0; i < 5; ++i){
        if(i == 0){
            newhead = insert(newhead, rednames[i], 'c', "red");
            newhead = insert(newhead, bluename[i], 'c', "blue");
        } else {
            newhead = insert(newhead, rednames[i], 'p', "red");
            newhead = insert(newhead, bluename[i], 'p', "blue");
        }
    }
    head = newhead;
    display(head);
    printf("\nPosition Query (2, 5, 7, 10): \n");
    temp = head;
    int i = 0;
    while (temp != NULL) {
        if(i + 1 == 2 || i + 1 == 5 || i + 1 == 7 || i + 1 == 10){
            printf("%d: %s %c %s\n",i + 1, temp -> name, temp -> role, temp -> team);
        }
        temp = temp -> next;
        ++i;
    }
    printf("\nPlayer Starting with 'S': \n");
    i = 0;
    temp = head;
    while (temp != NULL) {
        if((temp -> name)[0] == 'S'){
            printf("%d: %s %c %s\n",i + 1, temp -> name, temp -> role, temp -> team);
        }
        temp = temp -> next;
        ++i;
    }
    printf("\nList After deletion: \n");
    temp = head;
    while (temp != NULL){
        if(!strcmp(temp -> team, "red")){
            head = delete(head, temp);
        }
        temp = temp -> next;
    }
    display(head);
}