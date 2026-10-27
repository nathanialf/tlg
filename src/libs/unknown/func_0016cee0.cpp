/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpScaledConvexShape's vtable (0x16a54a0), its deleting destructor:
 * the destructor 0x16cf30, then the object back to the thread's heap at its recorded size. */
void FUN_0016cee0(hknpScaledConvexShape *self)
{
    FUN_0016cf30(self);
    freeReferencedObject(self, sizeof(hknpScaledConvexShape));
}
