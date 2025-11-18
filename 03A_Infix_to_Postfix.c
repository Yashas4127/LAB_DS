#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){ stack[++top] = x; }
char pop(){ return top == -1 ? -1 : stack[top--]; }

int priority(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='^') return 3;
    return 0;
}

int main(){
    char infix[100], postfix[100], ch;
    int i=0,k=0;

    scanf("%s", infix);

    while((ch=infix[i++])!='\0'){
        if(isalnum(ch)) postfix[k++] = ch;
        else if(ch=='(') push(ch);
        else if(ch==')'){
            while((ch=pop())!='(') postfix[k++] = ch;
        } else {
            while(top!=-1 && priority(stack[top])>=priority(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while(top!=-1) postfix[k++] = pop();
    postfix[k]='\0';

    printf("%s\n", postfix);
    return 0;
}
