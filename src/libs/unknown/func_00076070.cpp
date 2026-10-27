/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: the deleting destructor of the 0x160-byte object of
 * vtable 0x169b460 and of its derived class: the destructor 0x760c0, then
 * the object back to the thread's heap. */
void FUN_00076070(Elements000760c0 *self)
{
    FUN_000760c0(self);
    if (self) {
        D_16dc070->temp58->blockFree(self, 0x160);
    }
}
