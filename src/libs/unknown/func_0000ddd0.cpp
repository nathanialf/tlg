/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkSimpleLocalFrame's vtable (0x168d8e0), its deleting
 * destructor: the destructor 0xde20, then the object back to the thread's
 * heap at its recorded size. */
void FUN_0000ddd0(hkSimpleLocalFrame *self)
{
    FUN_0000de20(self);
    freeReferencedObject(self, sizeof(hkSimpleLocalFrame));
}
