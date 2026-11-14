/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: returns the first of the record's elements (the pointers at
 * +0x28, counted by the unsigned int at +0x30, an array indexed by int: the
 * index sign-extended in the loop) whose int at +0x30 equals the
 * int the second argument points at, or null. The types are not traced.
 * Class and method unknown. */
struct Element013d4a40 { /* derived name */
    u8 unknown0[0x30];
    int unknown30; /* +0x30: the id compared */
};

struct ElementArray013d4a40 { /* derived name */
    Element013d4a40 **data;   /* derived name */
    unsigned count;           /* derived name */

    unsigned size() const
    {
        return count;
    }

    Element013d4a40 *operator[](int index) const
    {
        return data[index];
    }
};

struct Object013d4a40 { /* derived name */
    u8 unknown0[0x28];
    ElementArray013d4a40 unknown28; /* +0x28 */
};

Element013d4a40 *FUN_013d4a40(Object013d4a40 *self, const int *id) /* derived name */
{
    for (unsigned i = 0; i < self->unknown28.size(); i++) {
        Element013d4a40 *element = self->unknown28[i];
        if (element->unknown30 == *id)
            return element;
    }
    return 0;
}
