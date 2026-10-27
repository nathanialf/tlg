/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the deleting destructor of the world's larger object at
 * +0x1d0: the destructor 0x14e100, then the object back to the thread's
 * heap. */
void FUN_0014e0b0(hknpWorldObject1d0Large *self)
{
    FUN_0014e100(self);
    if (self) {
        D_16dc070->temp58->blockFree(self, 0x1a0);
    }
}
