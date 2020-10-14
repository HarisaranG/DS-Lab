#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100000

struct stack {
    char arr[MAX_SIZE];
    int top;
};

void create(struct stack *lifo){
    lifo -> top = -1;
}

void push(struct stack *lifo, char data){
    if(lifo -> top < MAX_SIZE){
        lifo -> arr[lifo -> top] = data;
        ++lifo -> top;
    } else {
        printf("Stack Overflow");
        return;
    }
}

char pop(struct stack *lifo){
    if(lifo -> top != -1){
        char ch = lifo -> arr[lifo -> top];
        lifo -> arr[lifo -> top] = '\0';
        --lifo -> top;
        return ch;
    } else {
        printf("Stack Underflow");
        return '\0';
    }
}
int isEmpty(struct stack *lifo){
    if(lifo -> top != -1){
        return 1;
    } else {
        return 0;
    }
}

int precedence(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

int main() {
    char testcase[] = "(A+(B+(C*D))+E)";
    char ans[MAX_SIZE];
    struct stack lifo;
    create(&lifo);
    int  k = -1;
    for(int i = 0; testcase[i] != '\0'; ++i){
        char ch = testcase[i];
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
            ans[++k] = ch;
        } else if(ch == '('){
            push(&lifo, ch);
            printf("%d ", lifo.top);
        } else if(ch == ')'){
            while(!isEmpty(&lifo) && lifo.arr[lifo.top] != '('){
                ans[++k] = pop(&lifo);
            }
            if(!isEmpty(&lifo) && lifo.arr[lifo.top] != '('){
                return -1;
            } else{
                pop(&lifo);
            }
        } else {
            while(!isEmpty(&lifo) && precedence(ch) <= precedence(lifo.arr[lifo.top])){
                ans[++k] = pop(&lifo);
            }
            push(&lifo, ch);
        }
    }
    while(!isEmpty(&lifo)){
        ans[++k] = pop(&lifo);
    }
    printf("\n%s", ans);
    return 0;
}