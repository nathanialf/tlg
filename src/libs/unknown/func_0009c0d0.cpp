/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkcdPlanarCsgOperand's vtable (0x16a3730), its deleting destructor:
 * the destructor 0x9c120, then the object back to the thread's heap at its recorded size. */
void FUN_0009c0d0(hkcdPlanarCsgOperand *self)
{
    FUN_0009c120(self);
    freeReferencedObject(self, sizeof(hkcdPlanarCsgOperand));
}
