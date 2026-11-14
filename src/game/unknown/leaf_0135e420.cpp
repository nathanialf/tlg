/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: whether the int at +0x28 of the object is among the ints of
 * the array the second argument gives (the data at +0x0, counted by the
 * unsigned int at +0x8): the index of the first match, or -1, compared with
 * -1. The types are not traced. Class and method unknown. */
struct IntArray0135e420 { /* derived name */
    int *data;            /* derived name */
    u32 count;            /* derived name */
};

struct Object0135e420 { /* derived name */
    u8 unknown0[0x28];
    int unknown28; /* +0x28: the value looked up */
};

int FUN_0135e420(Object0135e420 *self, const IntArray0135e420 *array) /* derived name */
{
    int index = -1;
    for (u32 i = 0; i < array->count; i++) {
        if (array->data[i] == self->unknown28) {
            index = i;
            break;
        }
    }
    return index != -1;
}
