/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkMemoryMeshShape's vtable (0x1692530), its deleting
 * destructor: the destructor 0x2a9b0, then the object back to the thread's
 * heap at its recorded size, 72 bytes by default. */
void FUN_0002a960(hkMemoryMeshShape *self)
{
    FUN_0002a9b0(self);
    freeReferencedObject(self, 72);
}
