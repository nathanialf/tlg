/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxMaterial's vtable (0x16a0db0), its deleting destructor:
 * the destructor 0x87130, then the object back to the thread's heap at its recorded size. */
void FUN_000870e0(hkxMaterial *self)
{
    FUN_00087130(self);
    freeReferencedObject(self, sizeof(hkxMaterial));
}
