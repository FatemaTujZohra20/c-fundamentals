/*
 * Reading array values from the user.
 *
 * The shape is a loop wrapped around a single scanf, with the index as the
 * loop counter:
 *
 *     for (i = 0; i < 5; i++)
 *         scanf("%d", &a[i]);
 *
 * &a[i] is the address of one element, which is exactly what scanf wants -
 * the same & as for a plain variable.
 *
 * Two arrays of different types are read here to show that only the
 * specifier changes: %d for the int array, %f for the float one.
 *
 * Each scanf is checked and a failure returns immediately. Without the
 * check, input that does not match leaves that element uninitialised while
 * the loop carries on regardless, and the array is then printed anyway.
 */

#include <stdio.h>

int main(void)
{
    int   a[5];
    float f[4];
    int   i;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++)
        if (scanf("%d", &a[i]) != 1)
            return 1;

    printf("You entered: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Enter 4 floats:\n");
    for (i = 0; i < 4; i++)
        if (scanf("%f", &f[i]) != 1)
            return 1;

    printf("You entered: ");
    for (i = 0; i < 4; i++)
        printf("%.2f ", f[i]);
    printf("\n");

    return 0;
}
