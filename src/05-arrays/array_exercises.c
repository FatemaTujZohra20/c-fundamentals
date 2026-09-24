/*
 * Array exercises.
 *
 *   1. sum_of_ten()             read 10 integers and print their sum
 *   2. biggest_and_smallest()   find the largest and smallest in one pass
 *   3. add_two_arrays()         add two arrays element by element into a
 *                               third
 *   4. even_and_odd_sums()      print an array, then sum its even and its
 *                               odd values separately
 *
 * All four are the same skeleton: one loop over the indexes, with an
 * accumulator or a running best declared before it and read after it.
 *
 *     int sum = 0;                  declared outside
 *     for (i = 0; i < n; i++)
 *         sum += a[i];              updated inside
 *     printf(...);                  read after
 *
 * Declaring the accumulator inside the loop is the usual mistake: it would
 * be reset on every pass.
 *
 * biggest_and_smallest() starts max and min from a[0] and then loops from
 * i = 1. Starting from 0 instead would be wrong for the array used here,
 * which is entirely below zero at a[5]. Compare largest_of_three.c in
 * 03-control-flow, which starts from INT_MIN because it has no array
 * element to start from.
 */

#include <stdio.h>

/* 1. Sum of 10 integers read from the user. */
static void sum_of_ten(void)
{
    int a[10], i, sum = 0;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
        if (scanf("%d", &a[i]) != 1)
            return;

    for (i = 0; i < 10; i++)
        sum += a[i];

    printf("Sum of the array: %d\n", sum);
}

/* 2 & 3. Biggest and smallest value of a given array. */
static void biggest_and_smallest(void)
{
    int a[7] = {-99, 45, 100, 37, 89, -327, 245};
    int max = a[0], min = a[0];
    int i;

    for (i = 1; i < 7; i++) {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
}

/* 4. AB[i] = A[i] + B[i] */
static void add_two_arrays(void)
{
    int A[5], B[5], AB[5];
    int i;

    printf("Enter the values of A:\n");
    for (i = 0; i < 5; i++)
        if (scanf("%d", &A[i]) != 1)
            return;

    printf("Enter the values of B:\n");
    for (i = 0; i < 5; i++)
        if (scanf("%d", &B[i]) != 1)
            return;

    for (i = 0; i < 5; i++)
        AB[i] = A[i] + B[i];

    printf("Values of the AB array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", AB[i]);
    printf("\n");
}

/* 5. Sum the even and the odd values separately.
 *
 *    Values in array: 10 25 20 15 30
 *    Sum of Even values: 60
 *    Sum of Odd values: 40
 */
static void even_and_odd_sums(void)
{
    int a[5], i, even_sum = 0, odd_sum = 0;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++)
        if (scanf("%d", &a[i]) != 1)
            return;

    printf("Values in array: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    for (i = 0; i < 5; i++) {
        if (a[i] % 2 == 0)
            even_sum += a[i];
        else
            odd_sum += a[i];
    }

    printf("Sum of Even values: %d\n", even_sum);
    printf("Sum of Odd values: %d\n", odd_sum);
}

int main(void)
{
    biggest_and_smallest();
    sum_of_ten();
    add_two_arrays();
    even_and_odd_sums();

    return 0;
}
