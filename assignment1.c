#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkInteger(char ch)
{
    if (ch >= 48 && ch <= 57)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void intToString(int num, char temp_str[])
{
    int i = 0, temp = 0;
    while (num > 0)
    {
        temp_str[i] = (num % 10) + '0';
        i++;
        num = num / 10;
    }

    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        char tempo = temp_str[j];
        temp_str[j] = temp_str[k];
        temp_str[k] = tempo;
    }
    temp_str[i] = '\0';
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return true;
    }
    return false;
}

int evaluateExpression(char expr[])
{
    int result = 0;
    int currentNumber = 0;
    char lastOperator = '+';

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (checkInteger(expr[i]))
        {
            currentNumber = 0;
            while (checkInteger(expr[i]))
            {
                currentNumber = currentNumber * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            if (lastOperator == '+')
                result += currentNumber;
            else if (lastOperator == '-')
                result -= currentNumber;
        }
        else if (expr[i] == '+' || expr[i] == '-')
        {
            lastOperator = expr[i];
        }
    }

    return result;
}

int main()
{
    char expr[100];
    char result[100] = "";

    printf("Enter a mathematical expression: ");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    if (expr[0] == '"' && expr[strlen(expr) - 1] == '"')
    {
        memmove(expr, expr + 1, strlen(expr) - 1);
        expr[strlen(expr) - 1] = '\0';
        expr[strlen(expr) - 1] = '\0';
    }

    else
    {
        printf("Error: Invalid input format. Use double quotes.\n");
        return 0;
    }

    int i = 0, num = 0, temp = 0;
    char last_op = '\0';
    int k = 0;

    bool check = false;
    int j;
    for (j = 0; expr[j] != '\0'; j++)
    {

        if (expr[j] == 32)
        {
            continue;
        }

        if (expr[j] >= 48 && expr[j] <= 57)
        {
            continue;
        }
        else if (expr[j] == 43 || expr[j] == 45 || expr[j] == 42 || expr[j] == 47 || expr[j] == 32)
        {
            continue;
        }
        else
        {
            check = true;
            break;
        }
    }

    if (expr[0] == '*' || expr[0] == '/' || isOperator(expr[strlen(expr) - 1]))
    {
        check = true;
    }

    if (check)
    {
        printf("Error: Invalid expression\n");
        return 0;
    }

    char lastOpera = '\0';
    for (int j = 0; expr[j] != '\0'; j++)
    {
        if (expr[j] == 32)
        {
            continue;
        }
        if (isOperator(expr[j]))
        {
            if (isOperator(lastOpera))
            {
                printf("Error: Invalid expression\n");
                return 0;
            }
            lastOpera = expr[j];
        }
        else
        {
            lastOpera = '\0';
        }
    }

    while (expr[i] != '\0')
    {
        if (checkInteger(expr[i]))
        {
            num = 0;
            while (checkInteger(expr[i]))
            {
                num = num * 10 + (expr[i] - '0');
                i++;
            }

            if (last_op == '*')
            {
                temp *= num;
            }
            else if (last_op == '/')
            {
                if (num == 0)
                {
                    printf("Error: Division by zero.\n");
                    return 0;
                }
                temp /= num;
            }
            else
            {
                temp = num;
            }
        }
        else if (expr[i] == '*' || expr[i] == '/')
        {
            last_op = expr[i];
            i++;
        }
        else if (expr[i] == '+' || expr[i] == '-')
        {
            char temp_str[20];
            int j = 0;
            intToString(temp, temp_str);

            while (temp_str[j] != '\0')
            {
                result[k] = temp_str[j];
                j++;
                k++;
            }
            result[k++] = expr[i];

            last_op = expr[i];
            temp = 0;
            i++;
        }
        else
        {
            i++;
        }
    }

    i = 0;

    char temp_str[20];
    intToString(temp, temp_str);
    while (temp_str[i] != '\0')
    {
        result[k] = temp_str[i];
        i++;
        k++;
    }

    result[k] = '\0';
    int finalResult = evaluateExpression(result);
    printf("Final result: %d\n", finalResult);

    return 0;
}