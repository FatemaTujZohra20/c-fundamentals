/*
 * A natural number larger than 1 is prime if it divides evenly only by 1
 * and by itself.
 *
 *   1. is_prime_sqrt()  test divisors while i * i <= num
 *   2. is_prime_half()  test divisors up to num / 2, using a flag
 *
 * Two ways, differing only in how far they look for a factor - and that
 * difference is the whole lesson.
 *
 * If num has a factor larger than its square root, it must also have a
 * matching one below it, because the two multiply to num. So a factor
 * missed above the square root would already have been found below it,
 * and there is no reason to look past it.
 *
 *     1,000,003   way 1 checks about 1,000 divisors
 *                 way 2 checks about 500,000
 *
 * Both return the same answers. `i * i <= num` is also preferred to
 * `i <= sqrt(num)` because it stays in integer arithmetic - no <math.h>,
 * and no floating-point rounding near the boundary.
 *
 * Numbers below 2 are rejected up front: 1 is not prime, and neither is
 * 0 or any negative.
 */

#include <stdio.h>

/*
 * Way 1: test divisors while i * i <= num.
 *
 * If num has a factor larger than its square root, it must also have
 * one smaller than it - so there is no point looking past sqrt(num).
 * For 1,000,003 this checks about 1,000 divisors.
 */
static int is_prime_sqrt(int num)
{
    int i;

    if (num < 2)
        return 0;

    for (i = 2; i * i <= num; i++)
        if (num % i == 0)
            return 0;

    return 1;
}

/*
 * Way 2: test divisors up to num / 2, using a flag.
 *
 * Correct, but does far more work - about 500,000 divisions for the
 * same 1,000,003.
 */
static int is_prime_half(int n)
{
    int i, flag = 0;

    if (n == 0 || n == 1)
        flag = 1;

    for (i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    return flag == 0;
}

int main(void)
{
    int num;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1)
        return 1;

    if (is_prime_sqrt(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    /* Both methods must always agree. */
    printf("(second method agrees: %s)\n",
           is_prime_sqrt(num) == is_prime_half(num) ? "yes" : "no");

    return 0;
}
