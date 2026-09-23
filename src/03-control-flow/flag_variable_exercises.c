/*
 * Flag variables - two more uses of the same pattern.
 *
 *   1. validate_positive()           a flag recording whether the input
 *                                    passed a check
 *   2. natural_numbers_until_flag()  a flag ending a loop, instead of the
 *                                    limit living in the loop condition
 *
 * The second is the more interesting shape: `while (!flag)` has no idea
 * what it is counting towards, and the body decides when to stop. That is
 * how you write a loop whose end is discovered part way through - reading
 * until a sentinel arrives, or until input runs out.
 *
 * For a plain count to 10, `for (i = 1; i <= 10; i++)` says it more
 * directly. A flag earns its place when the stopping condition cannot be
 * expressed in the loop header.
 */

#include <stdio.h>
#include <stdbool.h>

/* 1. Validate input with a flag. */
static void validate_positive(void)
{
    bool flag = false;
    int number;

    printf("Enter a positive integer: ");
    if (scanf("%d", &number) != 1)
        return;

    if (number > 0)
        flag = true;

    if (flag)
        printf("You entered a valid number: %d\n", number);
    else
        printf("Invalid input! Please enter a positive integer.\n");
}

/* 2. Print natural numbers up to 10, using a flag to end the loop
 *    instead of putting the limit in the loop condition. */
static void natural_numbers_until_flag(void)
{
    bool flag = false;
    int i = 1;

    while (!flag) {
        printf("%d\t", i);
        i++;

        if (i > 10)
            flag = true;
    }

    printf("\nThe value of i is exceeded!\n");
}

int main(void)
{
    natural_numbers_until_flag();
    validate_positive();

    return 0;
}
