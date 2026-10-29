/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: the references of a strided array of objects released. */
void hkReferencedObject::FUN_000069c0(const hkReferencedObject *const *objects, int numObjects,
                                      int pointerStriding)
{
    for (int i = 0; i < numObjects; i++) {
        (*objects)->removeReference();
        objects = reinterpret_cast<const hkReferencedObject *const *>(
            reinterpret_cast<const char *>(objects) + pointerStriding);
    }
}
