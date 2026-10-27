/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkcdPlanarGeometryPlanesCollection's vtable (0x16a3770), its deleting destructor:
 * the destructor 0x9c960, then the object back to the thread's heap at its recorded size. */
void FUN_0009c910(hkcdPlanarGeometryPlanesCollection *self)
{
    FUN_0009c960(self);
    freeReferencedObject(self, sizeof(hkcdPlanarGeometryPlanesCollection));
}
