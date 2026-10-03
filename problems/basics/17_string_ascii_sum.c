/*
 * Add up the ASCII values of every character in a string.
 *
 * A char is a small integer, so `sum += name[i]` adds its character
 * code - 'A' contributes 65, 'a' contributes 97, and a space 32.
 */

#include <stdio.h>

int main(void)
{
    char name[50];
    int  sum = 0;
    int  i = 0;

    printf("Enter your name: ");

    /* %[^\n] reads up to the newline so spaces are included; the 49
     * keeps the read inside the array. */
    if (scanf("%49[^\n]", name) != 1)
        return 1;

    while (name[i] != '\0') {
        sum += name[i];
        i++;
    }

    printf("%s = %d\n", name, sum);

    return 0;
}
