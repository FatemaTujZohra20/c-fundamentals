/*
 * Exercise: add two numbers, passing them by address.
 *
 *     Input the first number: 5
 *     Input the second number: 6
 *     The sum of 5 and 6 is 11
 *
 * add_two_numbers() takes two pointers and dereferences both to read the
 * values:
 *
 *     static long long add_two_numbers(const long long *a, const long long *b)
 *     {
 *         return *a + *b;
 *     }
 *
 * Worth being honest about: passing addresses gains nothing here. The
 * function only reads, and `add(long long a, long long b)` would be
 * simpler and just as correct. Passing a pointer pays off when the
 * function must modify the caller's variable, as in
 * call_by_value_or_reference.c, or when copying the value would be
 * expensive - neither of which applies to two integers.
 *
 * `const` is what makes the read-only intent explicit, and the compiler
 * would reject an attempt to write through either pointer.
 *
 * long long is used so the sum cannot overflow on large input, and its
 * specifier is %lld rather than %d.
 */

#include <stdio.h>

static long long add_two_numbers(const long long *a, const long long *b)
{
    return *a + *b;
}

int main(void)
{
    long long first, second, sum;

    printf("\nPointer: add two numbers using call by reference\n");
    printf("-------------------------------------------------------------\n");

    printf("Input the first number: ");
    if (scanf("%lld", &first) != 1)
        return 1;

    printf("Input the second number: ");
    if (scanf("%lld", &second) != 1)
        return 1;

    sum = add_two_numbers(&first, &second);

    printf("The sum of %lld and %lld is %lld\n", first, second, sum);

    return 0;
}
