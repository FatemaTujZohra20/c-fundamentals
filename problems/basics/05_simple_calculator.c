/*
 * Write a program to make a simple calculator.
 *
 * Input is read as one expression - "12.5 * 3" - by asking scanf for a
 * number, a character and another number in a single call.
 *
 * An error flag records that the operator was not recognised, so the
 * result is only printed when there is a real result to print.
 */

#include <stdio.h>
#include <stdbool.h>

static double add(double a, double b)      { return a + b; }
static double subtract(double a, double b) { return a - b; }
static double multiply(double a, double b) { return a * b; }
static double divide(double a, double b)   { return a / b; }

int main(void)
{
    char   ch;
    double operand1, operand2, result = 0.0;
    bool   error = false;

    printf("Enter an expression (for example  12.5 * 3 ): ");
    if (scanf("%lf %c %lf", &operand1, &ch, &operand2) != 3)
        return 1;

    if (ch == '+')
        result = add(operand1, operand2);
    else if (ch == '-')
        result = subtract(operand1, operand2);
    else if (ch == '*')
        result = multiply(operand1, operand2);
    else if (ch == '/') {
        if (operand2 == 0.0) {
            error = true;
            printf("Cannot divide by zero!\n");
        } else {
            result = divide(operand1, operand2);
        }
    } else {
        error = true;                    /* the flag */
        printf("Syntax Error!!!\n");
    }

    if (!error)
        printf("%.2lf %c %.2lf = %.2lf\n", operand1, ch, operand2, result);

    return 0;
}
