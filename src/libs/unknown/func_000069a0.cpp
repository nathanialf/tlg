/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* derived name: slot 4 of hkReferencedObject's vtable, kept by most of the
 * classes derived from it (about 400 vtable slots): delete the object. */
void hkReferencedObject::FUN_000069a0() const /* derived name */
{
    delete this;
}
