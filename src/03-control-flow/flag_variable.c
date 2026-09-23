/*
 * The flag idea: a variable that records whether something happened, so
 * the answer can be checked later rather than acted on immediately.
 *
 * The pattern is always these three steps:
 *
 *     bool flag = false;        start from "it has not happened"
 *     if (condition)            somewhere, the thing happens
 *         flag = true;
 *     if (flag)                 later, react to it
 *
 * <stdbool.h> supplies bool, true and false. A bool takes 1 byte where an
 * int takes 4, and it states the intent: this variable holds a yes/no,
 * not a number.
 *
 * Initialising to false is what makes the absent `else` correct. If the
 * condition does not hold, flag is already false and there is nothing
 * left to do.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num;
    bool flag = false;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1)
        return 1;

    if (num >= 0)
        flag = true;

    /* An `else { flag = false; }` here would be redundant - flag already
     * starts out false, so leaving it alone says the same thing. */

    if (flag)
        printf("The number is a positive integer.\n");
    else
        printf("The number is a negative integer.\n");

    return 0;
}
