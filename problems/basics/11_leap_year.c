/*
 * Write a C program to find whether a given year is a leap year or not.
 * Test data: 2016
 *
 * The Gregorian rules:
 *   - a year divisible by 4 is a leap year,
 *   - except a century year (divisible by 100), which is not,
 *   - unless it is also divisible by 400, which makes it one again.
 *
 * So 1700, 1800, 1900, 2100, 2200 and 2300 are NOT leap years, while
 * 1600, 2000 and 2400 are.
 *
 * The order of the tests is what keeps this short. The century exception
 * is checked first:
 *
 *     year % 100 == 0 && year % 400 != 0   ->  not a leap year
 *     else if (year % 4 == 0)              ->  leap year
 *     else                                 ->  not a leap year
 *
 * so 1900 and 2100 are rejected before the `% 4` test ever sees them.
 * Testing `% 4` first would need the century rule nested inside it.
 *
 * The final else matters: without it a year that is divisible by neither
 * 100 nor 4 - 2019, say - would fall through every branch and print
 * nothing at all.
 */

#include <stdio.h>

int main(void)
{
    int year;

    printf("Enter the year's number: ");
    if (scanf("%d", &year) != 1)
        return 1;

    if (year % 100 == 0 && year % 400 != 0)
        printf("%d is not a leap year.\n", year);
    else if (year % 4 == 0)
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);

    return 0;
}
