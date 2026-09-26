/*
 * struct - grouping related values of different types under one name.
 *
 *     struct student {
 *         int   id;
 *         float cgpa;
 *         char  name[20];
 *     };
 *
 * That declares a TYPE and reserves no memory. The variable comes after:
 *
 *     struct student s;      one student, holding all three members
 *     s.id                   reach a member with a dot
 *
 * Unlike an array, the members have different types and are named rather
 * than numbered. That is the point of a struct: id, cgpa and name belong
 * to one person, and keeping them in three loose variables loses that
 * connection - nothing would stop one being updated without the others.
 *
 * Note the & in the scanf calls. `&s.id` is the address of that member,
 * the same as for any ordinary variable. s.name is the exception: it is
 * already an array, so it is already an address and takes no &.
 *
 * "%19s" caps the read at 19 characters, leaving room in name[20] for the
 * terminator.
 */

#include <stdio.h>

struct student {
    int   id;
    float cgpa;
    char  name[20];
};

int main(void)
{
    struct student s;

    printf("Enter your id: ");
    if (scanf("%d", &s.id) != 1)
        return 1;

    printf("Enter your cgpa: ");
    if (scanf("%f", &s.cgpa) != 1)
        return 1;

    printf("Enter your name: ");
    if (scanf("%19s", s.name) != 1)   /* width limit keeps scanf inside the array */
        return 1;

    printf("Name: %s; Id: %d; cgpa: %.2f\n", s.name, s.id, s.cgpa);

    return 0;
}
