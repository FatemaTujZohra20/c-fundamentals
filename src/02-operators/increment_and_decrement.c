/*
 * ++ and -- , prefix and postfix.
 *
 * Both forms change the variable by one. What differs is the value the
 * expression itself produces:
 *
 *   x = a++;   x gets the OLD value of a, then a increases  (postfix)
 *   x = ++a;   a increases first, then x gets the NEW value (prefix)
 *
 * The same applies to --.
 *
 * As a statement on its own, `a++;` and `++a;` are identical - nothing
 * reads the expression's value, so only the side effect matters. The
 * distinction appears only when that value is used, as in every line
 * below.
 *
 * The block at the end of main() explains why combining several ++ on
 * one variable inside a single expression is undefined behaviour.
 */

#include <stdio.h>

int main(void)
{
    int x, y, p, q, a = 4, b = 10;

    x = a++;                                    /* x gets 4, a becomes 5 */
    printf("x = %d, a = %d\n", x, a);

    x = ++a;                                    /* a becomes 6, x gets 6 */
    printf("x = %d, a = %d\n", x, a);

    y = b--;                                    /* y gets 10, b becomes 9 */
    printf("y = %d, b = %d\n", y, b);

    p = a++;
    printf("p = %d, a = %d\n", p, a);

    q = ++b;
    printf("q = %d, b = %d\n", q, b);

    printf("\na = %d, b = %d, x = %d, y = %d, p = %d, q = %d\n",
           a, b, x, y, p, q);

    /*
     * A warning about combining them in one expression:
     *
     *     int a = 10;
     *     printf("%d %d %d %d", a++, --a, ++a, a);
     *
     * This is undefined behaviour, not a "compiler optimisation quirk".
     * The C standard does not say what order the arguments are evaluated
     * in, and a is modified more than once between sequence points, so
     * any output is permitted and different compilers will disagree.
     * Never write this - change one variable per statement.
     */

    return 0;
}
