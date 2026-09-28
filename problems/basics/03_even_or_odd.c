/*
 * Write a program to check if the given number is even or odd.
 *
 * Two ways to structure it:
 *   1. The function prints the answer itself.
 *   2. The function returns a result and the caller decides what to print.
 *
 * The second is usually better - the function stays reusable because it
 * does not assume where the answer is going.
 */

#include <stdio.h>

/* Way 1: the function prints. */
static void print_even_or_odd(int num)
{
    if (num % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
}

/* Way 2: the function returns, the caller prints. */
static int is_even(int num)
{
    return num % 2 == 0;
}

int main(void)
{
    int test_num;

    printf("Enter a number: ");
    if (scanf("%d", &test_num) != 1)
        return 1;

    printf("Way 1: ");
    print_even_or_odd(test_num);

    printf("Way 2: ");
    if (is_even(test_num))
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}
