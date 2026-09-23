/*
 * Hollow patterns.
 *
 * The same nested loops as the solid shapes, with one extra decision
 * inside: print a star if this position is on the border, a space if it is
 * not. The whole difficulty is writing down what "on the border" means.
 *
 *   1. hollow_rectangle()        first or last row, or first or last column
 *   2. hollow_right_triangle()   first column, last row, or the diagonal
 *   3. hollow_pyramid()          the two sloping edges, plus the base
 *   4. hollow_diamond()          the four sloping edges
 *
 * So the pattern is always: compute the same rows and columns as the solid
 * version, then replace `printf("*")` with a condition that asks whether
 * this cell is an edge.
 *
 * Careful: the spaces still have to be printed. Skipping them collapses
 * the row, because there is nothing to hold the later stars in place.
 */

#include <stdio.h>

/* Hollow rectangle: a star on any edge - the first or last row, or the
 * first or last column - and a space everywhere inside. */
static void hollow_rectangle(int rows, int columns)
{
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

/* Hollow right triangle: the first column, the last row, and the
 * diagonal where col == row. */
static void hollow_right_triangle(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++) {
            if (col == 1 || row == total_rows || col == row)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

/* Hollow pyramid: the first star, the last star, and the whole base. */
static void hollow_pyramid(int total_rows)
{
    int row, space, star;

    for (row = 1; row <= total_rows; row++) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");

        for (star = 1; star <= (2 * row) - 1; star++) {
            if (star == 1 || row == total_rows || star == (2 * row) - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

/* Hollow diamond: only the two edges, and no base at all - the shape
 * closes itself when the second half meets the first. */
static void hollow_diamond(int total_rows)
{
    int row, space, star;

    for (row = 1; row <= total_rows; row++) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");
        for (star = 1; star <= (2 * row) - 1; star++) {
            if (star == 1 || star == (2 * row) - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    for (row = total_rows - 1; row >= 1; row--) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");
        for (star = 1; star <= (2 * row) - 1; star++) {
            if (star == 1 || star == (2 * row) - 1)
                printf("*");
            else
                printf(" ");
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

    printf("\n--- hollow rectangle ---\n");
    hollow_rectangle(n, n);

    printf("\n--- hollow right triangle ---\n");
    hollow_right_triangle(n);

    printf("\n--- hollow pyramid ---\n");
    hollow_pyramid(n);

    printf("\n--- hollow diamond ---\n");
    hollow_diamond(n);

    return 0;
}
