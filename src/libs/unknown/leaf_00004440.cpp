/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_pool.h"

/* The number of elements in the pool's array, the bound FUN_00180f50 uses
 * for FUN_00004450. */
int FUN_00004440(const Pool40 *pool) /* derived name */
{
    return pool->itemCount;
}
