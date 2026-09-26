/*
 * Swapping two variables through pointers.
 *
 * C passes arguments by value - a function receives a copy - so a plain
 * swap(int a, int b) would exchange its own two copies and leave the
 * caller's variables untouched. Passing addresses instead gives the
 * function a way to reach back into the caller. That is all "call by
 * reference" means in C: ordinary pointers, used deliberately.
 *
 *     swap(&num1, &num2);      pass the addresses, not the values
 *     int temp = *p1;          read through p1
 *     *p1 = *p2;               write through p1
 *
 * The temporary is not optional: assigning *p1 = *p2 first would destroy
 * the value from num1 before anything had saved a copy of it.
 */

#include <stdio.h>

static void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(void)
{
    int num1 = 10, num2 = 5;

    printf("Before swapping: num1 = %d; num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swapping:  num1 = %d; num2 = %d\n", num1, num2);

    return 0;
}
