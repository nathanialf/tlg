/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of 0x18-byte entries (FUN_00c0fb30 passes
 * it with the size 0x18, lea at 0xc0ff41): an entry whose first 64-bit field
 * is zero sorts after one whose field is set, 1 when the first's is zero, -1
 * when only the second's is, 0 otherwise. Class and method unknown. */
struct Entry00c11e40 { /* derived name */
    u64 unknown0;
    u8 unknown8[0x10];
};

int FUN_00c11e40(const void *first, const void *second) /* derived name */
{
    if (static_cast<const Entry00c11e40 *>(first)->unknown0 == 0) {
        return 1;
    }
    if (static_cast<const Entry00c11e40 *>(second)->unknown0 == 0) {
        return -1;
    }
    return 0;
}
