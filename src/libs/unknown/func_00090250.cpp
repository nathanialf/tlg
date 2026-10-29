/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the new object referenced before the old one is released. */
void FUN_00090250(hkRefVariant *self, hkReferencedObject *object)
{
    if (object) {
        object->addReference();
    }
    if (self->object) {
        self->object->removeReference();
    }
    self->object = object;
}
