#include <stdio.h>
#include <stdlib.h>

int takeInput(int *arr)
{
    int arrayIndex = 0;
    printf("Enter elements of array: ");
    while (1)
    {

        int number;
        if (scanf("%d", &number))
        {
            arr[arrayIndex++] = number;
        }
        else
        {
            printf("Invalid input");
            break;
        }

        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }
    return arrayIndex;
}

void swapNumbers(int * firstNo, int * secondNo) {
    int temp = * firstNo;
    * firstNo = * secondNo;
    * secondNo = temp;
}

void insertionSort(int * arr, int arraySize) {
    for(int sortedIndex = 1; sortedIndex < arraySize; sortedIndex++) {
        int temp = arr[sortedIndex];
        int unsortedIndex = sortedIndex - 1;

        while(unsortedIndex >= 0 && arr[unsortedIndex] > temp) {
            arr[unsortedIndex + 1] = arr[unsortedIndex];
            unsortedIndex--;
        }

        arr[unsortedIndex + 1] = temp;
    }
}

void printArray(int *arr, int arraySize)
{
    printf("Sorted array: ");
    for (int index = 0; index < arraySize; index++)
    {
        printf("%d ", arr[index]);
    }
}

int main() {

    int * arr = (int *)malloc(100 * sizeof(int));
    int arraySize = takeInput(arr);

    insertionSort(arr, arraySize);
    
    printArray(arr, arraySize);

    free(arr);

    return 0;
}