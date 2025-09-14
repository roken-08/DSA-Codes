#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(char x){
    if(top == MAX_SIZE-1) return;
    stack[++top] = x;
}

int pop(){
    if(top == -1) return -1;
    return stack[top--];
}

int eval(char* s){
    int result = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        char c = s[i];
        
        if(isdigit(c)){
            push(c-'0');
        }else{
            
            int x = pop();
            int y = pop();
            switch(c){
            case '+': result = y+x; break;
            case '-': result = y-x; break;
            case '*': result = y*x; break;
            case '/': result = y/x; break;
            default: return -1;
            }
            push(result);
        }
    }
    return pop();
}

int main(){
    char s[MAX_SIZE];
    scanf("%s",s);
    printf("%d",eval(s));
}