/*
 * Find the grade of a student using an if-else ladder.
 *
 *     80+  A+ (5.0)      50+  B  (3.0)
 *     70+  A  (4.0)      40+  C  (2.5)
 *     60+  A- (3.5)      33+  D  (2.0)
 *                        else F  (0.0)
 *
 * Two things make this the standard shape for grading.
 *
 * The range check happens first and returns on failure, so everything
 * below it can assume the marks are between 0 and 100. Validating up
 * front keeps the validation out of the logic.
 *
 * Then each branch states only its lower bound. `marks >= 70` needs no
 * `&& marks < 80`, because a ladder stops at its first true test -
 * reaching that branch at all already proves 80 did not match. Writing
 * both bounds would not be wrong, only redundant, and every extra
 * condition is somewhere else for a boundary to be got wrong.
 *
 * The order is therefore load-bearing: sorting these branches the other
 * way round would give every passing student an F.
 */

#include <stdio.h>

int main(void)
{
    int marks;

    printf("Enter the marks: ");
    if (scanf("%d", &marks) != 1)
        return 1;

    if (marks < 0 || marks > 100) {
        printf("Your input is invalid!\n");
        return 1;
    }

    /* Each branch only needs its lower bound - reaching it already
     * proves the higher ranges did not match. */
    if (marks >= 80)
        printf("The grade is A+ | GPA : 5.0\n");
    else if (marks >= 70)
        printf("The grade is A  | GPA : 4.0\n");
    else if (marks >= 60)
        printf("The grade is A- | GPA : 3.5\n");
    else if (marks >= 50)
        printf("The grade is B  | GPA : 3.0\n");
    else if (marks >= 40)
        printf("The grade is C  | GPA : 2.5\n");
    else if (marks >= 33)
        printf("The grade is D  | GPA : 2.0\n");
    else
        printf("The grade is F  | GPA : 0.0\n");

    return 0;
}
