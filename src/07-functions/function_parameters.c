/*
 * Passing several parameters of different types.
 *
 *   1. introduce()    a string and an int
 *   2. my_details()   two strings and an int
 *   3. profile()      two strings, an int and a float
 *
 * Arguments are matched by position, not by name. The parameter names
 * inside the function are its own; the caller's variable names are
 * irrelevant, and the two need not match.
 *
 * A char array parameter is received as a pointer to its first character.
 * That is why it needs no size in the declaration - and also why the
 * function cannot measure it. `char name[]` and `char *name` mean exactly
 * the same thing in a parameter list.
 *
 * Careful: because it is a pointer, writing through it changes the
 * caller's string. These three only read, but nothing in the signature
 * enforces that. `const char *name` is the way to say so and have the
 * compiler check it - see array_as_argument.c.
 */

#include <stdio.h>

static void introduce(char name[], int year)
{
    printf("I'm %s and I'm %d years old\n", name, year);
}

static void my_details(char name[], int age, char hobby[])
{
    printf("My name is \"%s\".\n", name);
    printf("I am %d years old.\n", age);
    printf("My hobby is \"%s\".\n", hobby);
}

/* The same function called repeatedly with different arguments is the
 * whole reason to write a function in the first place. */
static void profile(char name[], int age, char city[], float years)
{
    printf("\nName: %s\nAge: %d\nCity: %s\nYears there: %.2f\n",
           name, age, city, years);
}

int main(void)
{
    introduce("Meem", 15);

    my_details("Meem", 29, "Learning");

    profile("Lily",   59, "Dhaka",      3.5f);
    profile("Sriti",  89, "Chattogram", 2.0f);
    profile("Monika", 55, "Sylhet",     7.0f);

    return 0;
}
