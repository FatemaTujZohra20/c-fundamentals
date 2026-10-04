/*
 * Print all the odd numbers from 1 to N, and how many there are.
 *
 * Counting them takes a moment's thought:
 *   N = 10  ->  1,3,5,7,9      = 5  = 10 / 2
 *   N = 7   ->  1,3,5,7        = 4  = 7 / 2 + 1
 *
 * Both cases collapse into the single expression (N + 1) / 2, which is
 * why the branching version below always agrees with it.
 */

#include <stdio.h>

int main(void)
{
    int range, count = 1;

    printf("Enter a range: ");
    if (scanf("%d", &range) != 1)
        return 1;

    printf("List of all the odd numbers from 1 to %d\n", range);

    while (count <= range) {
        if (count % 2 != 0)
            printf("%d ", count);
        count++;
    }
    printf("\n");

    printf("Simplified:  total = %d\n", (range + 1) / 2);

    if (range % 2 == 0)
        printf("Case by case: total = %d\n", range / 2);
    else
        printf("Case by case: total = %d\n", (range / 2) + 1);

    return 0;
}
