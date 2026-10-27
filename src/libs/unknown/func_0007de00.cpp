/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkpRagdollConstraintData's vtable (0x169d0d0), its deleting destructor:
 * the destructor 0x7de50, then the object back to the thread's heap at its recorded size. */
void FUN_0007de00(hkpRagdollConstraintData *self)
{
    FUN_0007de50(self);
    freeReferencedObject(self, sizeof(hkpRagdollConstraintData));
}
