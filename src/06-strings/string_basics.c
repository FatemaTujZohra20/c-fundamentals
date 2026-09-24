/*
 * Strings in C are char arrays that end with a '\0' terminator.
 *
 * Nothing stores the length. The terminator marks the end, and every
 * string function finds it by scanning for that byte.
 *
 *     char name[] = "Meem";     5 bytes: 'M' 'e' 'e' 'm' '\0'
 *     sizeof(name)              5 - the storage
 *     strlen(name)              4 - the characters before the terminator
 *
 * A string literal adds the '\0' for you. An array built from individual
 * characters does not, which is the trap shown in the middle of main():
 * there the terminator has to be written by hand, or printf runs off the
 * end of the array hunting for one.
 *
 * The final loop walks a string one character at a time and stops at the
 * terminator. That is what every function in <string.h> does internally,
 * and it is why a missing '\0' sends them past the end of the array.
 */

#include <stdio.h>

int main(void)
{
    char name[] = "Meem";
    char sentence[] = "Mukla.C is a good boy.";

    /* A string literal quietly adds the '\0' for you: "Meem" occupies
     * 5 bytes, not 4. */
    printf("%s\n", name);
    printf("sizeof(name) = %zu (4 letters + the terminator)\n", sizeof(name));

    printf("%s\n", sentence);

    /*
     * An array built from individual characters does NOT get a
     * terminator automatically:
     *
     *     char random[] = {'a', '1', '*', 'e'};
     *     printf("%s", random);     <- undefined behaviour
     *
     * printf keeps reading past the end of the array looking for a '\0'
     * that was never written. Add it explicitly:
     */
    {
        char random[] = {'a', '1', '*', 'e', '\0'};
        printf("%s\n", random);
    }

    /* Walking a string one character at a time, stopping at the
     * terminator - this is what every string function does internally. */
    {
        char str[] = "abc";
        int i = 0;

        while (1) {
            printf("%d - %c\n", i, str[i]);
            if (str[i] == '\0')
                break;
            i++;
        }
    }

    return 0;
}
