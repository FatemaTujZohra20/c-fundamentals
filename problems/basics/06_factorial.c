/*
 * Write a program to find the factorial of a given number.
 *
 *   0! = 1
 *   1! = 1
 *   2! = 2 * 1! = 2
 *   3! = 3 * 2! = 6
 *   4! = 4 * 3! = 24
 *   5! = 5 * 4! = 120
 *
 * Each factorial is defined in terms of the one below it, which is
 * exactly the shape of a recursive function.
 */

#include <stdio.h>

static int find_factorial(int n)
{
    if (n == 0)                         /* base case */
        return 1;
    else
        return n * find_factorial(n - 1);   /* recursive case */
}

int main(void)
{
    int n, factorial;

    printf("Enter the number: ");
    if (scanf("%d", &n) != 1)
        return 1;

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    factorial = find_factorial(n);
    printf("The factorial of %d is: %d\n", n, factorial);

    return 0;
}
