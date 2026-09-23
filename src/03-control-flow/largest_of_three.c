/*
 * Finding the largest of three numbers - the same job written three ways.
 *
 *   1. nested_if()       compare two, then the winner against the third
 *   2. running_max()     keep the biggest value seen so far
 *   3. if_else_ladder()  test each candidate against both others
 *
 * All three print the same answer for the same input, which is the point:
 * choosing between them is a readability decision, not a correctness one.
 *
 * running_max() is the one that scales. A fourth number costs it one more
 * line, while the nested version doubles in size and the ladder needs
 * every comparison rewritten.
 */

#include <stdio.h>
#include <limits.h>

/* 1. Nested if: compare two, then compare the winner with the third. */
static int nested_if(int num1, int num2, int num3)
{
    if (num1 > num2) {
        if (num1 > num3)
            return num1;
        else
            return num3;
    } else {
        if (num2 > num3)
            return num2;
        else
            return num3;
    }
}

/* 2. Running maximum: start below every possible value, then keep the
 *    biggest one seen. INT_MIN from <limits.h> is that starting point.
 *    Writing a literal such as -2147483646 instead would be unportable,
 *    and simply wrong for any input below it. */
static int running_max(int num1, int num2, int num3)
{
    int max = INT_MIN;

    if (max < num1) max = num1;
    if (max < num2) max = num2;
    if (max < num3) max = num3;

    return max;
}

/* 3. An else-if ladder testing each candidate against both others.
 *    >= rather than > matters here: with > , three equal numbers would
 *    fall through every branch. */
static int if_else_ladder(int num1, int num2, int num3)
{
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 >= num1 && num2 >= num3)
        return num2;
    else
        return num3;
}

int main(void)
{
    int num1, num2, num3;

    printf("Enter the three numbers: ");
    if (scanf("%d %d %d", &num1, &num2, &num3) != 3)
        return 1;

    printf("nested if:      %d is the largest number.\n",
           nested_if(num1, num2, num3));
    printf("running max:    %d is the largest number.\n",
           running_max(num1, num2, num3));
    printf("if-else ladder: %d is the largest number.\n",
           if_else_ladder(num1, num2, num3));

    return 0;
}
