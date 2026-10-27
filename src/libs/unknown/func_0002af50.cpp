/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the ints after the tail's optional 16-byte blocks: one
 * when any flag is set, one more for bit 1 and one for bit 0. */
const s32 *FUN_0002af50(const Pair08Tail *tail)
{
    const char *base = reinterpret_cast<const char *>(tail);
    return reinterpret_cast<const s32 *>(base + (tail->hasFlags() ? sizeof(Vec4) : 0) +
                                         (tail->hasFlag1() ? sizeof(Vec4) : 0) +
                                         (tail->hasFlag0() ? sizeof(Vec4) : 0));
}
