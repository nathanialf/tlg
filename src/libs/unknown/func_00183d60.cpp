/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the critical-section object's vtable (0x16a6530), its deleting destructor:
 * the destructor 0x183db0, then the object back to the thread's heap at its recorded size. */
void FUN_00183d60(Object00183db0 *self)
{
    FUN_00183db0(self);
    freeReferencedObject(self, sizeof(Object00183db0));
}
