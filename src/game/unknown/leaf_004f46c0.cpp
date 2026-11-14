/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: takes an object out of the pointer list at +0xf8 (count at
 * +0x100) of the member at +0xc8 of the object the pointer at 0x57c9390
 * holds, the entries after it moved down one with memmove, then hands it to
 * FUN_005016d0. The index stays -1 when the object is not in the list (the
 * move is made with it all the same). The classes are not traced. */
struct Object005016d0; /* derived name */

struct List057c9390_c8 { /* derived name */
    u8 unknown0[0xf8];
    Object005016d0 **entries; /* +0xf8 */
    unsigned count;           /* +0x100 */
};

struct Object057c9390 { /* derived name */
    u8 unknown0[0xc8];
    List057c9390_c8 *unknownc8;
};

extern Object057c9390 *D_57c9390;

void FUN_005016d0(Object005016d0 *object); /* derived name */

void FUN_004f46c0(Object005016d0 *object) /* derived name */
{
    List057c9390_c8 *list = D_57c9390->unknownc8;
    unsigned index = -1;
    for (unsigned i = 0; i < list->count; ++i) {
        if (list->entries[i] == object) {
            index = i;
            break;
        }
    }
    Object005016d0 **entry = &list->entries[index];
    memmove(entry, entry + 1, (list->count - index - 1) * 8);
    --list->count;
    FUN_005016d0(object);
}
