/*
 * #define - text substitution performed by the preprocessor, before the
 * compiler sees the file at all. A macro is not a variable and not a
 * function: it has no type and occupies no memory.
 *
 *     #define VALUE   10
 *     #define GREET   printf("hello\n")
 *
 *     int i = VALUE;      the compiler actually sees:  int i = 10;
 *     GREET;              the compiler actually sees:  printf("hello\n");
 *
 * Because the mechanism is plain text, a #define takes no semicolon -
 * adding one would substitute the semicolon along with everything else.
 *
 * You can watch the substitution happen:
 *
 *     gcc -E preprocessor_macros.c
 *
 * The file also shows that printf returns the number of characters it
 * wrote, which is what makes it usable as a condition.
 */

#include <stdio.h>

#define VALUE   10
#define GREET   printf("hello\n")

int main(void)
{
    int i = VALUE;      /* becomes: int i = 10; */
    printf("%d\n", i);

    GREET;              /* becomes: printf("hello\n"); */

    /* printf returns the number of characters it wrote, so it can be
     * used as a condition - here it returns 5 and the branch is taken. */
    if (printf("Hello"))
        printf(" <- printf returned a non-zero character count\n");

    return 0;
}
