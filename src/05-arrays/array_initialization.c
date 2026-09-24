/*
 * Arrays - the ways to declare and initialize them, and what happens at
 * the edges.
 *
 *   1. assign_one_by_one()          declare, then fill element by element
 *   2. fill_in_a_loop()             declare, then fill with a loop
 *   3. initialize_at_declaration()  the values given in the declaration
 *   4. partial_initialization()     fewer values than slots
 *   5. size_from_initializers()     no size given, counted from the list
 *
 * The two that carry real rules:
 *
 *     int a[5] = {1, 2};      the remaining 3 are set to 0, not garbage
 *     int a[]  = {1, 2, 3};   the size becomes exactly 3
 *
 * An array with no initializer at all is a different case: `int a[5];` as
 * a local variable holds whatever was already in that memory, so reading
 * it before writing is undefined. Partial initialization is what zeroes
 * the remainder, which makes `int a[5] = {0};` the idiom for zeroing the
 * whole array.
 */

#include <stdio.h>

/* Assigning element by element, after declaring the array. */
static void assign_one_by_one(void)
{
    int numbers[5];
    int index = 0;

    numbers[index]   = 10;
    numbers[++index] = 20;
    numbers[++index] = 30;
    numbers[++index] = 40;
    numbers[++index] = 50;

    printf("%d %d %d %d %d\n",
           numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
}

/* Filling an array in a loop. */
static void fill_in_a_loop(void)
{
    int numbers[5];
    int index, start_value = 10;

    for (index = 0; index < 5; index++) {
        numbers[index] = start_value;
        start_value += 15;
    }

    for (index = 0; index < 5; index++)
        printf("%d ", numbers[index]);
    printf("\n");
}

/*
 * Initializing at declaration.
 *
 *   int marks[5] = {};                    all zero (a GNU extension)
 *   int marks[5] = {0};                   all zero (standard C)
 *   int marks[5] = {0, 0, 0, 0, 0};       all zero, written out
 *   int marks[5] = {10, 20, 30, 35, 40};  fully specified
 */
static void initialize_at_declaration(void)
{
    int marks[5] = {10, 20, 30, 35, 40};
    int index;

    for (index = 0; index < 5; index++)
        printf("marks[%d] = %d\n", index, marks[index]);
}

/* Give fewer values than the size: the rest are set to 0, not garbage. */
static void partial_initialization(void)
{
    int marks[5] = {80, 70, 75};
    int index;

    for (index = 0; index < 5; index++)
        printf("marks[%d] = %d\n", index, marks[index]);
}

/* Leave the size out and the compiler counts the initializers for you. */
static void size_from_initializers(void)
{
    int marks[] = {80, 70, 75, 88, 100, 90, 60, 100};
    int index;
    int array_size;

    /* total bytes of the array / bytes of one element.
     * Here: (4 * 8) / 4 = 8. This only works where the array is declared,
     * not on a pointer. */
    array_size = sizeof(marks) / sizeof(marks[0]);
    printf("array_size = %d\n", array_size);

    for (index = 0; index < array_size; index++)
        printf("marks[%d] = %d\n", index, marks[index]);
}

/*
 * Two rules worth writing out, because both are easy to get wrong and
 * neither fails in an obvious way:
 *
 *   int marks[5] = {80, 70, 75, 88, 100, 90, 60};
 *       More initializers than the array has room for. The compiler
 *       rejects this outright - it is an error, not a source of garbage
 *       values.
 *
 *   for (index = 0; index < 7; index++)   on an array of size 5
 *       Reading past the end of an array is undefined behaviour. It may
 *       print garbage, it may crash, and it may appear to work today and
 *       not tomorrow. Always loop to the real size.
 */

int main(void)
{
    printf("--- assigning one by one ---\n");
    assign_one_by_one();

    printf("\n--- filling in a loop ---\n");
    fill_in_a_loop();

    printf("\n--- initialized at declaration ---\n");
    initialize_at_declaration();

    printf("\n--- partial initialization (rest become 0) ---\n");
    partial_initialization();

    printf("\n--- size deduced from initializers ---\n");
    size_from_initializers();

    return 0;
}
