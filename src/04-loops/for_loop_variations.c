/*
 * The three parts of a for loop are all optional, and each can hold more
 * than one expression.
 *
 *     for (init; condition; update)
 *
 *   1. no_initialization()            init left empty, counter set before
 *   2. multiple_initialization()      two variables, comma separated
 *   3. initialization_with_input()    init can be any expression, even a
 *                                    scanf call
 *   4. no_update()                    update left empty, counter advanced
 *                                    in the body
 *   5. multiple_update()              two variables advanced at once
 *   6. compound_condition()           && inside the condition
 *   7. comma_in_condition_is_a_trap() three counters advancing at
 *                                     different rates, with only one of
 *                                     them controlling the loop
 *
 * An empty condition means "always true", so `for ( ; ; )` is an infinite
 * loop - see infinite_loops.c.
 *
 * Careful: the commas in init and update are the comma operator, and every
 * expression runs. The condition slot takes one condition, and listing
 * several is the trap in demo 7's name: `k <= 15, i <= 5` compiles, but
 * the comma operator throws away everything except the rightmost value,
 * so only `i <= 5` would be tested. That is why the loop below advances
 * three counters and tests just k.
 */

#include <stdio.h>

/* No initialization: i is already set before the loop. */
static void no_initialization(void)
{
    int i = 1;

    for (; i <= 5; i++)
        printf("%d\n", i);
}

/* Multiple initialization, separated by the comma operator. */
static void multiple_initialization(void)
{
    int i, j, k;

    for (i = 1, j = 10, k = 15; i <= 5; i++) {
        printf("i = %d, j = %d, k = %d\n", i, j, k);
        j--;
        k++;
    }
}

/* The initialization can be any expression at all, including a call. */
static void initialization_with_input(void)
{
    int i, j;

    printf("Enter a starting number: ");

    /* The result of scanf is checked here so no input error slips by;
     * the comma operator then discards it and moves on to j = i + 1. */
    for (scanf("%d", &i) == 1 ? 0 : (i = 11), j = i + 1; i <= 10; i++)
        printf("i = %d, j = %d\n", i, j++);
}

/* No update section: the counter is advanced inside the body instead. */
static void no_update(void)
{
    int i;

    for (i = 1; i <= 10; ) {
        printf("i = %d\n", i);
        i++;
    }
}

/* Multiple update expressions - two counters moving towards each other. */
static void multiple_update(void)
{
    int i, j;

    for (i = 1, j = 5; i <= j; i++, j--)
        printf("i = %d, j = %d\n", i, j);
}

/* A condition can combine tests with && - the loop ends as soon as
 * either one fails. */
static void compound_condition(void)
{
    int i, j;

    for (i = 1, j = 1; i <= 20 && j <= 10; i++, j = j + 2)
        printf("i = %d, j = %d\n", i, j);
}

/*
 * A trap: commas in the CONDITION are not a logical "and".
 *
 *     for (i=1, j=1, k=1; i <= 20, j <= 10, k <= 15; ...)
 *
 * The comma operator throws away everything but the last expression, so
 * only `k <= 15` actually controls the loop - `i <= 20` and `j <= 10`
 * are evaluated and discarded. Use && when you mean "and".
 */
static void comma_in_condition_is_a_trap(void)
{
    int i, j, k;

    for (i = 1, j = 1, k = 1; k <= 15; i++, j = j + 2, k = k + 3)
        printf("i=%d, j=%d, k=%d\n", i, j, k);
}

int main(void)
{
    printf("--- no initialization ---\n");
    no_initialization();

    printf("\n--- multiple initialization ---\n");
    multiple_initialization();

    printf("\n--- no update section ---\n");
    no_update();

    printf("\n--- multiple update ---\n");
    multiple_update();

    printf("\n--- compound condition ---\n");
    compound_condition();

    printf("\n--- only the last comma expression counts ---\n");
    comma_in_condition_is_a_trap();

    printf("\n--- initialization that reads input ---\n");
    initialization_with_input();

    return 0;
}
