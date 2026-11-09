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

// NONMATCHING: FUN_00cb5f80, the base loads the first entry's name before the second's
// (`mov rdi, [rdi]; mov rsi, [rsi]`) and the compile the other way round: a list-ilp
// tie between two independent loads, broken by their IR order (cookbook: list-ilp's
// ties fall to the nodes' IR order). The second entry's name read first in the
// source gives the base's order (tested, 4.0.0-src); not written, an ordering made to
// steer the scheduler. The same in all three comparators (0x1b0670, 0xcb5f80,
// 0xe79150), the only `mov rdi, [rdi]; mov rsi, [rsi]` pairs in the executable (the
// reverse pair occurs once, at 0x4222); 3.5.2 to 4.0.0 give the compile's order from
// this source.
int FUN_00cb5f80(const void *a, const void *b) /* derived name */
{
    return strcmp(static_cast<const Entry00cb5f80 *>(a)->name,
                  static_cast<const Entry00cb5f80 *>(b)->name);
}
