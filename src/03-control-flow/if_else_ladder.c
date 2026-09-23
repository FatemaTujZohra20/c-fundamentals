/*
 * if / else-if ladder - one value tested against several exact matches.
 *
 * Conditions are evaluated top to bottom and the first match wins, so the
 * remaining branches never run. The final bare `else` catches everything
 * that matched nothing, which is what makes the input validation work.
 *
 * A ladder of pure equality tests like this one is exactly what
 * switch/case exists for - switch_case.c writes the same shape that way.
 *
 * The two string literals in the last branch sit next to each other with
 * no operator between them. C joins adjacent string literals at compile
 * time, which is how one long message is split across two lines.
 */

#include <stdio.h>

int main(void)
{
    int num;

    printf("Enter an integer number between 1 to 5: ");
    if (scanf("%d", &num) != 1)
        return 1;

    if (num == 1)
        printf("This number is one.\n");
    else if (num == 2)
        printf("This number is two.\n");
    else if (num == 3)
        printf("This number is three.\n");
    else if (num == 4)
        printf("This number is four.\n");
    else if (num == 5)
        printf("This number is five.\n");
    else
        printf("\nYou have entered an invalid number.\n"
               "Please enter a number between 1 to 5.\n");

    return 0;
}
