/*
 * Function exercises.
 *
 *   1. even_or_odd()    report whether a number is even or odd
 *   2. find_divisors()  print every divisor of a number
 *   3. calculator()     one function per operation, all four applied to
 *                       the same pair of numbers
 *
 * The calculator is the one to look at. add(), subtract(), multiply() and
 * divide() share a signature - two floats in, one float out - and each is
 * a single line. Splitting them out leaves calculator() reading as a list
 * of what it reports, with no arithmetic buried inside the printf calls.
 *
 * find_divisors() tests `x % i == 0` for each i up to x. A divisor is a
 * number that divides with no remainder, so the remainder operator is the
 * entire test.
 *
 * The division is guarded by `if (b != 0.0f)` at the call site rather than
 * inside divide(). It has to be: divide() returns a float and has no way
 * to report a failure, since every float is a plausible answer. Dividing
 * floats by zero would not crash - it yields inf, which prints happily and
 * is easy to miss.
 */

#include <stdio.h>

/* 1. */
static void even_or_odd(int x)
{
    if (x % 2 == 0)
        printf("%d is Even\n", x);
    else
        printf("%d is ODD\n", x);
}

/* 2. */
static void find_divisors(int x)
{
    int i;

    printf("Divisors of %d: ", x);
    for (i = 1; i <= x; i++)
        if (x % i == 0)
            printf("%d ", i);
    printf("\n");
}

/* 3. One small function per operation. */
static float add(float a, float b)      { return a + b; }
static float subtract(float a, float b) { return a - b; }
static float multiply(float a, float b) { return a * b; }
static float divide(float a, float b)   { return a / b; }

static void calculator(void)
{
    float a, b;

    printf("Enter two numbers: ");
    if (scanf("%f %f", &a, &b) != 2)
        return;

    printf("Add:      %.2f\n", add(a, b));
    printf("Subtract: %.2f\n", subtract(a, b));
    printf("Multiply: %.2f\n", multiply(a, b));

    /* Guard the division - dividing by zero is undefined for integers
     * and gives inf for floats. */
    if (b != 0.0f)
        printf("Divide:   %.2f\n", divide(a, b));
    else
        printf("Divide:   undefined (b is zero)\n");
}

int main(void)
{
    even_or_odd(5);
    even_or_odd(6);
    even_or_odd(12345678);

    find_divisors(20);

    calculator();

    return 0;
}
