#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    char sk[20];
    int top;
}p;

int main()
{
    char exp[20];
    int i;
    p.top=-1;
    printf("Input the expression: ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                push(exp[i]);
            }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(exp[i]==')')
            {
                if(p.sk[p.top]=='(')
                    pop();
                else
                {
                    printf("Unbalanced expresssion");
                    break;
                }
            }
            if(exp[i]=='}')
            {
                if(p.sk[p.top]=='{')
                    pop();
                else
                {
                    printf("Unbalanced expresssion");
                    break;
                }
            }
            if(exp[i]==']')
            {
                if(p.sk[p.top]=='[')
                    pop();
                else
                {
                    printf("Unbalanced expresssion");
                    break;
                }
            }
        }
    }
    if(p.top==-1)
        printf("Balanced expression");
}
void push(char a)
{
    if(p.top>=19)
        printf("The stack is full");
    else
    {
        p.top=p.top+1;
        p.sk[p.top]=a;
    }
}
void pop()
{
    if(p.top==-1)
        printf("Stack is empty");
    else
    {
        p.top=p.top-1;
    }
}
