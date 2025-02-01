#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct stack {
    int arr[MAXSIZE];
    int top;
    int size;
};

void pushElementIntoStack(struct stack * myStack) {
    int number;
    printf("Enter element: ");
    scanf("%d", &number);

    if(myStack->top >= MAXSIZE) {
        printf("\nStack overflow\n\n");
        return;
    }
    myStack -> top++;
    myStack -> arr[(myStack->top)] = number;
}

void popElementFromStack(struct stack * myStack) {
    if(myStack -> top == -1) {
        printf("\nStack underflow\n\n");
        return;
    }

    int item = myStack -> arr[(myStack -> top)];
    printf("\n%d removed from stack\n\n", item);
    myStack -> top--;
}

void topElementOfStack(struct stack * myStack) {
    if(myStack -> top == -1) {
        printf("\nNo element present in the stack\n\n");
        return;
    }

    printf("\nTop element: %d\n\n", myStack -> arr[myStack -> top]);
}

void isEmpty(struct stack myStack) {
    if(myStack.top == -1) {
        printf("\nStack is empty\n\n");
        return;
    }

    printf("\nStack is not empty.\n\n");
}

int main() {

    struct stack myStack;
    myStack.top = -1;
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
                topElementOfStack(&myStack);
                break;

            case 4:
                isEmpty(myStack);
                break;

            case 5: 
                if(myStack.top != -1)
                    printf("Size of stack is: %d\n", myStack.top);
                else 
                    printf("Size of stack is: 0\n");
                break;
            
            case 6: 
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice");
                break;
        }
    }
    
    free(&myStack);

    return 0;
}