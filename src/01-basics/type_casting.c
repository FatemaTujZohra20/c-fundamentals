/*
 * Type casting - converting a value from one type to another on purpose.
 *
 *     double x = 10.5;
 *     int    n = (int)x;       n holds 10
 *
 * A cast to int truncates towards zero rather than rounding: 10.5 becomes
 * 10, and -10.5 becomes -10, not -11. To round, add 0.5 before casting,
 * or use round() from <math.h>.
 *
 * x itself is untouched. A cast produces a new value; it does not modify
 * the variable it reads from.
 *
 * Careful: the format specifier has to match the type that arrives -
 * %d for the int, %lf for the double. Mismatching them is undefined
 * behaviour, not a silent conversion.
 */

#include <stdio.h>

int main(void)
{
    int    n;
    double x = 10.5;

    n = (int)x;      /* truncates towards zero: 10.5 -> 10 */

    printf("Value of n is %d\n", n);
    printf("Value of x is %.2lf\n", x);

    return 0;
}
