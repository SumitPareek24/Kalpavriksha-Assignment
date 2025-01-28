#include <stdio.h>
#include <stdlib.h>

int takeInput(int *arr, int *elementToSearch)
{
    printf("Enter elements of array: ");
    int arraySize = 0;
    while (1)
    {
        int number = 0;
        scanf("%d", &number);
        arr[arraySize++] = number;
        char ch = getchar();
        if (ch == '\n' || ch == EOF)
        {
            break;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", elementToSearch);

    return arraySize;
}

int twoPointerSearch(int *arr, int arraySize, int elementToSearch)
{
    int left = 0;
    int right = arraySize - 1;
    while (left <= right)
    {
        if (arr[left] == elementToSearch)
            return 1;
        if (arr[right] == elementToSearch)
            return 1;
        left++;
        right--;
    }
    return 0;
}

int main()
{
    int *arr;
    arr = (int *)malloc(100 * sizeof(int));
    int elementToSearch = 0;

    int arraySize = takeInput(arr, &elementToSearch);

    arr = (int *)realloc(arr, arraySize * sizeof(int));

    if (twoPointerSearch(arr, arraySize, elementToSearch))
    {
        printf("Number found!\n");
    }
    else
    {
        printf("Number not found!\n");
    }

    return 0;
}