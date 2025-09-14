#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int top = -1;
int stack[100];

void push(char x,int n){
    if(top == n-1) return;
    stack[++top] = x;
}

char pop(){
    if(top == -1) return -1;
    return stack[top--];
}

int main(){
    char s[100];
    scanf("%s",s);
    int n = strlen(s);
    printf("Expression: %s\n",s);
    bool flag = true;
    
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == '(' || c == '[' || c == '{'){
            push(c,n);
        }else{
            char popped = pop();
            if((c == ')' && popped == '(') ||
               (c == ']' && popped == '[') ||
               (c == '}' && popped == '{') ){
                   flag = true;
               }else{
                   flag = false;
               }
        }
    }
    if(flag){
        printf("Brackets are balanced");
    }else{
        printf("Brackets are not balanced");
    }
}