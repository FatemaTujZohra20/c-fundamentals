/*
 * Two-dimensional arrays.
 *
 * int x[2][3] is 2 rows of 3 columns - read it as "an array of 2 things,
 * each of which is an array of 3 ints".
 *
 *     x[1][2]        row 1, column 2
 *
 * The outer loop walks the rows and the inner loop walks the columns,
 * which is the same nesting as every pattern in 04-loops.
 *
 * The rows sit one after another in memory, so x[0][2] and x[1][0] are
 * neighbours. A 2D array is a flat block with an agreed row length, not an
 * array of separate row objects.
 *
 * Careful: the indexes are written separately - x[1][2], never x[1, 2].
 * The second form is the comma operator inside one set of brackets, which
 * is not a 2D index at all.
 */

#include <stdio.h>

int main(void)
{
    int x[2][3] = {{11, 12, 13}, {21, 22, 23}};
    int a[3][3];
    int i, j, sum = 0;
    float average;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++)
            printf("x[%d][%d] = %d\n", i, j, x[i][j]);
    }

    /* Take a 3x3 array from the user and print the average of its values. */
    printf("\nEnter 9 integers for a 3x3 array:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
            sum += a[i][j];
        }
        printf("\n");
    }

    /* 9.0 rather than 9 - integer division would throw away the fraction. */
    average = sum / 9.0f;
    printf("Average is: %f\n",   average);
    printf("Average is: %.2f\n", average);
    printf("Average is: %.4f\n", average);

    return 0;
}
