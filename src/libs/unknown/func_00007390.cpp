/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the pool's vtable (0x168cba0), its deleting
 * destructor: the destructor 0x73e0, then the object back to the thread's
 * heap at its recorded size. */
void FUN_00007390(Pool00007880 *self)
{
    FUN_000073e0(self);
    freeReferencedObject(self, sizeof(Pool00007880));
}
