/*
 * Left shift and right shift.
 *
 * A shift moves every bit a given number of places and fills the vacated
 * positions with zeros. Because each bit position is worth twice the one
 * to its right, shifting is multiplication or division by a power of two:
 *
 *   var << 2   moves every bit 2 places left   ->  multiply by 2^2 = 4
 *   var >> 2   moves every bit 2 places right  ->  divide by 2^2 = 4
 *
 * A `short` is 2 bytes = 16 bits, and the comment on each line below
 * writes out all 16 so the movement is visible.
 *
 * Careful: bits shifted off the end are gone. Shifting left far enough
 * discards the high bits rather than growing the value, and shifting
 * right discards the low ones - which is why >> on an odd number loses
 * the remainder, unlike ordinary division that you then round. Shifting
 * a negative number right is implementation defined.
 */

#include <stdio.h>

int main(void)
{
    short var1 = 4;         /* 0000 0000 0000 0100 */

    /* Left shift */
    var1 = var1 << 2;       /* 0000 0000 0001 0000 -> 16   (4 * 4)  */
    var1 = var1 << 2;       /* 0000 0000 0100 0000 -> 64   (16 * 4) */
    printf("After left shift, var1 is: %d\n", var1);

    /* Right shift */
    var1 = var1 >> 2;       /* 0000 0000 0001 0000 -> 16   (64 / 4) */
    var1 = var1 >> 2;       /* 0000 0000 0000 0100 -> 4    (16 / 4) */
    printf("After right shift, var1 is: %d\n", var1);

    return 0;
}
