/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxMeshSection's vtable (0x16a29d0), its deleting destructor:
 * the destructor 0x8dc50, then the object back to the thread's heap at its recorded size. */
void FUN_0008dc00(hkxMeshSection *self)
{
    FUN_0008dc50(self);
    freeReferencedObject(self, sizeof(hkxMeshSection));
}
