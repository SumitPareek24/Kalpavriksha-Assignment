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

void printSubset(int *subset, int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("\n");
}

void generatePossibleSumCombination(int *arr, int index, int *subSet, int targetSum, int currentSum, 
                                    int subsetSize, int arraySize)
{
    if (currentSum == targetSum)
    {
        printSubset(subSet, subsetSize);
        return;
    }
    else if (currentSum > targetSum)
    {
        return;
    }

    for (int arrayIndex = index; arrayIndex < arraySize; arrayIndex++)
    {
        if(currentSum == -1)
            currentSum = 0;
        subSet[subsetSize] = arr[arrayIndex];
        generatePossibleSumCombination(arr, arrayIndex, subSet, targetSum, currentSum + arr[arrayIndex], subsetSize + 1, arraySize);
    }
}

int main()
{
    int *arr = (int *)malloc(1000 * sizeof(int));
    int arraySize = takeInput(arr);

    int targetSum = 0;
    printf("Enter target sum: ");
    scanf("%d", &targetSum);

    int* subArr = (int*)malloc(arraySize*sizeof(int));
    generatePossibleSumCombination(arr, 0, subArr, targetSum, -1, 0, arraySize);
    free(arr);

    return 0;
}