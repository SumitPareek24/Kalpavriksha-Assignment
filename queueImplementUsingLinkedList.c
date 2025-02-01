#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;
struct Node *end = NULL;

void isEmpty()
{
    if (start == NULL && end == NULL)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("The queue is not empty");
    }
}

void enqueue()
{
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (start == NULL)
    {
        start = end = newNode;
    }
    else
    {
        end->next = newNode;
        end = newNode;
    }
}

void dequeue()
{
    if (start == NULL)
    {
        printf("The queue is empty");
        return;
    }
    struct Node *temp = start;
    printf("Dequeued element is: %d\n", temp->data);
    start = start->next;
    if (start == NULL)
    {
        end = NULL;
    }
    free(temp);
}

void peek()
{
    if (start == NULL && end == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element of queue is %d.\n", start->data);
    }
}

void size()
{
    if (start == NULL && end == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        struct Node *temp;
        temp = start;
        int sizeOfQueue = 0;
        while (temp)
        {
            sizeOfQueue++;
            temp = temp->next;
        }
        printf("The size of queue is %d.\n", sizeOfQueue);
    }
}

void freeMem()
{
    struct Node *temp;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
    }
    printf("Queue memory freed successfully.\n");
}

int main()
{
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
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            isEmpty();
            break;

        case 5:
            size();
            break;

        case 6:
            printf("Exiting...\n");
            freeMem();
            return 0;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
