/*
 * Patterns made of digits rather than stars.
 *
 *   1. cross_of_numbers()          an X - print the row number where the
 *                                  column sits on either diagonal
 *   2. mirrored_number_pyramid()   digits out, a gap, then digits back
 *   3. running_count_triangle()    a counter that never resets between
 *                                  rows
 *
 * The nested loops are the same as in pyramid_patterns.c. What changes is
 * what gets printed at each position: instead of a fixed character, these
 * print a counter, so the row and column numbers become the output rather
 * than only controlling it.
 *
 * The two diagonals of the X come from one test:
 *
 *     col == row                      the left-to-right diagonal
 *     col == (2 * total_rows) - row    its mirror image
 *
 * running_count_triangle() is the one to notice: `count` is declared
 * outside both loops, so it carries on from row to row. Declaring it
 * inside the outer loop would restart every row at 1.
 */

#include <stdio.h>

/* An X of numbers: print the row number where the column sits on either
 * diagonal, and a space everywhere else. */
static void cross_of_numbers(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= (2 * total_rows) - 1; col++) {
            if (col == row || col == (2 * total_rows) - row)
                printf("%d", row);
            else
                printf(" ");
        }
        printf("\n");
    }

    for (row = total_rows - 1; row >= 1; row--) {
        for (col = 1; col <= (2 * total_rows) - 1; col++) {
            if (col == row || col == (2 * total_rows) - row)
                printf("%d", row);
            else
                printf(" ");
        }
        printf("\n");
    }
}

/* Two mirrored pyramids of counting numbers with a gap between them:
 * 1..row going out, spaces, then row..1 coming back. */
static void mirrored_number_pyramid(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++)
            printf("%d", col);

        for (col = row + 1; col <= (2 * total_rows) - row; col++)
            printf(" ");

        for (col = row; col >= 1; col--)
            printf("%d", col);

        printf("\n");
    }
}

/* A triangle of consecutive numbers: the counter keeps going across
 * rows instead of restarting. */
static void running_count_triangle(int total_rows)
{
    int row, col, count = 1;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++) {
            printf("%3d", count);
            count++;
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

    printf("\n--- cross of numbers ---\n");
    cross_of_numbers(n);

    printf("\n--- mirrored number pyramid ---\n");
    mirrored_number_pyramid(n);

    printf("\n--- running count triangle ---\n");
    running_count_triangle(n);

    return 0;
}
