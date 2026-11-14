/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: compares the strings the first fields of two 24-byte entries
 * point to, with strcmp as a tail call; FUN_00e744c0 passes its address (lea
 * at 0xe752e1) to qsort with the element size 24. */
struct Entry00e79150 { /* derived name */
    const char *name;
    u8 unknown8[16];
};

int FUN_00e79150(const void *a, const void *b) /* derived name */
{
    return strcmp(static_cast<const Entry00e79150 *>(a)->name,
                  static_cast<const Entry00e79150 *>(b)->name);
}
