/*
 * Looping until the user enters a sentinel - a value that means "stop"
 * rather than being data.
 *
 *   1. count_towards_minus_32()  `while (1)` with the test and a break
 *                                inside the body
 *   2. until_negative()          the same job, with the test in the loop
 *                                condition
 *
 * Both are correct. The difference is where the stopping rule lives: in
 * the condition, where it is visible at the top, or in the body, which is
 * the only option when the test needs something the loop must read first.
 *
 * Careful: a sentinel has to be a value the real data can never take.
 * Using 0 or -1 as the stop value only works while 0 or -1 is not a
 * legitimate input.
 */

#include <stdio.h>

/* Count from n down (or up) to -32, whichever direction is needed.
 * Entering -1 ends the program. */
static void count_towards_minus_32(void)
{
    int n, i;

    while (1) {
        printf("\nEnter the value of N [input -1 to stop]: ");
        if (scanf("%d", &n) != 1)
            return;

        if (n == -1)
            break;

        if (n > -32) {
            for (i = n; i >= -32; i--)
                printf("%d ", i);
        } else {
            for (i = n; i <= -32; i++)
                printf("%d ", i);
        }
        printf("\n");
    }
}

/*
 * The same idea with the test in the condition. scanf's return value is
 * checked at the same time, so bad input also ends the loop.
 */
static void until_negative(void)
{
    int number;

    printf("Enter a positive number (negative to quit): ");
    while (scanf("%d", &number) == 1 && number >= 0) {
        printf("You entered: %d\n", number);
        printf("Enter a positive number (negative to quit): ");
    }

    printf("Exiting the program.\n");
}

int main(void)
{
    count_towards_minus_32();
    until_negative();

    return 0;
}
