/*
 * Finding the largest of three numbers through pointers.
 *
 * The comparison itself is ordinary: `*p1 > *p2` dereferences both
 * pointers and compares the two ints, so this is the same if/else ladder
 * as largest_of_three.c in 03-control-flow. Pointers buy nothing here -
 * the three values are local and could be compared directly. The point of
 * the exercise is reading `*p` fluently inside a condition.
 *
 *     int  x  = 10;
 *     int *p1 = &x;      p1 holds the ADDRESS of x
 *     *p1                the VALUE 10, read back through that address
 *
 * Careful: `*p1 > *p2` compares the pointed-to values, while `p1 > p2`
 * would compare the two addresses. Both compile; only the first is a
 * comparison of numbers.
 */

#include <stdio.h>

int main(void)
{
    int x = 10, y = 20, z = 30;
    int *p1 = &x, *p2 = &y, *p3 = &z;

    if (*p1 > *p2 && *p1 > *p3)
        printf("The largest number is: %d\n", *p1);
    else if (*p2 > *p1 && *p2 > *p3)
        printf("The largest number is: %d\n", *p2);
    else
        printf("The largest number is: %d\n", *p3);

    return 0;
}
