/*
 * Check whether a character is a vowel or a consonant, using switch.
 *
 * Cases with no body fall through to the next one, so all ten labels -
 * five vowels in each case - share a single printf:
 *
 *     case 'a': case 'e': case 'i': case 'o': case 'u':
 *     case 'A': case 'E': case 'I': case 'O': case 'U':
 *         printf("Vowel\n");
 *         break;
 *
 * Both cases are listed because a switch compares exact values, and 'a'
 * and 'A' are different characters. The alternative is converting the
 * input with tolower() from <ctype.h> and listing five labels.
 *
 * `default` catches everything else, which is what makes the consonant
 * branch work without listing twenty-one more labels.
 */

#include <stdio.h>

int main(void)
{
    char alphabet;

    printf("Enter a character: ");
    if (scanf(" %c", &alphabet) != 1)
        return 1;

    /* Reject anything that is not a letter before classifying it. */
    if (!(alphabet >= 'a' && alphabet <= 'z')
        && !(alphabet >= 'A' && alphabet <= 'Z')) {
        printf("The character '%c' is not an alphabet.\n", alphabet);
        return 1;
    }

    switch (alphabet) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
    case 'A': case 'E': case 'I': case 'O': case 'U':
        printf("The character '%c' is a vowel.\n", alphabet);
        break;
    default:
        printf("The character '%c' is a consonant.\n", alphabet);
    }

    return 0;
}
