/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxNode's vtable (0x16a25e0), its deleting destructor:
 * the destructor 0x8c110, then the object back to the thread's heap at its recorded size. */
void FUN_0008c0c0(hkxNode *self)
{
    FUN_0008c110(self);
    freeReferencedObject(self, sizeof(hkxNode));
}
