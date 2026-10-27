/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxMesh's vtable (0x16a25a0), its deleting destructor:
 * the destructor 0x8bf00, then the object back to the thread's heap at its recorded size. */
void FUN_0008beb0(hkxMesh *self)
{
    FUN_0008bf00(self);
    freeReferencedObject(self, sizeof(hkxMesh));
}
