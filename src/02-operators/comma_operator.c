/*
 * The comma operator.
 *
 * In an expression, `(a, b)` evaluates a, discards the result, then
 * evaluates b - and the value of the whole thing is b, the rightmost one.
 *
 * This is not the comma that separates function arguments or variable
 * declarations. Those are punctuation; only this one is an operator.
 *
 * The four examples below each take their value from the rightmost item,
 * including the last, where the rightmost item is a printf and so the
 * result is the number of characters it wrote.
 *
 * The (void) casts are deliberate. Discarding a plain variable makes gcc
 * warn that the left operand "has no effect" - which is precisely the
 * behaviour being demonstrated. Casting to (void) says the discard is
 * intentional, and leaves the result unchanged.
 */

#include <stdio.h>

int main(void)
{
    int a = 5, b = 10, c = 15, x;

    printf("a=%d, b=%d, c=%d\n", a, b, c);

    x = ((void)a, b);         /* the rightmost value wins: 10 */
    printf("x1 = %d\n", x);

    x = ((void)a, (void)b, c);      /* 15 */
    printf("x2 = %d\n", x);

    /* printf runs, its result is discarded, and x gets a. */
    x = (printf("Call x3\n"), a);
    printf("x3 = %d\n", x);

    /* Here the rightmost item is the printf, so x gets its return value -
     * the number of characters it wrote ("Call x4\n" is 8). */
    x = ((void)a, printf("Call x4\n"));
    printf("x4 = %d\n", x);

    return 0;
}
