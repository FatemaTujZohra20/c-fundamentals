/*
 * Functions - defining one, calling it, and getting a value back.
 *
 *     static float square(float x)
 *            |     |      |
 *            |     |      the parameter: a local variable holding a copy
 *            |     |      of whatever the caller passed
 *            |     the name used to call it
 *            the return type: what the function hands back
 *
 *   1. hello_func()   no parameters, no return value  (void, void)
 *   2. square()       one parameter, returns a value
 *   3. add()          two parameters, returns a value
 *
 * `void` in the return position means the function hands nothing back;
 * `void` in the parameter list means it takes nothing. hello_func() is
 * written `(void)` rather than `()` because an empty list means "takes an
 * unspecified number of arguments" in C, not "takes none".
 *
 * `static` here means the function is private to this file. It is not
 * about storage or lifetime, and every function in these exercises is
 * static because nothing outside the file needs to call it.
 *
 * A function must be declared before it is used, which is why all three
 * are defined above main() rather than below it.
 */

#include <stdio.h>

/* No parameters, no return value. */
static void hello_func(void)
{
    printf("Hello!! I am from inside a function.\n");
}

/* Takes a float, returns a float. */
static float square(float x)
{
    return x * x;
}

/* Takes two ints, returns their sum. */
static int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    float y;

    hello_func();

    /* The returned value can be stored... */
    y = square(2.5f);
    printf("%.2f\n", y);

    y = square(3.5f);
    printf("%.2f\n", y);

    /* ...or used directly in the call that consumes it. */
    printf("%.2f\n", square(5.5f));

    /* An int argument is converted to float automatically. */
    printf("%f\n", square(5));

    printf("%d\n", add(123, 10));

    return 0;
}
