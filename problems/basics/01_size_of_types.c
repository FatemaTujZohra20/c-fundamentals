/*
 * Write a program to find the size of int, float, long, long long,
 * double and char, using the sizeof operator.
 *
 * The sizes are not fixed by the language - they depend on the platform.
 * On a typical 64-bit Linux system: char 1, int 4, long 8, double 8. The
 * standard fixes only the relative ordering and some minimum widths, so
 * code that assumes "an int is 4 bytes" is making a portability bet.
 *
 * sizeof yields a size_t: an unsigned type wide enough to measure any
 * object. Its printf specifier is %zu. Using %u instead happens to work
 * on 32-bit builds and warns on 64-bit ones, where size_t is wider than
 * unsigned int.
 *
 * sizeof is an operator, not a function, and it is resolved at compile
 * time - sizeof(int) has become a constant before the program runs.
 */

#include <stdio.h>

int main(void)
{
    printf("Size of int:       %zu bytes\n", sizeof(int));
    printf("Size of float:     %zu bytes\n", sizeof(float));
    printf("Size of long:      %zu bytes\n", sizeof(long));
    printf("Size of long long: %zu bytes\n", sizeof(long long));
    printf("Size of double:    %zu bytes\n", sizeof(double));
    printf("Size of char:      %zu bytes\n", sizeof(char));

    return 0;
}
