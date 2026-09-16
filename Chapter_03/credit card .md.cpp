 Credit Card Validation Program
Introduction

This is a C++ program that checks whether a credit card number is valid or not. The program uses the Luhn algorithm together with the card length and starting digits (prefix) to perform the validation.

The program asks the user to enter a credit card number and then displays whether the number is valid or invalid.
 How the Program Works

The program mainly checks three things:

1. The credit card number should contain between 13 and 16 digits.
2. The number should start with `4`, `5`, `37`, or `6`.
3. The number must satisfy the Luhn checksum. The total obtained from the calculation should be divisible by 10.

If all three conditions are true, the program considers the credit card number valid.
Header File
#include <iostream>
using namespace std;
`iostream` is used because the program needs `cin` and `cout` to receive input from the user and display output.

The original program also had:
#include <vector>
but it is not required because no vector is used in the program.

Function Prototypes

The program declares the functions before `main()`:
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);
These declarations tell the compiler about the functions that will be defined later.

Main Function

int main()
{
    long long number;

    cout << "Enter credit card number: ";
    cin >> number;

    if (isValid(number))
        cout << number << " is valid" << endl;
    else
        cout << number << " is invalid" << endl;

    return 0;
}

First, a variable called `number` is created to store the credit card number.

The user is then asked to enter the number. The value is passed to the `isValid()` function.

If `isValid()` returns `true`, the program prints:
is valid
Otherwise, it prints:
text
is invalid
 The isValid Function
bool isValid(long long number)
{
    return (getSize(number) >= 13 && getSize(number) <= 16) &&
    (prefixMatched(number, 4) || prefixMatched(number, 5) ||
    prefixMatched(number, 37) || prefixMatched(number, 6)) &&
    ((sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0);
This is the main function responsible for deciding if the number is valid.
It combines three checks using logical operators.

Checking the Size
getSize(number) >= 13 && getSize(number) <= 16
This makes sure that the number has at least 13 digits and not more than 16 digits.

Checking the Prefix
prefixMatched(number, 4) ||
prefixMatched(number, 5) ||
prefixMatched(number, 37) ||
prefixMatched(number, 6)
This checks if the number starts with one of the accepted prefixes.

The `||` operator means OR, so only one of these prefix checks needs to be true.
 Checking the Luhn Calculation

(sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0
The two sums are added together. The result is then divided by 10 using the modulus operator `%`.

For the card to pass the check, the remainder must be zero.
 sumOfDoubleEvenPlace Function
int sumOfDoubleEvenPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (isEvenPlace)
        {
            sum += getDigit(digit * 2);
        }

        isEvenPlace = !isEvenPlace;
        number /= 10;
    }

    return sum;
}

This function is used for the digits that need to be doubled during the Luhn calculation.

The program starts processing the number from the right side because:
number % 10
gets the last digit

The Boolean variable `isEvenPlace` is changed between `true` and `false` so that alternate digits can be selected.
When a digit is selected, it is multiplied by 2:
digit * 2
The result is then passed to `getDigit()`.

## getDigit Function
int getDigit(int number)
{
    if (number < 10)
        return number;
    else
        return number / 10 + number % 10;
}

This function returns the digit itself when the number is less than 10.

If the number is 10 or greater, it adds its two digits together.

For example text;
14 → 1 + 4 → 5
So;
getDigit(14)
returns `5`.
This is useful when a digit is doubled and the result becomes a two-digit number.
 sumOfOddPlace Function
int sumOfOddPlace(long long number)
{
    int sum = 0;
    bool isEvenPlace = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (!isEvenPlace)
        {
            sum += digit;
        }

        isEvenPlace = !isEvenPlace;
        number /= 10;
    }

    return sum;
}
This function adds the digits that are not doubled.
Like the previous function, it starts from the rightmost digit and processes the digits one at a time.
The Boolean variable is used to alternate between the digits that are added directly and the digits that are sent to the doubling function.

## prefixMatched Function
bool prefixMatched(long long number, int d)
{
    return getPrefix(number, getSize(d)) == d;
}
This function checks whether the beginning of the credit card number matches a given prefix.

For example, if the prefix being checked is `37`, the function gets the first two digits of the card number and compares them with `37`.
getSize Function
int getSize(long long d)
{
    int size = 0;

    while (d > 0)
    {
        size++;
        d /= 10;
    }

    return size;
}
This function counts the number of digits in a number.

For example:
text
123456
has 6 digits, so:
getSize(123456)
returns `6`
The number is repeatedly divided by 10 until it becomes zero.
getPrefix Function
long long getPrefix(long long number, int k)
{
    int size = getSize(number);

    if (size < k)
        return number;
    else
    {
        for (int i = 0; i < size - k; i++)
            number /= 10;

        return number;
    }
}
This function gets the first `k` digits of a number.

For example, if:
number = 371234567890
k = 2
the function returns:
text 37
It does this by repeatedly dividing the number by 10 until only the required number of digits remain.
