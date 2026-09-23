/*
 * Loop stepping, simple triangles, and operator precedence.
 *
 *   1. stepping()      the update expression sets the step: i++ walks by
 *                      one, i = i + 2 walks by two
 *   2. triangles()     a nested loop whose inner limit depends on the
 *                      outer counter - growing, then shrinking
 *   3. precedence()    how && and || group inside one condition
 *
 * triangles() holds the idea behind every pattern in this folder: when the
 * inner loop's limit is the outer loop's counter, the number of characters
 * per row changes as the rows advance. The second triangle starts its
 * inner counter at 2 instead of 1, which is what makes each row one
 * character shorter than the row above.
 */

#include <stdio.h>

/* Stepping by 1 vs. stepping by 2. */
static void stepping(void)
{
    int a, i;

    for (a = 1; a <= 10; a++)
        printf("*\t");
    printf("\n\nOut of loop\n");

    for (i = 2; i < 100; i = i + 2)
        printf("%d\t", i);
    printf("\n");
}

/* An increasing triangle, then a decreasing one. */
static void triangles(void)
{
    int i, j;

    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    for (i = 5; i >= 1; i--) {
        for (j = 2; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

/*
 * Operator precedence in a compound condition.
 *
 *   (a < b) && (a == 10) || (b >= 20) && !(a > c)
 *    1      &&  1        ||  1        && !1
 *    1                   ||  1        &&  0
 *    1                   ||  0
 *    1
 *
 * && binds tighter than ||, so both && groups are evaluated first.
 * The parentheses below are not required, but gcc suggests them and
 * they make the grouping impossible to misread.
 */
static void precedence(void)
{
    int a = 10, b = 20, c = 5, result;

    result = ((a < b) && (a == 10)) || ((b >= 20) && !(a > c));
    printf("Result is %d\n", result);
}

int main(void)
{
    stepping();
    triangles();
    precedence();

    return 0;
}
