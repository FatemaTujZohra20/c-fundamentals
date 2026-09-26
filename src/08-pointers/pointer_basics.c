/*
 * Pointers - introduction.
 *
 * A pointer is a variable that holds an address instead of a value.
 *
 *     int  x = 10;
 *     int *p = &x;       &x  is "the address of x"
 *     *p                 is "the value at the address p holds"  ->  10
 *
 * `&` and `*` are opposites: & goes from a variable to its address,
 * * goes from an address back to the variable.
 *
 * This file walks through four things in order:
 *
 *   1. reading a variable through a pointer (an int, then a char)
 *   2. dereferencing two pointers inside one expression
 *   3. an array name used as an address, so a[i] and *(a + i) are the same
 *   4. pointer arithmetic, and printing addresses with %p
 *
 * The pointer's type matters even though every pointer holds an address:
 * the type is what tells the compiler how many bytes to read at that
 * address, and how far one step of arithmetic moves.
 */

#include <stdio.h>

int main(void)
{
    int   x = 10;
    char  c = 'y';
    int  *p;
    char *cp;

    p = &x;
    printf("Value of x: %d\n", x);
    printf("Value of x through the pointer: %d\n", *p);

    cp = &c;
    printf("Value of c: %c\n", c);
    printf("Value of c through the pointer: %c\n", *cp);

    /* Dereferencing two pointers and adding the results. */
    {
        int a = 10, b = 20;
        int *pa = &a, *pb = &b;
        printf("Sum through pointers: %d\n", *pa + *pb);
    }

    /* An array name already behaves as the address of its first element,
     * so a[i] and *(a + i) mean exactly the same thing. */
    {
        int arr[5] = {1, 2, 3, 4, 5};
        int i, sum = 0;
        int *ptr;

        for (i = 0; i < 5; i++)
            sum += *(arr + i);
        printf("Sum of the array: %d\n", sum);

        /* Pointer arithmetic moves in units of the pointed-to type,
         * not in bytes. */
        ptr = &arr[3];
        printf("*(ptr)   = %d\n", *(ptr));
        printf("*(ptr+1) = %d\n", *(ptr + 1));
        printf("*(ptr-1) = %d\n", *(ptr - 1));

        /* %p is the specifier for an address, and it expects a void *,
         * hence the cast. Printing a pointer with %d or %u is wrong and
         * warns on 64-bit systems, where an address is wider than an
         * int. Addresses differ from run to run - only the spacing
         * between them is meaningful here. */
        for (i = 0; i < 5; i++)
            printf("&arr[%d] = %p\n", i, (void *)&arr[i]);
        printf("arr      = %p\n", (void *)arr);
    }

    return 0;
}
