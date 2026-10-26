/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 4 hands out the whole block, when nothing of it is out
 * and it holds the request; the request becomes what the block holds. */
void *SingleBlockAllocator::FUN_000120d0(int &numBytes) /* derived name */
{
    if (top != start) {
        return 0;
    }
    int available = end - top;
    if (available < numBytes) {
        return 0;
    }
    top += available;
    numBytes = available;
    return start;
}
