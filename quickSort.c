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

int partition(int * arr, int lowerBound, int upperBound) {
    int pivot = arr[lowerBound];
    int start = lowerBound;
    int end = upperBound;

    while (start <= end)
    {
        while(arr[start] <= pivot) {
            start++;
        } 

        while(arr[end] > pivot) {
            end--;
        }

        if(start < end) {
            swapNumbers(&arr[start], &arr[end]);
        }
    }
    swapNumbers(&arr[lowerBound], &arr[end]);
    return end;
}

void quickSort(int * arr, int lowerBound, int upperBound) {
    if(lowerBound <= upperBound) {
        int loc = partition(arr, lowerBound, upperBound);
        quickSort(arr, lowerBound, loc - 1);
        quickSort(arr, loc + 1, upperBound);
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

    quickSort(arr, 0, arraySize);
    printArray(arr, arraySize);
    
    free(arr);

    return 0;
}