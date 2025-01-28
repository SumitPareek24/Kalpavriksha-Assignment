#include <stdio.h>
#include <stdlib.h>

int takeInput(int * arr, int * elementToSearch) {
    printf("Enter elements of array: ");
    int arraySize = 0;
    while(1) {
        int number = 0;
        scanf("%d", &number);
        arr[arraySize++] = number;
        char ch = getchar();
        if(ch == '\n' || ch == EOF) {
            break;
        }
    }

    printf("Enter element to search: ");
    scanf("%d", elementToSearch);

    return arraySize;
}

void merge(int *arr, int left, int mid, int right)
{
    int leftArraySize = mid - left + 1;
    int rightArraySize = right - mid;
    
    int leftIndex = 0, rightIndex = 0, arrayIndex = left;
    
    int leftSubArr[leftArraySize], rightSubArr[rightArraySize];
    
    for(leftIndex = 0; leftIndex < leftArraySize; leftIndex++) {
        leftSubArr[leftIndex] = arr[arrayIndex++];
    }
    
    for(rightIndex = 0; rightIndex < rightArraySize; rightIndex++) {
        rightSubArr[rightIndex] = arr[arrayIndex++];
    }
    
    leftIndex = 0, rightIndex = 0, arrayIndex = left;
    
    while(leftIndex < leftArraySize && rightIndex < rightArraySize) {
        if(leftSubArr[leftIndex] <= rightSubArr[rightIndex]) {
            arr[arrayIndex] = leftSubArr[leftIndex];
            arrayIndex++;
            leftIndex++;
        } else {
            arr[arrayIndex] = rightSubArr[rightIndex];
            arrayIndex++;
            rightIndex++;
        }
    }
    
    while(leftIndex < leftArraySize) {
        arr[arrayIndex] = leftSubArr[leftIndex];
        arrayIndex++;
        leftIndex++;
    }
    
    while(rightIndex < rightArraySize) {
        arr[arrayIndex] = rightSubArr[rightIndex];
        arrayIndex++;
        rightIndex++;
    }
}

void mergeSort(int * arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int binarySearch(int * arr, int arraySize, int elementToSearch) {
    int left = 0, right = arraySize - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] > elementToSearch) {
            right = mid - 1;
        } else if(elementToSearch > arr[mid]) {
            left = mid + 1;
        } else {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int * arr;
    arr = (int *)malloc(100 * sizeof(int));
    int elementToSearch = 0;

    int arraySize = takeInput(arr, &elementToSearch);
    
    arr = (int *)realloc(arr, arraySize * sizeof(int));

    mergeSort(arr, 0, arraySize - 1);

    if(binarySearch(arr, arraySize, elementToSearch)) {
        printf("Number found!\n");
    } else {
        printf("Number not found!\n");   
    }

    return 0;
}