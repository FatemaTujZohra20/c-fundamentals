/*
 * Find the sum of all the digits of an integer.
 *
 * num % 10 gives the last digit, and num / 10 removes it. Repeating
 * both until the number reaches 0 walks through every digit.
 *
 *   1234 -> 4, 123 -> 3, 12 -> 2, 1 -> 1, 0   sum = 10
 */

#include <stdio.h>

int main(void)
{
    int number, sum = 0, remainder;

    printf("Enter an Integer: ");
    if (scanf("%d", &number) != 1)
        return 1;

    /* Work with the absolute value so negatives behave sensibly. */
    if (number < 0)
        number = -number;

    while (number != 0) {
        remainder = number % 10;
        sum = sum + remainder;
        number = number / 10;
    }

    printf("The sum of all digits of the number is = %d\n", sum);

    return 0;
}
