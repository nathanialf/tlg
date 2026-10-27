/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_lib_unknown.h"

/* derived name: slot 1 of hkxAttributeHolder's vtable (0x16a1670), its deleting destructor:
 * hkxAttributeHolder's destructor, then the object back to the thread's heap at its recorded size. */
void FUN_00089330(hkxAttributeHolder *self)
{
    self->hkxAttributeHolder::~hkxAttributeHolder();
    freeReferencedObject(self, sizeof(hkxAttributeHolder));
}
