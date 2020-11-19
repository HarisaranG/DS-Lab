#include<stdio.h>
#include<ctype.h>

int check(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    } else if (a == '[' && b == ']'){
        return 1;
    } else if(a == '{' && b == '}'){
        return 1;
    }
    return 0;
}

int main(){
    char stack[100];
    int top = -1;
    char exp[1000];
    printf("Enter a expression: ");
    scanf("%s", exp);
    int expr_valid = 0;
    int i = 0;
    while(exp[i]){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            stack[++top] = exp[i];
            expr_valid = 0;
        } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(top == -1){
                printf("Not Balanced!");
                return 0;
            }
            if(check(stack[top], exp[i])){
                --top;
            } else {
                printf("Not Balanced!");
                return 0;
            }
            expr_valid = 0;
        } else {
            if(isalnum(exp[i])){
                if(expr_valid == 1){ // Checking the validity of expression 
                    printf("Warning: Expression not valid - no opeator between two variables\n"); 
                }
                expr_valid = 1;
            } else {
                if(expr_valid == -1){
                    printf("Warning: Expression not valid - no variable between operators\n"); 
                }
                expr_valid = -1;
            }
        }
        ++i;
    }
    printf("Balanced!");
    return 0;
}