#include "NumClass.h"

#define true 1
#define false 0

int factorial(int number) //input: number (int), output: number! (factorial of the number).
{
    int result = 1;

    for(int i = 2; i <= number; i++)
    {
        result *= i;
    }

    return result;
}

int isPrime(int number)
{
    for(int i = number / 2; i > 1; i--)
    {
        if(number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int isStrong(int number)
{
    int nCopy = number, sum = 0;

    while(nCopy)
    {
        sum += factorial(nCopy % 10);
        nCopy /= 10;
    }

    return sum == number;
}