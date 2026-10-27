/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of Object0012a8c0's vtable (0x16a3e30), its deleting destructor:
 * the destructor 0x12a8c0, then the object back to the thread's heap at its recorded size. */
void FUN_0012a860(Object0012a8c0 *self)
{
    FUN_0012a8c0(self);
    freeReferencedObject(self, sizeof(Object0012a8c0));
}
