/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxScene's vtable (0x16a2910), its deleting destructor:
 * the destructor 0x8d2c0, then the object back to the thread's heap at its recorded size. */
void FUN_0008d270(hkxScene *self)
{
    FUN_0008d2c0(self);
    freeReferencedObject(self, sizeof(hkxScene));
}
