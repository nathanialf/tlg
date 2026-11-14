/* src/game/unknown/: game-region functions (0x1a3e00 and up; docs/TARGETS.md) matched before their translation unit is known. */
#include "tlg_types.h"
#include "tlg_libc.h"

/* derived names: compares the strings the first fields of two 16-byte entries
 * point to, with strcmp as a tail call; FUN_00cb5f90 passes its address (lea
 * at 0xcb5fca) to bsearch with the element size 16. */
struct Entry00cb5f80 { /* derived name */
    const char *name;
    u8 unknown8[8];
};

int FUN_00cb5f80(const void *a, const void *b) /* derived name */
{
    return strcmp(static_cast<const Entry00cb5f80 *>(a)->name,
                  static_cast<const Entry00cb5f80 *>(b)->name);
}
