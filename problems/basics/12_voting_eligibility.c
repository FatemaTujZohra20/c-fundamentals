/*
 * Voting Eligibility and Age Group Classification.
 *
 * Take a person's age as input and determine:
 *
 *   1. Voting eligibility
 *      - 18 or older  -> eligible to vote
 *      - below 18     -> not eligible
 *
 *   2. Age group
 *      - below 0   -> "Invalid age"
 *      - 0 to 12   -> "Child"
 *      - 13 to 17  -> "Teenager"
 *      - 18 to 64  -> "Adult"
 *      - 65 and up -> "Senior"
 *
 * Example:
 *   Enter age: 20      ->  Eligible to vote.     / Age group: Adult
 *   Enter age: 10      ->  Not eligible to vote. / Age group: Child
 *
 * Two independent questions about one input, so there are two separate
 * decisions rather than one combined ladder. The eligibility test is a
 * single comparison; the age group is a ladder over ranges.
 *
 * The invalid case is checked first, so the ladder below it can assume
 * the age is sane and test only upper bounds.
 */

#include <stdio.h>

int main(void)
{
    int age;

    printf("Enter age: ");
    if (scanf("%d", &age) != 1)
        return 1;

    if (age < 0) {
        printf("Invalid age\n");
        return 1;
    }

    /* 1. Voting eligibility */
    if (age >= 18)
        printf("Eligible to vote.\n");
    else
        printf("Not eligible to vote.\n");

    /* 2. Age group - the ladder stops at the first match, so each test
     *    only needs its upper bound. */
    printf("Age group: ");
    if (age <= 12)
        printf("Child\n");
    else if (age <= 17)
        printf("Teenager\n");
    else if (age <= 64)
        printf("Adult\n");
    else
        printf("Senior\n");

    return 0;
}
