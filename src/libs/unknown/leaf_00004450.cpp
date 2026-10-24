/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_pool.h"

/* The address of element `index` of the pool's 40-byte array. */
PoolElem40 *FUN_00004450(Pool40 *pool, int index) /* derived name */
{
    return &pool->items[index];
}
