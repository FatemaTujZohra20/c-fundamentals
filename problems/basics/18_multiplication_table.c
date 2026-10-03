/*
 * Print a multiplication table, asking for numbers until the user
 * enters 0.
 *
 * Combines an infinite outer loop with a break, and a counted inner
 * loop for the table itself.
 */

#include <stdio.h>

int main(void)
{
    int num, i;

    for ( ; ; ) {
        printf("To Exit -> Enter the number 0\n");
        printf("Enter an Integer Number: ");

        if (scanf("%d", &num) != 1)
            break;

        if (num == 0) {
            printf("The program is Terminated!...\n");
            break;
        }

        for (i = 1; i <= 10; i++)
            printf("%2d x %2d = %3d\n", num, i, num * i);

        printf("\n");
    }

    return 0;
}
