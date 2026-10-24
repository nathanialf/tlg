/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_types.h"

/* derived names: a pool whose element array sits at +0x28, 40-byte elements,
 * indexed by a signed int. Unknown owner. */
struct PoolElem40 {
    s64 words[5];
};

struct Pool40 {
    u8 unknown0[0x28];
    PoolElem40 *items;
};

PoolElem40 *FUN_00004450(Pool40 *pool, int index) /* derived name */
{
    return &pool->items[index];
}
