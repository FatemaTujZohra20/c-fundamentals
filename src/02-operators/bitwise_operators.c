/*
 * Bitwise operators, and how they differ from logical operators.
 *
 * A bitwise operator works on the individual bits of a value. A logical
 * operator collapses each side to a single true/false first. The two
 * demos below are where that distinction bites:
 *
 *   1. bitwise_versus_logical()  -  1 & 2 is 0, but 1 && 2 is true
 *   2. check_odd_even()          -  (n & 1) tests the lowest bit
 *
 * Careful: the result of & is a number, not a truth value. `x & y` being
 * 0 does not mean x and y are both zero - it means they have no set bit
 * in common.
 */

#include <stdio.h>

/*
 * & compares bit by bit; && compares whole values as true/false.
 *
 * A char is 1 byte = 8 bits, so 1 is 0000 0001 and 2 is 0000 0010.
 *
 *   x & y   ->  0000 0001 & 0000 0010  =  0000 0000  =  0  (false)
 *   x && y  ->  "x is non-zero" and "y is non-zero"  =  1  (true)
 *
 * The two operators disagree here, and that is the whole point.
 */
static void bitwise_versus_logical(void)
{
    char x = 1, y = 2;

    if (x & y)
        printf("x & y is non-zero\n");
    else
        printf("x & y is 0 - no bit is set in both x and y\n");

    if (x && y)
        printf("x && y is true - both values are non-zero\n");
    else
        printf("x && y is false\n");
}

/*
 * Even or odd using bitwise AND.
 *
 * The lowest bit of a number is 1 exactly when the number is odd, so
 * (n & 1) tests oddness without a division.
 */
static int is_odd(int n)
{
    return n & 1;
}

static void check_odd_even(void)
{
    int n;

    printf("Input any number: ");
    if (scanf("%d", &n) != 1)
        return;

    if (is_odd(n))
        printf("odd\n");
    else
        printf("even\n");
}

int main(void)
{
    bitwise_versus_logical();
    check_odd_even();

    return 0;
}
