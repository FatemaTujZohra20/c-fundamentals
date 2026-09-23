/*
 * while vs. do-while.
 *
 * A while loop tests the condition before the body, so the body may run
 * zero times. A do-while tests it after, so the body always runs at least
 * once.
 *
 *     while (cond) { ... }        test, then maybe run
 *     do { ... } while (cond);    run, then test
 *
 *   1. basic_while()                  the shape
 *   2. counting_down()                a decreasing counter
 *   3. numbers_1_to_100()             a long count
 *   4. evens_and_odds()               a test inside the body
 *   5. basic_do_while()               the shape
 *   6. do_while_runs_at_least_once()  a false condition, body still runs
 *   7. countdown_by_five()            a step other than one
 *
 * do-while suits anything that must happen before there is something to
 * test: read input, then decide whether to read again. That is why menus
 * and validation loops are usually do-while.
 *
 * Careful: a do-while ends with a semicolon after the condition. A while
 * loop must advance its counter in the body - a for loop has a slot for
 * that, a while loop does not, and forgetting it is the usual cause of a
 * loop that never ends.
 */

#include <stdio.h>

static void basic_while(void)
{
    int x = 1;

    while (x <= 3) {
        printf("Hi\n");
        printf("Hello\n");
        x = x + 2;
    }
}

/* Counting down - the condition and the step both have to be reversed. */
static void counting_down(void)
{
    int x = 20;

    while (x >= 15) {
        printf("x = %d\n", x);
        x = x - 2;
    }
}

static void numbers_1_to_100(void)
{
    int i = 1;

    while (i <= 100) {
        printf("%d ", i);
        i = i + 1;
    }
    printf("\n");
}

/* Start at 2 and step by 2 for evens; start at 1 and step by 2 for odds. */
static void evens_and_odds(void)
{
    int i;

    printf("Even: ");
    for (i = 2; i <= 100; i += 2)
        printf("%d ", i);
    printf("\n");

    printf("Odd:  ");
    for (i = 1; i <= 100; i += 2)
        printf("%d ", i);
    printf("\n");
}

static void basic_do_while(void)
{
    int i = 1;

    do {
        printf("Let me go!\n");
        i = i + 1;
    } while (i <= 4);
}

/*
 * The body runs once even though the condition is false from the start:
 * i begins at -10, which is not >= -12 after the first decrement... but
 * "Let me go!" has already printed. That is the difference from while.
 */
static void do_while_runs_at_least_once(void)
{
    int i = -10;

    do {
        printf("Let me go! (i = %d)\n", i);
        i = i - 3;
    } while (i >= -12);
}

static void countdown_by_five(void)
{
    int i = 100;

    do {
        printf("%d ", i);
        i = i - 5;
    } while (i >= 0);
    printf("\n");
}

int main(void)
{
    basic_while();
    counting_down();
    numbers_1_to_100();
    evens_and_odds();
    basic_do_while();
    do_while_runs_at_least_once();
    countdown_by_five();

    return 0;
}
