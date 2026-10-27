/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpWorldSnapshot's vtable (0x16a4d50), its deleting destructor:
 * the destructor 0x15bfa0, then the object back to the thread's heap at its recorded size. */
void FUN_0015bf50(hknpWorldSnapshot *self)
{
    FUN_0015bfa0(self);
    freeReferencedObject(self, sizeof(hknpWorldSnapshot));
}
