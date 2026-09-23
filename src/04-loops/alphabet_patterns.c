/*
 * Alphabet patterns.
 *
 * These rely on characters being numbers underneath. 'A' is ASCII 65, so
 * adding 64 to a 1-based counter turns 1 into 'A', 2 into 'B', and so on -
 * and printing it with %c shows the letter instead of the number.
 *
 *     printf("%3d", col)        ->  the plain number
 *     printf("%3d", col + 64)   ->  the ASCII code
 *     printf("%3c", col + 64)   ->  the character itself
 *
 *   1. letters_across()           letters advance along each row
 *   2. letters_down()             letters advance down the rows
 *   3. letters_down_reversed()    the same, counting backwards
 *   4. letters_with_a_step()      a step other than one between letters
 *
 * The nested loops are the triangles from loop_patterns.c; only the thing
 * being printed has changed.
 *
 * Careful: adding 64 works because the letters are consecutive in ASCII.
 * Using 'A' + (col - 1) says the same thing without the magic number, and
 * does not depend on knowing that 'A' is 65.
 */

#include <stdio.h>

/* Letters advance across each row: A / A B / A B C ... */
static void letters_across(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++)
            printf("%3c", col + 64);
        printf("\n");
    }
}

/* Letters advance down the rows: A / B B / C C C ... */
static void letters_down(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++)
            printf("%3c", row + 64);
        printf("\n");
    }
}

/* Counting the rows backwards: row 1 gives 'E' when total_rows is 5,
 * because total_rows - row + 1 = 5. */
static void letters_down_reversed(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++)
            printf("%3c", (total_rows - row + 1) + 64);
        printf("\n");
    }
}

/* A harder one: each row starts one letter further on, and the step
 * between letters within a row shrinks as the row gets wider. */
static void letters_with_a_step(int total_rows)
{
    int  row, col;
    char start_letter = 'A';
    char current_letter;

    for (row = 1; row <= total_rows; row++) {
        current_letter = start_letter + row - 1;    /* first letter of the row */

        for (col = 1; col <= row; col++) {
            printf("%c ", current_letter);
            current_letter = current_letter + (total_rows - col);
        }
        printf("\n");
    }
}

int main(void)
{
    int n;

    printf("Enter the number of rows: ");
    if (scanf("%d", &n) != 1 || n < 1)
        return 1;

    printf("\n--- letters across ---\n");
    letters_across(n);

    printf("\n--- letters down ---\n");
    letters_down(n);

    printf("\n--- letters down, reversed ---\n");
    letters_down_reversed(n);

    printf("\n--- letters with a step ---\n");
    letters_with_a_step(n);

    return 0;
}
