/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkMultipleVertexBuffer's vtable (0x1691ff0), its
 * deleting destructor: the destructor 0x24db0, then the object back to the
 * thread's heap at its recorded size. */
void FUN_00024b80(hkMultipleVertexBuffer *self)
{
    FUN_00024db0(self);
    freeReferencedObject(self, sizeof(hkMultipleVertexBuffer));
}
