/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkBinaryPackfileWriter's vtable (0x16a6470), its deleting destructor:
 * the base's destructor body 0x19c150 (the class adds nothing to destroy), then the object back to the thread's heap at its recorded size. */
void FUN_00181ba0(hkBinaryPackfileWriter *self)
{
    FUN_0019c150(self);
    freeReferencedObject(self, sizeof(hkBinaryPackfileWriter));
}
