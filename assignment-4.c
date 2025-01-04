#include <stdio.h>
char words[100][100];

int findLengthOfSentence(char *sen)
{
    int wc = 0;
    int wordEnd = 0;

    for (int i = 0; i < sen[i] != '\0'; i++)
    {
        if (sen[i] != ' ')
        {
            words[wc][wordEnd++] = sen[i];
        }
        else if (wordEnd > 0)
        {
            words[wc][wordEnd] = '\0';
            wordEnd = 0;
            wc++;
        }
    }
    if (wordEnd > 0)
    {
        words[wc][wordEnd] = '\0';
        wc++;
    }
    return wc;
}

int findLengthOfWord(char *sen)
{
    int len = 0;

    while (sen[len] != '\0')
    {
        len++;
    }
    return len;
}

void findLongestWord(int lengthOfWords)
{
    int maxLength = 0;
    int index;
    for (index = 0; index < lengthOfWords; index++)
    {
        if (maxLength < findLengthOfWord(words[index]))
        {
            maxLength = findLengthOfWord(words[index]);
        }
    }
    printf("longest word length: %d\n", maxLength);
}

int main()
{

    char str[100];
    printf("Enter a sentence: \n");
    scanf("%[^\n]*c", str);

    int wc = findLengthOfSentence(str);
    findLongestWord(wc);

    return 0;
}