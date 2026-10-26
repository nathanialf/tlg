/* src/libs/unknown/: library-region functions (below 0x1a3e00; docs/TARGETS.md) matched before their library is known. */
#include "tlg_hk_reflect.h"

/* Finish a loaded object through the type's finish callback, when it has
 * one, beside the cleanup forwarder FUN_00092fc0; the type info registry's
 * slot 6 calls it with the flag it keeps at +0x28 (0x17d904). */
void hkTypeInfo::FUN_00092f90(void *object, int finishing) const /* derived name */
{
    if (finishFunction) {
        finishFunction(object, finishing);
    }
}
