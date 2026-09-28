/*
 * UVa 100 - The 3n + 1 problem
 *
 * For a starting value n, repeat:
 *     n is even  ->  n = n / 2
 *     n is odd   ->  n = 3n + 1
 * until n reaches 1. The cycle length is how many numbers were visited,
 * counting both the start and the final 1.
 *
 *     22 -> 11 -> 34 -> 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10
 *        -> 5 -> 16 -> 8 -> 4 -> 2 -> 1          cycle length 16
 *
 * Input is pairs i j. For each pair, print i, j, and the largest cycle
 * length of any number between them - inclusive, and with i and j echoed
 * back in the order they were given, even if i > j.
 *
 * Two details that decide whether a judge accepts this:
 *
 *   The pair may arrive in either order. The loop needs the smaller bound
 *   first, so x and y are swapped when necessary while the originals are
 *   kept for the output line.
 *
 *   cycle_length() takes a long. 3n + 1 can climb well above the starting
 *   value before it comes back down, so an int is not obviously safe for
 *   the intermediate values even when the input fits comfortably.
 *
 * `while (scanf(...) == 2)` reads until the input runs out, which is the
 * usual shape for judge problems - there is no count of test cases and no
 * terminating line, only end of file.
 *
 * https://onlinejudge.org/external/1/100.pdf
 */

#include <stdio.h>

static int cycle_length(long x)
{
    int count = 1;

    while (x != 1) {
        if (x % 2 == 1)
            x = 3 * x + 1;
        else
            x = x / 2;
        count++;
    }

    return count;
}

int main(void)
{
    int x, y;

    while (scanf("%d %d", &x, &y) == 2) {
        int i;
        int original_x = x, original_y = y;
        int max_length = 0;

        /* The range may be given in either order, so normalise it for
         * the loop while still echoing the originals. */
        if (x > y) {
            int temp = x;
            x = y;
            y = temp;
        }

        for (i = x; i <= y; i++) {
            int len = cycle_length(i);
            if (len > max_length)
                max_length = len;
        }

        printf("%d %d %d\n", original_x, original_y, max_length);
    }

    return 0;
}
