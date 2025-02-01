#include <stdio.h>
#define MAXSIZE 100

struct Queue {
    int arr[MAXSIZE];
    int front, rear;
};

struct Stack
{
    struct Queue q1, q2;
    int size;
};

void enqueue(struct Queue * q, int value) {
    if(q -> rear == MAXSIZE - 1) {
        printf("Queue overflow\n");
        return;
    }

    if(q -> front == -1) {
        q -> front = 0;
    }

    q -> rear++;
    q -> arr[q -> rear] = value;
}

int isQueueEmpty(struct Queue * q) {
    if (q -> front == -1)
    {
        return 1;
    }
    return 0;
}

void dequeue(struct Queue * q) {
    if(isQueueEmpty(q)) {
        printf("Queue underflow\n");
        return;
    }

    int data = q -> arr[q -> front];
    if(q -> front == q -> rear) {
        q -> front = q -> rear = -1;
    }

    else {
        q -> front++;
    }
}

void push(struct Stack * stack) {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    stack -> size++;
    enqueue(&stack -> q2, value);

    while(!isQueueEmpty(&stack -> q1)) {
        enqueue(&stack -> q2, value);
        dequeue(&stack -> q1);
    }

    struct Queue temp = stack -> q1;
    stack -> q1 = stack -> q2;
    stack -> q2 = temp;
}

void pop(struct Stack * stack) {
    if(isQueueEmpty(&stack -> q1)) {
        printf("Stack underflow\n");
        return;
    }

    stack -> size--;
    dequeue(&stack -> q1);
}

int front(struct Queue *q) {
    return q -> arr[q -> front];
}

int peek(struct Stack stack) {
    if(isQueueEmpty(&stack.q1)) {
        printf("\nStack is empty\n");
        return 0;
    }

    return front(&stack.q1); 
}

int size(struct Stack stack) {
    return stack.size;
}

void isEmpty(struct Stack stack) {
    if(size(stack) == 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack is not empty\n");
}

int main() {

    struct Stack stack;
    stack.q1.front = -1;
    stack.q1.rear = -1;

    stack.q2.front = -1;
    stack.q2.rear = -1;

    stack.size = 0;

    int choice;
    while(1) {
        printf("\nStack Operations are:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Size\n");
        printf("6. Exit\n");
        printf("Choose the operation you want to perform: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(&stack);
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            printf("Peek element: %d\n", peek(stack));
            break;

        case 4:
            isEmpty(stack);
            break;

        case 5:
            printf("Size of stack is: %d\n", size(stack));
            break;

        case 6:
            printf("Exiting...");
            return 0;
        
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}