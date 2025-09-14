#include <stdio.h>

#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (x % 2 == 0) x = x * 2;

    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if ((rear + 1) % SIZE == front) {
        printf("Queue overflow\n");
    } else {
        rear = (rear + 1) % SIZE;
        queue[rear] = x;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int popped = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return popped;
}

void display(int* queue) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int n;
    while (1) {
        int wt;
        scanf("%d", &n);
        switch (n) {
        case 1:
            scanf("%d", &wt);
            enqueue(wt);
            break;
        case 2: {
            int val = dequeue();
            if (val != -1)
                printf("Element deleted from queue is : %d\n", val);
            break;
        }
        case 3:
            display(queue);
            break;
        case 4:
            printf("Exit\n");
            return 0;
        default:
            printf("incorrect!\n");
            break;
        }
    }
}
