/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpConstraintCollisionFilter's vtable (0x16a4c20), its deleting destructor:
 * the destructor 0x159bc0, then the object back to the thread's heap at its recorded size. */
void FUN_00159b70(hknpConstraintCollisionFilter *self)
{
    FUN_00159bc0(self);
    freeReferencedObject(self, sizeof(hknpConstraintCollisionFilter));
}
