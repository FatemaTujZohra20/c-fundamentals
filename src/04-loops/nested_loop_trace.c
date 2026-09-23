/*
 * Nested loops - tracing the order things actually run in.
 *
 * The inner loop runs to completion on every single pass of the outer
 * loop. The markers make that order visible:
 *
 *     Outer Loop Start        <- i = 1
 *     *** inner loop          <- j runs 1, 2, 3
 *     *** inner loop
 *     *** inner loop
 *     Outer Loop End
 *
 *     Outer Loop Start        <- i = 2, and j starts over from 1
 *     ...
 *
 * Two consequences, and both matter for every pattern in this folder: the
 * inner body runs (outer count x inner count) times in total, and j is
 * reinitialised on each outer pass, so it always restarts.
 */

#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 1; i <= 2; i++) {
        printf("Outer Loop Start\n");

        for (j = 1; j <= 3; j++)
            printf("*** inner loop\n");

        printf("Outer Loop End\n\n");
    }

    return 0;
}
