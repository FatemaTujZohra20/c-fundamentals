/*
 * Write a program to find the maximum and minimum of an array.
 *
 *   1. max_and_min_from_first()  start both from a[0], scan from index 1
 *   2. find_min_max()            the same idea, written differently
 *
 * Two ways, kept for comparison.
 *
 * Starting from a[0] rather than from 0 is the detail that matters: an
 * array that is entirely negative has no element above 0, so a max
 * starting at 0 would never be replaced and the answer would be wrong.
 * Any real element is a safe starting point; an invented one is not.
 *
 * Both functions take `const int[]` and a length, because an array
 * argument arrives as a pointer and carries no size of its own - see
 * array_as_argument.c in src/07-functions.
 */

#include <stdio.h>
#include <limits.h>

/*
 * Way 1: seed max and min with the first element and compare the rest
 * against them. Works on any array, including all-negative ones, because
 * the starting value is guaranteed to be a real member of the array.
 */
static void max_and_min_from_first(const int a[], int len)
{
    int i;
    int max = a[0];
    int min = a[0];

    for (i = 1; i < len; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

/*
 * Way 2: seed with INT_MAX and INT_MIN so that any real value replaces
 * them on the first comparison. One pass finds both.
 */
static void find_min_max(const int ar[], int len)
{
    int i;
    int min_element = INT_MAX, max_element = INT_MIN;

    for (i = 0; i < len; i++) {
        if (ar[i] < min_element)
            min_element = ar[i];
        if (ar[i] > max_element)
            max_element = ar[i];
    }

    printf("The minimum element is: %d\n", min_element);
    printf("The maximum element is: %d\n", max_element);
}

int main(void)
{
    int a[] = {12, 3, 10, 11, -5};
    int len = sizeof(a) / sizeof(a[0]);

    printf("--- way 1 ---\n");
    max_and_min_from_first(a, len);

    printf("\n--- way 2 ---\n");
    find_min_max(a, len);

    return 0;
}
