/*
 * && (and) and || (or) inside conditions.
 *
 * && is true only when both sides are; || is true when at least one is.
 *
 *   1. and_versus_or()        a range check, and why || cannot be one
 *   2. divisible_by_3_or_5()  || over two independent tests
 *   3. vowel_or_consonant()   chained || to test membership of a set
 *
 * Both operators short-circuit: when the left side already settles the
 * answer, the right side is never evaluated. A false left side makes &&
 * false; a true left side makes || true. That is what makes
 * `if (n != 0 && 100 / n > 2)` safe - the division cannot run when n
 * is 0.
 *
 * Careful: each side has to be a complete condition on its own.
 * `if (x > 50 && < 200)` does not compile, and `if (50 < x < 200)`
 * compiles but does not mean what it looks like - it compares the 0 or 1
 * produced by `50 < x` against 200, so it is always true.
 */

#include <stdio.h>

/* && needs both sides true; || needs only one. */
static void and_versus_or(void)
{
    int x = 100;
    int y = 250;

    if (x > 50 && x < 200)
        printf("x = %d is in range (both sides of && are true)\n", x);

    if (y > 50 && y < 200)
        printf("y = %d is in range\n", y);
    else
        printf("y = %d is out of range (y < 200 is false)\n", y);

    /* Careful: this || is true for almost any number - y > 50 fails but
     * y < 200 is not required to hold at the same time. A range check
     * needs &&, not ||. */
    if (y > 50 || y < 200)
        printf("y = %d passes the || test, which is not a range check\n", y);
}

/* Divisible by 3 or by 5. */
static void divisible_by_3_or_5(void)
{
    int a;

    printf("Enter the value of a: ");
    if (scanf("%d", &a) != 1)
        return;

    if (a % 3 == 0 || a % 5 == 0)
        printf("The number is divisible by 3 or 5.\n");
    else
        printf("The number is not divisible by 3 or 5.\n");
}

/* Chained || to test membership in a small set. */
static void vowel_or_consonant(void)
{
    char letter;

    printf("Enter a lower-case letter: ");
    if (scanf(" %c", &letter) != 1)
        return;

    if (letter == 'a' || letter == 'e' || letter == 'i'
        || letter == 'o' || letter == 'u')
        printf("The alphabet is a vowel.\n");
    else
        printf("The alphabet is a consonant.\n");
}

int main(void)
{
    and_versus_or();
    divisible_by_3_or_5();
    vowel_or_consonant();

    return 0;
}
