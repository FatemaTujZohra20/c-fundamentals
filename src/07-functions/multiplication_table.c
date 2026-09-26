/*
 * A function that prints a multiplication table (namta).
 *
 * The loop itself is nothing new. The point is what wrapping it in a
 * function buys: the table for any number becomes one call, and the loop
 * is written once instead of being copied for each number wanted.
 *
 *     namta(7);       prints the 7 times table
 *
 * x is a parameter rather than something namta() reads for itself, which
 * keeps the printing separate from the deciding. main() chooses the
 * number; namta() only prints. That split is what makes the function
 * reusable - compare multiplication_table.c in problems/basics, which
 * reads its own input.
 */

#include <stdio.h>

static void namta(int x)
{
    int i;

    printf("Namta of %d:\n", x);
    for (i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", x, i, x * i);
    printf("\n");
}

int main(void)
{
    namta(5);
    namta(3);
    namta(7);

    return 0;
}
