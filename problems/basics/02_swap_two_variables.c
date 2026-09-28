/*
 * Write a program to swap the values of two variables.
 *
 * Call by value does not work here - the function would swap its own
 * copies and the caller would see nothing change. Passing the addresses
 * is what makes the swap visible outside the function.
 */

#include <stdio.h>

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int num1, num2;

    printf("Enter num1: ");
    if (scanf("%d", &num1) != 1)
        return 1;

    printf("Enter num2: ");
    if (scanf("%d", &num2) != 1)
        return 1;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    swap(&num1, &num2);     /* & takes the address of each variable */

    printf("After swapping:  num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
