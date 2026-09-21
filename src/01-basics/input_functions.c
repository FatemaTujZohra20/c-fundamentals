/*
 * Reading input: scanf, sscanf, getchar.
 *
 *   scanf    - reads and converts from the keyboard
 *   sscanf   - the same, but reading from a string you already hold
 *   getchar  - reads exactly one character
 *
 * The demos run in that order: parsing a fixed string, then three values
 * from the keyboard, then a single character.
 *
 * Careful: getchar() returns int, not char. It has to be able to return
 * EOF, which is a value outside the range of a char, so storing the
 * result in a char can break the EOF test.
 *
 * The drain loop before single_character() matters: without it the
 * newline left by the previous scanf would be read as the character, and
 * the prompt would appear not to wait for you.
 */

#include <stdio.h>

/* Several values in one scanf call. */
static void multiple_inputs(void)
{
    int   product_id, quantity;
    float price;

    printf("Enter product id, quantity and price: ");
    if (scanf("%d %d %f", &product_id, &quantity, &price) != 3)
        return;

    printf("ProductID = %d, Quantity = %d, Price = %.2f\n",
           product_id, quantity, price);

    /* A width can be given too: "%3d" reads at most 3 digits and leaves
     * the rest of the number in the input for the next specifier. */
}

/*
 * sscanf reads from a string instead of from the keyboard. It is how you
 * pull numbers out of text you already have - a line from a file, or a
 * value that arrived as a string.
 */
static void parse_from_a_string(void)
{
    int   product_id, quantity;
    float price;
    char  str[] = "1010 80 105.5";

    if (sscanf(str, "%d %d %f", &product_id, &quantity, &price) != 3)
        return;

    printf("Parsed from \"%s\":\n", str);
    printf("ProductID = %d, Quantity = %d, Price = %.2f\n",
           product_id, quantity, price);
}

/* getchar reads exactly one character. */
static void single_character(void)
{
    int ch;   /* int, not char - getchar returns EOF, which is not a char */

    printf("Enter a character: ");
    ch = getchar();

    if (ch != EOF)
        printf("You entered: %c\n", (char)ch);
}

int main(void)
{
    parse_from_a_string();
    multiple_inputs();

    /* Clear whatever is left on the line before reading a single char. */
    while (getchar() != '\n' && !feof(stdin))
        ;

    single_character();

    return 0;
}
