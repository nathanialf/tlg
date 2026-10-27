/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the critical-section object's vtable (0x16a64f0), its deleting destructor:
 * the destructor 0x183810, then the object back to the thread's heap at its recorded size. */
void FUN_001837c0(Object00183810 *self)
{
    FUN_00183810(self);
    freeReferencedObject(self, sizeof(Object00183810));
}
