#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    if(top == MAX_SIZE-1) return;
    stack[++top] = x;
}

char pop() {
    if(top == -1) return -1;
    return stack[top--];
}

int priority(char x) {
    if(x == '(') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return -1;
}

void convert(char* s) {
    char ans[MAX_SIZE];
    int k = 0;
    int n = strlen(s);

    for(int i=0; i<n; i++) {
        char e = s[i];

        if(isalnum(e)) {
            ans[k++] = e;
        }
        else if(e == '(') {
            push(e);
        }
        else if(e == ')') {
            while(stack[top] != '(') {
                ans[k++] = pop();
            }
            pop();
        }
        else {
            while(top != -1 && priority(stack[top]) >= priority(e)) {
                ans[k++] = pop();
            }
            push(e);
        }
    }

    while(top != -1) {
        ans[k++] = pop();
    }
    ans[k] = '\0';

    printf("%s", ans);
}

int main() {
    char s[MAX_SIZE];
    scanf("%s", s);
    convert(s);
    return 0;
}
