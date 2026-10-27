/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpDummyShape's vtable (0x16967b0), its deleting
 * destructor: the destructor 0x3e200, then the object back to the thread's
 * heap at its recorded size. */
void FUN_0003e1b0(hknpDummyShape *self)
{
    FUN_0003e200(self);
    freeReferencedObject(self, sizeof(hknpDummyShape));
}
