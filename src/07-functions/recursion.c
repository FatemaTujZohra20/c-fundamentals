/*
 * Recursion - a function that calls itself.
 *
 * Every recursive function needs a base case, or it never stops. Here it
 * is n == 0 or n == 1, both of which have a factorial of 1.
 *
 *   find_factorial(5) = 5 * find_factorial(4)
 *                     = 5 * 4 * find_factorial(3)
 *                     ...
 *                     = 5 * 4 * 3 * 2 * 1
 *
 * Each call waits for the one it made before it can finish, so the
 * multiplications actually happen on the way back up, once the base case
 * returns 1.
 *
 * Careful: every waiting call occupies a stack frame, so recursion depth
 * is limited. And the base case must be reachable - find_factorial(-1)
 * would count downwards forever, because n never becomes 1 or 0.
 *
 * 07_fibonacci_recursion.c in problems/basics compares a recursive
 * version with a loop doing the same job.
 */

#include <stdio.h>

static int find_factorial(int n)
{
    if (n == 1 || n == 0)
        return 1;

    return n * find_factorial(n - 1);   /* the recursive call */
}

int main(void)
{
    int n, f;

    printf("\n Recursion : Find the Factorial of a number :\n");
    printf("-------------------------------------------------\n");
    printf(" Input a number : ");

    if (scanf("%d", &n) != 1)
        return 1;

    if (n < 0) {
        printf(" Factorial is not defined for negative numbers.\n");
        return 1;
    }

    f = find_factorial(n);
    printf(" The Factorial of %d is : %d\n\n", n, f);

    return 0;
}
