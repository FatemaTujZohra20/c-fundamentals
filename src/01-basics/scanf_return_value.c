/*
 * scanf returns a COUNT, not a value.
 *
 * It reports how many items it successfully assigned, so a call asking
 * for two items returns 2 when both were read. Testing that count is how
 * you detect input that did not match the format.
 *
 *     count = scanf("%d %c", &age, &term);
 *
 *     count == 2     both items read
 *     count == 1     the int matched, the char did not
 *     count == 0     nothing matched (letters typed where %d was wanted)
 *     count == EOF   end of input, or the stream failed
 *
 * Two demos: check_the_count() asks for two items, read_a_record() reads
 * five values of four different types in a single call.
 *
 * Careful: when a match fails, scanf leaves the offending characters
 * sitting in the input buffer. The next scanf meets them again and fails
 * the same way. This is the usual cause of a program that seems to spin
 * forever without ever waiting for input.
 *
 * Two details in the format strings are worth noticing:
 *
 *     " %c"    the leading space skips whitespace, including the newline
 *              left behind by a previous entry
 *     "%49s"   the width limit stops scanf writing past the end of a
 *              50-byte array
 */

#include <stdio.h>

/* Two items requested, so a good read returns 2. */
static void check_the_count(void)
{
    int  age;
    char term;
    int  count;

    printf("Enter an age and a single letter: ");
    count = scanf("%d %c", &age, &term);

    printf("scanf returned %d\n", count);

    if (count == 2)
        printf("Both items were read. Age = %d; term = %c\n", age, term);
    else
        printf("Input did not match the expected format.\n");
}

/* Reading several different types in one call. */
static void read_a_record(void)
{
    char  format;
    int   book_id;
    int   quantity;
    float price;
    char  name[50];
    int   count;

    printf("\nEnter: format bookId quantity price name\n");
    printf("(for example:  P 101 3 24.50 Dune)\n> ");

    count = scanf(" %c %d %d %f %49s",
                  &format, &book_id, &quantity, &price, name);

    if (count != 5) {
        printf("Expected 5 items, got %d.\n", count);
        return;
    }

    printf("\nFormat:   %c\n", format);
    printf("BookID:   %d\n", book_id);
    printf("Quantity: %d\n", quantity);
    printf("Price:    %.2f\n", price);
    printf("Name:     %s\n", name);
}

int main(void)
{
    check_the_count();
    read_a_record();

    return 0;
}
