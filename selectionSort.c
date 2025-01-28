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

void selectionSort(int * arr, int size) {
    for (int firstIndex = 0; firstIndex < size - 1; firstIndex++)
    {
        int minIndex = firstIndex;
        for (int secondIndex = firstIndex + 1; secondIndex < size; secondIndex++)
        {
            if(arr[secondIndex] < arr[minIndex]) {
                minIndex = secondIndex;
            }
        }
        if(minIndex != firstIndex) {
            swapNumbers(&arr[firstIndex], &arr[minIndex]);
        }
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

    selectionSort(arr, arraySize);
    printArray(arr, arraySize);

    free(arr);

    return 0;
}