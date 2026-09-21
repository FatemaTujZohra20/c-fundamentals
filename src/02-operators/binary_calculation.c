/*
 * Decimal to binary, by repeated division.
 *
 * Dividing by 2 and keeping the remainder peels off one bit at a time,
 * starting from the least significant:
 *
 *     13 / 2 = 6  remainder 1      <- lowest bit
 *      6 / 2 = 3  remainder 0
 *      3 / 2 = 1  remainder 1
 *      1 / 2 = 0  remainder 1      <- highest bit
 *
 *     read upwards:  1101
 *
 * The remainders arrive in the opposite order to the one they are printed
 * in, so print_binary() collects them in an array and then walks it
 * backwards. 32 slots is more than enough: an int cannot need more bits
 * than it has.
 *
 * n == 0 is handled before the loop, because the condition is n > 0 and
 * zero would otherwise produce no digits at all.
 *
 * main() prints the table for 1-16, with a blank line every fourth row.
 */

#include <stdio.h>

static void print_binary(int n)
{
    int bits[32];
    int count = 0;

    if (n == 0) {
        printf("0");
        return;
    }

    /* Remainders come out least-significant first... */
    while (n > 0) {
        bits[count++] = n % 2;
        n /= 2;
    }

    /* ...so print them in reverse. */
    while (count > 0)
        printf("%d", bits[--count]);
}

int main(void)
{
    int i;

    printf(" Decimal - Binary\n\n");
    for (i = 1; i <= 16; i++) {
        printf("    %2d ---> ", i);
        print_binary(i);
        printf("\n");

        if (i % 4 == 0)
            printf("\n");
    }

    return 0;
}
