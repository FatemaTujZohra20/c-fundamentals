/*
 * Reading three integers and printing their average.
 *
 * The whole exercise is in one line:
 *
 *     average = (a + b + c) / 3.0f;
 *
 * Dividing by 3 would be integer division - 10 / 3 gives 3, and the
 * remainder is thrown away before it can ever reach the float. Dividing
 * by 3.0f makes the expression floating point, so the fraction survives.
 *
 * Careful: the type of the variable being assigned to does not rescue
 * you. `float average = (a + b + c) / 3;` still truncates, because the
 * division is evaluated first and only the result is widened afterwards.
 */

#include <stdio.h>

int main(void)
{
    int a, b, c;
    float average;

    printf("Enter three integers: ");
    if (scanf("%d %d %d", &a, &b, &c) != 3)
        return 1;

    average = (a + b + c) / 3.0f;    /* 3.0f, not 3 - see the header */

    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("Value of c: %d\n", c);
    printf("Average of a, b, and c: %.2f\n", average);

    return 0;
}
