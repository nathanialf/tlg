/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the world's vtable (0x1699220, which its
 * constructor 0x48b20 stores), its deleting destructor: the destructor
 * 0x4b040, then the world back to the thread's heap at its recorded size. */
void FUN_0004aff0(hknpWorld *self)
{
    FUN_0004b040(self);
    freeReferencedObject(self, sizeof(hknpWorld));
}
