/*
 * if / else - the basic shapes of a conditional, seven at a time.
 *
 *   1. positive_or_negative()  two-way choice with else
 *   2. sign_of_a_number()      three-way choice with else if
 *   3. first_match_wins()      only the first true branch runs
 *   4. even_or_odd()           testing a remainder
 *   5. letter_case()           a char is a small integer, so it compares
 *   6. ternary()               if/else as an expression with a value
 *   7. age_group()             a ladder over ranges, reading from input
 *
 * What ties them together is that a ladder stops at its first true test.
 * That is what lets age_group() write `age < 10` without also checking
 * `age >= 2` - reaching that branch at all already proves it.
 *
 * Careful: a condition needs a comparison, not an assignment.
 * `if (n = 0)` assigns and then tests the result, so it is always false.
 * `if (n == 0)` is the test.
 */

#include <stdio.h>

/* 1. Two-way choice. */
static void positive_or_negative(void)
{
    int n = -5;

    if (n < 0)
        printf("The number is negative\n");
    else
        printf("The number is positive\n");
}

/* 2. Three-way choice with else-if. */
static void sign_of_a_number(void)
{
    int n = 10;

    if (n < 0)
        printf("The number is Negative\n");
    else if (n > 0)
        printf("The number is Positive\n");
    else
        printf("The number is Zero\n");
}

/* 3. Order matters in a ladder: the first true branch wins and the rest
 *    are skipped, even if they would also be true. n = 10 is less than
 *    both 30 and 50, but only the first message prints. */
static void first_match_wins(void)
{
    int n = 10;

    if (n < 30)
        printf("The number is less than 30.\n");
    else if (n < 50)
        printf("The number is less than 50.\n");
}

/* 4. Even or odd, from the remainder. */
static void even_or_odd(void)
{
    int number = 5;
    int remainder = number % 2;

    if (remainder == 0)
        printf("The number is even\n");
    else
        printf("The number is odd\n");
}

/* 5. Comparing characters - a char is just a small integer, so it can be
 *    compared with < and > against the ends of a range. */
static void letter_case(void)
{
    char ch = 'z';

    if (ch >= 'a' && ch <= 'z')
        printf("%c is lower case\n", ch);
    else if (ch >= 'A' && ch <= 'Z')
        printf("%c is upper case\n", ch);
}

/* 6. An age classifier. Because a ladder stops at the first match, the
 *    later tests do not need to repeat the lower bound: reaching
 *    `age < 10` already proves age >= 2. */
static void age_group(void)
{
    int age;

    printf("Enter a person's age: ");
    if (scanf("%d", &age) != 1)
        return;

    if (age < 2)
        printf("Infant\n");
    else if (age < 10)
        printf("Child\n");
    else if (age < 20)
        printf("Teenage\n");
    else if (age < 30)
        printf("Adult\n");
    else
        printf("Old\n");
}

/* 7. The ternary operator: a compact if/else that produces a value. */
static void ternary(void)
{
    int time = 20;

    (time < 18) ? printf("Good Morning!\n") : printf("Good Evening\n");
}

int main(void)
{
    positive_or_negative();
    sign_of_a_number();
    first_match_wins();
    even_or_odd();
    letter_case();
    ternary();
    age_group();

    return 0;
}
