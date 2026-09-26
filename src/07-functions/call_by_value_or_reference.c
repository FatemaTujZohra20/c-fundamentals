/*
 * Call by value vs. call by reference.
 *
 * C always passes by value. Passing a pointer just means the value being
 * copied is an address - and an address is enough to reach back and
 * change the caller's variable.
 *
 *   modify_by_value(a, b)        gets copies; the caller sees nothing
 *   modify_by_reference(&a, &b)  gets addresses; the caller sees the change
 *
 * "Call by reference" is therefore a description of a technique, not a
 * separate mechanism in the language. There is one mechanism, and the
 * difference is only in what you choose to copy.
 *
 * Inside modify_by_reference(), `*a = ...` writes through the pointer to
 * the caller's variable. Writing `a = ...` instead would reassign the
 * local copy of the address and change nothing the caller can see.
 */

#include <stdio.h>

/* Call by value - a and b are copies, so the caller sees no change.
 * Printing them here shows the copies really did change inside. */
static void modify_by_value(int a, int b)
{
    a = 15;
    b = 25;
    printf("  inside modify_by_value: a = %d, b = %d\n", a, b);
}

/* Call by reference - a and b are addresses, so the caller does see it. */
static void modify_by_reference(int *a, int *b)
{
    *a = 15;
    *b = 25;
}

int main(void)
{
    int x = 10, y = 20;

    printf("Before calling the function:\n");
    printf("x = %d, y = %d\n\n", x, y);

    modify_by_value(x, y);
    printf("After call by value (unchanged):\n");
    printf("x = %d, y = %d\n\n", x, y);

    modify_by_reference(&x, &y);
    printf("After call by reference (changed):\n");
    printf("x = %d, y = %d\n\n", x, y);

    return 0;
}
