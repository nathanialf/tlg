/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the number of blocks in a chain. */
int FUN_000188a0(const FreeListBlock *block) /* derived name */
{
    int count = 0;
    for (; block; block = block->next) {
        count++;
    }
    return count;
}
