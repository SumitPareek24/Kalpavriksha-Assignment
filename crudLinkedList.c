#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedList
{
    int data;
    struct SinglyLinkedList * next;
};

void insertAtBeginning(int value, struct SinglyLinkedList ** head)
{
    struct SinglyLinkedList * newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
    newNode -> data = value;
    newNode -> next = * head;
    * head = newNode;
    printf("Inserted at beginning\n");
}

void insertAtEnd(int value, struct SinglyLinkedList ** head)
{
    struct SinglyLinkedList * newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
    newNode -> data = value;
    newNode -> next = NULL;
    if (* head == NULL)
    {
        * head = newNode;
    }
    else
    {
        struct SinglyLinkedList * tempNode = *head;
        while (tempNode -> next != NULL)
        {
            tempNode = tempNode -> next;
        }
        tempNode -> next = newNode;
    }
    printf("Inserted at end\n");
}

void insertAtPosition(int value, int position, struct SinglyLinkedList ** head)
{

    if (position == 1)
    {
        insertAtBeginning(value, head);
        return;
    }

    if (position > 1 && * head == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    int index = 1;
    struct SinglyLinkedList * newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
    newNode -> data = value;
    newNode -> next = NULL;
    struct SinglyLinkedList * currNode = * head;
    while (index < position - 1 && currNode != NULL)
    {
        currNode = currNode -> next;
        index++;
    }

    if(currNode == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode -> next = currNode -> next;
    currNode -> next = newNode;
    printf("Inserted at position %d\n", position);
}

void updateAtPosition(int value, int position, struct SinglyLinkedList ** head)
{
    int index = 1;
    struct SinglyLinkedList * currNode = * head;
    while (index < position && currNode != NULL)
    {
        currNode = currNode -> next;
        index++;
    }
    if (currNode == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    currNode -> data = value;
    printf("Value updated\n");
}

void deleteAtBeginning(struct SinglyLinkedList ** head)
{
    if (* head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct SinglyLinkedList * nodeToDelete = * head;
    * head = (* head) -> next;
    free(nodeToDelete);
    printf("Deleted the node at beginning\n");
}

void deleteAtEnd(struct SinglyLinkedList ** head)
{
    if (* head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct SinglyLinkedList * nodeToDelete = * head, * prevNode = NULL;
    while (nodeToDelete -> next != NULL)
    {
        prevNode = nodeToDelete;
        nodeToDelete = nodeToDelete -> next;
    }

    if (prevNode == NULL)
    {
        * head = NULL;
    }
    else
    {
        prevNode -> next = NULL;
    }
    free(nodeToDelete);
    printf("Deleted the node at end\n");
}

void deleteAtPosition(int position, struct SinglyLinkedList ** head)
{
    if (* head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct SinglyLinkedList * currentNode = * head;

    if (position == 1)
    {
        deleteAtBeginning(head);
        return;
    }

    int index = 1;
    struct SinglyLinkedList * prevNode = NULL;
    while (index < position && currentNode != NULL)
    {
        prevNode = currentNode;
        currentNode = currentNode -> next;
        index++;
    }

    if(currentNode == NULL) {
        printf("Invalid position\n");
        return;
    }

    prevNode -> next = currentNode -> next;

    free(currentNode);
    printf("Deleted the node at position: %d\n", position);
}

void printLinkedList(struct SinglyLinkedList * head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

int main()
{
    struct SinglyLinkedList * head = NULL;

    int noOfOperation = 0;
    printf("Enter number of operation to perform: ");
    scanf("%d", &noOfOperation);

    while (noOfOperation--)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at Position\n");
        printf("4. Display\n");
        printf("5. Update at Position\n");
        printf("6. Delete at beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        int choice;
        printf("Enter choice\n");
        scanf("%d", &choice);
        int value, position;

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(value, &head);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(value, &head);
            break;

        case 3:
            printf("Enter value & position: ");
            scanf("%d%d", &value, &position);
            insertAtPosition(value, position, &head);
            break;

        case 4:
            printf("Linked List: ");
            printLinkedList(head);
            break;

        case 5:
            printf("Enter value & position to be update: ");
            scanf("%d%d", &value, &position);
            updateAtPosition(value, position, &head);
            break;

        case 6:
            deleteAtBeginning(&head);
            break;

        case 7:
            deleteAtEnd(&head);
            break;

        case 8:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(position, &head);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}