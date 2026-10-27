/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpPhysicsSceneData's vtable (0x1697ea0), its
 * deleting destructor: the destructor 0x467f0, then the object back to the
 * thread's heap at its recorded size. */
void FUN_000467a0(hknpPhysicsSceneData *self)
{
    FUN_000467f0(self);
    freeReferencedObject(self, sizeof(hknpPhysicsSceneData));
}
