/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: compares the strings the first fields of two 16-byte entries
 * point to, with strcmp as a tail call; FUN_001b17f0 passes its address (lea
 * at 0x1b1e06) to qsort with the element size 16. */
struct Entry001b0670 { /* derived name */
    const char *name;
    u8 unknown8[8];
};

int FUN_001b0670(const void *a, const void *b) /* derived name */
{
    return strcmp(static_cast<const Entry001b0670 *>(a)->name,
                  static_cast<const Entry001b0670 *>(b)->name);
}
