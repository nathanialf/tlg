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

    Item00d47670 *at(int index) const
    {
        return items[index];
    } /* derived name */
};

/* the counter is unsigned and the list's index an int: the index is sign-extended at each
 * use (`movsxd rdx, ecx`), not widened */
void FUN_00d47670(Object00d47670 *, List00d47670 *list) /* derived name */
{
    u32 count = list->count;
    for (u32 i = 0; i < count; ++i) {
        Item00d47670 *item = list->at(i);
        Source00d47670 *source = item->source;
        if (source) {
            item->unknown30 = source->unknownf0;
            item->unknown40 = source->unknown110;
            item->unknown50 = source->unknown100;
        }
    }
}
