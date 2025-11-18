#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top=-1;

void push(char x){ stack[++top]=x; }
char pop(){ return top==-1?-1:stack[top--]; }

int priority(char x){
    if(x=='+'||x=='-') return 1;
    if(x=='*'||x=='/') return 2;
    if(x=='^') return 3;
    return 0;
}

void reverse(char s[]){
    int i=0,j=strlen(s)-1;
    char t;
    while(i<j){ t=s[i]; s[i]=s[j]; s[j]=t; i++; j--; }
}

void swapBrackets(char s[]){
    int i;
    for(i=0;s[i];i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
}

void infixToPostfix(char in[], char out[]){
    int i=0,k=0; char ch;
    top=-1;
    while((ch=in[i++])){
        if(isalnum(ch)) out[k++]=ch;
        else if(ch=='(') push(ch);
        else if(ch==')'){
            while((ch=pop())!='(') out[k++]=ch;
        } else {
            while(top!=-1 && priority(stack[top])>=priority(ch))
                out[k++]=pop();
            push(ch);
        }
    }
    while(top!=-1) out[k++]=pop();
    out[k]='\0';
}

int main(){
    char infix[100], rev[100], post[100];
    scanf("%s", infix);
    strcpy(rev, infix);
    reverse(rev);
    swapBrackets(rev);
    infixToPostfix(rev, post);
    reverse(post);
    printf("%s\n", post);
    return 0;
}
