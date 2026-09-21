/*
 * Variables, types and format specifiers.
 *
 * Four demos, in order: int truncation, doubles and precision, reading
 * two numbers, reading a single character.
 *
 * The recurring theme is that C converts between number types silently,
 * and usually by discarding information rather than rounding.
 * `int a = 50.45;` compiles without complaint and stores 50.
 *
 * Comments come in two forms: a line comment starting with two slashes,
 * which runs to the end of the line, and a block comment opened with
 * slash-star and closed with star-slash, which can span many lines.
 * Neither reaches the compiled program.
 *
 * Block comments do not nest - the first star-slash closes the comment,
 * whatever came before it.
 *
 * Careful: a format specifier that does not match its argument is
 * undefined behaviour, not a conversion. -Wall -Wextra catches many of
 * them.
 */

#include <stdio.h>

/*
 * Assigning a floating-point value to an int silently drops the
 * fraction - the compiler does not stop you.
 *
 *     int a = 50.45;   ->  a holds 50
 *     int k = 10.5;    ->  k holds 10
 */
static void int_truncation(void)
{
    int   a = 50.45;
    int   b = 60;
    int   sum;
    int   k = 10.5;
    float d = 4;
    float h = (int)(23.0 / 6.0);    /* 3.833... -> cast to int -> 3 */

    sum = a + b;
    printf("%d + %d = %d\n", a, b, sum);
    printf("k = %d, d = %f, h = %f\n", k, d, h);
}

/*
 * Format specifiers have to match the type:
 *
 *     %d    int
 *     %f    float (and double, in printf)
 *     %lf   double
 *     %c    char
 *     %s    string
 *
 * A precision can be added: %.2f prints two decimal places.
 */
static void doubles_and_precision(void)
{
    double a = 9.5;
    double b = 8.743;
    double sum = a + b;

    printf("Sum is : %lf\n", sum);
    printf("Sum is : %.2f\n", sum);
}

/* Reading numbers, and the & that scanf needs. */
static void read_two_numbers(void)
{
    double a, b, sum;

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &a, &b) != 2)
        return;

    sum = a + b;
    printf("Sum is: %lf\n", sum);
}

/* Reading a single character, two ways. */
static void read_a_character(void)
{
    char ch;

    printf("Enter the first letter of your name: ");
    if (scanf(" %c", &ch) != 1)
        return;

    printf("The first letter of your name is: %c\n", ch);
}

int main(void)
{
    int_truncation();
    doubles_and_precision();
    read_two_numbers();
    read_a_character();

    return 0;
}
