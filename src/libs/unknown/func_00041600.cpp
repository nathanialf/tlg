/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpCompoundShape's vtable (0x1697900), its deleting
 * destructor: the destructor 0x41650, then the object back to the thread's
 * heap at its recorded size. */
void FUN_00041600(hknpCompoundShape *self)
{
    FUN_00041650(self);
    freeReferencedObject(self, sizeof(hknpCompoundShape));
}
