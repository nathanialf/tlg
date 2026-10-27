/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkp6DofConstraintData's vtable (0x16a5d20), its deleting destructor:
 * the destructor 0x17b750, then the object back to the thread's heap at its recorded size. */
void FUN_0017b700(hkp6DofConstraintData *self)
{
    FUN_0017b750(self);
    freeReferencedObject(self, sizeof(hkp6DofConstraintData));
}
