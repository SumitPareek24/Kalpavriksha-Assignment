#include <stdio.h>

long long int modularExponent(long int base, long int exponent, long int modulus)
{
    long long int result = 1;
    //for reducing the value in case of larger value of base
    long long int newBase = base % modulus;
    for (int i = 0; i < exponent; i++)
    {
        result = (result * newBase) % modulus;
    }
    return result;
}

int main()
{
    long long int base = 0, exponent = 0, modulus = 0;
    printf("Enter base (B): \n");
    scanf("%ld", &base);
    printf("Enter exponent (N):\n");
    scanf("%ld", &exponent);
    printf("Enter modulus (M):\n");
    scanf("%ld", &modulus);

    //input validation
    if (exponent < 0 || modulus <= 1)
    {
        printf("Value of modulus should be greater than 1 \nor value of exponent should be greater than or equal to 0.\n");
    }
    long long int result = modularExponent(base, exponent, modulus);
    printf("The result is %ld", result);
}