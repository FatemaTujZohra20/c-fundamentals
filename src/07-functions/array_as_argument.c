/*
 * Passing an array as an argument.
 *
 *     static int add(const int b[], int len)
 *
 * The array is not copied. The function receives a pointer to its first
 * element, which is why the length has to travel with it as a second
 * argument: sizeof() inside add() would measure the pointer, not the
 * array.
 *
 * `const` says add() only reads the array. The compiler enforces it, and
 * a reader can see the promise in the signature without reading the body.
 *
 * `int b[]` in a parameter list is not an array declaration - it is
 * another spelling of `int *b`. The empty brackets are documentation for
 * the human, and the compiler treats both identically.
 */

#include <stdio.h>

static int add(const int b[], int len)
{
    int sum = 0, i;

    for (i = 0; i < len; i++)
        sum += b[i];        /* same meaning as sum = sum + b[i] */

    return sum;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, -5, 8, 10};

    /* sizeof works here because a[] is a real array in this scope. */
    int len = sizeof(a) / sizeof(a[0]);

    printf("Sum of %d elements: %d\n", len, add(a, len));

    return 0;
}
