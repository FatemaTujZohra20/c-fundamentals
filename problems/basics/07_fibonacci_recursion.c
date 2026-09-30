/*
 * Write a program to print the Fibonacci series using recursion.
 *
 * Each number is the sum of the previous two: 0 1 1 2 3 5 8 13 21 ...
 *
 *   1. fib() + print_fib()   carry the previous two terms down through
 *                            the calls, printing as it goes
 *   2. fibonacci()           return the nth term directly
 *   3. fib_up_to_value()     print terms until a value is exceeded,
 *                            rather than counting terms
 *
 * Three approaches, kept together because they answer slightly different
 * questions: "print n terms", "give me term n", and "print terms up to a
 * limit".
 *
 * The contrast between 1 and 2 is the useful part. fib() passes the two
 * previous values along as parameters, so each term costs one call and
 * the work grows linearly. fibonacci() recomputes both halves from
 * scratch at every step, so the calls double each time - fibonacci(40)
 * already takes noticeably long, and the two produce the same numbers.
 *
 * print_fib() exists because the first two terms have no "previous two"
 * to add, so they are handled before the recursion starts.
 */

#include <stdio.h>

/*
 * Way 1: print the first n terms, carrying the two previous values down
 * through the recursion. Each call does one step of work, so this is
 * linear - it visits each term once.
 */
static void fib(int n, int prev1, int prev2)
{
    int updated;

    if (n < 3)                  /* base case: 0, 1 and one more are done */
        return;

    updated = prev1 + prev2;
    prev1 = prev2;
    prev2 = updated;

    printf("%d ", updated);

    fib(n - 1, prev1, prev2);   /* recursive case */
}

/* Handles the first two terms, which have no "previous two" to add. */
static void print_fib(int n)
{
    if (n < 1) {
        printf("Invalid term!");
    } else if (n == 1) {
        printf("%d ", 0);
    } else if (n == 2) {
        printf("%d %d", 0, 1);
    } else {
        printf("%d %d ", 0, 1);
        fib(n, 0, 1);
    }
    printf("\n");
}

/*
 * Way 2: return the nth Fibonacci number directly.
 *
 * Simple to read, but slow - each call spawns two more, so the work
 * doubles with every step. fibonacci(40) already takes noticeably long.
 */
static int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
 * Way 3: iteratively, printing the series up to a value rather than up
 * to a count.
 */
static void fib_up_to_value(int n)
{
    int a = 0, b = 1, temp;

    printf("%d %d ", a, b);

    while (b <= n) {
        temp = a;
        a = b;
        b = temp + b;

        if (b <= n)
            printf("%d ", b);
    }
    printf("\n");
}

int main(void)
{
    int n = 11;

    printf("First %d terms: ", n);
    print_fib(n);

    printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));

    printf("Series up to the value 50: ");
    fib_up_to_value(50);

    return 0;
}
