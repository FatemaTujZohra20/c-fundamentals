/*
 * Write a program to find the largest number among three numbers.
 *
 *   1. running_max()       start from INT_MIN, keep the biggest seen
 *   2. ladder_inline()     an if/else ladder that prints as it decides
 *   3. find_largest_num()  a ladder that returns the winner instead
 *
 * Three ways of solving it, kept together for comparison.
 *
 * running_max() starts from INT_MIN in <limits.h>, the smallest value an
 * int can hold, so the first comparison always succeeds. A hand-written
 * literal such as -2147483646 would be unportable, and simply wrong for
 * any input below it.
 *
 * The difference between 2 and 3 is worth noticing: printing inside the
 * function ties it to one use, while returning the value leaves the
 * caller free to print it, compare it, or store it. 03_even_or_odd.c
 * makes the same point about the same choice.
 */

#include <stdio.h>
#include <limits.h>

/* Way 1: a running maximum. Scales to any number of values.
 *
 * max starts at INT_MIN from <limits.h>, so the first comparison always
 * replaces it. A hand-written literal would have to be the true minimum
 * to be safe, and would stop being it on a platform with a different
 * int width. */
static int running_max(int num1, int num2, int num3)
{
    int max = INT_MIN;

    if (max < num1) max = num1;
    if (max < num2) max = num2;
    if (max < num3) max = num3;

    return max;
}

/* Way 2: an if-else ladder, inline. */
static void ladder_inline(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
        printf("Largest number is: %d\n", num1);
    else if (num2 >= num1 && num2 >= num3)
        printf("Largest number is: %d\n", num2);
    else
        printf("Largest number is: %d\n", num3);
}

/* Way 3: the same ladder, but as a function that returns the answer. */
static int find_largest_num(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

int main(void)
{
    int num1, num2, num3;

    printf("Enter the three numbers: ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3)
        return 1;

    printf("Way 1: %d\n", running_max(num1, num2, num3));

    printf("Way 2: ");
    ladder_inline(num1, num2, num3);

    printf("Way 3: %d\n", find_largest_num(num1, num2, num3));

    return 0;
}
