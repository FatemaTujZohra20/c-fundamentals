/*
 * break and continue.
 *
 *   break     leaves the loop entirely
 *   continue  skips the rest of this pass and starts the next one
 *
 *   1. demo_break()                   stopping early on a condition
 *   2. demo_continue()                skipping selected values
 *   3. break_in_nested_loop()         break leaves only the inner loop
 *   4. break_and_continue_together()  both in one loop
 *
 * In nested loops, both apply only to the innermost loop containing them.
 * Demo 3 is where that becomes visible: the break ends the inner loop, and
 * the outer loop carries on to its next pass regardless.
 *
 * Careful: in a for loop, continue still runs the update expression, so
 * the counter advances. In a while loop it does not - a continue placed
 * before the increment gives an infinite loop.
 */

#include <stdio.h>

/* break: the loop stops at 3, so 3, 4 and 5 never print. */
static void demo_break(void)
{
    int i;

    printf("--- break ---\n");
    for (i = 1; i <= 5; i++) {
        if (i == 3)
            break;
        printf("%d\n", i);
    }
    printf("Loop Ended\n\n");
}

/* continue: 3 is skipped, but the loop carries on to 4 and 5. */
static void demo_continue(void)
{
    int i;

    printf("--- continue ---\n");
    for (i = 1; i <= 5; i++) {
        if (i == 3)
            continue;
        printf("%d\n", i);
    }
    printf("Loop Ended\n\n");
}

/* break inside a nested loop ends only the inner loop. The outer loop
 * keeps going, which is why i = 3 still prints afterwards. */
static void break_in_nested_loop(void)
{
    int i, j;

    printf("--- break inside a nested loop ---\n");
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 5; j++) {
            if (i == 2 && j == 3)
                break;
            printf("i=%d, j=%d\n", i, j);
        }
    }
    printf("\n");
}

/* Both in one loop: skip the evens, and stop altogether at 7. */
static void break_and_continue_together(void)
{
    int count = 0;

    printf("--- both together ---\n");
    while (count < 10) {
        count++;

        if (count % 2 == 0)
            continue;       /* skip the even numbers */

        if (count == 7)
            break;          /* leave the loop at 7 */

        printf("%d\n", count);
    }
    printf("Loop exited.\n");
}

int main(void)
{
    demo_break();
    demo_continue();
    break_in_nested_loop();
    break_and_continue_together();

    return 0;
}
