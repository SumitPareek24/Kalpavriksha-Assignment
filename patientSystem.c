#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char *str;
    int data;
    struct Node *next;
};

int checkPriority(struct Node *head)
{
    if (strcmp(head->str, "Critical") == 0)
    {
        return 3;
    }
    else if (strcmp(head->str, "Serious") == 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

void takeInput(int noOfPatients, struct Node **head, struct Node *current)
{

    struct Node *seriousHead = NULL, *criticalHead = NULL, *stableHead = NULL;
    struct Node *seriousEnd = NULL, *criticalEnd = NULL, *stableEnd = NULL;

    printf("No of patients: %d\n", noOfPatients);
    printf("Enter id & status: \n");
    while (noOfPatients--)
    {
        char *status = (char *)malloc(10 * sizeof(char));
        int number;

        scanf("%d", &number);

        scanf("%s", status);
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->str = status;
        newNode->data = number;
        newNode->next = NULL;

        if (checkPriority(newNode) == 3)
        {
            if (criticalHead == NULL)
            {
                criticalHead = newNode;
                criticalEnd = newNode;
            }
            else
            {
                criticalEnd->next = newNode;
                criticalEnd = newNode;
            }
        }
        else if (checkPriority(newNode) == 2)
        {
            if (seriousHead == NULL)
            {
                seriousHead = newNode;
                seriousEnd = newNode;
            }
            else
            {
                seriousEnd->next = newNode;
                seriousEnd = newNode;
            }
        }
        else if (checkPriority(newNode) == 1)
        {
            if (stableHead == NULL)
            {
                stableHead = newNode;
                stableEnd = newNode;
            }
            else
            {
                stableEnd->next = newNode;
                stableEnd = newNode;
            }
        }
    }

    if (criticalHead != NULL)
    {
        *head = criticalHead;
        if (seriousHead != NULL)
        {
            criticalEnd->next = seriousHead;
            if (stableHead != NULL)
            {
                seriousEnd->next = stableHead;
            }
        }
        else if (stableHead != NULL)
        {
            criticalEnd->next = stableHead;
        }
    }
    else if (seriousHead != NULL)
    {
        *head = seriousHead;
        if (stableHead != NULL) {
            seriousEnd->next = stableHead;
        }
    }
    else
    {
        *head = stableHead;
    }

    // stableEnd = NULL;
}

int main()
{

    struct Node *head = NULL, *current = NULL;
    int noOfPatients;
    printf("Enter no of patients: ");
    scanf("%d", &noOfPatients);
    takeInput(noOfPatients, &head, current);

    printf("Sorted data:\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        printf("%s ", head->str);
        printf("\n");
        head = head->next;
    }

    return 0;
}