/*
 * Write a C program to convert Celsius to Fahrenheit and Fahrenheit to
 * Celsius.
 *
 *   F = (C * 1.8) + 32
 *   C = (F - 32) / 1.8
 */

#include <stdio.h>

int main(void)
{
    char  choice;
    float fahren, celsi;

    printf("Enter the unit you want the answer in (c or C or f or F): ");

    /* The space before %c skips leftover whitespace from earlier input. */
    if (scanf(" %c", &choice) != 1)
        return 1;

    if (choice == 'c' || choice == 'C') {
        printf("Enter temperature in Fahrenheit: ");
        if (scanf("%f", &fahren) != 1)
            return 1;

        celsi = (fahren - 32) / 1.8f;
        printf("%.2f Fahrenheit is %.2f Celsius\n", fahren, celsi);

    } else if (choice == 'f' || choice == 'F') {
        printf("Enter temperature in Celsius: ");
        if (scanf("%f", &celsi) != 1)
            return 1;

        fahren = (celsi * 1.8f) + 32;
        printf("%.2f Celsius is %.2f Fahrenheit\n", celsi, fahren);

    } else {
        printf("Your choice is invalid!\n");
    }

    return 0;
}
