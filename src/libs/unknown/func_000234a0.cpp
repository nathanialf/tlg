/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkIndexedTransformSet's vtable (0x1691760), its
 * deleting destructor: the destructor 0x234f0, then the object back to the
 * thread's heap at its recorded size. */
void FUN_000234a0(hkIndexedTransformSet *self)
{
    FUN_000234f0(self);
    freeReferencedObject(self, sizeof(hkIndexedTransformSet));
}
