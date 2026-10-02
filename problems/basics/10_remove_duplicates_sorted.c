/*
 * Write a program that takes a sorted array and removes its duplicates.
 *
 * Because the array is sorted, every run of equal values sits together,
 * so a single pass is enough. Index i tracks the last unique element
 * found; j scans ahead looking for the next value that differs from it.
 *
 * The new length is returned, and the unique values occupy arr[0..len-1].
 *
 * About the "Duplicates" line below: this version swaps rather than
 * overwrites, so the discarded values are still somewhere in the tail of
 * the array afterwards - but in no meaningful order. That line prints
 * whatever ended up there, which is not the set of duplicates. It is
 * printed only to show what the swap actually does to the tail.
 *
 * Careful: the whole method depends on the array being sorted. Given
 * unsorted input it removes only the duplicates that happen to be
 * adjacent, and reports a length that is too large.
 */

#include <stdio.h>

static int remove_duplicates(int arr[], int n)
{
    int i = 0;      /* index of the last unique element */
    int j;

    if (n <= 1)
        return n;   /* 0 for an empty array, 1 for a single element */

    for (j = 1; j < n; j++) {
        if (arr[j] != arr[i] && arr[j] > arr[i]) {
            int temp = arr[i + 1];
            arr[i + 1] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    return i + 1;   /* count of unique elements */
}

int main(void)
{
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int new_length;
    int i;

    new_length = remove_duplicates(arr, n);

    printf("Unique elements: ");
    for (i = 0; i < new_length; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Tail of the array: ");
    for (i = new_length; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
