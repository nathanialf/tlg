/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the object's vtable (0x16a68d0), its deleting destructor:
 * the destructor 0x19a7c0, then the object back to the thread's heap at its recorded size. */
void FUN_0019a770(Object0019a7c0 *self)
{
    FUN_0019a7c0(self);
    freeReferencedObject(self, sizeof(Object0019a7c0));
}
