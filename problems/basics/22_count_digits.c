/*
 * Count the number of digits in a given integer.
 *
 * Same idea as summing the digits - divide by 10 until nothing is left -
 * but counting the steps instead of adding the remainders.
 *
 * Two edge cases: 0 has one digit but the loop would never run for it,
 * and a negative number has to be made positive first or the division
 * never reaches 0 cleanly.
 */

#include <stdio.h>

int main(void)
{
    int number, count = 0;

    printf("Enter an Integer: ");
    if (scanf("%d", &number) != 1)
        return 1;

    if (number == 0) {
        count = 1;
    } else {
        if (number < 0)
            number = -number;

        while (number != 0) {
            number = number / 10;
            count++;
        }
    }

    printf("The number of digits of the number is = %d\n", count);

    return 0;
}
