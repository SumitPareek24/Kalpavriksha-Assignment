#include <stdio.h>
#include <string.h>

int stringLength(char * str) {
    int len = 0;
    while(* str) {
        len++;
        str++;
    }
    return len;
}

int countNameWithVowels(int rows, int columns, char (*names)[columns][51]) {
    int countOfNames = 0;
    for(int rowIndex = 0 ; rowIndex < rows ; rowIndex++) {
        for(int colIndex = 0; colIndex < columns; colIndex++) {
            if(names[rowIndex][colIndex][0]=='A' || names[rowIndex][colIndex][0]=='E' || names[rowIndex][colIndex][0]=='I' || names[rowIndex][colIndex][0]=='O' || names[rowIndex][colIndex][0]=='U' || names[rowIndex][colIndex][0]=='a' || names[rowIndex][colIndex][0]=='e' || names[rowIndex][colIndex][0]=='i' || names[rowIndex][colIndex][0]=='o' || names[rowIndex][colIndex][0]=='u'
                ){
                countOfNames++;
            }
        }
    }
    return countOfNames;
}

void printNames(int rows, int columns, char (* names)[columns][51]) {
    printf("The 2D array of names is:\n");
    for(int rowIndex = 0 ; rowIndex < rows ; rowIndex++) {
        for(int colIndex = 0; colIndex < columns; colIndex++) {
            printf("%s ", names[rowIndex][colIndex]);
        }
        printf("\n");
    }
}

void matrixInput(int rows, int columns, char (* names)[columns][51], char ** longName) {
    printf("Enter the names:\n");
    int maxLength = 0;
    for(int rowIndex = 0 ; rowIndex < rows ; rowIndex++) {
        for(int colIndex = 0; colIndex < columns; colIndex++) {
            while(1) {
                printf("Name at [%d, %d]: ", rowIndex, colIndex);
                scanf("%s", names[rowIndex][colIndex]);
                int lengthOfString = stringLength(names[rowIndex][colIndex]);
                if(lengthOfString <= 50) {
                    if(lengthOfString > maxLength) {
                        maxLength = lengthOfString;
                        * longName = names[rowIndex][colIndex];
                    }
                    break;
                }
                else {
                    printf("Name is exceeding 50 characters, Please try a different name.\n");
                }
            }
        }
    }
}

int dimensionInput(int minDimension, int maxDimension) {
    int dimension;
    
    scanf("%d", &dimension);
    while(dimension < minDimension || dimension > maxDimension) {
        printf("Please enter a value between %d to %d\n", minDimension, maxDimension);
        scanf("%d", &dimension);
    }
    return dimension;
}
 
int main() {
    int rows, columns;
    printf("Enter the number of rows:");
    rows = dimensionInput(1, 10);
    printf("Enter the number of columns:");
    columns = dimensionInput(1, 101);
    
    char names[rows][columns][51];
    char * longName;
    
    matrixInput(rows, columns, names, &longName);
    
    printNames(rows, columns, names);
    
    printf("Number of names starting with a vowel: %d\n", countNameWithVowels(rows, columns, names));
    printf("The longest name: %s", longName);
    return 0;
}
