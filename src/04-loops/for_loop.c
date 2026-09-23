/*
 * for loop - a progression of exercises, from the simplest counted loop
 * to nested loops.
 *
 *     for (init; condition; update)
 *          |     |          |
 *          |     |          runs after each pass
 *          |     tested before each pass; the loop ends when it is false
 *          runs once, before anything else
 *
 *   1. repeat_fixed()          repeat a fixed number of times
 *   2. step_by_four()          an update other than ++
 *   3. print_counter()         using the counter's value in the body
 *   4. odd_numbers()           stepping by 2 from an odd start
 *   5. count_down()            counting backwards
 *   6. sum_naturals()          accumulating a running total
 *   7. sum_multiples_of_15()   accumulating with a test inside
 *   8. sum_of_squares()        accumulating a computed value
 *   9. nested()                a loop inside a loop
 *
 * Each exercise is its own function so they can all be run and compared.
 */

#include <stdio.h>

/* 1. Repeat a fixed number of times. */
static void repeat_fixed(void)
{
    int i;
    for (i = 1; i <= 3; i++)
        printf("Let me go.\n");
}

/* 2. The counter does not have to step by 1. */
static void step_by_four(void)
{
    int a;
    for (a = 1; a <= 10; a = a + 4)
        printf("a = %d\n", a);
}

/* 3. Print the counter itself, then show that it is still in scope after. */
static void print_counter(void)
{
    int i;
    for (i = 1; i <= 3; i++)
        printf("%d\n", i);
    printf("Out of the loop!\n");
}

/* 4. Odd numbers from 1 to 100. */
static void odd_numbers(void)
{
    int i;
    for (i = 1; i <= 100; i = i + 2)
        printf("%d ", i);
    printf("\n");
}

/* 5. Counting down instead of up. */
static void count_down(void)
{
    int i;
    for (i = 100; i >= 0; i = i - 10)
        printf("%d ", i);
    printf("\n");
}

/* 6. Sum of the first n natural numbers.
 *
 * Careful with the accumulator: `sum =+ i` compiles, but parses as
 * `sum = +i`, so sum ends up holding only the last value instead of the
 * running total. The operator that accumulates is `+=`.
 */
static void sum_naturals(void)
{
    int i, n, sum = 0;

    printf("Enter upper limit: ");
    if (scanf("%d", &n) != 1)
        return;

    for (i = 1; i <= n; i++)
        sum += i;

    printf("Sum of first %d natural numbers = %d\n", n, sum);
}

/* 7. Sum every number in a range that is divisible by both 3 and 5. */
static void sum_multiples_of_15(void)
{
    int i, sum = 0;
    for (i = 30; i <= 120; i++)
        if (i % 3 == 0 && i % 5 == 0)
            sum += i;
    printf("Summation: %d\n", sum);
}

/* 8. Sum of squares from 5 to 25. */
static void sum_of_squares(void)
{
    int i, sum = 0;
    for (i = 5; i <= 25; i++)
        sum += i * i;
    printf("Sum of squares: %d\n", sum);
}

/* 9. Nested loops: the inner loop runs in full for every outer step. */
static void nested(void)
{
    int i, j;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
}

int main(void)
{
    repeat_fixed();
    step_by_four();
    print_counter();
    odd_numbers();
    count_down();
    sum_multiples_of_15();
    sum_of_squares();
    nested();
    sum_naturals();   /* asks for input, so it goes last */

    return 0;
}
