/*
 * Write a program to print "Hello World!" on the console.
 *
 * Also a look at two printf details:
 *
 *   printf returns the number of characters it wrote, so a printf can be
 *   nested inside another one to print that count.
 *
 *   "%50s" pads the string to at least 50 characters wide, right-aligned.
 *   If the string is longer than the width it is printed in full - the
 *   width is a minimum, not a limit.
 */

#include <stdio.h>

int main(void)
{
    printf("%s", "Hello World!\n");

    printf("[%50s]\n", "Hello World!");

    /* The inner printf writes 12 characters, so the outer one prints 12. */
    printf("\ncharacters written: %d\n", printf("%s", "Hello World!"));

    return 0;
}
