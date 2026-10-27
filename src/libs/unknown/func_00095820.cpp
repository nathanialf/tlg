/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkcdPlanarSolid's vtable (0x16a3630), its deleting destructor:
 * the destructor 0x95870, then the object back to the thread's heap at its recorded size. */
void FUN_00095820(hkcdPlanarSolid *self)
{
    FUN_00095870(self);
    freeReferencedObject(self, sizeof(hkcdPlanarSolid));
}
