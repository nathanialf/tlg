/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the reference-counted base's vtable (0x16a6960), its deleting destructor:
 * the destructor 0x19c150, then the object back to the thread's heap at its recorded size. */
void FUN_0019c100(hkPackfileWriter *self)
{
    FUN_0019c150(self);
    freeReferencedObject(self, sizeof(hkPackfileWriter));
}
