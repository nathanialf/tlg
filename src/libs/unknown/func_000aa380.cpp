/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkSkinBinding's vtable (0x16a3850), its deleting destructor:
 * the destructor 0xaa3d0, then the object back to the thread's heap at its recorded size. */
void FUN_000aa380(hkSkinBinding *self)
{
    FUN_000aa3d0(self);
    freeReferencedObject(self, sizeof(hkSkinBinding));
}
