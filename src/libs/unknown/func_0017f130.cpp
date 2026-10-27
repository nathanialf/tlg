/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkMemoryResourceHandle's vtable (0x16a6270), its deleting destructor:
 * the destructor 0x17f180, then the object back to the thread's heap at its recorded size. */
void FUN_0017f130(hkMemoryResourceHandle *self)
{
    FUN_0017f180(self);
    freeReferencedObject(self, sizeof(hkMemoryResourceHandle));
}
