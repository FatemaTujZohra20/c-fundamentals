/*
 * The <string.h> functions: strlen, strcpy, strcmp, strcat.
 *
 *   strlen(a)      how many characters sit before the '\0'
 *   strcpy(a, b)   replace a with a copy of b
 *   strcmp(a, b)   0 if equal, negative or positive otherwise
 *   strcat(a, b)   append b onto the end of a
 *
 * Each demo sits in its own braced block, so the same names can be reused
 * with fresh values every time.
 *
 * Two things they all share, and both are where the usual bugs come from:
 *
 *   They find the end of a string by looking for '\0'. An unterminated
 *   char array sends any of them past the end of its memory.
 *
 *   They never allocate. strcpy and strcat write into a destination you
 *   supplied and neither checks that it fits, which is why the
 *   destinations here are declared char a[20] while the sources are
 *   shorter.
 *
 * Careful: strcmp returns 0 for equal strings, so `if (strcmp(a, b))`
 * actually reads as "if they differ". And comparing strings with ==
 * compares their addresses rather than their contents, which is almost
 * never what was meant.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    /* strlen counts the characters before the '\0' - it does not
     * include the terminator, so it differs from sizeof. */
    {
        char a[] = "Bangla";
        printf("Length of your string is: %zu\n", strlen(a));
    }

    /* strcpy overwrites the destination with the source. */
    {
        char a[20] = "Bangladesh";
        char b[]   = "Dhaka";

        strcpy(a, b);
        printf("Value of a is: %s\n", a);
        printf("Value of b is: %s\n", b);
    }

    /* strcmp returns 0 when the strings are equal, and a negative or
     * positive number otherwise. It does NOT return true/false - a
     * non-zero result means "different". */
    {
        char a[] = "Bangladesh";
        char b[] = "Dhaka";

        if (strcmp(a, b) == 0)
            printf("a and b are equal.\n");
        else
            printf("a and b are not equal.\n");
    }

    /* strcat appends the source onto the end of the destination.
     * The destination must be big enough to hold both plus the '\0'. */
    {
        char a[20] = "Bangladesh";
        char b[]   = "Dhaka";

        strcat(a, b);
        printf("Value of a is: %s\n", a);
        printf("Value of b is: %s\n", b);
    }

    return 0;
}
