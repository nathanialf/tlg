/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkMemoryMeshBody's vtable (0x1691600), its deleting
 * destructor: the destructor 0x23200, then the object back to the thread's
 * heap at its recorded size. */
void FUN_000231b0(hkMemoryMeshBody *self)
{
    FUN_00023200(self);
    freeReferencedObject(self, sizeof(hkMemoryMeshBody));
}
