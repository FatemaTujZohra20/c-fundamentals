/*
 * switch / case - four exercises.
 *
 *   1. day_of_week()          one case per value
 *   2. days_in_month()        several labels sharing one body
 *   3. vowel_or_consonant()   the same, over characters
 *   4. even_or_odd()          switching on a computed value, num % 2
 *
 * A switch compares one value against constant labels and jumps to the
 * match. `break` matters: without it, control falls through into the next
 * case body. Cases that share a body - the 31-day months, the vowels -
 * use that fall-through deliberately by stacking labels with nothing
 * between them.
 *
 * `default` catches everything unmatched, and is where the input
 * validation lives.
 *
 * Careful: case labels must be compile-time constants, so a switch cannot
 * test a range or compare against a variable. That is what an if/else
 * ladder is for - compare if_else_ladder.c and largest_of_three.c.
 *
 * even_or_odd() switches on num % 2, which in C is -1 for a negative odd
 * number rather than 1. Hence `case -1:` alongside `case 1:`.
 */

#include <stdio.h>

static void day_of_week(void)
{
    int week;

    printf("Enter week number (1 - 7): ");
    if (scanf("%d", &week) != 1)
        return;

    switch (week) {
    case 1:  printf("Monday\n");    break;
    case 2:  printf("Tuesday\n");   break;
    case 3:  printf("Wednesday\n"); break;
    case 4:  printf("Thursday\n");  break;
    case 5:  printf("Friday\n");    break;
    case 6:  printf("Saturday\n");  break;
    case 7:  printf("Sunday\n");    break;
    default: printf("Invalid input! Please enter week number between 1-7.\n");
    }
}

static void days_in_month(void)
{
    int month;

    printf("Enter month number (1 - 12): ");
    if (scanf("%d", &month) != 1)
        return;

    switch (month) {
    case 1: case 3: case 5: case 7:
    case 8: case 10: case 12:
        printf("31 days\n");
        break;
    case 4: case 6: case 9: case 11:
        printf("30 days\n");
        break;
    case 2:
        printf("28/29 days\n");
        break;
    default:
        printf("Invalid input! Please enter a month number between 1-12.\n");
    }
}

static void vowel_or_consonant(void)
{
    char ch;

    printf("Enter an alphabet: ");
    /* The space before %c skips any leftover whitespace, including the
     * newline the previous scanf left behind. */
    if (scanf(" %c", &ch) != 1)
        return;

    switch (ch) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
        printf("Vowel\n");
        break;
    default:
        printf("Consonant\n");
    }
}

static void even_or_odd(void)
{
    int num;

    printf("Enter any number to see if it is even or odd: ");
    if (scanf("%d", &num) != 1)
        return;

    /* Negative odd numbers give -1, so that case is handled too. */
    switch (num % 2) {
    case 0:            printf("Even Number\n"); break;
    case 1: case -1:   printf("Odd Number\n");  break;
    }
}

int main(void)
{
    day_of_week();
    days_in_month();
    vowel_or_consonant();
    even_or_odd();

    return 0;
}
