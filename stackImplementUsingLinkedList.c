#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * createStack(int value) {
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    return newNode;
}

void pushElementIntoStack(struct Node ** myStack) {
    int number;
    printf("enter element: ");
    scanf("%d", &number);

    struct Node * newNode = createStack(number);
    if(* myStack == NULL) {
        * myStack = newNode;
        return;
    }

    newNode -> next = * myStack;
    * myStack = newNode;
}

void popElementFromStack(struct Node ** myStack) {
    if(* myStack == NULL) {
        printf("\nStack underflow\n\n");
        return;
    }
    printf("\nRemoved element: %d\n\n", (* myStack) -> data);
    struct Node * temp = * myStack;
    
    * myStack = (* myStack) -> next;
    free(temp);
}

void topElementOfStack(struct Node * myStack) {
    if( myStack == NULL) {
        printf("\nNo element present in the stack\n\n");
        return;
    }

    printf("\nTop element: %d\n\n", myStack -> data);
}

void size(struct Node * myStack) {
    if(myStack == NULL) {
        printf("\nNo element present in the stack\n\n");
        return;
    }
    struct Node * temp = myStack;
    int sizeOfStack = 0;
    while(temp != NULL) {
        sizeOfStack++;
        temp = temp -> next;
    }
    printf("\nSize of stack is: %d\n", sizeOfStack);
    printf("\n");
}

void isEmpty(struct Node * myStack) {
    if(myStack == NULL) {
        printf("\nStack is empty\n\n");
        return;
    } else {
        printf("\nStack is not empty\n\n");
        return;
    }
}

void freeMem(struct Node ** myStack) {
    struct Node * temp;
    while((* myStack) != NULL) {
        temp = * myStack;
        * myStack = (* myStack) -> next;
        free(temp);
    }
    printf("\nStack memory freed successfully\n\n");
}

int main() {

    struct Node * myStack = NULL;

    int choice;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is empty\n");
        printf("5. Size\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                pushElementIntoStack(&myStack);
                break;
            
            case 2:
                popElementFromStack(&myStack);
                break;

            case 3:
                topElementOfStack(myStack);
                break;

            case 4: 
                isEmpty(myStack);
                break;

            case 5: 
                size(myStack);
                break;
            
            case 6:     
                printf("Exiting...\n");
                freeMem(&myStack);
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}