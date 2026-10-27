/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the deleting destructor of the 0xa0-byte object of vtable
 * 0x16a3f50: the destructor 0x140e70, then the object back to the thread's
 * heap. */
void FUN_00140e20(Object00140a60 *self)
{
    FUN_00140e70(self);
    if (self) {
        D_16dc070->temp58->blockFree(self, 0xa0);
    }
}
