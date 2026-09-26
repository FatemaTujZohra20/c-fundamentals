/*
 * union - several members sharing one piece of memory.
 *
 * A struct gives every member its own storage, so all of them hold their
 * values at the same time. A union lays every member down at the SAME
 * address, so it is only ever holding one of them:
 *
 *     struct                        union
 *     +------+--------+-------+     +----------------+
 *     | i    | d      | name  |     | i / d / name   |   all at one address
 *     +------+--------+-------+     +----------------+
 *
 * Two consequences follow from that one fact:
 *
 *   1. sizeof(union) is the size of its LARGEST member (rounded up for
 *      alignment), not the sum of them.
 *
 *   2. Writing one member overwrites whatever another member was
 *      holding. Only the most recently written member has a meaningful
 *      value - the rest are reinterpretations of those same bytes.
 *
 * Unions are used when a value is one of several things but never more
 * than one at a time, and storing all the possibilities separately would
 * waste space.
 *
 *   1. compare_sizes()        sizeof a struct against sizeof a union with
 *                             identical members
 *   2. show_shared_address()  every member reports the same address
 *   3. show_overwriting()     writing one member destroys the others
 *   4. tagged_union_demo()    a struct pairing a union with an enum tag
 *                             recording which member is currently valid
 *   5. inspect_bytes()        viewing one float as its individual bytes
 *
 * Demo 4 is the pattern that makes unions usable in practice. A union on
 * its own has no way to say which member it is holding, so it is wrapped
 * in a struct alongside a tag that does, and every read goes through that
 * tag - see print_value().
 */

#include <stdio.h>
#include <string.h>

/* The same three members, once as a struct and once as a union, so the
 * sizes can be compared directly. */
struct as_struct {
    int    i;
    double d;
    char   name[20];
};

union as_union {
    int    i;
    double d;
    char   name[20];
};

/*
 * 1. Size: the struct needs room for everything, the union only for its
 *    biggest member.
 */
static void compare_sizes(void)
{
    printf("sizeof(int)        = %zu\n", sizeof(int));
    printf("sizeof(double)     = %zu\n", sizeof(double));
    printf("sizeof(char[20])   = %zu\n", sizeof(char[20]));
    printf("\n");
    printf("sizeof(struct)     = %zu   (every member gets its own space)\n",
           sizeof(struct as_struct));
    printf("sizeof(union)      = %zu   (only the largest member's space)\n",
           sizeof(union as_union));
}

/*
 * 2. Sharing: every member reports the same address, because there is
 *    only one piece of memory underneath.
 */
static void show_shared_address(void)
{
    union as_union u;

    printf("&u.i    = %p\n", (void *)&u.i);
    printf("&u.d    = %p\n", (void *)&u.d);
    printf("&u.name = %p\n", (void *)u.name);
    printf("\nAll three are the same address.\n");
}

/*
 * 3. Overwriting: assigning to one member destroys the others.
 *
 *    u.i is set first and reads back correctly. Then u.d is written over
 *    the same bytes, and u.i is no longer 42 - it is whatever the first
 *    four bytes of the double happen to be.
 */
static void show_overwriting(void)
{
    union as_union u;

    u.i = 42;
    printf("after u.i = 42;        u.i = %d\n", u.i);

    u.d = 3.14;
    printf("after u.d = 3.14;      u.d = %.2f\n", u.d);
    printf("                       u.i = %d   <- no longer 42\n", u.i);

    strcpy(u.name, "hello");
    printf("after strcpy(u.name);  u.name = %s\n", u.name);
    printf("                       u.d = %f   <- meaningless now\n", u.d);
}

/*
 * 4. The safe way to use a union: pair it with a tag that records which
 *    member is currently valid.
 *
 * This is called a "tagged union" or "variant". The struct wrapper costs
 * a few bytes for the tag, but it makes the union usable - without the
 * tag there is no way to know which member holds the real value.
 */
enum value_kind {
    KIND_INT,
    KIND_DOUBLE,
    KIND_STRING
};

struct value {
    enum value_kind kind;       /* which member of data is valid */
    union {
        int    i;
        double d;
        char   s[20];
    } data;
};

static void print_value(const struct value *v)
{
    /* The tag decides which member may be read. Reading any other one
     * would be reading bytes that were never written as that type. */
    switch (v->kind) {
    case KIND_INT:
        printf("int:    %d\n", v->data.i);
        break;
    case KIND_DOUBLE:
        printf("double: %.2f\n", v->data.d);
        break;
    case KIND_STRING:
        printf("string: %s\n", v->data.s);
        break;
    }
}

static void tagged_union_demo(void)
{
    struct value values[3];

    values[0].kind = KIND_INT;
    values[0].data.i = 7;

    values[1].kind = KIND_DOUBLE;
    values[1].data.d = 2.5;

    values[2].kind = KIND_STRING;
    strcpy(values[2].data.s, "union");

    for (int i = 0; i < 3; i++)
        print_value(&values[i]);

    printf("\nsizeof(struct value) = %zu\n", sizeof(struct value));
}

/*
 * 5. Looking at the bytes of a value through a different member.
 *
 * Writing a float and reading the char array shows how that float is
 * actually stored in memory. In C this is legal and well defined (since
 * C99); in C++ the same code is undefined behaviour.
 *
 * The byte order below depends on the machine - on a little-endian CPU,
 * which is nearly all of them now, the least significant byte prints
 * first.
 */
union bytes_view {
    float        f;
    unsigned char raw[sizeof(float)];
};

static void inspect_bytes(void)
{
    union bytes_view v;
    size_t i;

    v.f = 1.0f;

    printf("the float %.1f is stored as the bytes:", v.f);
    for (i = 0; i < sizeof(v.raw); i++)
        printf(" %02X", v.raw[i]);
    printf("\n");
}

int main(void)
{
    printf("=== 1. struct size vs union size ===\n");
    compare_sizes();

    printf("\n=== 2. every member shares one address ===\n");
    show_shared_address();

    printf("\n=== 3. writing one member overwrites the others ===\n");
    show_overwriting();

    printf("\n=== 4. a tagged union, the safe pattern ===\n");
    tagged_union_demo();

    printf("\n=== 5. viewing the bytes of a float ===\n");
    inspect_bytes();

    return 0;
}
