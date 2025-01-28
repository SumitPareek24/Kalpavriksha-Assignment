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

void merge(int *arr, int left, int mid, int right)
{
    int leftSubArrSize = mid - left + 1, rightSubArrSize = right - mid;
    int leftSubArray[leftSubArrSize], rightSubArray[rightSubArrSize];

    int leftSubArrIndex = 0, rightSubArrIndex = 0, arrIndex = left;

    while (leftSubArrIndex < leftSubArrSize)
    {
        leftSubArray[leftSubArrIndex] = arr[arrIndex];
        leftSubArrIndex++;
        arrIndex++;
    }

    while (rightSubArrIndex < rightSubArrSize)
    {
        rightSubArray[rightSubArrIndex] = arr[arrIndex];
        rightSubArrIndex++;
        arrIndex++;
    }

    leftSubArrIndex = 0, rightSubArrIndex = 0, arrIndex = left;

    while (leftSubArrIndex < leftSubArrSize && rightSubArrIndex < rightSubArrSize)
    {
        if (leftSubArray[leftSubArrIndex] <= rightSubArray[rightSubArrIndex])
        {
            arr[arrIndex++] = leftSubArray[leftSubArrIndex++];
        }
        else
        {
            arr[arrIndex++] = rightSubArray[rightSubArrIndex++];
        }
    }

    while (leftSubArrIndex < leftSubArrSize)
    {
        arr[arrIndex++] = leftSubArray[leftSubArrIndex++];
    }

    while (rightSubArrIndex < rightSubArrSize)
    {
        arr[arrIndex++] = rightSubArray[rightSubArrIndex++];
    }
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, arraySize - 1);
    printArray(arr, arraySize);

    free(arr);

    return 0;
}