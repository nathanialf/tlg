/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxVertexAnimation's vtable (0x16a26c0), its deleting destructor:
 * the destructor 0x8c990, then the object back to the thread's heap at its recorded size. */
void FUN_0008c940(hkxVertexAnimation *self)
{
    FUN_0008c990(self);
    freeReferencedObject(self, sizeof(hkxVertexAnimation));
}
