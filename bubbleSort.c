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

void swapNumbers(int *firstNo, int *secondNo)
{
    int temp = *firstNo;
    *firstNo = *secondNo;
    *secondNo = temp;
}

void bubbleSort(int *arr, int arraySize)
{
    for (int firstIndex = 0; firstIndex < arraySize - 1; firstIndex++)
    {
        for (int secondIndex = 0; secondIndex < arraySize - firstIndex - 1; secondIndex++)
        {
            if (arr[secondIndex] > arr[secondIndex + 1])
                swapNumbers(&arr[secondIndex], &arr[secondIndex + 1]);
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

int main()
{

    int *arr = (int *)malloc(100 * sizeof(int));
    int arraySize = takeInput(arr);

    bubbleSort(arr, arraySize);
    printArray(arr, arraySize);

    free(arr);

    return 0;
}