/*
 * Finding the length of a string by hand, without strlen.
 *
 *     while (name[i] != '\0')
 *         i++;
 *
 * Count characters until the terminator is reached, and the count is
 * exactly what strlen would return - the terminator itself is not
 * counted. This loop is, near enough, strlen's own implementation.
 *
 * The result is the number of characters, one less than the bytes the
 * string occupies.
 *
 * Careful: this depends entirely on the '\0' being there. On a char array
 * that was never terminated, the loop does not stop at the end of the
 * array. It keeps reading whatever follows it in memory until it happens
 * across a zero byte.
 */

#include <stdio.h>

int main(void)
{
    char name[50];
    int i = 0;

    printf("Enter your name: ");

    /* %[^\n] reads everything up to the newline, so spaces are kept.
     * The 49 caps the read so it cannot overflow name[50]. */
    if (scanf("%49[^\n]", name) != 1)
        return 1;

    while (name[i] != '\0')
        i++;

    printf("Length of name is: %d\n", i);

    return 0;
}
