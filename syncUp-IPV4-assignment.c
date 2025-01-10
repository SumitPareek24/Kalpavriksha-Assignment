#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

char arr[4][10];

int splitWords(char *str)
{
    int wordCount = 0, wordEnd = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '.' && str[i] != ' ')
        {
            arr[wordCount][wordEnd++] = str[i];
        }
        else if (wordEnd > 0)
        {
            arr[wordCount][wordEnd++] = '\0';
            wordCount++;
            wordEnd = 0;
        }
    }
    if (wordEnd > 0)
    {
        arr[wordCount][wordEnd++] = '\0';
        wordCount++;
    }
    return wordCount;
}

int convertNumber(char *str)
{
    int number = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        number = number * 10 + (str[i] - '0');
    }
    return number;
}

void checkValidationSpaceDot(int lengthOfString, char *str, int *check, int wordCount)
{
    for (int i = 0; i < lengthOfString - 1; i++)
    {
        if (str[i] == '.' && str[i + 1] == '.')
        {
            * check = 0;
            break;
        }
        else if (str[i] == ' ')
        {
            * check = 0;
            break;
        }
    }

    for (int i = 0; i < wordCount; i++)
    {
        if (arr[i][0] == '0' && stringLength(arr[i]) > 1)
        {
            * check = 0;
            break;
        }
    }
}

void chekValidationNumbers(int * check, int wordCount) {
    for (int i = 0; i < wordCount; i++)
    {
        int n = convertNumber(arr[i]);
        if (n < 0 || n > 255)
        {
            * check = 0;
            break;
        }
    }
}

int main()
{

    char *str;
    str = (char *)malloc(1000 * sizeof(char));
    printf("Enter string: ");
    scanf("%[^\n]%*c", str);

    int lengthOfString = stringLength(str);
    if (lengthOfString > 15)
    {
        printf("Length should be less than 15\n");
        return 0;
    }

    int check = 1;

    int wordCount = splitWords(str);

    checkValidationSpaceDot(lengthOfString, str, &check, wordCount);

    chekValidationNumbers(&check, wordCount);

    check ? printf("Valid\n") : printf("Invalid\n");

    return 0;
}