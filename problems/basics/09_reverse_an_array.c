/*
 * Write a program to reverse an array of size n entered by the user.
 *
 * Two pointers walk towards each other from the ends, swapping as they
 * go, and stop when they meet in the middle - so only n/2 swaps happen,
 * not n.
 */

#include <stdio.h>

static void reverse_arr(int arr[], int start, int end)
{
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

static void print_arr(const int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int n, i;

    printf("Enter the size of the array, n = ");
    if (scanf("%d", &n) != 1 || n < 1)
        return 1;

    {
        /* A variable-length array - its size is decided at run time.
         * Valid C99 and later. */
        int arr[n];

        printf("Enter values of the array:\n");
        for (i = 0; i < n; i++)
            if (scanf("%d", &arr[i]) != 1)
                return 1;

        printf("\nThe original array is:\n");
        print_arr(arr, n);

        reverse_arr(arr, 0, n - 1);

        printf("Reversed array is:\n");
        print_arr(arr, n);
    }

    return 0;
}
