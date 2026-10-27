/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpPhysicsSystemData's vtable (0x16a5130), its deleting destructor:
 * the destructor 0x165af0, then the object back to the thread's heap at its recorded size. */
void FUN_00165aa0(hknpPhysicsSystemData *self)
{
    FUN_00165af0(self);
    freeReferencedObject(self, sizeof(hknpPhysicsSystemData));
}
