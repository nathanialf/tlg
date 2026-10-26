/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 4 of hkReferencedObject's vtable, kept by most of the
 * classes derived from it (about 400 vtable slots): delete the object. As
 * the class's key function it emits the vtable and, with it, the deleting
 * destructor of the inline destructor (slot 1, FUN_000066e0: nothing to
 * release, the object freed through the class allocator). */
void hkReferencedObject::FUN_000069a0() const /* derived name */
{
    delete this;
}
