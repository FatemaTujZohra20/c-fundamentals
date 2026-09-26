/*
 * Summing an array inside a function, using pointer arithmetic.
 *
 * An array "decays" to a pointer to its first element when passed to a
 * function, so sum() receives an address rather than the array itself.
 * That is why the length must be passed separately: inside sum(),
 * sizeof(a) is the size of a pointer - 8 bytes on a 64-bit system - not
 * the size of the 3-element array back in main().
 *
 *     total += *(a + i);       exactly equivalent to total += a[i];
 *
 * `const int *a` promises that sum() only reads the array. The compiler
 * enforces it, and it tells anyone reading the signature that this
 * function will not modify their data.
 */

#include <stdio.h>

static int sum(const int *a, int size)
{
    int i, total = 0;

    for (i = 0; i < size; i++)
        total += *(a + i);

    return total;
}

int main(void)
{
    int arr[3] = {4, 5, 10};
    int result = sum(arr, 3);

    printf("Sum of the array is: %d\n", result);

    return 0;
}
