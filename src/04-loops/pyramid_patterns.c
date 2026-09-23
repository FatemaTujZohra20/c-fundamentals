/*
 * Pyramid patterns with nested loops.
 *
 * Every shape here comes from the same idea: the outer loop walks the
 * rows, and the inner loops decide how many spaces and how many stars
 * that row gets.
 *
 * For a centred pyramid of N rows, row r needs:
 *     spaces:  N - r
 *     stars:   2r - 1
 *
 *   1. rectangle()               the simplest case - every row the same
 *   2. rectangle_with_while()    the same shape, written with while loops
 *   3. half_pyramid()            stars grow, no leading spaces
 *   4. inverted_half_pyramid()   stars shrink
 *   5. pyramid()                 centred, using the formula above
 *   6. inverted_pyramid()        the same upside down
 *   7. diamond()                 a pyramid then an inverted one
 *   8. half_diamond()            the same without the leading spaces
 *
 * Demo 2 is worth comparing with demo 1: a while loop can do this, but the
 * counters have to be reset by hand before each inner pass, which is
 * exactly the bookkeeping a for loop's init slot does for you.
 *
 * Getting these right is a matter of writing down the count per row before
 * writing the loop, not of guessing at the loop bounds.
 */

#include <stdio.h>

/* Solid rectangle. */
static void rectangle(int total_rows, int total_cols)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= total_cols; col++)
            printf("*");
        printf("\n");
    }
}

/* The same rectangle with while loops. Note that cols has to be reset
 * at the top of every outer pass - a for loop does that for you. */
static void rectangle_with_while(int total_rows, int total_cols)
{
    int rows = 1, cols;

    while (rows <= total_rows) {
        cols = 1;                   /* important */
        while (cols <= total_cols) {
            printf("*");
            cols++;
        }
        printf("\n");
        rows++;
    }
}

/* Half pyramid - row r gets r stars. */
static void half_pyramid(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= row; col++)
            printf("*");
        printf("\n");
    }
}

/* Inverted half pyramid, right-aligned. */
static void inverted_half_pyramid(int total_rows)
{
    int row, col;

    for (row = 1; row <= total_rows; row++) {
        for (col = 1; col <= total_rows; col++) {
            if (col < row)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}

/* Centred pyramid. */
static void pyramid(int total_rows)
{
    int row, space, star;

    for (row = 1; row <= total_rows; row++) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");
        for (star = 1; star <= (2 * row) - 1; star++)
            printf("*");
        printf("\n");
    }
}

/* Centred pyramid, upside down - count the rows downward instead. */
static void inverted_pyramid(int total_rows)
{
    int row, space, star;

    for (row = total_rows; row >= 1; row--) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");
        for (star = 1; star <= (2 * row) - 1; star++)
            printf("*");
        printf("\n");
    }
}

/* A diamond is a pyramid followed by an inverted one. The second half
 * starts at total_rows - 1 so the widest row is not printed twice. */
static void diamond(int total_rows)
{
    int row, space, star;

    for (row = 1; row <= total_rows; row++) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");
        for (star = 1; star <= (2 * row) - 1; star++)
            printf("*");
        printf("\n");
    }

    for (row = total_rows - 1; row >= 1; row--) {
        for (space = 1; space <= total_rows - row; space++)
            printf(" ");
        for (star = 1; star <= (2 * row) - 1; star++)
            printf("*");
        printf("\n");
    }
}

/* The same trick without the leading spaces. */
static void half_diamond(int total_rows)
{
    int row, star;

    for (row = 1; row <= total_rows; row++) {
        for (star = 1; star <= row; star++)
            printf("*");
        printf("\n");
    }

    for (row = total_rows - 1; row >= 1; row--) {
        for (star = 1; star <= row; star++)
            printf("*");
        printf("\n");
    }
}

int main(void)
{
    int n;

    printf("Enter the number of rows: ");
    if (scanf("%d", &n) != 1 || n < 1)
        return 1;

    printf("\n--- rectangle ---\n");
    rectangle(n, n);

    printf("\n--- rectangle, written with while loops ---\n");
    rectangle_with_while(n, n);

    printf("\n--- half pyramid ---\n");
    half_pyramid(n);

    printf("\n--- inverted half pyramid ---\n");
    inverted_half_pyramid(n);

    printf("\n--- pyramid ---\n");
    pyramid(n);

    printf("\n--- inverted pyramid ---\n");
    inverted_pyramid(n);

    printf("\n--- diamond ---\n");
    diamond(n);

    printf("\n--- half diamond ---\n");
    half_diamond(n);

    return 0;
}
