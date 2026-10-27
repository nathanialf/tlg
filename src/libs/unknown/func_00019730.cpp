/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of the page allocator's vtable (0x168e8e0), its deleting
 * destructor: the destructor 0x19780, then the object back to the thread's
 * heap at its recorded size. */
void FUN_00019730(PageAllocator *self)
{
    FUN_00019780(self);
    freeReferencedObject(self, sizeof(PageAllocator));
}
