#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printLeftSide(int n)
{
    int row, col;
    for (row = 1; row <= n; row++)
    {
        int spaces = 2 * (n - row);
        for (col = 1; col <= row; col++)
        {
            printf("%d ", col);
        }
        for (col = 1; col <= spaces; col++)
        {
            printf("  ");
        }
        for (col = row; col >= 1; col--)
        {
            printf("%d ", col);
        }
        printf("\n");
    }
}
void printRightSide(int n)
{
    int row, col;
    for (row = n - 1; row >= 1; row--)
    {
        int spaces = 2 * (n - row);
        for (col = 1; col <= row; col++)
        {
            printf("%d ", col);
        }
        for (col = 1; col <= spaces; col++)
        {
            printf("  ");
        }
        for (col = row; col >= 1; col--)
        {
            printf("%d ", col);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printLeftSide(n);
    printRightSide(n);
    return 0;
}