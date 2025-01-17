#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList *next;
};

int findLengthOfLinkedList(struct SinglyLinkedList *head)
{
    struct SinglyLinkedList *lengthCheck = head;
    int lengthOfLinkedList = 0;

    while (lengthCheck != NULL)
    {
        lengthOfLinkedList++;
        lengthCheck = lengthCheck->next;
    }
    return lengthOfLinkedList;
}

void printMiddleNode(struct SinglyLinkedList * head, int lengthOfLinkedList) {
    int index = 0;
    struct SinglyLinkedList * halfLinkedList = head;
    while (index < lengthOfLinkedList / 2)
    {
        halfLinkedList = halfLinkedList->next;
        index++;
    }

    printf("Middle Element: %d\n", halfLinkedList->data);
}

int main()
{

    printf("Enter linked list: ");
    int checkNumber = 0;

    struct SinglyLinkedList *head = NULL, *current = NULL;
    while (1)
    {
        int number, validateNumber = 0;
        validateNumber = scanf("%d", &number);
        if (validateNumber == 0)
        {
            checkNumber = 1;
            break;
        }
        struct SinglyLinkedList *newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
        newNode->data = number;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current->next = newNode;
        }
        current = newNode;
        char ch = getchar();
        if (ch == '\n')
        {
            break;
        }
    }

    if (checkNumber)
    {
        printf("Invalid\n");
        return 0;
    }

    int lengthOfLinkedList = findLengthOfLinkedList(head);

    printMiddleNode(head, lengthOfLinkedList);

    free(head);

    return 0;
}