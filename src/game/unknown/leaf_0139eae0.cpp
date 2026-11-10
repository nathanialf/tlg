/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"

/* derived names: a qsort comparison of 0x10-byte entries (FUN_0139e980 passes
 * it with the size 0x10, lea at 0x139ea52): 1 when the first entry's unsigned
 * 64-bit key is above the second's, -1 otherwise. Class and method unknown. */
struct Entry0139eae0 { /* derived name */
    u64 unknown0;
    u8 unknown8[8];
};

int FUN_0139eae0(const void *first, const void *second) /* derived name */
{
    if (static_cast<const Entry0139eae0 *>(first)->unknown0 >
        static_cast<const Entry0139eae0 *>(second)->unknown0) {
        return 1;
    }
    return -1;
}
