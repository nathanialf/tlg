/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_math.h"

/* derived names: a virtual slot (its address at 0x16ba440) whose object is
 * not read: for each of the items its argument lists (the array at +0x268,
 * counted by the unsigned int at +0x270) that has a source at +0x60, copies the
 * source's aligned vectors at +0xf0, +0x110 and +0x100 into the item's at
 * +0x30, +0x40 and +0x50. The types are not traced. */
struct Object00d47670; /* derived name */

struct Source00d47670 { /* derived name */
    u8 unknown0[0xf0];
    Float4A unknownf0;
    Float4A unknown100;
    Float4A unknown110;
};

struct Item00d47670 { /* derived name */
    u8 unknown0[0x30];
    Float4A unknown30;
    Float4A unknown40;
    Float4A unknown50;
    Source00d47670 *source; /* derived name; +0x60 */
};

struct List00d47670 { /* derived name */
    u8 unknown0[0x268];
    Item00d47670 **items; /* derived name; +0x268 */
    u32 count;            /* derived name; +0x270 */
};

// NONMATCHING: the int index kept 32-bit and sign-extended at each use where the
// build widens it to 64 bits (0xf501a0's IndVarSimplify class).
void FUN_00d47670(Object00d47670 *, List00d47670 *list) /* derived name */
{
    u32 count = list->count;
    for (int i = 0; i < count; ++i) {
        Item00d47670 *item = list->items[i];
        Source00d47670 *source = item->source;
        if (source) {
            item->unknown30 = source->unknownf0;
            item->unknown40 = source->unknown110;
            item->unknown50 = source->unknown100;
        }
    }
}
