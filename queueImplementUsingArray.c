#include <stdio.h>
#define MAX_SIZE 100

struct Queue
{
    int arr[MAX_SIZE];
    int currentSize;
    int start;
    int end;
};

void enqueue(struct Queue *queue)
{
    if (queue->currentSize == MAX_SIZE)
    {
        printf("Queue is full!\n");
        return;
    }
    int value;
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);
    queue->arr[queue->end] = value;
    queue->end = (queue->end + 1) % MAX_SIZE;
    queue->currentSize++;
}

void dequeue(struct Queue *queue)
{
    if(queue->currentSize == 0){
        printf("Queue is empty!\n");
        return;
    }
    printf("The value removed is %d.\n", queue->arr[(queue->start)]);
    queue->start = (queue->start+1) %MAX_SIZE;
    queue->currentSize--;
}

void peek(struct Queue queue)
{
    if (queue.currentSize == 0)
    {
        printf("The top of the queue is empty.\n");
        return;
    }
    printf("The top of the queue is %d\n", queue.arr[(queue.start)]);
}

void isEmpty(struct Queue queue)
{
    if(queue.currentSize == 0){
        printf("The queue is empty.\n");
        return;
    }
    printf("The queue is not empty.\n");
}

int main()
{
    struct Queue queue;
    queue.currentSize = 0;
    queue.start = 0;
    queue.end = 0;

    int choice;
    while (1)
    {
        printf("\nQueue Operations are:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. Size\n");
        printf("6. Exit\n");
        printf("Choose the operation you want to perform: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&queue);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            peek(queue);
            break;

        case 4:
            isEmpty(queue);
            break;

        case 5:
            printf("The current size of queue is %d.\n", queue.currentSize);
            break;

        case 6:
            printf("Exiting...");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
            break;
        }
    }
}