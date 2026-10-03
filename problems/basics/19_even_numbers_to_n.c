/*
 * Print all the even numbers from 1 to N, and how many there are.
 *
 * The count needs no loop: the evens up to N are 2, 4, ... so there are
 * exactly N / 2 of them, and integer division already truncates
 * correctly for odd N (7 / 2 = 3, and 2, 4, 6 really is three numbers).
 */

#include <stdio.h>

int main(void)
{
    int range, count = 1;

    printf("Enter a range: ");
    if (scanf("%d", &range) != 1)
        return 1;

    printf("List of all the even numbers from 1 to %d\n", range);

    while (count <= range) {
        if (count % 2 == 0)
            printf("%d ", count);
        count++;
    }
    printf("\n");

    printf("The total even numbers from 1 to %d is = %d\n", range, range / 2);

    return 0;
}
