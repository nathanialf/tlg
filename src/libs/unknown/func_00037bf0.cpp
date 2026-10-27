/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hknpMaskedShape's vtable (0x1693a80), its deleting
 * destructor: the destructor 0x37c40, then the object back to the thread's
 * heap at its recorded size. */
void FUN_00037bf0(hknpMaskedShape *self)
{
    FUN_00037c40(self);
    freeReferencedObject(self, sizeof(hknpMaskedShape));
}
