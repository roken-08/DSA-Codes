#include <stdio.h>

#define MAX_SIZE 100
int front = -1;
int rear = -1;
int queue[MAX_SIZE];

void enqueue(int x){
    if(rear == MAX_SIZE-1){
        return;
    }
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = x;
    }else{
        queue[++rear] = x;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int b = 0;
        scanf("%d",&b);
        enqueue(b);
    }
    double sum = 0;
    for(int i = front; i < rear+1; i++){
        sum += queue[i];
        double avg = sum/(i-front+1);
        printf("%.2f ",avg);
    }
    
}