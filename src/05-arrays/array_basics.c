/*
 * Arrays - declaring, indexing, measuring and iterating.
 *
 * An array is a fixed number of values of one type, laid out next to each
 * other in memory and reached by a numeric index.
 *
 *     int fixed[5] = {5, 6, 7, 8, 3};
 *     fixed[0]       the first element, not fixed[1]
 *     fixed[4]       the last one
 *
 * Indexing starts at 0, so an array of 5 has valid indexes 0 to 4.
 *
 * C does not record an array's length anywhere, so there is nothing to
 * ask. It is computed instead:
 *
 *     sizeof(myNumbers) / sizeof(myNumbers[0])
 *
 * total bytes divided by bytes per element. This only works where the real
 * array is visible. Inside a function that received the array as a
 * parameter it has decayed to a pointer and the length must be passed in
 * separately - see array_as_argument.c in 07-functions.
 *
 * The last loop makes a point worth keeping: the index written into the
 * array need not be the loop counter. The counter runs 105..114 while the
 * element written is sqrs[i - 105].
 */

#include <stdio.h>

int main(void)
{
    int  myNumbers[] = {10, 25, 50, 75, 100};
    int  length;
    int  a[3];
    int  fixed[5] = {5, 6, 7, 8, 3};
    int  sqrs[10];
    int  i, x;

    /* Indexing starts at 0. */
    printf("First element: %d\n", myNumbers[0]);

    /* There is no built-in length, so it is computed from the sizes. */
    length = sizeof(myNumbers) / sizeof(myNumbers[0]);
    printf("Length: %d\n", length);

    /* Elements are ordinary variables - assign and re-assign freely. */
    a[0] = 3;
    a[1] = 4;
    a[2] = 400;
    x = a[0] + a[2];
    printf("a[0] + a[2] = %d\n", x);

    a[2] = 100;
    x = a[0] + a[2];
    printf("after a[2] = 100, a[0] + a[2] = %d\n", x);

    /* Walking an array with a for loop. */
    for (i = 0; i < 5; i++)
        printf("fixed[%d] = %d\n", i, fixed[i]);

    /* The index written into the array need not match the loop counter. */
    for (i = 105; i < 115; i++)
        sqrs[i - 105] = i * i;

    printf("Squares of 105..114: ");
    for (i = 0; i < 10; i++)
        printf("%d ", sqrs[i]);
    printf("\n");

    return 0;
}
