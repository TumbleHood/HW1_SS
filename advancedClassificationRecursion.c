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

int isArmstrongHelper(int number, int length, int sum)
{
    if (!number)
    {
        return sum == number;
    }

    return isArmstrongHelper(number / 10, length, sum + power((number % 10), length));
}

int isArmstrong(int number) //calls the helper.
{
    int nCopy = number, length = 0;

    while (nCopy)
    {
        length++;
        nCopy /= 10;
    }

    return isArmstrongHelper(number, length, 0);
}

int isPalindromeHelper(int number, int digits)
{
    if((number / 10) == 0) //number is 1 digits (or less)
    {
        return true;
    }

    if((number % 10) != (number / digits))
    {
        return false;
    }

    return isPalindromeHelper((number / digits) % 10, digits / 100);
}

int isPalindrome(int number) //calls the helper.
{
    int nCopy = number, digits = 1;

    while(nCopy)
    {
        digits *= 10;
        nCopy /= 10;
    }

    return isPalindromeHelper(number, digits / 10);
}