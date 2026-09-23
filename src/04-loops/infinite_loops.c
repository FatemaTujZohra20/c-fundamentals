/*
 * Infinite loops, and the two ways to end one.
 *
 *     for ( ; ; )      no condition, so it never becomes false
 *     while (1)        the condition is always true
 *
 *   1. break_out_after_ten()   a counter and a break
 *   2. until_user_exits()      looping until input says to stop
 *   3. the_stray_semicolon()   a semicolon that becomes the loop body
 *
 * Either of the first two forms needs a break somewhere, or the program
 * never stops.
 *
 * This is the right shape when the number of passes is not known in
 * advance - a menu, or reading until a sentinel arrives. Compare
 * loop_until_sentinel.c, which writes the same job with the test in the
 * loop condition instead.
 *
 * Careful: a semicolon straight after the loop header becomes the entire
 * body, and the indented lines below it are then outside the loop. The for
 * loop in demo 3 still finishes, because its update slot keeps advancing
 * count - it simply does nothing eleven times, leaving count at 11. The
 * same slip on a while loop does not finish at all: with the increment
 * sitting outside the body, nothing advances the counter.
 */

#include <stdio.h>

/* Turning an infinite loop into a finite one with a break. */
static void break_out_after_ten(void)
{
    int count = 1;

    for ( ; ; ) {
        if (count > 10)
            break;

        printf("Count=%d\n", count);
        count++;
    }
}

/* The common real use: loop until the user asks to stop. */
static void until_user_exits(void)
{
    int num;

    for ( ; ; ) {
        printf("\nFor Exit -> Please Enter 0\n");
        printf("Enter a number: ");

        if (scanf("%d", &num) != 1)
            break;

        if (num == 0) {
            printf("\nYou Exit from the Loop\n");
            break;
        }

        printf("num = %d\n", num);
    }
}

/*
 * A classic mistake - the stray semicolon:
 *
 *     for (count = 0; count <= 10; count++);
 *     {
 *         printf("%d\n", count);
 *     }
 *
 * The `;` ends the loop immediately, so the loop body is empty. The
 * block below it is just an ordinary block that runs once, after the
 * loop has finished - so this prints 11, not 0 through 10.
 */
static void the_stray_semicolon(void)
{
    int count;

    for (count = 0; count <= 10; count++)
        ;   /* deliberately empty - on its own line so it is visible */

    printf("count after the empty loop = %d\n", count);
}

int main(void)
{
    break_out_after_ten();
    the_stray_semicolon();
    until_user_exits();

    return 0;
}
