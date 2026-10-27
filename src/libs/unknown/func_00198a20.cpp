/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: an element's index handed back to the free list. */
void ElementPool00198a20::FUN_00198a20(int index)
{
    freeIndices.pushBack(index);
}
