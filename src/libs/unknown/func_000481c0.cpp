/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_thread.h"
#include "tlg_lib_unknown.h"

/* derived name: RefArrays's deleting destructor: the arrays destroyed by the
 * base destructor 0x48040, then the object back to the thread's heap. */
void FUN_000481c0(RefArrays *self)
{
    self->RefArrays::~RefArrays();
    if (self) {
        D_16dc070->temp58->blockFree(self, sizeof(RefArrays));
    }
}
