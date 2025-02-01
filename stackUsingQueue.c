#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct Queue
{
    int arr[MAXSIZE];
    int front, rear, size;
};

struct Stack
{
    struct Queue q;
    int size;
};

int isQueueFull(struct Queue *q)
{
    return q->size == MAXSIZE;
}

void enqueue(struct Queue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("\nQueue overflow\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAXSIZE;
    q->arr[q->rear] = value;
    q->size++;
}

int isQueueEmpty(struct Queue *q)
{
    return q->size == 0;
}

void dequeue(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("\nQueue underflow\n");
        return;
    }

    q->front = (q->front + 1) % MAXSIZE;
    q->size--;
    if (q->size == 0)
    {
        q->front = q->rear = -1;
    }
}

int front(struct Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    return q->arr[q->front];
}

void push(struct Stack *stack)
{
    if (isQueueFull(&stack->q))
    {
        printf("\nStack overflow\n");
        return;
    }

    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    enqueue(&stack->q, value);
    int originalSize = stack->q.size - 1;

    for (int i = 0; i < originalSize; i++)
    {
        int temp = front(&stack->q);
        dequeue(&stack->q);
        enqueue(&stack->q, temp);
    }
}

int peek(struct Stack *stack)
{
    if (isQueueEmpty(&stack->q))
    {
        printf("\nStack is empty\n");
        return -1;
    }

    return front(&stack->q);
}

void pop(struct Stack *stack)
{
    if (isQueueEmpty(&stack->q))
    {
        printf("\nStack underflow\n");
        return;
    }
    printf("\nThe removed element is %d\n", peek(stack));
    dequeue(&stack->q);
}

int size(struct Stack stack)
{
    return stack.q.size;
}

void isEmpty(struct Stack stack)
{
    if (size(stack) == 0)
    {
        printf("\nStack is empty\n");
        return;
    }
    printf("\nStack is not empty\n"); 
}

int main()
{

    struct Stack myStack;
    myStack.q.front = -1;
    myStack.q.rear = -1;
    myStack.q.size = 0;
    myStack.size = 0;

    int choice;
    while (1)
    {
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
            push(&myStack);
            break;

        case 2:
            pop(&myStack);
            break;

        case 3:
            printf("\nTop value is: %d\n", peek(&myStack));
            break;

        case 4: 
            isEmpty(myStack);
            break;
        
        case 5:
            printf("\nSize of stack is: %d\n", size(myStack));
            break;

        case 6:
            return 0;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }

    return 0;
}