#include "NumClass.h"

#define true 1
#define false 0

int power(int n1, int n2) //input 2 numbers (int, n1 and n2), output: n1^n2 (n1 to the power of n1).
{
    int result = n1;

    for (int i = 1; i < n2; i++)
    {
        result *= n1;
    }

    return result;
}

int isArmstrong(int number)
{
    int nCopy = number, length = 0, sum = 0;

    while (nCopy)
    {
        length++;
        nCopy /= 10;
    }

    nCopy = number;

    while (nCopy)
    {
        sum += power((nCopy % 10), length);
        nCopy /= 10;
    }

    return sum == number;
}

int isPalindrome(int number)
{
    int nCopy = number, length = 0;

    while (nCopy)
    {
        length++;
        nCopy /= 10;
    }

    nCopy = number;
    int digits = power(10, length - 1);

    for (int i = 0; i < length / 2; i++)
    {
        if ((nCopy % 10) != (nCopy / digits)) //compare the first and last digits of the number.
        {
            return false;
        }

        nCopy %= digits; //remove the last digits of the number.
        nCopy /= 10; // remove the first digit of the number.
        digits /= 100; // the number is now 2 digits shorter so we divide "digits" by 10^2.
    }

    return true;
}