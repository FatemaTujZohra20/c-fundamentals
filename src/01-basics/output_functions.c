/*
 * Writing output: printf, putchar, puts.
 *
 *   printf   - formatted output, the general-purpose one
 *   putchar  - writes a single character
 *   puts     - writes a string and appends a newline automatically
 *
 * puts(text) and printf("%s\n", text) do the same job; puts is the
 * simpler choice when there is nothing to format.
 *
 * putchar takes an int, so a character code can be passed straight in -
 * putchar(65) writes 'A'.
 *
 * Careful: fgets() keeps the trailing newline, so it is trimmed below
 * before the string is printed.
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[20];
    int  ch;
    size_t len;

    /* putchar writes one character at a time. It takes an int, so a
     * character code can be passed directly - 65 is 'A'. */
    printf("Enter a character: ");
    ch = getchar();
    if (ch != EOF) {
        putchar(ch);
        putchar('\n');
        putchar(65);
        putchar('\n');
    }

    /* Drop the rest of the line before reading the string. */
    while (getchar() != '\n' && !feof(stdin))
        ;

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
        return 1;

    len = strlen(text);
    if (len > 0 && text[len - 1] == '\n')
        text[len - 1] = '\0';

    /* puts appends its own newline - printf("%s") does not. */
    puts("The string is:");
    puts(text);

    return 0;
}
