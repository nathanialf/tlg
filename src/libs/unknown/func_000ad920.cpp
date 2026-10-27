/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkStorageSkinnedMeshShape's vtable (0x16a3af0), its deleting destructor:
 * the destructor 0xadba0, then the object back to the thread's heap at its recorded size. */
void FUN_000ad920(hkStorageSkinnedMeshShape *self)
{
    FUN_000adba0(self);
    freeReferencedObject(self, sizeof(hkStorageSkinnedMeshShape));
}
