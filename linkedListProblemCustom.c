#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedList {
    int data;
    struct SinglyLinkedList* next;
};

void takeInput(struct SinglyLinkedList ** head, struct SinglyLinkedList ** current)
{

    printf("Enter Linked List: ");
    while (1)
    {
        int number;
        scanf("%d", &number);
        struct SinglyLinkedList * newNode = (struct SinglyLinkedList *)malloc(sizeof(struct SinglyLinkedList));
        newNode -> data = number;
        newNode -> next = NULL;

        if (* head == NULL)
        {
            * head = newNode;
        }
        else
        {
            (* current) -> next = newNode;
        }

        * current = newNode;

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
}

struct SinglyLinkedList * findMiddle(struct SinglyLinkedList * head) {
    struct SinglyLinkedList * slow = head, * fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

struct SinglyLinkedList *  merge2SortedList(struct SinglyLinkedList * head1, struct SinglyLinkedList * head2) {
    struct SinglyLinkedList * temp1 = NULL, * tempHead = NULL;

    if(head1 -> data <= head2 -> data) {
        temp1 = tempHead = head1;
        head1 = head1 -> next;
    } else {
        temp1 = tempHead = head2;
        head2 = head2 -> next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        if(head1 -> data <= head2 -> data) {
            temp1 -> next = head1;
            temp1 = head1;
            head1 = head1 -> next;
        } else {
            temp1 -> next = head2;
            temp1 = head2;
            head2 = head2 -> next;
        }
    }
    if(head1 != NULL) {
        temp1 -> next = head1;
    } else {
        temp1 -> next = head2;
    }
    return tempHead;
}

struct SinglyLinkedList * mergeSort(struct SinglyLinkedList * head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }

    struct SinglyLinkedList * middle = findMiddle(head);

    struct SinglyLinkedList * leftHead = head;
    struct SinglyLinkedList * rightHead = middle -> next;
    middle -> next = NULL;

    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    return merge2SortedList(leftHead, rightHead);
}

int findKthLargest(struct SinglyLinkedList* head, int kthLargestElement) {

    struct SinglyLinkedList* current = head;
    int length = 0;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    if(length < kthLargestElement) {
        printf("value of k is out of bounds\n");
        return 0;
    }
    current = head;
    int target = length - kthLargestElement;
    while (target > 0) {
        current = current->next;
        target--;
    }

    return current->data;
}

void printLinkedList(struct SinglyLinkedList * head) {
    while (head != NULL)
    {
        printf("%d", head->data);
        if(head -> next) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct SinglyLinkedList *head = NULL;
    struct SinglyLinkedList *current = NULL;

    takeInput(&head, &current);
    
    printf("Original list: ");
    printLinkedList(head);

    printf("Sorted list: ");
    struct SinglyLinkedList *headprint = NULL;
    headprint = mergeSort(head);
    printLinkedList(headprint);

    printf("Enter the value of K to find largest element: ");
    int kthLargestElement = 0;
    scanf("%d", &kthLargestElement);

    int kthLargest = findKthLargest(headprint, kthLargestElement);

    printf("The %d-th largest element is: %d\n", kthLargestElement, kthLargest); 

    return 0;
}
