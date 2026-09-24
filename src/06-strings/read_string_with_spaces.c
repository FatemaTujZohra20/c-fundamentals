/*
 * Reading a string that contains spaces.
 *
 * The obvious call does not do it:
 *
 *     scanf("%s", name)
 *         stops at the first whitespace, so "Zohra Rahman" gives "Zohra"
 *
 * Two that do:
 *
 *     scanf("%49[^\n]", name)
 *         %[^\n] means "any characters that are not a newline", so it
 *         reads to the end of the line. The 49 caps it below name[50].
 *
 *     fgets(name, sizeof(name), stdin)
 *         the usual choice, and what this file uses. It is told the size
 *         of the buffer, so it cannot be made to write past the end.
 *
 * fgets keeps the trailing newline when the whole line fitted, which is
 * why it is trimmed below before the name is printed. Forgetting that
 * trim is the common bug: the newline is invisible in the output but
 * still in the string, and every later comparison against a plain name
 * then fails.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[50];
    size_t len;

    printf("Enter your full name: ");

    if (fgets(name, sizeof(name), stdin) == NULL)
        return 1;

    /* fgets keeps the '\n' if the line fit, so remove it. */
    len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';

    printf("Hello! %s.\n", name);

    return 0;
}
