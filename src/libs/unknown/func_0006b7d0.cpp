/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of RefArrays0005a230's vtable (0x169ab10), its deleting destructor:
 * the destructor 0x5a230, then the object back to the thread's heap at its recorded size. */
void FUN_0006b7d0(RefArrays0005a230 *self)
{
    FUN_0005a230(self);
    freeReferencedObject(self, sizeof(RefArrays0005a230));
}
