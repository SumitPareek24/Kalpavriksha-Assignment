#include <stdio.h>
#include <stdlib.h>

struct Node {
    char str[10];
    int data;
    struct Node * next;
};

int checkDuplicate(struct Node * head, int currentId) {
    while(head != NULL) {
        if(currentId == head -> data) {
            return 1;
        }
    }
    return 0;
}

int checkPriority(struct Node * head) {
    if(head -> str == "Critical") {
        return 3;
    } else if(head -> str == "Serious") {
        return 2;
    } else {
        return 1;
    }
}

void takeInput(int noOfPatients, struct Node * head, struct Node * current) {    

    struct Node * seriousHead = NULL, * criticalHead = NULL, * stableHead = NULL;
    struct Node * seriousEnd = NULL, * criticalEnd = NULL, * stableEnd = NULL;

    printf("No of patients: %d\n", noOfPatients);
    printf("Enter id & status: \n");
    while(noOfPatients--) {
        char status[10];
        int number;

        scanf("%d", &number);

        if(checkDuplicate(head, number)) {
            printf("id already exist\n");
            continue;
        }

        scanf("%s", status);
        struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
        // newNode -> str = (char *)malloc(sizeof(char));
        newNode -> str = status;
        newNode -> data = number;
        newNode -> next = NULL;

        if(checkPriority(newNode) == 3) {
            if(criticalHead == NULL) {
                criticalHead = newNode;
            }
            criticalEnd = newNode;
            criticalEnd = criticalEnd -> next;
        } else if(checkPriority(newNode) == 2) {
            if(seriousHead == NULL) {
                seriousHead = newNode;
            }
            seriousEnd = newNode;
            seriousEnd = seriousEnd -> next;
        } else {
            if(stableHead == NULL) {
                stableHead = newNode;
            }
            stableEnd = newNode;
            stableEnd = stableEnd -> next;
        }

        if(head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current -> next = newNode;
            // current = current -> next;
        }
        printf("cur: %d\n", current -> data);
        current = current -> next;
    }


    printf("cri: %d\n", criticalHead -> data);
    printf("seri: %d\n", seriousHead -> data);
    printf("stab: %d\n", stableHead -> data);
}

struct Node * findMiddle(struct Node * head) {
    struct Node * slow = head, * fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

void merge(struct Node * head) {

}

struct Node * mergeSort(struct Node * head, struct Node * left, struct Node * right) {
    if(head == NULL || head -> next == NULL) {
        return  head;
    }

    struct Node * middle = findMiddle(head);

}

void bubbleSort() {

}

int main() {

    struct Node * head = NULL, * current = NULL;
    int noOfPatients;
    printf("Enter no of patients: ");
    scanf("%d", &noOfPatients);
    takeInput(noOfPatients, head, current);

    return 0;
}