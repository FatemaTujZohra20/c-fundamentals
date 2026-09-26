/*
 * A function that modifies the caller's array.
 *
 * An array argument arrives as a pointer to its first element, so the
 * function writes into the original array. No copy is made, which is why
 * negate() needs no return value - the change is already visible to the
 * caller when it returns.
 *
 *   negate()       writes into the array it is given
 *   print_split()  takes const, so it can only read
 *
 * The two signatures side by side are the thing to notice:
 *
 *     static void negate(int *x, int len)
 *     static void print_split(const int *numbers, int len)
 *
 * The difference is one word, and it is the whole contract. Passing an
 * array to a function that does not promise const means accepting that it
 * may come back changed.
 */

#include <stdio.h>

static void negate(int *x, int len)
{
    int i;

    for (i = 0; i < len; i++)
        x[i] = -x[i];
}

static void print_split(const int *numbers, int len)
{
    int i;

    printf("negative: ");
    for (i = 0; i < len; i++)
        if (numbers[i] < 0)
            printf("%d ", numbers[i]);
    printf("\n");

    printf("positive: ");
    for (i = 0; i < len; i++)
        if (numbers[i] >= 0)
            printf("%d ", numbers[i]);
    printf("\n");
}

int main(void)
{
    int numbers[] = {10, -1, -7, 5, 8, 9, 0, -2, -25, 30};
    int len = sizeof(numbers) / sizeof(numbers[0]);

    printf("--- before ---\n");
    print_split(numbers, len);

    negate(numbers, len);

    printf("\n--- after negate() ---\n");
    print_split(numbers, len);

    return 0;
}
