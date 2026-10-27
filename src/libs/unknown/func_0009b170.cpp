/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkcdPlanarGeometry's vtable (0x16a36f0), its deleting destructor:
 * the destructor 0x9b1c0, then the object back to the thread's heap at its recorded size. */
void FUN_0009b170(hkcdPlanarGeometry *self)
{
    FUN_0009b1c0(self);
    freeReferencedObject(self, sizeof(hkcdPlanarGeometry));
}
